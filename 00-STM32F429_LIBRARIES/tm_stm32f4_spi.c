/**	
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
#include "tm_stm32f4_spi.h"

/* Private functions */
static void TM_SPIx_Init(SPI_TypeDef* SPIx, TM_SPI_PinsPack_t pinspack, TM_SPI_Mode_t SPI_Mode, uint16_t SPI_BaudRatePrescaler, uint16_t SPI_MasterSlave, uint16_t SPI_FirstBit);
void TM_SPI1_INT_InitPins(TM_SPI_PinsPack_t pinspack);
void TM_SPI2_INT_InitPins(TM_SPI_PinsPack_t pinspack);
void TM_SPI3_INT_InitPins(TM_SPI_PinsPack_t pinspack);
void TM_SPI4_INT_InitPins(TM_SPI_PinsPack_t pinspack);
void TM_SPI5_INT_InitPins(TM_SPI_PinsPack_t pinspack);
void TM_SPI6_INT_InitPins(TM_SPI_PinsPack_t pinspack);

/*
 * FlowChart:
 * 			TM_SPI_Init -------------
 * 			(TM_SPI_InitWithMode)	|
 * 			(TM_SPI_InitFull)		|
 * 									|
 * 									TM_SPIx_Init --------
 * 														|
 * 														SPI_StructInit
 * 														TM_SPI1_INT_InitPins --------
 * 																					|
 * 																					TM_GPIO_InitAlternate
 * 														SPI_Init
 */
 
/*
 *	SPI 初始化的 Function
 */
void TM_SPI_Init(SPI_TypeDef* SPIx, TM_SPI_PinsPack_t pinspack) {
	/*
	 *	可以看到這邊，要使用每一組 SPI 都經過了包裝，各自呼叫了 TM_SPIx_Init，因此在指定要使用哪一個 SPI 時，
	 *	記得要去 defines.h 先進行 preprocessor 做定義。
	 *
	 *	可以發現到，其實類似的 Init Function 有好幾個，這一個 TM_SPI_Init 則是所有的參數都使用預設值。
	 */
	/* Init with default settings */
#ifdef SPI1
	if (SPIx == SPI1) {
		TM_SPIx_Init(SPI1, pinspack, TM_SPI1_MODE, TM_SPI1_PRESCALER, TM_SPI1_MASTERSLAVE, TM_SPI1_FIRSTBIT);
	}
#endif
#ifdef SPI2
	if (SPIx == SPI2) {
		TM_SPIx_Init(SPI2, pinspack, TM_SPI2_MODE, TM_SPI2_PRESCALER, TM_SPI2_MASTERSLAVE, TM_SPI2_FIRSTBIT);
	}
#endif
#ifdef SPI3
	if (SPIx == SPI3) {
		TM_SPIx_Init(SPI3, pinspack, TM_SPI3_MODE, TM_SPI3_PRESCALER, TM_SPI3_MASTERSLAVE, TM_SPI3_FIRSTBIT);
	}
#endif
#ifdef SPI4
	if (SPIx == SPI4) {
		TM_SPIx_Init(SPI4, pinspack, TM_SPI4_MODE, TM_SPI4_PRESCALER, TM_SPI4_MASTERSLAVE, TM_SPI4_FIRSTBIT);
	}
#endif
#ifdef SPI5
	if (SPIx == SPI5) {
		TM_SPIx_Init(SPI5, pinspack, TM_SPI5_MODE, TM_SPI5_PRESCALER, TM_SPI5_MASTERSLAVE, TM_SPI5_FIRSTBIT);
	}
#endif
#ifdef SPI6
	if (SPIx == SPI6) {
		TM_SPIx_Init(SPI6, pinspack, TM_SPI6_MODE, TM_SPI6_PRESCALER, TM_SPI6_MASTERSLAVE, TM_SPI6_FIRSTBIT);
	}
#endif
}

/*
 *	和 TM_SPI_Init 一樣，但多了可以自訂 SPI Mode 的參數(取代預設的 SPI Mode)。
 */
