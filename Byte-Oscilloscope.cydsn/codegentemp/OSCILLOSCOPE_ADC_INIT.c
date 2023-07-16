/***************************************************************************//**
* \file     OSCILLOSCOPE_ADC_INIT.c
* \version  3.10
*
* \brief
* Provides the initialization data structure for the OSCILLOSCOPE_ADC Component.
*
********************************************************************************
* \copyright
* (c) 2017-2018, Cypress Semiconductor Corporation. All rights reserved.
* This software, including source code, documentation and related
* materials ("Software"), is owned by Cypress Semiconductor
* Corporation ("Cypress") and is protected by and subject to worldwide
* patent protection (United States and foreign), United States copyright
* laws and international treaty provisions. Therefore, you may use this
* Software only as provided in the license agreement accompanying the
* software package from which you obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,
* non-transferable license to copy, modify, and compile the
* Software source code solely for use in connection with Cypress's
* integrated circuit products. Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO
* WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING,
* BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE. Cypress reserves the right to make
* changes to the Software without notice. Cypress does not assume any
* liability arising out of the application or use of the Software or any
* product or circuit described in the Software. Cypress does not
* authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/
#include "OSCILLOSCOPE_ADC.h"

/* Array of configuration structures for the ScanADC PDL */
static const cy_stc_sar_config_t OSCILLOSCOPE_ADC_hwConfigs[OSCILLOSCOPE_ADC_TOTAL_CONFIGS] = {
    /*Configuration 0*/
    {
        .ctrl               = OSCILLOSCOPE_ADC_CFG0_CTRL_INIT,
        .sampleCtrl         = OSCILLOSCOPE_ADC_CFG0_SAMPLE_CTRL_INIT,
        .sampleTime01       = OSCILLOSCOPE_ADC_CFG0_SAMPLE_TIME01_INIT,
        .sampleTime23       = OSCILLOSCOPE_ADC_CFG0_SAMPLE_TIME23_INIT,
        .rangeThres         = OSCILLOSCOPE_ADC_CFG0_RANGE_THRES_INIT,
        .rangeCond          = OSCILLOSCOPE_ADC_CFG0_RANGE_COND_INIT,
        .chanEn             = OSCILLOSCOPE_ADC_CFG0_CHANNEL_EN,
        .chanConfig         = {((uint32_t) (0 << SAR_CHAN_CONFIG_SAMPLE_TIME_SEL_Pos)),
        CY_SAR_DEINIT,
        CY_SAR_DEINIT,
        CY_SAR_DEINIT,
        CY_SAR_DEINIT,
        CY_SAR_DEINIT,
        CY_SAR_DEINIT,
        CY_SAR_DEINIT,
        CY_SAR_DEINIT,
        CY_SAR_DEINIT,
        CY_SAR_DEINIT,
        CY_SAR_DEINIT,
        CY_SAR_DEINIT,
        CY_SAR_DEINIT,
        CY_SAR_DEINIT,
        CY_SAR_DEINIT},

        .intrMask           = SAR_INTR_MASK_EOS_MASK_Msk,
        .satIntrMask        = OSCILLOSCOPE_ADC_CFG0_SATURATE_INTR_MASK,
        .rangeIntrMask      = OSCILLOSCOPE_ADC_CFG0_RANGE_INTR_MASK,
        .muxSwitch          = CY_SAR_DEINIT,
        .muxSwitchSqCtrl    = CY_SAR_DEINIT,
        .configRouting      = false,
        .vrefMvValue        = (uint32_t) OSCILLOSCOPE_ADC_CFG0_VREF_MV_VALUE,
    }
#if(OSCILLOSCOPE_ADC_TOTAL_CONFIGS > 1)
    /*Configuration 1*/
    ,{
        .ctrl               = OSCILLOSCOPE_ADC_CFG1_CTRL_INIT,
        .sampleCtrl         = OSCILLOSCOPE_ADC_CFG1_SAMPLE_CTRL_INIT,
        .sampleTime01       = OSCILLOSCOPE_ADC_CFG1_SAMPLE_TIME01_INIT,
        .sampleTime23       = OSCILLOSCOPE_ADC_CFG1_SAMPLE_TIME23_INIT,
        .rangeThres         = OSCILLOSCOPE_ADC_CFG1_RANGE_THRES_INIT,
        .rangeCond          = OSCILLOSCOPE_ADC_CFG1_RANGE_COND_INIT,
        .chanEn             = OSCILLOSCOPE_ADC_CFG1_CHANNEL_EN,
        /* CHAN_CONFIG Settings */
        .chanConfig         = 
        .intrMask           = SAR_INTR_MASK_EOS_MASK_Msk,
        .satIntrMask        = OSCILLOSCOPE_ADC_CFG1_SATURATE_INTR_MASK,
        .rangeIntrMask      = OSCILLOSCOPE_ADC_CFG1_RANGE_INTR_MASK,
        .muxSwitch          = CY_SAR_DEINIT,
        .muxSwitchSqCtrl    = CY_SAR_DEINIT,
        .configRouting      = false, /* configRouting */
        .vrefMvValue        = (uint32_t) OSCILLOSCOPE_ADC_CFG1_VREF_MV_VALUE,
    }
#endif
#if(OSCILLOSCOPE_ADC_TOTAL_CONFIGS > 2)
    /*Configuration 2*/
    ,{
        .ctrl               = OSCILLOSCOPE_ADC_CFG2_CTRL_INIT,
        .sampleCtrl         = OSCILLOSCOPE_ADC_CFG2_SAMPLE_CTRL_INIT,
        .sampleTime01       = OSCILLOSCOPE_ADC_CFG2_SAMPLE_TIME01_INIT,
        .sampleTime23       = OSCILLOSCOPE_ADC_CFG2_SAMPLE_TIME23_INIT,
        .rangeThres         = OSCILLOSCOPE_ADC_CFG2_RANGE_THRES_INIT,
        .rangeCond          = OSCILLOSCOPE_ADC_CFG2_RANGE_COND_INIT,
        .chanEn             = OSCILLOSCOPE_ADC_CFG2_CHANNEL_EN,
        /* CHAN_CONFIG Settings */
        .chanConfig         = 
        .intrMask           = SAR_INTR_MASK_EOS_MASK_Msk,
        .satIntrMask        = OSCILLOSCOPE_ADC_CFG2_SATURATE_INTR_MASK,
        .rangeIntrMask      = OSCILLOSCOPE_ADC_CFG2_RANGE_INTR_MASK,
        .muxSwitch          = CY_SAR_DEINIT,
        .muxSwitchSqCtrl    = CY_SAR_DEINIT,
        .configRouting      = false, /* configRouting */
        .vrefMvValue        = (uint32_t) OSCILLOSCOPE_ADC_CFG2_VREF_MV_VALUE,
    }
#endif
    /*Configuration 3*/
#if(OSCILLOSCOPE_ADC_TOTAL_CONFIGS > 3)
    ,{
        .ctrl               = OSCILLOSCOPE_ADC_CFG3_CTRL_INIT,
        .sampleCtrl         = OSCILLOSCOPE_ADC_CFG3_SAMPLE_CTRL_INIT,
        .sampleTime01       = OSCILLOSCOPE_ADC_CFG3_SAMPLE_TIME01_INIT,
        .sampleTime23       = OSCILLOSCOPE_ADC_CFG3_SAMPLE_TIME23_INIT,
        .rangeThres         = OSCILLOSCOPE_ADC_CFG3_RANGE_THRES_INIT,
        .rangeCond          = OSCILLOSCOPE_ADC_CFG3_RANGE_COND_INIT,
        .chanEn             = OSCILLOSCOPE_ADC_CFG3_CHANNEL_EN,
        /* CHAN_CONFIG Settings */
        .chanConfig         = 
        .intrMask           = SAR_INTR_MASK_EOS_MASK_Msk,
        .satIntrMask        = OSCILLOSCOPE_ADC_CFG3_SATURATE_INTR_MASK,
        .rangeIntrMask      = OSCILLOSCOPE_ADC_CFG3_RANGE_INTR_MASK,
        .muxSwitch          = CY_SAR_DEINIT,
        .muxSwitchSqCtrl    = CY_SAR_DEINIT,
        .configRouting      = false, /* configRouting */
        .vrefMvValue        = (uint32_t) OSCILLOSCOPE_ADC_CFG3_VREF_MV_VALUE,
    }
#endif
};

