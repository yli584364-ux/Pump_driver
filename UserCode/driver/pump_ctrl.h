/**
 ******************************************************************************
 * @file    pump_ctrl.h
 * @brief   驱动层接口文件：真空泵与电磁阀控制（原气压传感器）
 * @note    本文件不依赖具体硬件引脚，硬件映射由 BSP 层定义
 * @author  
 * @version 1.0
 * @date    2025-11-08
 ******************************************************************************
 */

#ifndef __PUMP_CTRL_H
#define __PUMP_CTRL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"   // 根据芯片系列修改
#include "bsp/bsp_pump.h"     // 引用板级引脚定义（调整路径以匹配 -IUserCode）

/**
 * @brief  初始化泵与传感器控制GPIO（调用BSP层）
 */
void PumpCtrl_Init(void);

/**
 * @brief  打开真空泵
 */
void Pump_On(void);

/**
 * @brief  关闭真空泵
 */
void Pump_Off(void);

/**
 * @brief  打开电磁阀
 */
void Valve_On(void);

/**
 * @brief  关闭电磁阀
 */
void Valve_Off(void);

/**
 * @brief  设置泵的功率（占空比）
 * @param  power: 0-100，表示0%到100%的占空比
 */
void Pump_SetPower(uint8_t power);

#ifdef __cplusplus
}
#endif

#endif /* __PUMP_CTRL_H */