void TM_SPI_InitWithMode(SPI_TypeDef* SPIx, TM_SPI_PinsPack_t pinspack, TM_SPI_Mode_t SPI_Mode) {
	/* Init with custom mode, 0, 1, 2, 3 */
#ifdef SPI1
	if (SPIx == SPI1) {
		TM_SPIx_Init(SPI1, pinspack, SPI_Mode, TM_SPI1_PRESCALER, TM_SPI1_MASTERSLAVE, TM_SPI1_FIRSTBIT);
	}
#endif
#ifdef SPI2
	if (SPIx == SPI2) {
		TM_SPIx_Init(SPI2, pinspack, SPI_Mode, TM_SPI2_PRESCALER, TM_SPI2_MASTERSLAVE, TM_SPI2_FIRSTBIT);
	}
#endif
#ifdef SPI3
	if (SPIx == SPI3) {
		TM_SPIx_Init(SPI3, pinspack, SPI_Mode, TM_SPI3_PRESCALER, TM_SPI3_MASTERSLAVE, TM_SPI3_FIRSTBIT);
	}
#endif
#ifdef SPI4
	if (SPIx == SPI4) {
		TM_SPIx_Init(SPI4, pinspack, SPI_Mode, TM_SPI4_PRESCALER, TM_SPI4_MASTERSLAVE, TM_SPI4_FIRSTBIT);
	}
#endif
#ifdef SPI5
	if (SPIx == SPI5) {
		TM_SPIx_Init(SPI5, pinspack, SPI_Mode, TM_SPI5_PRESCALER, TM_SPI5_MASTERSLAVE, TM_SPI5_FIRSTBIT);
	}
#endif
#ifdef SPI6
	if (SPIx == SPI6) {
		TM_SPIx_Init(SPI6, pinspack, SPI_Mode, TM_SPI6_PRESCALER, TM_SPI6_MASTERSLAVE, TM_SPI6_FIRSTBIT);
	}
#endif
}

/*
 *	和 TM_SPI_Init 相同，但主要是變成所有的參數都可以進行定義(全部可以取代預設值)。
 */
void TM_SPI_InitFull(
	SPI_TypeDef* SPIx, 
	TM_SPI_PinsPack_t pinspack,
	uint16_t SPI_BaudRatePrescaler,
	TM_SPI_Mode_t SPI_Mode_t,
	uint16_t SPI_Mode,
	uint16_t SPI_FirstBit\
) {
	/* Init FULL SPI settings by user */
#ifdef SPI1
	if (SPIx == SPI1) {
		TM_SPIx_Init(SPI1, pinspack, SPI_Mode_t, SPI_BaudRatePrescaler, SPI_Mode, SPI_FirstBit);
	}
#endif
#ifdef SPI2
	if (SPIx == SPI2) {
		TM_SPIx_Init(SPI2, pinspack, SPI_Mode_t, SPI_BaudRatePrescaler, SPI_Mode, SPI_FirstBit);
	}
#endif
#ifdef SPI3
	if (SPIx == SPI3) {
		TM_SPIx_Init(SPI3, pinspack, SPI_Mode_t, SPI_BaudRatePrescaler, SPI_Mode, SPI_FirstBit);
	}
#endif
#ifdef SPI4
	if (SPIx == SPI4) {
		TM_SPIx_Init(SPI4, pinspack, SPI_Mode_t, SPI_BaudRatePrescaler, SPI_Mode, SPI_FirstBit);
	}
#endif
#ifdef SPI5
	if (SPIx == SPI5) {
		TM_SPIx_Init(SPI5, pinspack, SPI_Mode_t, SPI_BaudRatePrescaler, SPI_Mode, SPI_FirstBit);
	}
#endif
#ifdef SPI6
	if (SPIx == SPI6) {
		TM_SPIx_Init(SPI6, pinspack, SPI_Mode_t, SPI_BaudRatePrescaler, SPI_Mode, SPI_FirstBit);
	}
#endif
}

