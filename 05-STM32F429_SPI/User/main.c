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

	// 初始化 SPI，選擇第一組 SPI 和第一組 SPI 的 PinsPack。PinsPack 可以參考這邊 https://sites.google.com/site/johnkneenmicrocontrollers/input_output/stm32f429_io
	/* Initialize SPI */
	/* SCK = PA5, MOSI = PA7, MISO = PA6 */
	TM_SPI_Init(SPI1, TM_SPI_PinsPack_1);
	
	// 傳送 0x15 這個 ASCII 出去
	/* Send 0x15 over SPI1 */
	TM_SPI_Send(SPI1, 0x15);
	
    while(1) {

    }
}
