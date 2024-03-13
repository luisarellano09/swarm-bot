/**
 * @file TasksConfig.h
 * @author Luis Arellano (luis.arellano09@gmail.com)
 * @brief Declarations of the Tasks class
 * 
 */

#ifndef TASKSCONFIG_H
#define TASKSCONFIG_H

/*******************************************************************************************************************************************
 *  												INCLUDES
 *******************************************************************************************************************************************/
#include <Arduino.h>
#include "soc/soc.h"


/*******************************************************************************************************************************************
 *  												DECLARATION VARIABLES
 *******************************************************************************************************************************************/

TaskHandle_t TaskCLIHandle;                     /**@brief Handle of Task CLI */
TaskHandle_t TaskGetValueCLIHandle;             /**@brief Handle of Task Get Value CLI */
TaskHandle_t TaskOTAHandle;                     /**@brief Handle of Task OTA */
TaskHandle_t TaskNodeESP32Handle;               /**@brief Handle of Task Node ESP32 */
TaskHandle_t TaskModesHandle;                   /**@brief Handle of Task Modes */
TaskHandle_t TaskIMUHandle;                     /**@brief Handle of Task IMU */
TaskHandle_t TaskRegistersUpdateRTHandle;       /**@brief Handle of Task Registers Update in Runtime */
TaskHandle_t TaskTFTHandle;                     /**@brief Handle of Task TFT */
TaskHandle_t TaskServoControllerHandle;         /**@brief Handle of Task Servo Controller */

TickType_t TimerTaskCLI = 500 / portTICK_PERIOD_MS;                     /**@brief Timer of Task CLI */
TickType_t TimerTaskOTA = 2000 / portTICK_PERIOD_MS;                    /**@brief Timer of Task OTA */
TickType_t TimerTaskNodeESP32 = 1 / portTICK_PERIOD_MS;                 /**@brief Timer of Task Node ESP32 */
TickType_t TimerTaskModes = 500 / portTICK_PERIOD_MS;                   /**@brief Timer of Task Modes */
TickType_t TimerTaskIMU = 5 / portTICK_PERIOD_MS;                       /**@brief Timer of Task IMU */
TickType_t TimerTaskRegistersUpdateRT = 100 / portTICK_PERIOD_MS;       /**@brief Timer of Task Registers Update in Runtime */
TickType_t TimerTaskTFT = 100 / portTICK_PERIOD_MS;                     /**@brief Timer of Task TFT */
TickType_t TimerTaskServoController = 50 / portTICK_PERIOD_MS;          /**@brief Timer of Task Servo Controller */


/*******************************************************************************************************************************************
 *  												DECLARATION FUNCTIONS
 *******************************************************************************************************************************************/

/**
 * @brief InitTasks 
 * 
 */
void InitTasks();

/**
 * @brief MonitorTasks
 * 
 */
void MonitorTasks();

/**
 * @brief Print Task information
 * 
 * @param task Task Handle
 */
void PrintTaskInfo(TaskHandle_t* task);

/**
 * @brief TaskCLI
 * 
 * @param parameter Parameter
 */
void TaskCLI(void *parameter);

/**
 * @brief TaskGetValueCLI 
 * 
 * @param parameter Parameter
 */
void TaskGetValueCLI(void *parameter);

/**
 * @brief TaskOTA 
 * 
 * @param parameter Parameter
 */
void TaskOTA(void *parameter);

/**
 * @brief TaskNodeESP32 
 * 
 * @param parameter Parameter
 */
void TaskNodeESP32(void *parameter);

/**
 * @brief TaskIMU
 * 
 * @param parameter Parameter
 */
void TaskIMU(void *parameter);

/**
 * @brief Task Modes
 * 
 * @param parameter Parameter
 */
void TaskModes(void *parameter);

/**
 * @brief Task Registers Update Fast
 * 
 * @param parameter Parameter
 */
void TaskRegistersUpdateRT(void *parameter);

/**
 * @brief Task TFT
 * 
 * @param parameter Parameter
 */
void TaskTFT(void *parameter);

/**
 * @brief Task Servo Controller
 * 
 * @param parameter Parameter
 */
void TaskServoController(void *parameter);


#endif // TASKSCONFIG_H