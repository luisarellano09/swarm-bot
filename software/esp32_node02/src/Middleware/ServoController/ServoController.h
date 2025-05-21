/**
 * @file ServoController.h
 * @author Luis Arellano - luis.arellano09@gmail.com
 * @brief ServoController Class
 * 
 */

#ifndef SERVOCONTROLLER_H
#define SERVOCONTROLLER_H

/*******************************************************************************************************************************************
 *  												INCLUDE
 *******************************************************************************************************************************************/
#include <Arduino.h>
#include "../../Definition/Global/RC.h"
#include "../../Definition/Local/LocalConfig.h"


/*******************************************************************************************************************************************
 *  												STRUCTURE
 *******************************************************************************************************************************************/

struct ServoRequest
{
    uint8_t channel;    /**@brief Channel. */
    double position;    /**@brief Position. */
    uint16_t speed;     /**@brief Speed. */
};



/*******************************************************************************************************************************************
 *  												CLASS
 *******************************************************************************************************************************************/

/**
 * @brief ServoController Class
 * 
 */
class ServoController {
public:  

    /**
     * @brief Construct a new ServoController object
     * 
     * @param serial Pointer of serialport
     * @param baud Baud rate speed
     * @param RX RX GPIO
     * @param TX TX GPIO
     */
    ServoController(HardwareSerial* serial, uint32_t baud, uint8_t RX, uint8_t TX);

    /**
     * @brief Destroy object
     * 
     */
    ~ServoController();

    /**
     * @brief Function to add request to the buffer
     * 
     * @param channel Channel
     * @param position Position
     * @param speed Speed
     * @return RC_e Result code
     */
    RC_e AddRequest(uint8_t channel, double position, uint16_t speed);

    /**
     * @brief Function to send the next request
     * 
     * @return RC_e Result code
     */
    RC_e SendNextRequest();

    /**
     * @brief Funtion to clean Buffer of requests
     * 
     * @return RC_e Result code
     */
    RC_e CleanBuffer();

private:

    ServoRequest m_ServoRequestBuffer[SERVO_CONTROLLER_REQUEST_SIZE];   /**@brief Servo Request Buffer. */
    int16_t m_ServoRequestBufferIndex ;                                 /**@brief Servo Request Buffer Index. */
    SemaphoreHandle_t semaphoreMutex;                                   /**@brief Semaphore Mutex. */
    HardwareSerial* m_Serial;                                           /**@brief Serial Port. */
};

#endif // SERVOCONTROLLER_H


