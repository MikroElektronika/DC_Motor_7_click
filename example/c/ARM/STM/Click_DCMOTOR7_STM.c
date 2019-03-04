/*
Example for DCMOTOR7 Click

    Date          : okt 2018.
    Author        : Katarina Perendic

Test configuration STM32 :
    
    MCU              : STM32F107VCT6
    Dev. Board       : EasyMx PRO v7 for STM32
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C module and sets RST pin and PWM pin as OUTPUT
- Application Initialization - Initialization driver init, enabled all output port, sets H-Bridge operation mode and Motor Digital tBLK
- Application Task - (code snippet) -  Set the motor A and the motor B to rotate clockwise and in the Counte clockwise direction, 
                                       and between the change of direction, the motor stops the motor.

- note
    VM input - 10 V (min) to 47 V (max)

*/

#include "Click_DCMOTOR7_types.h"
#include "Click_DCMOTOR7_config.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_i2cInit( _MIKROBUS1, &_DCMOTOR7_I2C_CFG[0] );
    Delay_ms( 100 );
}

void applicationInit()
{
    dcmotor7_i2cDriverInit( (T_DCMOTOR7_P)&_MIKROBUS1_GPIO, (T_DCMOTOR7_P)&_MIKROBUS1_I2C, _DCMOTOR7_SLAVE_ADDRESS_1_1 );

    dcmotor7_writeCommand(_DCMOTOR7_CMD_CONFIGURATION, _DCMOTOR7_ENABLE_ALL_OUTPUT_PORT);
    dcmotor7_setTBLKAB(_DCMOTOR7_TBLK_FOSCM_X6_CLK);
    dcmotor7_setHBMode(_DCMOTOR7_HBMODE_SMALL_MODE);
}

void applicationTask()
{
    dcmotor7_setMotor(_DCMOTOR7_MOTOR_A, 0, 1);
    dcmotor7_setMotor(_DCMOTOR7_MOTOR_B, 0, 1);
    Delay_ms( 500 );
    
    dcmotor7_motorStop(_DCMOTOR7_MOTOR_A);
    dcmotor7_motorStop(_DCMOTOR7_MOTOR_B);
    Delay_ms( 2000 );
    
    dcmotor7_setMotor(_DCMOTOR7_MOTOR_A, 1, 0);
    dcmotor7_setMotor(_DCMOTOR7_MOTOR_B, 1, 0);
    Delay_ms( 500 );
    
    dcmotor7_motorStop(_DCMOTOR7_MOTOR_A);
    dcmotor7_motorStop(_DCMOTOR7_MOTOR_B);
    Delay_ms( 2000 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}