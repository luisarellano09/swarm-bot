/**
 * @file Manager.h
 * @author Luis Arellano - luis.arellano09@gmail.com
 * @brief Class to Manage the ESP32
 * 
 */

#ifndef MANAGER_H
#define MANAGER_H

/*******************************************************************************************************************************************
 *  												INCLUDE
 *******************************************************************************************************************************************/
#include "../../Definition/Global/RC.h"
#include "../../Middleware/WifiManager/WifiManager.h"
#include "../../Middleware/IMU/IMU.h"
#include "../CommunicationBus/NodeEsp32/NodeEsp32.h"
#include "../TFT/TFT.h"
#include "../../Middleware/ServoController/ServoController.h"

/*******************************************************************************************************************************************
 *  												CLASS
 *******************************************************************************************************************************************/

/**
 * @brief Class to Manage the ESP32
 * 
 */
class Manager {
public:  

    WifiManager* m_wifiManager = NULL;              /**@brief Instance for Wifimanager. */
    NodeEsp32* m_nodeESP32 = NULL;                  /**@brief Instance for the node ESP32. */
    IMU* m_IMU = NULL;                              /**@brief Instance for the IMU. */
    TFT* m_TFT = NULL;                              /**@brief Instance for the TFT. */
    ServoController* m_servoController = NULL;      /**@brief Instance for the ServoController. */
    
    /**
     * @brief Construct a new Manager object
     * 
     */
    Manager();

    /**
     * @brief Destroy the Manager object
     * 
     */
    ~Manager();
   
private:


};

#endif // MANAGER_H