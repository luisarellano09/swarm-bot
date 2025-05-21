/**
 * @file ServoController.cpp
 * @author Luis Arellano - luis.arellano09@gmail.com
 * @brief ServoController Class
 * 
 */

/*******************************************************************************************************************************************
 *                                                 INCLUDE
 * *****************************************************************************************************************************************/
#include "ServoController.h"
#include <ArduinoLog.h>


/*******************************************************************************************************************************************
 *                                                 CONSTRUCTOR
 * *****************************************************************************************************************************************/

ServoController::ServoController(HardwareSerial* serial, uint32_t baud, uint8_t RX, uint8_t TX){
    // Create Semaphore
    semaphoreMutex = xSemaphoreCreateMutex();
    
    // Config Pins
    pinMode(RX, PULLUP);
    pinMode(TX, PULLUP);

    // Set serial port
    this->m_Serial = serial;
    this->m_Serial->begin(baud, SERIAL_8N1, RX, TX);
    Log.traceln("[ServoController::ServoController] Serial port initialized");

    // Clear buffer
    if (this->CleanBuffer() != RC_e::SUCCESS){
        Log.errorln("[ServoController::ServoController] Error in CleanBuffer()");
    }
}


//=====================================================================================================

ServoController::~ServoController(){}


/*******************************************************************************************************************************************
 *                                                 PUBLIC METHODS
 * *****************************************************************************************************************************************/

RC_e ServoController::AddRequest(uint8_t channel, double position, uint16_t speed){
    // Result code
    RC_e retCode = RC_e::SUCCESS;

    // Block semaphore
    xSemaphoreTake(semaphoreMutex, 10);

    // Check if max index is reached
    if (this->m_ServoRequestBufferIndex >= SERVO_CONTROLLER_REQUEST_SIZE){
        Log.fatalln("[ServoController::AddRequest] m_ServoRequestBufferIndex MAX_SERVO_REQUEST_INDEX");
        retCode = RC_e::ERROR_MAX_SERVO_REQUEST_INDEX;
    }

    // Increase index
    this->m_ServoRequestBufferIndex++;

    // Add request
    this->m_ServoRequestBuffer[this->m_ServoRequestBufferIndex].channel = channel;
    this->m_ServoRequestBuffer[this->m_ServoRequestBufferIndex].position = position;
    this->m_ServoRequestBuffer[this->m_ServoRequestBufferIndex].speed = speed;

    // Unblock semaphore
    xSemaphoreGive(semaphoreMutex);

    return retCode;
}


//=====================================================================================================

RC_e ServoController::SendNextRequest(){
    // Result code
    RC_e retCode = RC_e::SUCCESS;

    // Check if the pointer is null
    if (this->m_Serial == NULL){
        Log.errorln("[ServoController::SendNextRequest] m_Serial ERROR_NULL_POINTER");
        return RC_e::ERROR_NULL_POINTER;
    }

    // Block semaphore
    xSemaphoreTake(semaphoreMutex, 10);

    // Check if index is negative
    if (this->m_ServoRequestBufferIndex < 0){
        this->m_ServoRequestBufferIndex = -1;
        xSemaphoreGive(semaphoreMutex);
        return RC_e::SUCCESS;
    }

    // Assign values from request
    uint8_t channel = this->m_ServoRequestBuffer[0].channel;
    double position = this->m_ServoRequestBuffer[0].position;
    uint16_t speed = this->m_ServoRequestBuffer[0].speed;

    // Move all requests one position to the left
    for (int i=1; i<=this->m_ServoRequestBufferIndex; i++){
        this->m_ServoRequestBuffer[i-1].channel = this->m_ServoRequestBuffer[i].channel;
        this->m_ServoRequestBuffer[i-1].position = this->m_ServoRequestBuffer[i].position;
        this->m_ServoRequestBuffer[i-1].speed = this->m_ServoRequestBuffer[i].speed;
    }

    // Clean last request
    this->m_ServoRequestBuffer[this->m_ServoRequestBufferIndex].channel = -1;
    this->m_ServoRequestBuffer[this->m_ServoRequestBufferIndex].position = -1;
    this->m_ServoRequestBuffer[this->m_ServoRequestBufferIndex].speed = -1;

    // Decrease index
    this->m_ServoRequestBufferIndex--;

    // Scale position %
    position = position * 20.0 + 500.0;

    // Send request Serial2.println("#1P1500T100D0");
    this->m_Serial->print("#");
    this->m_Serial->print(channel);
    this->m_Serial->print("P");
    this->m_Serial->print((uint16_t)position);
    this->m_Serial->print("T");
    this->m_Serial->print(speed);
    this->m_Serial->print("D0");
    this->m_Serial->println();

    // Unblock semaphore
    xSemaphoreGive(semaphoreMutex);

    return retCode;
}


//=====================================================================================================

RC_e ServoController::CleanBuffer(){
    // Result code
    RC_e retCode = RC_e::SUCCESS;

    // Block semaphore
    xSemaphoreTake(semaphoreMutex, 10);

    // Clean buffer
    for (int i=0; i<SERVO_CONTROLLER_REQUEST_SIZE; i++){
        this->m_ServoRequestBuffer[i].channel = -1;
        this->m_ServoRequestBuffer[i].position = -1;
        this->m_ServoRequestBuffer[i].speed = -1;
    }

    // Init index
    this->m_ServoRequestBufferIndex = -1;

    // Unblock semaphore
    xSemaphoreGive(semaphoreMutex);

    return retCode;
}