uint16_t TM_SPI_GetPrescalerFromMaxFrequency(SPI_TypeDef* SPIx, uint32_t MAX_SPI_Frequency) {
	RCC_ClocksTypeDef RCC_Clocks;
	uint32_t APB_Frequency;
	uint8_t i;
	
	/* Prevent false input */
	if (MAX_SPI_Frequency == 0) {
		return SPI_BaudRatePrescaler_256;
	}
	
	/* Get clock values from RCC */
	RCC_GetClocksFreq(&RCC_Clocks);
	
	/* Calculate max SPI clock */
	if (0
#ifdef SPI1	
		|| SPIx == SPI1
#endif
#ifdef SPI4
		|| SPIx == SPI4
#endif
#ifdef SPI5
		|| SPIx == SPI5
#endif
#ifdef SPI6
		|| SPIx == SPI6
#endif
	) {
		APB_Frequency = RCC_Clocks.PCLK2_Frequency;
	} else {
		APB_Frequency = RCC_Clocks.PCLK1_Frequency;
	}
	
	/* Calculate prescaler value */
	/* Bits 5:3 in CR1 SPI registers are prescalers */
	/* 000 = 2, 001 = 4, 002 = 8, ..., 111 = 256 */
	for (i = 0; i < 8; i++) {
		if (APB_Frequency / (1 << (i + 1)) <= MAX_SPI_Frequency) {
			/* Bits for BP are 5:3 in CR1 register */
			return (i << 3);
		}
	}
	
	/* Use max prescaler possible */
	return SPI_BaudRatePrescaler_256;
}

/*
 * 此 Function 用來傳送 8 bit 資料
 *
 * 會先檢查 SPI 的狀態，在進行傳送，最後再檢查狀態。
 * 但其實都是去檢查暫存器，值丟到暫存器，再檢查暫存器。
 */
uint8_t TM_SPI_Send(SPI_TypeDef* SPIx, uint8_t data) {
	/* Wait for previous transmissions to complete if DMA TX enabled for SPI */
	SPI_WAIT(SPIx);
	/* Fill output buffer with data */
	SPIx->DR = data;
	/* Wait for transmission to complete */
	SPI_WAIT(SPIx);
	
	/* Return data from buffer */
	return SPIx->DR;
}

void TM_SPI_SendMulti(SPI_TypeDef* SPIx, uint8_t* dataOut, uint8_t* dataIn, uint16_t count) {
	uint16_t i;
	
	/* Wait for previous transmissions to complete if DMA TX enabled for SPI */
	SPI_WAIT(SPIx);
	
	for (i = 0; i < count; i++) {
		/* Fill output buffer with data */
		SPIx->DR = dataOut[i];
		/* Wait for SPI to end everything */
		SPI_WAIT(SPIx);
		/* Read data register */
		dataIn[i] = SPIx->DR;
	}
}

void TM_SPI_WriteMulti(SPI_TypeDef* SPIx, uint8_t* dataOut, uint16_t count) {
	uint16_t i;
	
	/* Wait for previous transmissions to complete if DMA TX enabled for SPI */
	SPI_WAIT(SPIx);
	
	for (i = 0; i < count; i++) {
		/* Fill output buffer with data */
		SPIx->DR = dataOut[i];
		/* Wait for SPI to end everything */
		SPI_WAIT(SPIx);
		/* Read data register */
		SPIx->DR;
	}
}

void TM_SPI_ReadMulti(SPI_TypeDef* SPIx, uint8_t* dataIn, uint8_t dummy, uint16_t count) {
	uint16_t i;
	
	/* Wait for previous transmissions to complete if DMA TX enabled for SPI */
	SPI_WAIT(SPIx);
	
	for (i = 0; i < count; i++) {
		/* Fill output buffer with data */
		SPIx->DR = dummy;
		/* Wait for SPI to end everything */
		SPI_WAIT(SPIx);
		/* Save data to buffer */
		dataIn[i] = SPIx->DR;
	}
}

uint16_t TM_SPI_Send16(SPI_TypeDef* SPIx, uint16_t data) {
	/* Wait for previous transmissions to complete if DMA TX enabled for SPI */
	SPI_WAIT(SPIx);
	
	/* Fill output buffer with data */
	SPIx->DR = data;
	/* Wait for SPI to end everything */
	SPI_WAIT(SPIx);
	/* Return data from buffer */
	return SPIx->DR;
}

