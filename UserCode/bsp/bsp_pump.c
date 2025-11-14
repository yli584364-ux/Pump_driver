#include "bsp_pump.h"

TIM_HandleTypeDef BSP_PUMP_TIM;

/**
 * @brief  初始化泵与电磁阀的GPIO引脚
 */
void BSP_Pump_GPIO_Init(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Pin = BSP_PUMP_GPIO_PIN;
    HAL_GPIO_Init(BSP_PUMP_GPIO_PORT, &GPIO_InitStruct);

    // 初始化电磁阀 GPIO（原 Sensor）
    GPIO_InitStruct.Pin = BSP_VALVE_GPIO_PIN;
    HAL_GPIO_Init(BSP_VALVE_GPIO_PORT, &GPIO_InitStruct);

    HAL_GPIO_WritePin(BSP_PUMP_GPIO_PORT, BSP_PUMP_GPIO_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(BSP_VALVE_GPIO_PORT, BSP_VALVE_GPIO_PIN, GPIO_PIN_RESET);
}

/**
 * @brief  初始化泵的PWM功能
 * @note   需要修改模块->定时器设定，以匹配具体硬件
 * :(这边只是为了防止报错设定成TIM4，实际使用时请根据硬件修改
 */
void BSP_Pump_Init(void)
{
    __HAL_RCC_TIM4_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    //配置PWM引脚
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = BSP_PUMP_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(BSP_PUMP_GPIO_PORT, &GPIO_InitStruct);

    //定时器配置
    //厂家建议PWM输出频率为20kHz
    BSP_PUMP_TIM.Instance = TIM4;
    BSP_PUMP_TIM.Init.Prescaler = 42 - 1; //假设时钟为84MHz，预分频42，计数频率2MHz
    BSP_PUMP_TIM.Init.CounterMode = TIM_COUNTERMODE_UP;
    BSP_PUMP_TIM.Init.Period = 100 - 1; //周期100，频率20kHz
    BSP_PUMP_TIM.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    HAL_TIM_PWM_Init(&BSP_PUMP_TIM);

    TIM_OC_InitTypeDef sConfigOC = {0};
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 0; // 初始占空比0%
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&BSP_PUMP_TIM, &sConfigOC, TIM_CHANNEL_1);
    
    HAL_TIM_PWM_Start(&BSP_PUMP_TIM, TIM_CHANNEL_1);
}