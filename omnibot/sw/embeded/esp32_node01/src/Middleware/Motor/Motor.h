/**
 * @file Motor.h
 * @author Luis Arellano (luis.arellano09@gmail.com)
 * @brief Class to control a motor
 * 
 */

#ifndef MOTOR_H
#define MOTOR_H

/*******************************************************************************************************************************************
 *  												INCLUDE
 *******************************************************************************************************************************************/
#include "MotorConfig.h"
#include <Arduino.h>
#include "../../Definition/Global/RC.h"


/*******************************************************************************************************************************************
 *  												CLASS
 *******************************************************************************************************************************************/

/**
 * @brief Class to control a motor
 * 
 */
class Motor {
public:  

    /**
     * @brief Construct a new Motor object
     * 
     * @param pwmChannel PWM Channel
     * @param pwmPin PWM Pin
     * @param frequency PWM frequency 
     * @param resolution PWM resolution 1-20 bits
     * @param offset Correction offset 
     * @param dirPin GPIO PIN to control the motor direction
     * @param direction Direction of the Motor
     */
    Motor(PWMChannel_e pwmChannel, uint8_t pwmPin, double frequency, uint8_t resolution, double offset, uint8_t dirPin, bool invertDirection = false);

    /**
     * @brief Destructor
     * 
     */
    ~Motor();

    /**
     * @brief Set the Speed of the motor
     * 
     * @param speed Speed -100% to 100%
     * @return RC_e Result code
     */
    RC_e SetSpeed(double speed);

    /**
     * @brief Get the Speed
     * 
     * @return double Speed
     */
    double GetSpeed();

    /**
     * @brief Stop the motor
     * 
     * @return RC_e Result code
     */
    RC_e Stop();

    /**
     * @brief Set the Offset
     * 
     * @param offset Motor offset
     * @return RC_e Result code
     */
    RC_e SetOffset(double offset);

    /**
     * @brief Get the Offset
     * 
     * @return double Offset
     */
    double GetOffset();

    /**
     * @brief Set Motor direction
     * 
     * @param direction Motor direction 0=Normal, 1=Invert
     * @return RC_e Result code
     */
    RC_e SetDirection(bool direction);

    /**
     * @brief Get the Direction
     * 
     * @return true Direction inverted
     * @return false Direction Normal
     */
    bool GetDirection();

    /**
     * @brief Function to print the motor status
     * 
     * @return RC_e Result code
     */
    RC_e Print();

private:

    PWMChannel_e m_pwmChannel;      /**@brief PWM Channel */
    uint8_t m_pwmPin;               /**@brief PWM Pin */
    double m_frequency;             /**@brief PWM Frecuency */
    uint8_t m_resolution;           /**@brief PWM resolution 1-20 bits */
    double m_offset;                /**@brief Correction offset */
    uint8_t m_dirPin;               /**@brief Pin to control the direction */
    bool m_invertDirection;         /**@brief Invert Motor direction 0=Normal, 1=Invert */
    double m_speed = 0.0;           /**@brief Motor Speed */

    /**
     * @brief Initializate the Motor
     * 
     * @return RC_e Result code
     */
    RC_e Init();

};

#endif // MOTOR_H