void TM_SPI_SendMulti16(SPI_TypeDef* SPIx, uint16_t* dataOut, uint16_t* dataIn, uint16_t count) {
	uint16_t i;
	
	/* Wait for previous transmissions to complete if DMA TX enabled for SPI */
	SPI_WAIT(SPIx);
	
	for (i = 0; i < count; i++) {
		/* Fill output buffer with data */
		SPIx->DR = dataOut[i];
		/* Wait for SPI to end everything */
		SPI_WAIT(SPIx);
		/* Read data register */
		dataIn[i] = SPIx->DR;
	}
}

void TM_SPI_WriteMulti16(SPI_TypeDef* SPIx, uint16_t* dataOut, uint16_t count) {
	uint16_t i;
	
	/* Wait for previous transmissions to complete if DMA TX enabled for SPI */
	SPI_WAIT(SPIx);
	
	for (i = 0; i < count; i++) {
		/* Fill output buffer with data */
		SPIx->DR = dataOut[i];
		/* Wait for SPI to end everything */
		SPI_WAIT(SPIx);
		/* Read data register */
		SPIx->DR;
	}
}

void TM_SPI_ReadMulti16(SPI_TypeDef* SPIx, uint16_t* dataIn, uint16_t dummy, uint16_t count) {
	uint16_t i;
	
	/* Wait for previous transmissions to complete if DMA TX enabled for SPI */
	SPI_WAIT(SPIx);
	
	for (i = 0; i < count; i++) {
		/* Fill output buffer with data */
		SPIx->DR = dummy;
		/* Wait for SPI to end everything */
		SPI_WAIT(SPIx);
		/* Save data to buffer */
		dataIn[i] = SPIx->DR;
	}
}

/* Private functions */
static void TM_SPIx_Init(SPI_TypeDef* SPIx, TM_SPI_PinsPack_t pinspack, TM_SPI_Mode_t SPI_Mode, uint16_t SPI_BaudRatePrescaler, uint16_t SPI_MasterSlave, uint16_t SPI_FirstBit) {
	SPI_InitTypeDef SPI_InitStruct;

	// 這一個 Function 直接呼叫到 STM32 所提供的 Function，此 Function 的功能在於，把 SPI 的結構，填上預設值。
	/* Set default settings */
	SPI_StructInit(&SPI_InitStruct);

	// 接下來的各個 Region，分別對於各自的 SPI 做個別的設定。
		// 在這邊先只註解第一個 (SPI 1)
#ifdef SPI1	
	if (SPIx == SPI1) {

		/* 
		 * 把 APB2 Enable 起來，因為 SPI 1 要使用 APB2 這一個 Bus
		 * 我們注意到，SPI 1, 4, 5, 6 皆使用 APB2 這一個 Bus
		 * SPI 2, 3 則是使用 APB1 這一個 Bus
		 *
		 * 因此藉由 RCC->APB2ENR 來 Enable Clock，並使用 API 給予的 Define。
		 * 
		 */
		/* Enable SPI clock */
		RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

		// 這邊進行 TM Library 的 Pin 的設定
		/* Init pins */
		TM_SPI1_INT_InitPins(pinspack);

		// 設定 SPI 1 DataSize，這邊比照 STM32 預設值
		/* Set options */
		SPI_InitStruct.SPI_DataSize = TM_SPI1_DATASIZE;
	}
#endif
#ifdef SPI2
	if (SPIx == SPI2) {
		/* Enable SPI clock */
		RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
		
		/* Init pins */
		TM_SPI2_INT_InitPins(pinspack);
		
		/* Set options */
		SPI_InitStruct.SPI_DataSize = TM_SPI2_DATASIZE;
	}
#endif
#ifdef SPI3
	if (SPIx == SPI3) {
		/* Enable SPI clock */
		RCC->APB1ENR |= RCC_APB1ENR_SPI3EN;
		
		/* Init pins */
		TM_SPI3_INT_InitPins(pinspack);
		
		/* Set options */
		SPI_InitStruct.SPI_DataSize = TM_SPI3_DATASIZE;
	
	}
#endif
#ifdef SPI4
	if (SPIx == SPI4) {
		/* Enable SPI clock */
		RCC->APB2ENR |= RCC_APB2ENR_SPI4EN;
		
		/* Init pins */
		TM_SPI4_INT_InitPins(pinspack);
		
		/* Set options */
		SPI_InitStruct.SPI_DataSize = TM_SPI4_DATASIZE;
	}
#endif
#ifdef SPI5
	if (SPIx == SPI5) {
		/* Enable SPI clock */
		RCC->APB2ENR |= RCC_APB2ENR_SPI5EN;
		
		/* Init pins */
		TM_SPI5_INT_InitPins(pinspack);
		
		/* Set options */
		SPI_InitStruct.SPI_DataSize = TM_SPI5_DATASIZE;
	}
#endif
#ifdef SPI6
	if (SPIx == SPI6) {
		/* Enable SPI clock */
		RCC->APB2ENR |= RCC_APB2ENR_SPI6EN;
		
		/* Init pins */
		TM_SPI6_INT_InitPins(pinspack);
		
		/* Set options */
		SPI_InitStruct.SPI_DataSize = TM_SPI6_DATASIZE;
	}
#endif

	// 這邊再重新給予一次 SPI 各個的參數
	/* Fill SPI settings */
	SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler;
	SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStruct.SPI_FirstBit = SPI_FirstBit;
	SPI_InitStruct.SPI_Mode = SPI_MasterSlave;
	SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;

	// 這邊給予不同的 SPI Mode，然後設定不一樣的 CPOL, CPHA
	// 看起來 STM 是靠 SPI_CPOL, SPI_CPHA 來決定 Mode (有點像是設定哪一種觸發方式、高低相位等)
	/* SPI mode */
	if (SPI_Mode == TM_SPI_Mode_0) {
		SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;
		SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
	} else if (SPI_Mode == TM_SPI_Mode_1) {
		SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;
		SPI_InitStruct.SPI_CPHA = SPI_CPHA_2Edge;
	} else if (SPI_Mode == TM_SPI_Mode_2) {
		SPI_InitStruct.SPI_CPOL = SPI_CPOL_High;
		SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
	} else if (SPI_Mode == TM_SPI_Mode_3) {
		SPI_InitStruct.SPI_CPOL = SPI_CPOL_High;
		SPI_InitStruct.SPI_CPHA = SPI_CPHA_2Edge;
	}
	
	/* Disable first */
	SPIx->CR1 &= ~SPI_CR1_SPE;					// 先至 SPI Register 直接進行 Disable
	
	/* Init SPI */
	SPI_Init(SPIx, &SPI_InitStruct);			// 直接下至 STM32 所提供的 SPI Init Function
	
	/* Enable SPI */
	SPIx->CR1 |= SPI_CR1_SPE;					// Enable SPI Register
}

/*
 * 這幾個 Region 用來設定 SPI 所需要的 Pin 腳
 * 可以看到 SPI 搭配各自的 PinPack, 可以參考這邊 https://sites.google.com/site/johnkneenmicrocontrollers/input_output/stm32f429_io
 * PinPack 會去呼叫 GPIO AF 的部分
 */
/* Private functions */
#ifdef SPI1
void TM_SPI1_INT_InitPins(TM_SPI_PinsPack_t pinspack) {
	/* Init SPI pins */
#if defined(GPIOA)
	if (pinspack == TM_SPI_PinsPack_1) {
		TM_GPIO_InitAlternate(GPIOA, GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI1);
	}
#endif
#if defined(GPIOB)
	if (pinspack == TM_SPI_PinsPack_2) {
		TM_GPIO_InitAlternate(GPIOB, GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI1);
	}
#endif
	if (pinspack == TM_SPI_PinsPack_Custom) {
		/* Call user function */
		TM_SPI_InitCustomPinsCallback(SPI1);
	}
}
#endif

