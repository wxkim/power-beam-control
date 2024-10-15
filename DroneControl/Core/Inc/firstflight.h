/*
 * firstflight.h
 *
 *  Created on: Oct 14, 2024
 *      Author: micha
 */

#ifndef INC_FIRSTFLIGHT_H_
#define INC_FIRSTFLIGHT_H_

/**
 * Hardcoded Fly-over on MAVLINK with UART
 *
 * author: willkim  -> wkim@utdallas.edu
 * hi
 */

// #include "main.h"
#include "../Libraries/MAVLink/common/mavlink.h"
#include "main.h"

extern UART_HandleTypeDef huart1;

/// @brief Function to set up UART communication using HAL
void setup_serial();

/// @brief Write a MAVLink message over UART
/// @param msg MAVLink message pointer
void send_mavlink_message(mavlink_message_t *msg);

/// @brief Arm the drone using MAVLink
void arm_drone();

/// @brief Take off the drone to a specific altitude
/// @param altitude Target altitude in meters
void takeoff(float altitude);

/// @brief Land the drone using MAVLink
void land_drone();

void fly(void);



#endif /* INC_FIRSTFLIGHT_H_ */
