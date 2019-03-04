/*
    __dcmotor7_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__dcmotor7_driver.h"
#include "__dcmotor7_hal.c"

static uint8_t _portData = 0xFF;
/* ------------------------------------------------------------------- MACROS */

/* Command */
const uint8_t _DCMOTOR7_CMD_INPUT_PORT         = 0x00; // def xxxx xxxx
const uint8_t _DCMOTOR7_CMD_OUTPUT_PORT        = 0x01; // def 1111 1111
const uint8_t _DCMOTOR7_CMD_POLARITY_INVERSION = 0x02; // def 0000 0000
const uint8_t _DCMOTOR7_CMD_CONFIGURATION      = 0x03; // def 1111 1111

/* PORT */
const uint8_t _DCMOTOR7_PORT_0 = 0x01;
const uint8_t _DCMOTOR7_PORT_1 = 0x02;
const uint8_t _DCMOTOR7_PORT_2 = 0x04;
const uint8_t _DCMOTOR7_PORT_3 = 0x08;
const uint8_t _DCMOTOR7_PORT_4 = 0x10;
const uint8_t _DCMOTOR7_PORT_5 = 0x20;
const uint8_t _DCMOTOR7_PORT_6 = 0x40;
const uint8_t _DCMOTOR7_PORT_7 = 0x80;

/* TBLK noise rejection time */
const uint8_t _DCMOTOR7_TBLK_FOSCM_X4_CLK = 0x00;
const uint8_t _DCMOTOR7_TBLK_FOSCM_X6_CLK = 0x01;

/* H-Bridge operation mode */
const uint8_t _DCMOTOR7_HBMODE_SMALL_MODE = 0x00;
const uint8_t _DCMOTOR7_HBMODE_LARGE_MODE = 0x01;

/* Motor */
const uint8_t _DCMOTOR7_MOTOR_A = 0x01;
const uint8_t _DCMOTOR7_MOTOR_B = 0x02;

/* Device slave address */
const uint8_t _DCMOTOR7_SLAVE_ADDRESS_0_0 = 0x70;
const uint8_t _DCMOTOR7_SLAVE_ADDRESS_0_1 = 0x71;
const uint8_t _DCMOTOR7_SLAVE_ADDRESS_1_0 = 0x72;
const uint8_t _DCMOTOR7_SLAVE_ADDRESS_1_1 = 0x73;

/* Configuration */
const uint8_t _DCMOTOR7_ENABLE_ALL_OUTPUT_PORT  = 0x00;
const uint8_t _DCMOTOR7_DISABLE_ALL_OUTPUT_PORT = 0xFF;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __DCMOTOR7_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __DCMOTOR7_DRV_SPI__

void dcmotor7_spiDriverInit(T_DCMOTOR7_P gpioObj, T_DCMOTOR7_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __DCMOTOR7_DRV_I2C__

void dcmotor7_i2cDriverInit(T_DCMOTOR7_P gpioObj, T_DCMOTOR7_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __DCMOTOR7_DRV_UART__

void dcmotor7_uartDriverInit(T_DCMOTOR7_P gpioObj, T_DCMOTOR7_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void dcmotor7_writeCommand(uint8_t cmd, uint8_t _data)
{
    uint8_t writeData[ 2 ];
    
    writeData[ 0 ] = cmd;
    writeData[ 1 ] = _data;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeData, 2, END_MODE_STOP);
}

uint8_t dcmotor7_readCommand(uint8_t cmd)
{
    uint8_t writeData[ 1 ];
    uint8_t readData[ 1 ];
    
    writeData[ 0 ] = cmd;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeData, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readData, 1, END_MODE_STOP);
    
    return readData[0];
}

void dcmotor7_setPort(uint8_t port, uint8_t value)
{
    if(value == 1)
    {
        _portData = _portData | port;
    }
    else
    {
       _portData = _portData & (~port);
    }
    
    dcmotor7_writeCommand(_DCMOTOR7_CMD_OUTPUT_PORT, _portData);
}

void dcmotor7_setMotor(uint8_t motor, uint8_t in1, uint8_t in2)
{
    if(motor == _DCMOTOR7_MOTOR_A)
    {
        dcmotor7_setPort(_DCMOTOR7_PORT_4, in1);
        dcmotor7_setPort(_DCMOTOR7_PORT_3, in2);
        hal_gpio_rstSet(1);
    }
    else
    {
        dcmotor7_setPort(_DCMOTOR7_PORT_2, in1);
        dcmotor7_setPort(_DCMOTOR7_PORT_1, in2);
        hal_gpio_pwmSet(1);
    }
}

void dcmotor7_setTBLKAB(uint8_t tBLK)
{
    dcmotor7_setPort(_DCMOTOR7_PORT_0, tBLK);
}

void dcmotor7_setHBMode(uint8_t mode)
{
    dcmotor7_setPort(_DCMOTOR7_PORT_5, mode);
}

void dcmotor7_motorStop(uint8_t motor)
{
    if(motor == _DCMOTOR7_MOTOR_A)
    {
        dcmotor7_setPort(_DCMOTOR7_PORT_4, 0);
        dcmotor7_setPort(_DCMOTOR7_PORT_3, 0);
        hal_gpio_rstSet(1);
    }
    else
    {
        dcmotor7_setPort(_DCMOTOR7_PORT_2, 0);
        dcmotor7_setPort(_DCMOTOR7_PORT_1, 0);
        hal_gpio_pwmSet(1);
    }
}

void dcmotor7_goToStandByMode(uint8_t motor)
{
    if(motor == _DCMOTOR7_MOTOR_A)
    {
        dcmotor7_setPort(_DCMOTOR7_PORT_4, 0);
        dcmotor7_setPort(_DCMOTOR7_PORT_3, 0);
        hal_gpio_rstSet(0);
    }
    else
    {
        dcmotor7_setPort(_DCMOTOR7_PORT_2, 0);
        dcmotor7_setPort(_DCMOTOR7_PORT_1, 0);
        hal_gpio_pwmSet(0);
    }
}

void dcmotor7_setPWM_motorA(uint8_t state)
{
    hal_gpio_rstSet( state );
}

void dcmotor7_setPWM_motorB(uint8_t state)
{
    hal_gpio_pwmSet( state );
}

/* -------------------------------------------------------------------------- */
/*
  __dcmotor7_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */