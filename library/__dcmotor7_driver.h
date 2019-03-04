/*
    __dcmotor7_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __dcmotor7_driver.h
@brief    DCMOTOR7 Driver
@mainpage DCMOTOR7 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   DCMOTOR7
@brief      DCMOTOR7 Click Driver
@{

| Global Library Prefix | **DCMOTOR7** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **okt 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _DCMOTOR7_H_
#define _DCMOTOR7_H_

/** 
 * @macro T_DCMOTOR7_P
 * @brief Driver Abstract type 
 */
#define T_DCMOTOR7_P    const uint8_t*

/** @defgroup DCMOTOR7_COMPILE Compilation Config */              /** @{ */

//  #define   __DCMOTOR7_DRV_SPI__                            /**<     @macro __DCMOTOR7_DRV_SPI__  @brief SPI driver selector */
   #define   __DCMOTOR7_DRV_I2C__                            /**<     @macro __DCMOTOR7_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __DCMOTOR7_DRV_UART__                           /**<     @macro __DCMOTOR7_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup DCMOTOR7_VAR Variables */                           /** @{ */

/* Command */
extern const uint8_t _DCMOTOR7_CMD_INPUT_PORT         ; // def xxxx xxxx
extern const uint8_t _DCMOTOR7_CMD_OUTPUT_PORT        ; // def 1111 1111
extern const uint8_t _DCMOTOR7_CMD_POLARITY_INVERSION ; // def 0000 0000
extern const uint8_t _DCMOTOR7_CMD_CONFIGURATION      ; // def 1111 1111

/* PORT */
extern const uint8_t _DCMOTOR7_PORT_0 ;
extern const uint8_t _DCMOTOR7_PORT_1 ;
extern const uint8_t _DCMOTOR7_PORT_2 ;
extern const uint8_t _DCMOTOR7_PORT_3 ;
extern const uint8_t _DCMOTOR7_PORT_4 ;
extern const uint8_t _DCMOTOR7_PORT_5 ;
extern const uint8_t _DCMOTOR7_PORT_6 ;
extern const uint8_t _DCMOTOR7_PORT_7 ;

/* TBLK noise rejection time */
extern const uint8_t _DCMOTOR7_TBLK_FOSCM_X4_CLK ;
extern const uint8_t _DCMOTOR7_TBLK_FOSCM_X6_CLK ;

/* H-Bridge operation mode */
extern const uint8_t _DCMOTOR7_HBMODE_SMALL_MODE;
extern const uint8_t _DCMOTOR7_HBMODE_LARGE_MODE;

/* Motor */
extern const uint8_t _DCMOTOR7_MOTOR_A ;
extern const uint8_t _DCMOTOR7_MOTOR_B ;

/* Device slave address */
extern const uint8_t _DCMOTOR7_SLAVE_ADDRESS_0_0;
extern const uint8_t _DCMOTOR7_SLAVE_ADDRESS_0_1;
extern const uint8_t _DCMOTOR7_SLAVE_ADDRESS_1_0;
extern const uint8_t _DCMOTOR7_SLAVE_ADDRESS_1_1;

/* Configuration */
extern const uint8_t _DCMOTOR7_ENABLE_ALL_OUTPUT_PORT;
extern const uint8_t _DCMOTOR7_DISABLE_ALL_OUTPUT_PORT;

                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup DCMOTOR7_INIT Driver Initialization */              /** @{ */

