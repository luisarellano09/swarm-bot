/**
 * @file Manager.cpp
 * @author Luis Arellano - luis.arellano09@gmail.com
 * @brief Class to Manage the ESP32
 * 
 */

/*******************************************************************************************************************************************
 *  												INCLUDE
 *******************************************************************************************************************************************/
#include "Manager.h"
#include "../../Definition/Local/LocalConfig.h"
#include <ArduinoLog.h>


/*******************************************************************************************************************************************
 *  												CONSTRUCTOR
 *******************************************************************************************************************************************/

Manager::Manager(){

    // Wifi
    this->m_wifiManager = new WifiManager();
    Log.traceln("[Manager::Manager] WifiManager instanced");

    // Node - Communication Bus
    this->m_nodeESP32 = new NodeEsp32(&Serial1, NODE_ESP32s_BAUDRATE, NODE_ESP32s_RX, NODE_ESP32s_TX);
    Log.traceln("[Manager::Manager] NodeEsp32 instanced");

    // TFT
    this->m_TFT = new TFT(TFT_ROTATION, TFT_BL_GPIO);
    Log.traceln("[Manager::Manager] TFT instanced");

    // IMU
    this->m_IMU = new IMU(IMU_CS_GPIO, IMU_WAK_GPIO, IMU_INT_GPIO, IMU_RST_GPIO, IMU_SPI_PORT_SPEED, IMU_CLK_GPIO, IMU_MISO_GPIO, IMU_MOSI_GPIO, IMU_PS0_GPIO, IMU_PS1_GPIO);
    Log.traceln("[Manager::Manager] IMU instanced");

    // Servo Controller
    this->m_servoController = new ServoController(&Serial2, SERVO_CONTROLLER_BAUDRATE, SERVO_CONTROLLER_RX, SERVO_CONTROLLER_TX);
    Log.traceln("[Manager::Manager] ServoController instanced");

    // Start Node 
    this->m_nodeESP32->Start();
    this->m_nodeESP32->UpdateRegister(COM_REQUEST_REG_ID_e::MODE_NODE1_SYNC_DATA_RW, RegisterCommand_e::CMD_REQUESTED);
    Log.traceln("[Manager::Manager] NodeEsp32 started");
    
    Log.traceln("[Manager::Manager] Manager initialization finished");
}


//=====================================================================================================

Manager::~Manager(){}


/*******************************************************************************************************************************************
 *  												PUBLIC METHODS
 *******************************************************************************************************************************************/



/*******************************************************************************************************************************************
 *  												PRIVATE METHODS
 *******************************************************************************************************************************************/

