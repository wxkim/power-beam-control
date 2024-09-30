#include <stdint.h>
#include <stdio.h>

//mavlink dependencies
#include <mavlink/common/mavlink.h>

#define SERIAL_PORT "/dev/ttyUSB0"  
#define BAUD_RATE B57600  

int open_serial_port(const char *port){

}

void takeoff(int fd, float altitude) {

}

void land(int fd) {
    mavlink_message_t msg;
    uint8_t buf[MAVLINK_MAX_PACKET_LEN];
    uint16_t len;

    mavlink_msg_command_long_pack(
        255,  
        0,    
        &msg,
        1,    
        1,    
        MAV_CMD_NAV_LAND, 
        0,    
        0,0,0,0,0,0,0    
    );

    // Convert the message to digital
    len = mavlink_msg_to_send_buffer(buf, &msg);

    if (write(fd, buf, len) != len) {
        perror("Failed to send land command");
    }
}

int main() {
    int fd = open_serial_port(SERIAL_PORT);
    if (fd == -1) {
        return EXIT_FAILURE;
    }

    printf("Serial port opened successfully.\n");

    printf("Taking off to 1 meter\n");
    takeoff(fd, 1.0);
    sleep(100);  

    // Land the drone
    printf("Landing drone...\n");
    land(fd);


    return EXIT_SUCCESS;
}
