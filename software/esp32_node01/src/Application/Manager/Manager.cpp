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

    // Motors
    this->m_motor01 = new Motor(PWMChannel_e::PWM1, MOTOR_01_PWM_GPIO, MOTOR_PWM_FREQUENCY, MOTOR_PWM_RESOLUTION, MOTOR_01_OFFSET, MOTOR_01_DIR_GPIO);
    this->m_motor02 = new Motor(PWMChannel_e::PWM2, MOTOR_02_PWM_GPIO, MOTOR_PWM_FREQUENCY, MOTOR_PWM_RESOLUTION, MOTOR_02_OFFSET, MOTOR_02_DIR_GPIO);
    this->m_motor03 = new Motor(PWMChannel_e::PWM3, MOTOR_03_PWM_GPIO, MOTOR_PWM_FREQUENCY, MOTOR_PWM_RESOLUTION, MOTOR_03_OFFSET, MOTOR_03_DIR_GPIO);
    this->m_motor04 = new Motor(PWMChannel_e::PWM4, MOTOR_04_PWM_GPIO, MOTOR_PWM_FREQUENCY, MOTOR_PWM_RESOLUTION, MOTOR_04_OFFSET, MOTOR_04_DIR_GPIO);
    Log.traceln("[Manager::Manager] Motors instanced");

    // Encoders
    this->m_encoder01 = new Encoder(1, ENCODER_01_CHANNEL_A_GPIO, ENCODER_01_CHANNEL_B_GPIO);
    this->m_encoder02 = new Encoder(2, ENCODER_02_CHANNEL_A_GPIO, ENCODER_02_CHANNEL_B_GPIO);
    this->m_encoder03 = new Encoder(3, ENCODER_03_CHANNEL_A_GPIO, ENCODER_03_CHANNEL_B_GPIO);
    this->m_encoder04 = new Encoder(4, ENCODER_04_CHANNEL_A_GPIO, ENCODER_04_CHANNEL_B_GPIO);
    Log.traceln("[Manager::Manager] Encoders instanced");

    //Odometry
    this->m_odometry = new Odometry(this->m_encoder01, this->m_encoder02, ODOMETRY_WHEEL_RADIO, ODOMETRY_DISTANCE_WHEELS, ODOMETRY_TICKS_REVOLUTION);
    Log.traceln("[Manager::Manager] Odometry instanced");

    // Motion Control
    this->m_motionControl = new MotionControl(this->m_odometry, this->m_motor01, this->m_motor02);
    Log.traceln("[Manager::Manager] Motion Control instanced");

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

