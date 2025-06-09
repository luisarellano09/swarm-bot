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

void InitModes(){
    SetModeIdle();
}

//=====================================================================================================

void SetModeIdle()
{
    vTaskSuspend(TaskOTAHandle);
    vTaskSuspend(TaskGetValueCLIHandle);
    vTaskResume(TaskCLIHandle);
    vTaskResume(TaskNodeESP32Handle);
    vTaskResume(TaskNodeLinuxHandle);

    Log.infoln("[Modes::SetModeIdle] Mode set to Idle");
}


//=====================================================================================================

void SetModeProgram()
{
    vTaskSuspend(TaskNodeESP32Handle);
    vTaskSuspend(TaskNodeLinuxHandle);   
    manager->m_wifiManager->Connect();
    vTaskResume(TaskOTAHandle); 

    Log.infoln("[Modes::SetModeProgram] Mode set to Program");
}

#endif // MODES_H