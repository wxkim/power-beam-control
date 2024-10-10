/**
 * Hardcoded Fly-over on MAVLINK with UART
 *
 * author: willkim  -> wkim@utdallas.edu
 * hi
 */

// #include "main.h"
#include "../libraries/mavlink/common/mavlink.h"
#include "main.h"

extern UART_HandleTypeDef huart1;

/// @brief Function to set up UART communication using HAL
void setup_serial()
{
    // UART is already initialized in STM32CubeMX code generation
    HAL_UART_Init(&huart1);
}

/// @brief Write a MAVLink message over UART
/// @param msg MAVLink message pointer
void send_mavlink_message(mavlink_message_t *msg)
{
    uint8_t buf[MAVLINK_MAX_PACKET_LEN];
    uint16_t len = mavlink_msg_to_send_buffer(buf, msg);

    HAL_UART_Transmit(&huart1, buf, len, HAL_MAX_DELAY);
}

/// @brief Arm the drone using MAVLink
void arm_drone()
{
    mavlink_message_t msg;

    // Pack comm
    mavlink_msg_command_long_pack(
        1, 1, &msg,                   // system_id, component_id, message pointer
        1, 1,                         // target_system, target_component
        MAV_CMD_COMPONENT_ARM_DISARM, // Command to arm/disarm
        0,                            // Confirmation (0 = first command)
        1,                            // param1: 1 to arm, 0 to disarm
        0, 0, 0, 0, 0, 0              // Other params unused for this command
    );
    send_mavlink_message(&msg);
}

/// @brief Take off the drone to a specific altitude
/// @param altitude Target altitude in meters
void takeoff(float altitude)
{
    mavlink_message_t msg;
    // Pack comm
    mavlink_msg_command_long_pack(
        1, 1, &msg,          // system_id, component_id, message pointer
        1, 1,                // target_system, target_component
        MAV_CMD_NAV_TAKEOFF, // Takeoff command
        0,                   // Confirmation (0 = first command)
        0, 0, 0, 0,          // Unused parameters
        0, 0,                // Lat, Long (unused)
        altitude             // Target altitude in meters
    );
    send_mavlink_message(&msg);
}

/// @brief Land the drone using MAVLink
void land_drone()
{
    mavlink_message_t msg;

    // Pack comm
    mavlink_msg_command_long_pack(
        1, 1, &msg,       // system_id, component_id, message pointer
        1, 1,             // target_system, target_component
        MAV_CMD_NAV_LAND, // Land command
        0,                // Confirmation (0 = first command)
        0, 0, 0, 0,       // Unused parameters
        0, 0, 0           // Lat, Long, Alt (unused)
    );
    send_mavlink_message(&msg);
}

void fly(void)
{
    // MCU Inits
    HAL_Init();
    SystemClock_Config();
    MX_USART1_UART_Init();

    // Actually fly
    setup_serial();

    printf("Arming the drone...\n");
    arm_drone();
    HAL_Delay(2000);

    printf("Taking off to 1 meter...\n");
    takeoff(1.0f);
    HAL_Delay(5000);

    printf("Landing the drone...\n");
    land_drone();
    HAL_Delay(2000);

    while (1)
    {
        break;
    }

    printf("SUCCESS\n");
    return 0;
}
