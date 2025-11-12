#include "bsp/bsp_pump.h"
#include "driver/pump_ctrl.h"

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    PumpCtrl_Init();

    Pump_SetPower(30);  // 设置30%功率
    Pump_On();
    HAL_Delay(3000);

    Pump_SetPower(80);  // 提高到80%
    HAL_Delay(3000);

    Pump_Off();

    while (1);
}
