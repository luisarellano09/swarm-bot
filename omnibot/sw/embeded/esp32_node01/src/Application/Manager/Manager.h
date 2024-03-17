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
#include "../CommunicationBus/NodeEsp32/NodeEsp32.h"
#include "../../Middleware/Motor/Motor.h"
#include "../MotionControl/MotionControl.h"
#include "../../Middleware/Encoder/Encoder.h"
#include "../../Middleware/Odometry/Odometry.h"


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
    Motor* m_motor01 = NULL;                        /**@brief Instance for the motor 01. */
    Motor* m_motor02 = NULL;                        /**@brief Instance for the motor 02. */
    Motor* m_motor03 = NULL;                        /**@brief Instance for the motor 03. */
    Motor* m_motor04 = NULL;                        /**@brief Instance for the motor 04. */
    Encoder* m_encoder01 = NULL;                    /**@brief Instance for the encoder 01. */
    Encoder* m_encoder02 = NULL;                    /**@brief Instance for the encoder 02. */
    Encoder* m_encoder03 = NULL;                    /**@brief Instance for the encoder 03. */
    Encoder* m_encoder04 = NULL;                    /**@brief Instance for the encoder 04. */
    Odometry* m_odometry = NULL;                    /**@brief Instance for the odometry. */
    MotionControl* m_motionControl = NULL;          /**@brief Instance for the Motion Control. */

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