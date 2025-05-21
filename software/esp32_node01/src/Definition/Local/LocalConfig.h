/**
 * @file LocalConfig.h
 * @author Luis Arellano (luis.arellano09@gmail.com)
 * @brief Local Config
 * 
 */

#ifndef LOCALCONFIG_H
#define LOCALCONFIG_H

/*******************************************************************************************************************************************
 *  												INCLUDE
 *******************************************************************************************************************************************/
#include <Arduino.h>
#include "../Global/Devices.h"


/*******************************************************************************************************************************************
 *  												DEFINE
 *******************************************************************************************************************************************/

// ========================== NODE_ID =======================
/**
 * @brief Node ID
 * 
 */
#define NODE_ID DEVICE_e::ESP32_NODE01


// ========================== HOSTNAME =======================
/**
 * @brief Hostname of the ESP32
 * 
 */
#define ESP32_HOSTNAME "OMNI_ESP32_NODE01"


// ========================== NODE ESP32s =====================
/**
 * @brief NODE_ESP32s_BAUDRATE
 * 
 */
#define NODE_ESP32s_BAUDRATE 460800

/**
 * @brief NODE_ESP32s_TX
 * 
 */
#define NODE_ESP32s_TX   19

/**
 * @brief NODE_ESP32s_RX
 * 
 */
#define NODE_ESP32s_RX   21


// ========================== MOTORS =====================
/**
 * @brief GPIO to control the direction of the Motor 01
 * 
 */
#define MOTOR_01_DIR_GPIO 15

/**
 * @brief PWM GPIO of the Motor 01
 * 
 */
#define MOTOR_01_PWM_GPIO 2

/**
 * @brief GPIO to control the direction of the Motor 02
 * 
 */
#define MOTOR_02_DIR_GPIO 4

/**
 * @brief PWM GPIO of the Motor 02
 * 
 */
#define MOTOR_02_PWM_GPIO 5

/**
 * @brief GPIO to control the direction of the Motor 03
 * 
 */
#define MOTOR_03_DIR_GPIO 18

/**
 * @brief PWM GPIO of the Motor 03
 * 
 */
#define MOTOR_03_PWM_GPIO 12

/**
 * @brief GPIO to control the direction of the Motor 04
 * 
 */
#define MOTOR_04_DIR_GPIO 27

/**
 * @brief PWM GPIO of the Motor 04
 * 
 */
#define MOTOR_04_PWM_GPIO 26

/**
 * @brief Motor PWM Frequency
 * 
 */
#define MOTOR_PWM_FREQUENCY 20000

/**
 * @brief Motor PWM Resolution
 * 
 */
#define MOTOR_PWM_RESOLUTION 10

/**
 * @brief Motor 01 Offset
 * 
 */
#define MOTOR_01_OFFSET (double) 0.0

/**
 * @brief Motor 02 Offset
 * 
 */
#define MOTOR_02_OFFSET (double) 3.0

/**
 * @brief Motor 03 Offset
 * 
 */
#define MOTOR_03_OFFSET (double) 0.0

/**
 * @brief Motor 04 Offset
 * 
 */
#define MOTOR_04_OFFSET (double) 0.0


// ========================== ENCODERS =====================
/**
 * @brief GPIO of the Channel A of Encoder 01
 * 
 */
#define ENCODER_01_CHANNEL_A_GPIO 34

/**
 * @brief GPIO of the Channel B of Encoder 01
 * 
 */
#define ENCODER_01_CHANNEL_B_GPIO 35

/**
 * @brief GPIO of the Channel A of Encoder 02
 * 
 */
#define ENCODER_02_CHANNEL_A_GPIO 23

/**
 * @brief GPIO of the Channel B of Encoder 02
 * 
 */
#define ENCODER_02_CHANNEL_B_GPIO 22

/**
 * @brief GPIO of the Channel A of Encoder 03
 * 
 */
#define ENCODER_03_CHANNEL_A_GPIO 32

/**
 * @brief GPIO of the Channel B of Encoder 03
 * 
 */
#define ENCODER_03_CHANNEL_B_GPIO 13

/**
 * @brief GPIO of the Channel A of Encoder 04
 * 
 */
#define ENCODER_04_CHANNEL_A_GPIO 25

/**
 * @brief GPIO of the Channel B of Encoder 04
 * 
 */
#define ENCODER_04_CHANNEL_B_GPIO 14


// ========================== ODOMETRY =====================
/**
 * @brief ODOMETRY__WHEEL_RADIO
 * 
 */
#define ODOMETRY_WHEEL_RADIO (double)0.035 

/**
 * @brief ODOMETRY_DISTANCE_WHEELS
 * 
 */
#define ODOMETRY_DISTANCE_WHEELS (double)0.231

/**
 * @brief ODOMETRY_TICKS_REVOLUTION
 * 
 */
#define ODOMETRY_TICKS_REVOLUTION 960 

#endif /* LOCALCONFIG_H */