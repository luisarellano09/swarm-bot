/**
 * @file Modes.h
 * @author Luis Arellano (luis.arellano09@gmail.com)
 * @brief Modes of the robot
 * 
 */

#ifndef MODES_H
#define MODES_H


/*******************************************************************************************************************************************
 *  												INCLUDES
 *******************************************************************************************************************************************/
#include <Arduino.h>
#include <ArduinoLog.h>
#include "ModesConfig.h"
#include "../../../Definition/Local/GlobalVar.h"


/*******************************************************************************************************************************************
 *  												DEFINITION FUNCTIONS
 *******************************************************************************************************************************************/

void InitModes()
{
    SetModeInit();
}


//=====================================================================================================

void SetModeInit()
{
    vTaskSuspend(TaskOTAHandle);
    vTaskSuspend(TaskGetValueCLIHandle);
    vTaskSuspend(TaskMotionControlHandle);
    vTaskSuspend(TaskDatalogHandle);
    vTaskResume(TaskOdometryHandle);
    vTaskResume(TaskCLIHandle);
    vTaskResume(TaskNodeESP32Handle);
    vTaskResume(TaskRegistersUpdateRTHandle);
    vTaskResume(TaskMotionControlHandle);
    manager->m_motionControl->Stop();
}


//=====================================================================================================

void SetModeProgram()
{
    vTaskSuspend(TaskNodeESP32Handle);
    vTaskSuspend(TaskRegistersUpdateRTHandle);
    vTaskSuspend(TaskDatalogHandle);
    vTaskSuspend(TaskOdometryHandle);
    manager->m_motionControl->Stop();
    vTaskSuspend(TaskMotionControlHandle);
    manager->m_motor01->Stop();
    manager->m_motor02->Stop();
    manager->m_motor03->Stop();
    manager->m_motor04->Stop();    
    manager->m_wifiManager->Connect();
    vTaskResume(TaskOTAHandle);
}


#endif // MODES_H