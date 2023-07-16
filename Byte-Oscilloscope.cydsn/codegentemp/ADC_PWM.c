/*******************************************************************************
* File Name: ADC_PWM.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the ADC_PWM
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_PWM.h"

/** Indicates whether or not the ADC_PWM has been initialized. 
*  The variable is initialized to 0 and set to 1 the first time 
*  ADC_PWM_Start() is called. This allows the Component to 
*  restart without reinitialization after the first call to 
*  the ADC_PWM_Start() routine.
*/
uint8_t ADC_PWM_initVar = 0U;

/** The instance-specific configuration structure. This should be used in the 
*  associated ADC_PWM_Init() function.
*/ 
cy_stc_tcpwm_pwm_config_t const ADC_PWM_config =
{
    .pwmMode = 4UL,
    .clockPrescaler = 0UL,
    .pwmAlignment = 0UL,
    .deadTimeClocks = 0UL,
    .runMode = 0UL,
    .period0 = 199UL,
    .period1 = 32768UL,
    .enablePeriodSwap = false,
    .compare0 = 100UL,
    .compare1 = 16384UL,
    .enableCompareSwap = false,
    .interruptSources = 0UL,
    .invertPWMOut = 0UL,
    .invertPWMOutN = 0UL,
    .killMode = 2UL,
    .swapInputMode = 3UL,
    .swapInput = CY_TCPWM_INPUT_CREATOR,
    .reloadInputMode = 3UL,
    .reloadInput = CY_TCPWM_INPUT_CREATOR,
    .startInputMode = 3UL,
    .startInput = CY_TCPWM_INPUT_CREATOR,
    .killInputMode = 3UL,
    .killInput = CY_TCPWM_INPUT_CREATOR,
    .countInputMode = 3UL,
    .countInput = CY_TCPWM_INPUT_CREATOR,
};


/*******************************************************************************
* Function Name: ADC_PWM_Start
****************************************************************************//**
*
*  Calls the ADC_PWM_Init() when called the first time and enables 
*  the ADC_PWM. For subsequent calls the configuration is left 
*  unchanged and the component is just enabled.
*
* \globalvars
*  \ref ADC_PWM_initVar
*
*******************************************************************************/
void ADC_PWM_Start(void)
{
    if (0U == ADC_PWM_initVar)
    {
        (void) Cy_TCPWM_PWM_Init(ADC_PWM_HW, ADC_PWM_CNT_NUM, &ADC_PWM_config);

        ADC_PWM_initVar = 1U;
    }

    Cy_TCPWM_Enable_Multiple(ADC_PWM_HW, ADC_PWM_CNT_MASK);
    
    #if (ADC_PWM_INPUT_DISABLED == 7UL)
        Cy_TCPWM_TriggerStart(ADC_PWM_HW, ADC_PWM_CNT_MASK);
    #endif /* (ADC_PWM_INPUT_DISABLED == 7UL) */    
}


/* [] END OF FILE */
