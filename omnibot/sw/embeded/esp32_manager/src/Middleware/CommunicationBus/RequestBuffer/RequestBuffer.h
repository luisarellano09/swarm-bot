/**
 * @file RequestBuffer.h
 * @author Luis Arellano (luis.arellano09@gmail.com)
 * @brief Class to describe the Buffer of requests
 * 
 */

#ifndef REQUESTBUFFER_H
#define REQUESTBUFFER_H

/*******************************************************************************************************************************************
 *  												INCLUDE
 *******************************************************************************************************************************************/
#include "../../../Definition/Global/RC.h"
#include "../../../Definition/Global/Devices.h"
#include "../../../Definition/Global/RegisterTableDef.h"
#include "../../../Definition/Global/GlobalConfig.h"
#include "../Request/RequestConfig.h"
#include "../Request/Request.h"


/*******************************************************************************************************************************************
 *  												CLASS
 *******************************************************************************************************************************************/

/**
 * @brief Class to describe the Buffer of requests
 * 
 */
class RequestBuffer {
public:  

    /**
     * @brief Constructor
     * 
     */
    RequestBuffer();

    /**
     * @brief Destructor
     * 
     */
    ~RequestBuffer();

    /**
     * @brief Function to add request to the buffer
     * 
     * @param nodeId Node ID
     * @param reqType Request type
     * @param regID Register ID
     * @param data Data Value
     * @return RC_e Result code
     */
    RC_e AddRequest(DEVICE_e nodeId, COM_REQUEST_TYPE_e reqType, COM_REQUEST_REG_ID_e regID, uint32_t data);  

    /**
     * @brief Function to add request to the buffer
     * 
     * @param request Pointer of request
     * @return RC_e Result code
     */
    RC_e AddRequest(Request* request);  

    /**
     * @brief Function to consume request from the buffer
     * 
     * @param request Pointer of request
     * @return RC_e Result code
     */
    RC_e ConsumeRequest(Request* request);  

    /**
     * @brief Function to clean Buffer of requests
     * 
     * @return RC_e 
     */
    RC_e CleanBuffer();  

    /**
     * @brief Function to print Buffer of requests
     * 
     * @return RC_e 
     */
    RC_e PrintBuffer();  


private:

    Request m_RequestsArray[REQUEST_BUFFER_SIZE];       /**@brief Array of requests. */
    int16_t m_RequestsArrayIndex;                       /**@brief Index of array of requests. */
    SemaphoreHandle_t semaphoreMutex;                   /**@brief Semaphore to Mutex */
    
};

#endif // REQUESTBUFFER_H