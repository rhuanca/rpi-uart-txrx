//
// Created by rhuanca on 8/3/15.
//

#include <fcntl.h>			//Used for UART
#include <termios.h>		//Used for UART
#include "uart.h"

int uart0_filestream;

int uart_open(int flags) {
    // O_RDWR | O_NOCTTY | O_NDELAY
    uart0_filestream = open("/dev/ttyAMA0", flags);        //Open in non blocking read/write mode
    if (uart0_filestream == -1) {
        return -1;
    }
    return 1;
}

void uart_set_options() {
    struct termios options;
    tcgetattr(uart0_filestream, &options);
    options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;        //<Set baud rate
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(uart0_filestream, TCIFLUSH);
    tcsetattr(uart0_filestream, TCSANOW, &options);
}