#ifdef   __DCMOTOR7_DRV_SPI__
void dcmotor7_spiDriverInit(T_DCMOTOR7_P gpioObj, T_DCMOTOR7_P spiObj);
#endif
#ifdef   __DCMOTOR7_DRV_I2C__
void dcmotor7_i2cDriverInit(T_DCMOTOR7_P gpioObj, T_DCMOTOR7_P i2cObj, uint8_t slave);
#endif
#ifdef   __DCMOTOR7_DRV_UART__
void dcmotor7_uartDriverInit(T_DCMOTOR7_P gpioObj, T_DCMOTOR7_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void dcmotor7_gpioDriverInit(T_DCMOTOR7_P gpioObj);
                                                                       /** @} */
/** @defgroup DCMOTOR7_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for write one byte in register
 *
 * @param[in] cmd    Command in which the data will be written
 * @param[in] _data  Data which be written in the register
 */
void dcmotor7_writeCommand(uint8_t cmd, uint8_t _data);

/**
 * @brief Functions for read byte from register
 *
 * @param[in] cmd    Command register which will be read
 * @retval one byte data which is read from the register
 */
uint8_t dcmotor7_readCommand(uint8_t cmd);

/**
 * @brief Functions for set port
 *
 * @param[in] port    Port to be set up
 * @param[in] value   Value to which the selected port is being set
 */
void dcmotor7_setPort(uint8_t port, uint8_t value);

/**
 * @brief Functions for set Motor
 *
 * @param[in] motor   Motor (A or B)
 * @param[in] in1     Motor Ach or Bch IN1 signal
 * @param[in] in2     Motor Ach or Bch IN2 signal
 */
void dcmotor7_setMotor(uint8_t motor, uint8_t in1, uint8_t in2);

/**
 * @brief Functions for set Motor Ach and Bch Digital tBLK
 *
 * @param[in] tBLK   TBLK noise rejection time (Digital tBLK = fOSCM × 4 clk or fOSCM × 6 clk)
 */
void dcmotor7_setTBLKAB(uint8_t tBLK);

/**
 * @brief Functions for set H-Bridge operation mode
 *
 * @param[in] mode   Mode (Small mode or Large mode)
 */
void dcmotor7_setHBMode(uint8_t mode);

/**
 * @brief Motor stop function
 *
 * @param[in] motor   Motor (A or B)
 */
void dcmotor7_motorStop(uint8_t motor);

/**
 * @brief Function for setting the motor in stand mode
 *
 * @param[in] motor   Motor (A or B)
 */
void dcmotor7_goToStandByMode(uint8_t motor);

/**
 * @brief Function for set PWM value for motor A
 *
 * @param[in] state   PWM state
 */
void dcmotor7_setPWM_motorA(uint8_t state);

/**
 * @brief Function for set PWM value for motor B
 *
 * @param[in] state   PWM state
 */
void dcmotor7_setPWM_motorB(uint8_t state);






                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_DCMOTOR7_STM.c
    @example Click_DCMOTOR7_TIVA.c
    @example Click_DCMOTOR7_CEC.c
    @example Click_DCMOTOR7_KINETIS.c
    @example Click_DCMOTOR7_MSP.c
    @example Click_DCMOTOR7_PIC.c
    @example Click_DCMOTOR7_PIC32.c
    @example Click_DCMOTOR7_DSPIC.c
    @example Click_DCMOTOR7_AVR.c
    @example Click_DCMOTOR7_FT90x.c
    @example Click_DCMOTOR7_STM.mbas
    @example Click_DCMOTOR7_TIVA.mbas
    @example Click_DCMOTOR7_CEC.mbas
    @example Click_DCMOTOR7_KINETIS.mbas
    @example Click_DCMOTOR7_MSP.mbas
    @example Click_DCMOTOR7_PIC.mbas
    @example Click_DCMOTOR7_PIC32.mbas
    @example Click_DCMOTOR7_DSPIC.mbas
    @example Click_DCMOTOR7_AVR.mbas
    @example Click_DCMOTOR7_FT90x.mbas
    @example Click_DCMOTOR7_STM.mpas
    @example Click_DCMOTOR7_TIVA.mpas
    @example Click_DCMOTOR7_CEC.mpas
    @example Click_DCMOTOR7_KINETIS.mpas
    @example Click_DCMOTOR7_MSP.mpas
    @example Click_DCMOTOR7_PIC.mpas
    @example Click_DCMOTOR7_PIC32.mpas
    @example Click_DCMOTOR7_DSPIC.mpas
    @example Click_DCMOTOR7_AVR.mpas
    @example Click_DCMOTOR7_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __dcmotor7_driver.h

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