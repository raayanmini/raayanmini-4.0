/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ADC10_LM35_Pin GPIO_PIN_0
#define ADC10_LM35_GPIO_Port GPIOC
#define ADC11_POT_Pin GPIO_PIN_1
#define ADC11_POT_GPIO_Port GPIOC
#define CAN_SPI2_MISO_Pin GPIO_PIN_2
#define CAN_SPI2_MISO_GPIO_Port GPIOC
#define CAN_SPI2_MOSI_Pin GPIO_PIN_3
#define CAN_SPI2_MOSI_GPIO_Port GPIOC
#define TFT_SPI1_AO_Pin GPIO_PIN_0
#define TFT_SPI1_AO_GPIO_Port GPIOA
#define TFT_SPI1_RESET_Pin GPIO_PIN_1
#define TFT_SPI1_RESET_GPIO_Port GPIOA
#define TFT_SPI1_CS_Pin GPIO_PIN_4
#define TFT_SPI1_CS_GPIO_Port GPIOA
#define TFT_SPI1_SCK_Pin GPIO_PIN_5
#define TFT_SPI1_SCK_GPIO_Port GPIOA
#define TFT_SPI1_MOSI_Pin GPIO_PIN_7
#define TFT_SPI1_MOSI_GPIO_Port GPIOA
#define CAN_SPI2_CS_Pin GPIO_PIN_4
#define CAN_SPI2_CS_GPIO_Port GPIOC
#define LCD_D4_Pin GPIO_PIN_0
#define LCD_D4_GPIO_Port GPIOB
#define LCD_D5_Pin GPIO_PIN_1
#define LCD_D5_GPIO_Port GPIOB
#define LCD_D6_Pin GPIO_PIN_2
#define LCD_D6_GPIO_Port GPIOB
#define CAN_SPI2_SCK_Pin GPIO_PIN_10
#define CAN_SPI2_SCK_GPIO_Port GPIOB
#define BUZZ_Pin GPIO_PIN_12
#define BUZZ_GPIO_Port GPIOB
#define RED_LED_Pin GPIO_PIN_13
#define RED_LED_GPIO_Port GPIOB
#define GREEN_LED_Pin GPIO_PIN_14
#define GREEN_LED_GPIO_Port GPIOB
#define SW_UP_Pin GPIO_PIN_8
#define SW_UP_GPIO_Port GPIOC
#define SW_UP_EXTI_IRQn EXTI9_5_IRQn
#define SW_DN_Pin GPIO_PIN_9
#define SW_DN_GPIO_Port GPIOC
#define SW_DN_EXTI_IRQn EXTI9_5_IRQn
#define SW_ENT_Pin GPIO_PIN_10
#define SW_ENT_GPIO_Port GPIOC
#define SW_ENT_EXTI_IRQn EXTI15_10_IRQn
#define LCD_D7_Pin GPIO_PIN_3
#define LCD_D7_GPIO_Port GPIOB
#define LCD_RS_Pin GPIO_PIN_4
#define LCD_RS_GPIO_Port GPIOB
#define LCD_RW_Pin GPIO_PIN_5
#define LCD_RW_GPIO_Port GPIOB
#define LCD_EN_Pin GPIO_PIN_8
#define LCD_EN_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
