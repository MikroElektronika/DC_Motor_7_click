#line 1 "D:/Clicks_git/D/DC_motor_7_click/SW/example/c/ARM/STM/Click_DCMOTOR7_STM.c"
#line 1 "d:/clicks_git/d/dc_motor_7_click/sw/example/c/arm/stm/click_dcmotor7_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/d/dc_motor_7_click/sw/example/c/arm/stm/click_dcmotor7_config.h"
#line 1 "d:/clicks_git/d/dc_motor_7_click/sw/example/c/arm/stm/click_dcmotor7_types.h"
#line 19 "d:/clicks_git/d/dc_motor_7_click/sw/example/c/arm/stm/click_dcmotor7_config.h"
const uint32_t _DCMOTOR7_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "d:/clicks_git/d/dc_motor_7_click/sw/library/__dcmotor7_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 58 "d:/clicks_git/d/dc_motor_7_click/sw/library/__dcmotor7_driver.h"
extern const uint8_t _DCMOTOR7_CMD_INPUT_PORT ;
extern const uint8_t _DCMOTOR7_CMD_OUTPUT_PORT ;
extern const uint8_t _DCMOTOR7_CMD_POLARITY_INVERSION ;
extern const uint8_t _DCMOTOR7_CMD_CONFIGURATION ;


extern const uint8_t _DCMOTOR7_PORT_0 ;
extern const uint8_t _DCMOTOR7_PORT_1 ;
extern const uint8_t _DCMOTOR7_PORT_2 ;
extern const uint8_t _DCMOTOR7_PORT_3 ;
extern const uint8_t _DCMOTOR7_PORT_4 ;
extern const uint8_t _DCMOTOR7_PORT_5 ;
extern const uint8_t _DCMOTOR7_PORT_6 ;
extern const uint8_t _DCMOTOR7_PORT_7 ;


extern const uint8_t _DCMOTOR7_TBLK_FOSCM_X4_CLK ;
extern const uint8_t _DCMOTOR7_TBLK_FOSCM_X6_CLK ;


extern const uint8_t _DCMOTOR7_HBMODE_SMALL_MODE;
extern const uint8_t _DCMOTOR7_HBMODE_LARGE_MODE;


extern const uint8_t _DCMOTOR7_MOTOR_A ;
extern const uint8_t _DCMOTOR7_MOTOR_B ;


extern const uint8_t _DCMOTOR7_SLAVE_ADDRESS_0_0;
extern const uint8_t _DCMOTOR7_SLAVE_ADDRESS_0_1;
extern const uint8_t _DCMOTOR7_SLAVE_ADDRESS_1_0;
extern const uint8_t _DCMOTOR7_SLAVE_ADDRESS_1_1;


extern const uint8_t _DCMOTOR7_ENABLE_ALL_OUTPUT_PORT;
extern const uint8_t _DCMOTOR7_DISABLE_ALL_OUTPUT_PORT;
#line 106 "d:/clicks_git/d/dc_motor_7_click/sw/library/__dcmotor7_driver.h"
void dcmotor7_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 113 "d:/clicks_git/d/dc_motor_7_click/sw/library/__dcmotor7_driver.h"
void dcmotor7_gpioDriverInit( const uint8_t*  gpioObj);
#line 123 "d:/clicks_git/d/dc_motor_7_click/sw/library/__dcmotor7_driver.h"
void dcmotor7_writeCommand(uint8_t cmd, uint8_t _data);
#line 131 "d:/clicks_git/d/dc_motor_7_click/sw/library/__dcmotor7_driver.h"
uint8_t dcmotor7_readCommand(uint8_t cmd);
#line 139 "d:/clicks_git/d/dc_motor_7_click/sw/library/__dcmotor7_driver.h"
void dcmotor7_setPort(uint8_t port, uint8_t value);
#line 148 "d:/clicks_git/d/dc_motor_7_click/sw/library/__dcmotor7_driver.h"
void dcmotor7_setMotor(uint8_t motor, uint8_t in1, uint8_t in2);
#line 155 "d:/clicks_git/d/dc_motor_7_click/sw/library/__dcmotor7_driver.h"
void dcmotor7_setTBLKAB(uint8_t tBLK);
#line 162 "d:/clicks_git/d/dc_motor_7_click/sw/library/__dcmotor7_driver.h"
void dcmotor7_setHBMode(uint8_t mode);
#line 169 "d:/clicks_git/d/dc_motor_7_click/sw/library/__dcmotor7_driver.h"
void dcmotor7_motorStop(uint8_t motor);
#line 176 "d:/clicks_git/d/dc_motor_7_click/sw/library/__dcmotor7_driver.h"
void dcmotor7_goToStandByMode(uint8_t motor);
#line 183 "d:/clicks_git/d/dc_motor_7_click/sw/library/__dcmotor7_driver.h"
void dcmotor7_setPWM_motorA(uint8_t state);
#line 190 "d:/clicks_git/d/dc_motor_7_click/sw/library/__dcmotor7_driver.h"
void dcmotor7_setPWM_motorB(uint8_t state);
#line 35 "D:/Clicks_git/D/DC_motor_7_click/SW/example/c/ARM/STM/Click_DCMOTOR7_STM.c"
void systemInit()
{
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
 mikrobus_i2cInit( _MIKROBUS1, &_DCMOTOR7_I2C_CFG[0] );
 Delay_ms( 100 );
}

void applicationInit()
{
 dcmotor7_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, _DCMOTOR7_SLAVE_ADDRESS_1_1 );

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
