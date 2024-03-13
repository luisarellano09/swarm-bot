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
#define NODE_ID DEVICE_e::ESP32_NODE02


// ========================== HOSTNAME =======================
/**
 * @brief Hostname of the ESP32
 * 
 */
#define ESP32_HOSTNAME "OMNI_ESP32_NODE02"


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


// ========================== IMU =====================
/**
 * @brief IMU CS
 * 
 */
#define IMU_CS_GPIO 32

/**
 * @brief IMU WAK
 * 
 */
#define IMU_WAK_GPIO 18

/**
 * @brief IMU INT
 * 
 */
#define IMU_INT_GPIO 26

/**
 * @brief IMU RST
 * 
 */
#define IMU_RST_GPIO 27

/**
 * @brief IMU SPI PORT SPEED
 * 
 */
#define IMU_SPI_PORT_SPEED 3000000

/**
 * @brief IMU CLK
 * 
 */
#define IMU_CLK_GPIO 14

/**
 * @brief IMU MISO
 * 
 */
#define IMU_MISO_GPIO 25

/**
 * @brief IMU MOSI
 * 
 */
#define IMU_MOSI_GPIO 13

/**
 * @brief IMU PS0
 * 
 */
#define IMU_PS0_GPIO 18

/**
 * @brief IMU PS1
 * 
 */
#define IMU_PS1_GPIO 12


// ========================== TFT =====================

/**
 * @brief TFT LEDA
 * 
 */
#define TFT_BL_GPIO 4

/**
 * @brief Rotation
 * 
 */
#define TFT_ROTATION 0


// ========================== SERVO CONTROLLER =====================
/**
 * @brief SERVO CONTROLLER BAUDRATE
 * 
 */
#define SERVO_CONTROLLER_BAUDRATE 115200

/**
 * @brief SERVO CONTROLLER TX
 * 
 */
#define SERVO_CONTROLLER_TX 5

/**
 * @brief SERVO CONTROLLER RX
 * 
 */
#define SERVO_CONTROLLER_RX 34

/**
 * @brief SERVO CONTROLLER REQUEST SIZE
 * 
 */
#define SERVO_CONTROLLER_REQUEST_SIZE 50


#endif /* LOCALCONFIG_H */