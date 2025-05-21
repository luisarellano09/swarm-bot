/**
 * @file NodeHandler.h
 * @author Luis Arellano (luis.arellano09@gmail.com)
 * @brief Handler of the Node
 * 
 */

#ifndef NODEHANDLER_H
#define NODEHANDLER_H

/*******************************************************************************************************************************************
 *  												INCLUDE
 *******************************************************************************************************************************************/
#include "../../../Middleware/CommunicationBus/Request/Request.h"
#include "../../System/Tasks/Tasks.h"
#include <ArduinoLog.h>


/*******************************************************************************************************************************************
 *  												DEFINITION FUNCTIONS
 *******************************************************************************************************************************************/

RC_e ExtHandler(Request* request){
    
    // Result code
    RC_e retCode = RC_e::SUCCESS;

    // Check if the pointer is null
    if (request == NULL){
        Log.fatalln("[NodeHandler::ExtHandler] request ERROR_NULL_POINTER");
        return RC_e::ERROR_NULL_POINTER;
    }

    Log.traceln("[NodeHandler::ExtHandler] Request received: nodeId=%d, reqType=%d, regId=%d, data=%d, CRC=%d", request->nodeId, request->reqType, request->regId, request->data, request->CRC);

    switch(request->regId){

        case COM_REQUEST_REG_ID_e::STATUS_HEARTBEAT_ESP32_COUNTER_R: {
            manager->m_nodeESP32->TokenCounter(request->data, COM_REQUEST_REG_ID_e::STATUS_HEARTBEAT_ESP32_COUNTER_R);
            break;
        }
        
        case COM_REQUEST_REG_ID_e::MODE_NODE1_RESTART_W: {
            Serial.println("Restarting...");
            ESP.restart();
            break;
        }
        
        case COM_REQUEST_REG_ID_e::MODE_NODE1_PROGRAM_W: {
            Serial.println("Program Mode.....");
            StartMode(Modes_e::Mode_Program);
            Log.infoln("[NodeHandler::MODE_NODE1_PROGRAM_W] Mode Program started");
            break;
        }
        
        case COM_REQUEST_REG_ID_e::MODE_NODE1_SYNC_DATA_RW: {
            if ( (RegisterCommand_e)request->data == RegisterCommand_e::CMD_READY_TO_COMPLETE ) {
                manager->m_nodeESP32->UpdateRegister(COM_REQUEST_REG_ID_e::MODE_NODE1_SYNC_DATA_RW, RegisterCommand_e::CMD_COMPLETED);
            }
            break;
        }
    }

    return retCode;
}


//=====================================================================================================

RC_e UpdateRegistersRT(){
    // Result code
    RC_e retCode = RC_e::SUCCESS;

    if (manager->m_nodeESP32->GetError() == false) {

    }

    return retCode;
}


#endif // NODEHANDLER_H