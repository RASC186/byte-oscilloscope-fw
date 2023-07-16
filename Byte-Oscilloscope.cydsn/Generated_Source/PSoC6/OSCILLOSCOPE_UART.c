/***************************************************************************//**
* \file OSCILLOSCOPE_UART.c
* \version 2.0
*
*  This file provides the source code to the API for the UART Component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "OSCILLOSCOPE_UART.h"
#include "sysint/cy_sysint.h"
#include "cyfitter_sysint.h"
#include "cyfitter_sysint_cfg.h"

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
*     Global variables
***************************************/

/** OSCILLOSCOPE_UART_initVar indicates whether the OSCILLOSCOPE_UART
*  component has been initialized. The variable is initialized to 0
*  and set to 1 the first time OSCILLOSCOPE_UART_Start() is called.
*  This allows  the component to restart without reinitialization
*  after the first call to the OSCILLOSCOPE_UART_Start() routine.
*
*  If re-initialization of the component is required, then the
*  OSCILLOSCOPE_UART_Init() function can be called before the
*  OSCILLOSCOPE_UART_Start() or OSCILLOSCOPE_UART_Enable() function.
*/
uint8_t OSCILLOSCOPE_UART_initVar = 0U;


/** The instance-specific configuration structure.
* The pointer to this structure should be passed to Cy_SCB_UART_Init function
* to initialize component with GUI selected settings.
*/
cy_stc_scb_uart_config_t const OSCILLOSCOPE_UART_config =
{
    .uartMode                   = CY_SCB_UART_STANDARD,
    .enableMutliProcessorMode   = false,
    .smartCardRetryOnNack       = false,
    .irdaInvertRx               = false,
    .irdaEnableLowPowerReceiver = false,

    .oversample                 = 10UL,
    
    .enableMsbFirst             = false,
    .dataWidth                  = 8UL,
    .parity                     = CY_SCB_UART_PARITY_NONE,
    .stopBits                   = CY_SCB_UART_STOP_BITS_1,
    .enableInputFilter          = false,
    .breakWidth                 = 11UL,
    .dropOnFrameError           = false,
    .dropOnParityError          = false,

    .receiverAddress            = 0x0UL,
    .receiverAddressMask        = 0x0UL,
    .acceptAddrInFifo           = false,

    .enableCts                  = false,
    .ctsPolarity                = CY_SCB_UART_ACTIVE_LOW,
    .rtsRxFifoLevel             = 0UL,
    .rtsPolarity                = CY_SCB_UART_ACTIVE_LOW,

    .rxFifoTriggerLevel         = 0UL,
    .rxFifoIntEnableMask        = 0x0UL,

    .txFifoTriggerLevel         = 0UL,
    .txFifoIntEnableMask        = 0x0UL
};

/** The instance-specific context structure.
* It is used while the driver operation for internal configuration and
* data keeping for the UART. The user should not modify anything in this 
* structure.
*/
cy_stc_scb_uart_context_t OSCILLOSCOPE_UART_context;


/*******************************************************************************
* Function Name: OSCILLOSCOPE_UART_Start
****************************************************************************//**
*
* Invokes OSCILLOSCOPE_UART_Init() and OSCILLOSCOPE_UART_Enable().
* Also configures interrupt if it is internal.
* After this function call the component is enabled and ready for operation.
* This is the preferred method to begin component operation.
*
* \globalvars
* \ref OSCILLOSCOPE_UART_initVar - used to check initial configuration,
* modified  on first function call.
*
*******************************************************************************/
void OSCILLOSCOPE_UART_Start(void)
{
    if (0U == OSCILLOSCOPE_UART_initVar)
    {
        /* Configure component */
        (void) Cy_SCB_UART_Init(OSCILLOSCOPE_UART_HW, &OSCILLOSCOPE_UART_config, &OSCILLOSCOPE_UART_context);

        /* Hook interrupt service routine */
    #if defined(OSCILLOSCOPE_UART_SCB_IRQ__INTC_ASSIGNED)
        (void) Cy_SysInt_Init(&OSCILLOSCOPE_UART_SCB_IRQ_cfg, &OSCILLOSCOPE_UART_Interrupt);
    #endif /* (OSCILLOSCOPE_UART_SCB_IRQ__INTC_ASSIGNED) */
    
        /* Component is configured */
        OSCILLOSCOPE_UART_initVar = 1U;
    }

    /* Enable interrupt in NVIC */
#if defined(OSCILLOSCOPE_UART_SCB_IRQ__INTC_ASSIGNED)
    NVIC_EnableIRQ((IRQn_Type) OSCILLOSCOPE_UART_SCB_IRQ_cfg.intrSrc);
#endif /* (OSCILLOSCOPE_UART_SCB_IRQ__INTC_ASSIGNED) */

    Cy_SCB_UART_Enable(OSCILLOSCOPE_UART_HW);
}

#if defined(__cplusplus)
}
#endif


/* [] END OF FILE */