/* Array of configuration structures used to set configurations */
const OSCILLOSCOPE_ADC_CONFIG_STRUCT OSCILLOSCOPE_ADC_allConfigs[OSCILLOSCOPE_ADC_TOTAL_CONFIGS] = {
    /*Configuration 0*/
    {
        .channelBase        = OSCILLOSCOPE_ADC_CFG0_CHANNEL_BASE,
        .numChannels        = OSCILLOSCOPE_ADC_CFG0_CHANNEL_COUNT,
        .hwConfigStc        = &OSCILLOSCOPE_ADC_hwConfigs[0],
        .miscConfig         = OSCILLOSCOPE_ADC_CFG0_MISC_CONFIG_INIT,
    #if (OSCILLOSCOPE_ADC_CLOCK_INTERNAL)
        .clkDivider         = OSCILLOSCOPE_ADC_CFG0_CLOCKDIVIDER,
    #endif /* OSCILLOSCOPE_ADC_CLOCK_INTERNAL */
    }
#if(OSCILLOSCOPE_ADC_TOTAL_CONFIGS > 1)
    /*Configuration 1*/
    ,{
        .channelBase        = OSCILLOSCOPE_ADC_CFG1_CHANNEL_BASE,
        .numChannels        = OSCILLOSCOPE_ADC_CFG1_CHANNEL_COUNT,
        .hwConfigStc        = &OSCILLOSCOPE_ADC_hwConfigs[1],
        .miscConfig         = OSCILLOSCOPE_ADC_CFG1_MISC_CONFIG_INIT,
    #if (OSCILLOSCOPE_ADC_CLOCK_INTERNAL)
        .clkDivider         = OSCILLOSCOPE_ADC_CFG1_CLOCKDIVIDER,
    #endif /* OSCILLOSCOPE_ADC_CLOCK_INTERNAL */
    }
#endif
#if(OSCILLOSCOPE_ADC_TOTAL_CONFIGS > 2)
    /*Configuration 2*/
    ,{
        .channelBase        = OSCILLOSCOPE_ADC_CFG2_CHANNEL_BASE,
        .numChannels        = OSCILLOSCOPE_ADC_CFG2_CHANNEL_COUNT,
        .hwConfigStc        = &OSCILLOSCOPE_ADC_hwConfigs[2],
        .miscConfig         = OSCILLOSCOPE_ADC_CFG2_MISC_CONFIG_INIT,
    #if (OSCILLOSCOPE_ADC_CLOCK_INTERNAL)
        .clkDivider         = OSCILLOSCOPE_ADC_CFG2_CLOCKDIVIDER,
    #endif /* OSCILLOSCOPE_ADC_CLOCK_INTERNAL */
    }
#endif
    /*Configuration 3*/
#if(OSCILLOSCOPE_ADC_TOTAL_CONFIGS > 3)
    ,{
        .channelBase        = OSCILLOSCOPE_ADC_CFG3_CHANNEL_BASE,
        .numChannels        = OSCILLOSCOPE_ADC_CFG3_CHANNEL_COUNT,
        .hwConfigStc        = &OSCILLOSCOPE_ADC_hwConfigs[3],
        .miscConfig         = OSCILLOSCOPE_ADC_CFG3_MISC_CONFIG_INIT,
    #if (OSCILLOSCOPE_ADC_CLOCK_INTERNAL)
        .clkDivider         = OSCILLOSCOPE_ADC_CFG3_CLOCKDIVIDER,
    #endif /* OSCILLOSCOPE_ADC_CLOCK_INTERNAL */
    }
#endif
};

/* [] END OF FILE */