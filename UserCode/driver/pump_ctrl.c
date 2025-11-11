#include "pump_ctrl.h"
#include "bsp/bsp_pump.h"    // 引用BSP层定义（调整路径）

void PumpCtrl_Init(void)
{
    BSP_Pump_GPIO_Init();   // 由BSP负责引脚初始化
    Pump_SetPower(0);
}

void Pump_On(void)
{
    HAL_GPIO_WritePin(BSP_PUMP_GPIO_PORT, BSP_PUMP_GPIO_PIN, GPIO_PIN_SET);
}

void Pump_Off(void)
{
    HAL_GPIO_WritePin(BSP_PUMP_GPIO_PORT, BSP_PUMP_GPIO_PIN, GPIO_PIN_RESET);
}

void Valve_On(void)
{
    HAL_GPIO_WritePin(BSP_VALVE_GPIO_PORT, BSP_VALVE_GPIO_PIN, GPIO_PIN_SET);
}

void Valve_Off(void)
{
    HAL_GPIO_WritePin(BSP_VALVE_GPIO_PORT, BSP_VALVE_GPIO_PIN, GPIO_PIN_RESET);
}

/**
 * @brief  设置泵的功率（占空比）
 * @param  power: 0-100，表示0%到100%的占空比
 */
void Pump_SetPower(uint8_t power)
{
    if (power > 100) power = 100; // 限制最大值为100%

    uint32_t pulse = (BSP_PUMP_TIM.Init.Period + 1) * power / 100;
    __HAL_TIM_SET_COMPARE(&BSP_PUMP_TIM, BSP_PUMP_TIM_CHANNEL, pulse);
}