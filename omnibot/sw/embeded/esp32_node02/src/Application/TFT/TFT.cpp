/**
 * @file TFT.cpp
 * @author Luis Arellano - luis.arellano09@gmail.com
 * @brief TFT Class
 * 
 */

/*******************************************************************************************************************************************
 *                                                 INCLUDE
 * *****************************************************************************************************************************************/
#include "TFT.h"


/*******************************************************************************************************************************************
 *                                                 CONSTRUCTOR
 * *****************************************************************************************************************************************/

TFT::TFT(uint8_t rotation, uint8_t BLPin){

    // Create instance
    this->m_ST7735 = new TFT_eSPI();

    // Begin
    this->m_ST7735->begin();
    this->m_ST7735->setRotation(rotation);
    this->m_ST7735->fillScreen(TFT_BLACK);

    // Set Backlight pin
    this->m_BLPin = BLPin;

    // Set LED backlight pin to output mode
    pinMode(this->m_BLPin, OUTPUT);

    // Set Backlight to 50%
    this->SetBackLight(50);

    // Print Title
    this->PrintTitle("OMNIROBOT");

    // Print Values
    this->PrintValues();
}


//=====================================================================================================

TFT::~TFT(){}


/*******************************************************************************************************************************************
 *  												PUBLIC METHODS
 *******************************************************************************************************************************************/

RC_e TFT::SetBackLight(uint level){
    // Result code
    RC_e retCode = RC_e::SUCCESS;

    // Set Backlight
    analogWrite(this->m_BLPin, level*255/100);

    return retCode;
}


RC_e TFT::PrintValues(){
    // Result code
    RC_e retCode = RC_e::SUCCESS;

    this->PrintValue("Pitch:", this->m_Pitch, TFT_WHITE, 10, 30, 50, 30, 45);
    this->PrintValue("Roll :", this->m_Roll, TFT_WHITE, 10, 45, 50, 45, 45);
    this->PrintValue("Yaw  :", this->m_Yaw, TFT_WHITE, 10, 60, 50, 60, 45);

    return retCode;
}

/*******************************************************************************************************************************************
 *  												PRIVATE METHODS
 *******************************************************************************************************************************************/

RC_e TFT::PrintTitle(String data){
    // Result code
    RC_e retCode = RC_e::SUCCESS;

    this->m_ST7735->drawLine(0, 1, 128, 1, TFT_RED);
    this->m_ST7735->setTextColor(TFT_GREEN);
    this->m_ST7735->setTextSize(2);
    this->m_ST7735->setCursor(10, 5, 0);
    this->m_ST7735->print(data);
    this->m_ST7735->drawLine(0, 25, 128, 25, TFT_RED);

    return retCode;
}


RC_e TFT::PrintValue(String label, String data, uint16_t color, uint16_t x_label, uint16_t y_label, uint16_t x_data, uint16_t y_data, uint16_t with_delete_data, uint8_t size){
    // Result code
    RC_e retCode = RC_e::SUCCESS;

    // Set text color and size
    this->m_ST7735->setTextColor(color);
    this->m_ST7735->setTextSize(size);

    // Print label
    this->m_ST7735->setCursor(x_label, y_label, 0);
    this->m_ST7735->print(label);

    // Clear data
    this->m_ST7735->fillRect(x_data, y_data, with_delete_data, this->m_ST7735->fontHeight(), TFT_BLACK);

    // Print data
    this->m_ST7735->setCursor(x_data, y_data, 0);
    this->m_ST7735->print(data);   

    return retCode;
}


RC_e TFT::PrintValue(String label, double data, uint16_t color, uint16_t x_label, uint16_t y_label, uint16_t x_data, uint16_t y_data, uint16_t with_delete_data, uint8_t size){
    // Result code
    RC_e retCode = RC_e::SUCCESS;

    // Set text color and size
    this->m_ST7735->setTextColor(color);
    this->m_ST7735->setTextSize(size);

    // Print label
    this->m_ST7735->setCursor(x_label, y_label, 0);
    this->m_ST7735->print(label);

    // Clear data
    this->m_ST7735->fillRect(x_data, y_data, with_delete_data, this->m_ST7735->fontHeight(), TFT_BLACK);

    // Print data
    this->m_ST7735->setCursor(x_data, y_data, 0);
    this->m_ST7735->print(data);

    return retCode;
}


