#ifndef __BSP_PUMP_H
#define __BSP_PUMP_H

#include "stm32f4xx_hal.h"   // 根据芯片系列修改

// 定义当前板子的引脚映射
#define BSP_PUMP_GPIO_PORT      GPIOA
#define BSP_PUMP_GPIO_PIN       GPIO_PIN_0

// 电磁阀（原 Sensor）GPIO 映射
#define BSP_VALVE_GPIO_PORT     GPIOA
#define BSP_VALVE_GPIO_PIN      GPIO_PIN_1

// 定义PWM输出通道
// 请根据实际使用的定时器和通道修改
#define BSP_PUMP_TIM             htim4
#define BSP_PUMP_TIM_CHANNEL     TIM_CHANNEL_1
extern TIM_HandleTypeDef BSP_PUMP_TIM; // 在bsp_pump.c定义

// 可选：兼容旧名称（如无需兼容可删除下面两行）
#define BSP_SENSOR_GPIO_PORT    BSP_VALVE_GPIO_PORT
#define BSP_SENSOR_GPIO_PIN     BSP_VALVE_GPIO_PIN

void BSP_Pump_GPIO_Init(void);

void BSP_Pump_Init(void);

#endif
