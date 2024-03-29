/**
 * @file NodeEsp32Handler.h
 * @author Luis Arellano (luis.arellano09@gmail.com)
 * @brief Handler of the Node
 * 
 */

#ifndef NODEESP32HANDLER_H
#define NODEESP32HANDLER_H

/*******************************************************************************************************************************************
 *  												INCLUDE
 *******************************************************************************************************************************************/
#include "../../../Middleware/CommunicationBus/Request/Request.h"
#include "../../System/Tasks/Tasks.h"
#include <ArduinoLog.h>


/*******************************************************************************************************************************************
 *  												DEFINITION FUNCTIONS
 *******************************************************************************************************************************************/

RC_e ExtNodeEsp32Handler(Request* request){
    
    // Result code
    RC_e retCode = RC_e::SUCCESS;

    // Check if the pointer is null
    if (request == NULL){
        Log.fatalln("[NodeEsp32Handler::ExtNodeEsp32Handler] request ERROR_NULL_POINTER");
        return RC_e::ERROR_NULL_POINTER;
    }

    Log.traceln("[NodeEsp32Handler::ExtNodeEsp32Handler] Request received: nodeId=%d, reqType=%d, regId=%d, data=%d, CRC=%d", request->nodeId, request->reqType, request->regId, request->data, request->CRC);

    // Handle requests
    switch(request->regId){

        case COM_REQUEST_REG_ID_e::STATUS_HEARTBEAT_ESP32_COUNTER_R: {
            manager->m_nodeESP32->TokenCounter(request->data, COM_REQUEST_REG_ID_e::STATUS_HEARTBEAT_ESP32_COUNTER_R);
            break;
        }

        case COM_REQUEST_REG_ID_e::MODE_MANAGER_RESTART_W: {
            Serial.println("Restarting...");
            ESP.restart();
            break;
        }

        case COM_REQUEST_REG_ID_e::MODE_MANAGER_PROGRAM_W: {
            Serial.println("Program Mode.....");
            StartMode(Modes_e::Mode_Program);
            Log.infoln("[NodeEsp32Handler::ExtNodeEsp32Handler] Mode Program started");
            break;
        }

        case COM_REQUEST_REG_ID_e::MODE_MANAGER_SYNC_DATA_RW: {
            // ToDo
            break;
        }

        case COM_REQUEST_REG_ID_e::MODE_LINUX_SYNC_DATA_RW: {
            // Todo
            break;
        }
       
    }

    return retCode;
}


#endif // NODEESP32HANDLER_H