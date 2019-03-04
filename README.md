![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# DCMOTOR7 Click

- **CIC Prefix**  : DCMOTOR7
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : okt 2018.

---

### Software Support

We provide a library for the DCMOTOR7 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2587/dc-motor-7-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**


The library initializes and defines the I2C bus driver and drivers that offer a choice for writing data in register and reads data form register.
The library includes function for sets Motor rotation and motor stop, Motor Ach and Bch Digital tBLK, H-Bridge operation mode and PWM value for motor A and motor B.
The user also has the function for go to stand by mode and function for set port.

Key functions :

- ``` void dcmotor7_setMotor(uint8_t motor, uint8_t in1, uint8_t in2) ``` - Functions for set Motor
- ``` void dcmotor7_setTBLKAB(uint8_t tBLK) ``` - Functions for set Motor Ach and Bch Digital tBLK
- ``` void dcmotor7_setHBMode(uint8_t mode) ``` - Functions for set H-Bridge operation mode

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes I2C module and sets RST pin and PWM pin as OUTPUT
- Application Initialization - Initialization driver init, enabled all output port, sets H-Bridge operation mode and Motor Digital tBLK
- Application Task - (code snippet) -  Set the motor A and the motor B to rotate clockwise and in the Counte clockwise direction, 
                                       and between the change of direction, the motor stops the motor.

- note
    VM input - 10 V (min) to 47 V (max)


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2587/dc-motor-7-click) page.

Other mikroE Libraries used in the example:

- I2C

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
