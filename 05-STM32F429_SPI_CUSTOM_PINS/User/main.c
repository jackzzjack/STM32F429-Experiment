/**
 *	Keil project for SPI
 *
 *	Before you start, select your target, on the right of the "Load" button
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
#include "tm_stm32f4_spi.h"

int main(void) {
	/* Initialize system */
	SystemInit();

	// PinsPack 設定為 自訂，注意不要忘記要寫 callback function
	/* Initialize SPI with custom pins */
	TM_SPI_Init(SPI1, TM_SPI_PinsPack_Custom);
	
	/* Send 0x15 over SPI1 */
	TM_SPI_Send(SPI1, 0x15);
	
    while(1) {

    }
}

/* 多了這一個 callback，這邊的目的在於，可以針對不同的 SPI 自己混搭不同組的 GPIO
 * 例如這邊，原本是 PA5 ~ PA7，其中 PA5 和 PB3 一樣都是 SPI1_SCK，因此可以互換。
 * 		Reference: https://sites.google.com/site/johnkneenmicrocontrollers/input_output/stm32f429_io
 */
/* Custom pins callback for SPI */
void TM_SPI_InitCustomPinsCallback(SPI_TypeDef* SPIx) {
	/* Check for SPI1 */
	if (SPIx == SPI1) {
		/* Init custom pins */
		/* MOSI = PA7, MISO = PA6 */
		TM_GPIO_InitAlternate(GPIOA, GPIO_PIN_7 | GPIO_PIN_6, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI1);
		/* SCK = PB3 */
		TM_GPIO_InitAlternate(GPIOB, GPIO_PIN_3, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI1);
	}
}
