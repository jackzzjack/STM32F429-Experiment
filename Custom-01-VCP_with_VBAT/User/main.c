/**
 *	Keil project for ADC peripheral how to measure Vbat pin
 *
 *  Before you start, select your target, on the right of the "Load" button
 *
 *	@author		Tilen Majerle
 *	@email		tilen@majerle.eu
 *	@website	http://stm32f4-discovery.com
 *	@ide		Keil uVision 5
 *	@packs		STM32F4xx Keil packs version 2.2.0 or greater required
 *	@stdperiph	STM32F4xx Standard peripheral drivers version 1.4.0 or greater required
 */

/* Include core modules */
#include "stm32f4xx.h"
/* Include my libraries here */
#include "defines.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_adc.h"
#include "tm_stm32f4_usart.h"
#include <stdio.h>

#include "tm_stm32f4_usb_vcp.h"
#include "tm_stm32f4_disco.h"

int main(void) {
	char str[150];
	char c;
	
	/* Initialize system */
	SystemInit();
	
	/* Initialize Delay library */
	TM_DELAY_Init();
	
	 TM_DISCO_LedInit();
	
	/* Initialize USART1, 115200 baud, TX: PB6 */
	//TM_USART_Init(USART1, TM_USART_PinsPack_2, 115200);
	
	/* Initialize USB VCP */    
    TM_USB_VCP_Init();
	
	/* Initialize ADC1 */
	TM_ADC_InitADC(ADC1);
	
	/* Enable vbat channel */
	TM_ADC_EnableVbat();
	
	//while (1) {
		/* Read & format data */
		//sprintf(str, "----------------------------\nVbat voltage: %d mV\n", TM_ADC_ReadVbat(ADC1));
		
		/* Put to USART */
		//TM_USART_Puts(USART1, str);
		
		/* Little delay */
		//Delayms(1000);
	//}
	
	
	while (1) {
        /* USB configured OK, drivers OK */
        if (TM_USB_VCP_GetStatus() == TM_USB_VCP_CONNECTED) {
            /* Turn on GREEN led */
            TM_DISCO_LedOn(LED_GREEN);
			
			
			//TM_USB_VCP_Puts(str);
			
			//Delayms(1000);
			
            /* If something arrived at VCP */
            if (TM_USB_VCP_Getc(&c) == TM_USB_VCP_DATA_OK) {
                /* Return data back */
                TM_USB_VCP_Putc(c);
				sprintf(str, "----------------------------\nVbat voltage: %d mV\n", TM_ADC_ReadVbat(ADC1));
				TM_USB_VCP_Puts(str);
            }
        } else {
            /* USB not OK */
            TM_DISCO_LedOff(LED_GREEN);
        }
    }
}
