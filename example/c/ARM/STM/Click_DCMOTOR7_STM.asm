_systemInit:
;Click_DCMOTOR7_STM.c,35 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_DCMOTOR7_STM.c,37 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #6
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_DCMOTOR7_STM.c,38 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_DCMOTOR7_STM.c,39 :: 		mikrobus_i2cInit( _MIKROBUS1, &_DCMOTOR7_I2C_CFG[0] );
MOVW	R0, #lo_addr(__DCMOTOR7_I2C_CFG+0)
MOVT	R0, #hi_addr(__DCMOTOR7_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_DCMOTOR7_STM.c,40 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_DCMOTOR7_STM.c,41 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_DCMOTOR7_STM.c,43 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_DCMOTOR7_STM.c,45 :: 		dcmotor7_i2cDriverInit( (T_DCMOTOR7_P)&_MIKROBUS1_GPIO, (T_DCMOTOR7_P)&_MIKROBUS1_I2C, _DCMOTOR7_SLAVE_ADDRESS_1_1 );
MOVS	R2, __DCMOTOR7_SLAVE_ADDRESS_1_1
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_dcmotor7_i2cDriverInit+0
;Click_DCMOTOR7_STM.c,47 :: 		dcmotor7_writeCommand(_DCMOTOR7_CMD_CONFIGURATION, _DCMOTOR7_ENABLE_ALL_OUTPUT_PORT);
MOVS	R1, __DCMOTOR7_ENABLE_ALL_OUTPUT_PORT
MOVS	R0, __DCMOTOR7_CMD_CONFIGURATION
BL	_dcmotor7_writeCommand+0
;Click_DCMOTOR7_STM.c,48 :: 		dcmotor7_setTBLKAB(_DCMOTOR7_TBLK_FOSCM_X6_CLK);
MOVS	R0, __DCMOTOR7_TBLK_FOSCM_X6_CLK
BL	_dcmotor7_setTBLKAB+0
;Click_DCMOTOR7_STM.c,49 :: 		dcmotor7_setHBMode(_DCMOTOR7_HBMODE_SMALL_MODE);
MOVS	R0, __DCMOTOR7_HBMODE_SMALL_MODE
BL	_dcmotor7_setHBMode+0
;Click_DCMOTOR7_STM.c,50 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_DCMOTOR7_STM.c,52 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_DCMOTOR7_STM.c,54 :: 		dcmotor7_setMotor(_DCMOTOR7_MOTOR_A, 0, 1);
MOVS	R2, #1
MOVS	R1, #0
MOVS	R0, __DCMOTOR7_MOTOR_A
BL	_dcmotor7_setMotor+0
;Click_DCMOTOR7_STM.c,55 :: 		dcmotor7_setMotor(_DCMOTOR7_MOTOR_B, 0, 1);
MOVS	R2, #1
MOVS	R1, #0
MOVS	R0, __DCMOTOR7_MOTOR_B
BL	_dcmotor7_setMotor+0
;Click_DCMOTOR7_STM.c,56 :: 		Delay_ms( 500 );
MOVW	R7, #36223
MOVT	R7, #91
NOP
NOP
L_applicationTask2:
SUBS	R7, R7, #1
BNE	L_applicationTask2
NOP
NOP
NOP
;Click_DCMOTOR7_STM.c,58 :: 		dcmotor7_motorStop(_DCMOTOR7_MOTOR_A);
MOVS	R0, __DCMOTOR7_MOTOR_A
BL	_dcmotor7_motorStop+0
;Click_DCMOTOR7_STM.c,59 :: 		dcmotor7_motorStop(_DCMOTOR7_MOTOR_B);
MOVS	R0, __DCMOTOR7_MOTOR_B
BL	_dcmotor7_motorStop+0
;Click_DCMOTOR7_STM.c,60 :: 		Delay_ms( 2000 );
MOVW	R7, #13823
MOVT	R7, #366
NOP
NOP
L_applicationTask4:
SUBS	R7, R7, #1
BNE	L_applicationTask4
NOP
NOP
NOP
;Click_DCMOTOR7_STM.c,62 :: 		dcmotor7_setMotor(_DCMOTOR7_MOTOR_A, 1, 0);
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, __DCMOTOR7_MOTOR_A
BL	_dcmotor7_setMotor+0
;Click_DCMOTOR7_STM.c,63 :: 		dcmotor7_setMotor(_DCMOTOR7_MOTOR_B, 1, 0);
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, __DCMOTOR7_MOTOR_B
BL	_dcmotor7_setMotor+0
;Click_DCMOTOR7_STM.c,64 :: 		Delay_ms( 500 );
MOVW	R7, #36223
MOVT	R7, #91
NOP
NOP
L_applicationTask6:
SUBS	R7, R7, #1
BNE	L_applicationTask6
NOP
NOP
NOP
;Click_DCMOTOR7_STM.c,66 :: 		dcmotor7_motorStop(_DCMOTOR7_MOTOR_A);
MOVS	R0, __DCMOTOR7_MOTOR_A
BL	_dcmotor7_motorStop+0
;Click_DCMOTOR7_STM.c,67 :: 		dcmotor7_motorStop(_DCMOTOR7_MOTOR_B);
MOVS	R0, __DCMOTOR7_MOTOR_B
BL	_dcmotor7_motorStop+0
;Click_DCMOTOR7_STM.c,68 :: 		Delay_ms( 2000 );
MOVW	R7, #13823
MOVT	R7, #366
NOP
NOP
L_applicationTask8:
SUBS	R7, R7, #1
BNE	L_applicationTask8
NOP
NOP
NOP
;Click_DCMOTOR7_STM.c,69 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_DCMOTOR7_STM.c,71 :: 		void main()
;Click_DCMOTOR7_STM.c,73 :: 		systemInit();
BL	_systemInit+0
;Click_DCMOTOR7_STM.c,74 :: 		applicationInit();
BL	_applicationInit+0
;Click_DCMOTOR7_STM.c,76 :: 		while (1)
L_main10:
;Click_DCMOTOR7_STM.c,78 :: 		applicationTask();
BL	_applicationTask+0
;Click_DCMOTOR7_STM.c,79 :: 		}
IT	AL
BAL	L_main10
;Click_DCMOTOR7_STM.c,80 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
