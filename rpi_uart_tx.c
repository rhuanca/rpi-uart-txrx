#include <stdio.h>
#include <unistd.h>			//Used for UART
#include <fcntl.h>			//Used for UART
#include <termios.h>		//Used for UART

int main() {
    int uart0_filestream = -1;

    printf("UART TX\n");
    // Setup the uart
    // ---
    uart0_filestream = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY | O_NDELAY);		//Open in non blocking read/write mode
    if (uart0_filestream == -1)
    {
        //ERROR - CAN'T OPEN SERIAL PORT
        printf("Error - Unable to open UART.  Ensure it is not in use by another application\n");
        return 0;
    }
    printf("serial port opened.\n");

    struct termios options;
    tcgetattr(uart0_filestream, &options);
    options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;		//<Set baud rate
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(uart0_filestream, TCIFLUSH);
    tcsetattr(uart0_filestream, TCSANOW, &options);

    // Transmiting bytes
    // ---

    unsigned char tx_buffer[20];
    unsigned char *p_tx_buffer;

    p_tx_buffer = &tx_buffer[0];
    *p_tx_buffer++ = 'H';
    *p_tx_buffer++ = 'e';
    *p_tx_buffer++ = 'l';
    *p_tx_buffer++ = 'l';
    *p_tx_buffer++ = 'o';

    // Sending data
    // ---
    int count = write(uart0_filestream, &tx_buffer[0], (p_tx_buffer - &tx_buffer[0]));		//Filestream, bytes to write, number of bytes to write
    if (count < 0)
    {
        printf("UART TX error\n");
    }

    close(uart0_filestream);
    printf("serial port closed.\n");
    return 0;
}