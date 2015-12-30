#include <stdio.h>
#include <unistd.h>			//Used for UART
#include <fcntl.h>			//Used for UART
#include <termios.h>		//Used for UART
#include "uart.h"

int main() {
//    if (uart_open(O_RDWR | O_NOCTTY | O_NDELAY) == -1) {
//        printf("Unable to open uart por\n");
//    }
//    printf("uart port opened.\n");
//
//    uart_set_options();

    // Transmiting bytes
    // ---

    unsigned char tx_buffer[20148];
    unsigned char *p_tx_buffer;

    p_tx_buffer = &tx_buffer[0];
    *p_tx_buffer++ = 'H';
    *p_tx_buffer++ = 'e';
    *p_tx_buffer++ = 'l';
    *p_tx_buffer++ = 'l';
    *p_tx_buffer++ = 'o';

    // Sending data
    // ---
    int count = write(uart0_filestream, &tx_buffer[0],
                      (p_tx_buffer - &tx_buffer[0]));        //Filestream, bytes to write, number of bytes to write
    if (count < 0) {
        printf("UART TX error\n");
    }

    close(uart0_filestream);
    printf("serial port closed.\n");
    return 0;
}