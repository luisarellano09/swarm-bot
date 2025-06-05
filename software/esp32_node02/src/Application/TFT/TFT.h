/**
 * @file TFT.h
 * @author Luis Arellano - luis.arellano09@gmail.com
 * @brief TFT Class
 * 
 */

#ifndef TFT_H
#define TFT_H

/*******************************************************************************************************************************************
 *  												INCLUDE
 *******************************************************************************************************************************************/
#include "../../lib/TFT_eSPI/TFT_eSPI.h"
#include "../../Definition/Global/RC.h"


/*******************************************************************************************************************************************
 *  												CLASS
 *******************************************************************************************************************************************/

/**
 * @brief TFT Class
 * 
 */
class TFT {
public:

    TFT_eSPI* m_ST7735 = NULL;                         /**@brief Instance for the TFT. */
    double m_Pitch = 0.0;                              /**@brief Pitch */
    double m_Roll = 0.0;                               /**@brief Roll */
    double m_Yaw = 0.0;                                /**@brief Yaw */

    /**
     * @brief Construct a new TFT object
     * 
     * @param BLPin Backlight Pin
     */
    TFT(uint8_t rotation, uint8_t BLPin);

    /**
     * @brief Destroy the TFT object
     * 
     */
    ~TFT();

    /**
     * @brief Set BackLight
     * 
     * @param level Level of Backlight in %
     * @return RC_e Result code
     */
    RC_e SetBackLight(uint level);


    RC_e PrintValues();



private:
    uint8_t m_BLPin;                                /**@brief Backlight Pin */  

    RC_e PrintTitle(String data);

    RC_e PrintValue(String label, String data, uint16_t color, uint16_t x_label, uint16_t y_label, uint16_t x_data, uint16_t y_data, uint16_t with_delete_data, uint8_t size=1);

    RC_e PrintValue(String label, double data, uint16_t color, uint16_t x_label, uint16_t y_label, uint16_t x_data, uint16_t y_data, uint16_t with_delete_data, uint8_t size=1);
   
};

#endif // TFT_H