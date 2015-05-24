/**
 *  Defines for your entire project at one place
 * 
 *	@author 	Tilen Majerle
 *	@email		tilen@majerle.eu
 *	@website	http://stm32f4-discovery.com
 *	@version 	v1.0
 *	@ide		Keil uVision 5
 *	@license	GNU GPL v3
 *	
 * |----------------------------------------------------------------------
 * | Copyright (C) Tilen Majerle, 2014
 * | 
 * | This program is free software: you can redistribute it and/or modify
 * | it under the terms of the GNU General Public License as published by
 * | the Free Software Foundation, either version 3 of the License, or
 * | any later version.
 * |  
 * | This program is distributed in the hope that it will be useful,
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * | GNU General Public License for more details.
 * | 
 * | You should have received a copy of the GNU General Public License
 * | along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * |----------------------------------------------------------------------
 */
#ifndef TM_DEFINES_H
#define TM_DEFINES_H

// 這邊可以定義一些關於 SPI 的參數
/*
 *		基本上 SPI 有 1 到 6 組可以使用
 *		而每一組有 1 到 3 組 pin腳連接方式 ====>	 SPI: 1 ~ 6
 *											PinPack: 1 ~ 3
 *											可參考 http://stm32f4-discovery.com/2014/04/library-05-spi-for-stm32f4xx/
 *											此為 STM32F429 的 datasheet
 *
 *		下面還有提到一些關於 SPI 的一些參數，當然也可以使用 STM32 所給的預設值。
 *		例如下面的 prescaler 是除頻的部分，最高為 32，最低為 2，除頻越高代表速度越慢，除頻越低代表越快，這之間都與 CPU Core Clock 有關係。
 *		datasize 代表的應該是，一次傳送幾個 bit
 *		firstbit 代表的是，little-endian or big-endian
 *		masterslave 設定你是 master 還是 slave 的角色
 *		mode 的話，則是有 0, 1, 2, 3 				(看起來像是 TM 自己定義的)
 *				TM_SPI_Mode_0, // Clock polarity low, clock phase 1st edge
 *				TM_SPI_Mode_1, // Clock polarity low, clock phase 2nd edge
 *				TM_SPI_Mode_2, // Clock polarity high, clock phase 1st edge
 *				TM_SPI_Mode_3  // Clock polarity high, clock phase 2nd edge
 *			http://blog.csdn.net/ce123_zhouwei/article/details/6923293
 *			http://wiki.csie.ncku.edu.tw/embedded/SPI#is-functional-description
 */

/* Put your global defines for all libraries here used in your project */

/* If you need to change settings for your SPI, then uncomment lines you want to change */
/* Replace x with SPI number, 1 - 6 */
/* If you need to change for more SPI's, copy content below more times and edit */

/* Default prescaler */
//#define TM_SPIx_PRESCALER	SPI_BaudRatePrescaler_32
/* Specify datasize */
//#define TM_SPIx_DATASIZE 	SPI_DataSize_8b
/* Specify which bit is first */
//#define TM_SPIx_FIRSTBIT 	SPI_FirstBit_MSB
/* Mode, master or slave */
//#define TM_SPIx_MASTERSLAVE	SPI_Mode_Master
/* Specify mode of operation, clock polarity and clock phase */
//#define TM_SPIx_MODE		TM_SPI_Mode_0

#endif
