#include "project.h"

//Rotina de inicialização do acesso direto à memória do conversor AD:
void adcDmaInit()
{
    cy_en_dma_status_t dma_init_status;
    cy_stc_dma_channel_config_t channel_config;	

    //Inicializando os descritores:
    
    dma_init_status = Cy_DMA_Descriptor_Init(&ADC_DMA_adcDescriptor, &ADC_DMA_adcDescriptor_config);  
    
    //Inicializando o canal de acesso direto à memória:
    
    channel_config.descriptor  = &ADC_DMA_adcDescriptor;
    channel_config.preemptable = ADC_DMA_PREEMPTABLE;
    channel_config.priority    = ADC_DMA_PRIORITY;
    channel_config.enable      = 0u;
  
    dma_init_status = Cy_DMA_Channel_Init(ADC_DMA_HW, ADC_DMA_DW_CHANNEL, &channel_config);
	
    //Definindo os endereços de origem e destino dos descritores:
        
    Cy_DMA_Descriptor_SetSrcAddress(&ADC_DMA_adcDescriptor, (uint32_t *)&(SAR->CHAN_RESULT[0]));
    Cy_DMA_Descriptor_SetDstAddress(&ADC_DMA_adcDescriptor, (uint32_t *)&(SCB5->TX_FIFO_WR));
        
    //Habilitando o canal de acesso direto à memória:
    
    Cy_DMA_Channel_Enable(ADC_DMA_HW, ADC_DMA_DW_CHANNEL);
    Cy_DMA_Enable(ADC_DMA_HW);
}

//Função principal:
int main(void)
{
    //Habilitando os interruptores:
        
    __enable_irq();
      
    //Inicializando componentes:
    
    adcDmaInit();
        
    FILTER_OP0_Start();
    FILTER_OP1_Start();

    ADC_PWM_Start();
    
    OSCILLOSCOPE_ADC_Start();
    
    OSCILLOSCOPE_UART_Start();    
    
    //Iniciando a conversão analógico-digital:
    
    OSCILLOSCOPE_ADC_StartConvert();
        
    //Laço de piscagem do LED:
    
    for(;;)
    {
        Cy_GPIO_Write(LED_GPIO_PORT,LED_GPIO_NUM,1);
        CyDelay(1000);
        Cy_GPIO_Write(LED_GPIO_PORT,LED_GPIO_NUM,0);
        CyDelay(1000);
    }
}