#ifdef SPI2
void TM_SPI2_INT_InitPins(TM_SPI_PinsPack_t pinspack) {
	/* Init SPI pins */
#if defined(GPIOB) && defined(GPIOC)
	if (pinspack == TM_SPI_PinsPack_1) {
		TM_GPIO_InitAlternate(GPIOB, GPIO_PIN_10, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI2);
		TM_GPIO_InitAlternate(GPIOC, GPIO_PIN_2 | GPIO_PIN_3, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI2);
	}
#endif
#if defined(GPIOB)
	if (pinspack == TM_SPI_PinsPack_2) {
		TM_GPIO_InitAlternate(GPIOB, GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI2);
	}
#endif
#if defined(GPIOI)
	if (pinspack == TM_SPI_PinsPack_3) {
		TM_GPIO_InitAlternate(GPIOI, GPIO_PIN_0 | GPIO_PIN_2 | GPIO_PIN_3, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI2);
	}
#endif
	if (pinspack == TM_SPI_PinsPack_Custom) {
		/* Call user function */
		TM_SPI_InitCustomPinsCallback(SPI2);
	}
}
#endif

#ifdef SPI3
void TM_SPI3_INT_InitPins(TM_SPI_PinsPack_t pinspack) {
	/* Enable SPI pins */
#if defined(GPIOB)
	if (pinspack == TM_SPI_PinsPack_1) {
		TM_GPIO_InitAlternate(GPIOB, GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI3);
	}
#endif
#if defined(GPIOC)
	if (pinspack == TM_SPI_PinsPack_2) {
		TM_GPIO_InitAlternate(GPIOC, GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI3);
	}
#endif
	if (pinspack == TM_SPI_PinsPack_Custom) {
		/* Call user function */
		TM_SPI_InitCustomPinsCallback(SPI3);
	}
}
#endif

#ifdef SPI4
void TM_SPI4_INT_InitPins(TM_SPI_PinsPack_t pinspack) {
	/* Init SPI pins */
#if defined(GPIOE)
	if (pinspack == TM_SPI_PinsPack_1) {
		TM_GPIO_InitAlternate(GPIOE, GPIO_PIN_2 | GPIO_PIN_5 | GPIO_PIN_6, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI4);
	}
#endif
#if defined(GPIOE)
	if (pinspack == TM_SPI_PinsPack_2) {
		TM_GPIO_InitAlternate(GPIOE, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI4);
	}
#endif
	if (pinspack == TM_SPI_PinsPack_Custom) {
		/* Call user function */
		TM_SPI_InitCustomPinsCallback(SPI4);
	}
}
#endif

#ifdef SPI5
void TM_SPI5_INT_InitPins(TM_SPI_PinsPack_t pinspack) {
	/* Init SPI pins */
#if defined(GPIOF)
	if (pinspack == TM_SPI_PinsPack_1) {
		TM_GPIO_InitAlternate(GPIOF, GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI5);
	}
#endif
#if defined(GPIOF) && defined(GPIOH)
	if (pinspack == TM_SPI_PinsPack_2) {
		TM_GPIO_InitAlternate(GPIOF, GPIO_PIN_11, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI5);
		TM_GPIO_InitAlternate(GPIOH, GPIO_PIN_6 | GPIO_PIN_7, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI5);
	}
#endif
	if (pinspack == TM_SPI_PinsPack_Custom) {
		/* Call user function */
		TM_SPI_InitCustomPinsCallback(SPI5);
	}
}
#endif

#ifdef SPI6
void TM_SPI6_INT_InitPins(TM_SPI_PinsPack_t pinspack) {
#if defined(GPIOG)
	if (pinspack == TM_SPI_PinsPack_1) {
		/* Init SPI pins */
		TM_GPIO_InitAlternate(GPIOG, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI6);
	}
#endif
	if (pinspack == TM_SPI_PinsPack_Custom) {
		/* Call user function */
		TM_SPI_InitCustomPinsCallback(SPI6);
	}
}
#endif

