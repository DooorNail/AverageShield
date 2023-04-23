#include "i2cmaster.h"
#include "lm75.h"

#include <stdio.h>
#include "usart.h"

#define SOFTWARE_EMULATION

#if defined(SOFTWARE_EMULATION)

FILE f2_uart = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);

float prevTemperature = 22;

#endif // SOFTWARE_EMULATION

void lm75_init()
{
#if defined(SOFTWARE_EMULATION)

    uart_init();

#else

    // Set sensor configuration
    i2c_start_wait(LM75_ADR + I2C_WRITE);
    // In the pointer register, request to write the configuration register
    i2c_write(0x01);
    // Write the configuration register to normal mode and default params
    i2c_write(0x00);
    i2c_stop();

#endif // SOFTWARE_EMULATION
}

double get_temperature()
{
#if defined(SOFTWARE_EMULATION)

    float temperature = prevTemperature;

    // fprintf(uart_stream(), "-");

    char x;
    while (!bit_is_clear(UCSR0A, RXC0))
    {
        x = fgetc(&f2_uart);
        if (x == '`')
        {
            fprintf(&f2_uart, "Enter temperature\n>>> ");
            fscanf(&f2_uart, "%f", &temperature);
            prevTemperature = temperature;
        }
        // fprintf(uart_stream(), ".");
        // fprintf(uart_stream(), "%d", uart_stream()->flags);
    }

#else
    float temperature;      // will hold the measured ambient temperature in deg. Celsius
    unsigned int temp_data; // intermediate value
    unsigned char low_temp_byte;
    unsigned char high_temp_byte;

    // In the pointer register, request to read from Temp register
    i2c_start_wait(LM75_ADR + I2C_WRITE);
    i2c_write(0x00);

    // The LM75a will respond with 2 bytes
    // Temperature returned as follows:
    // High byte: | D10 | D09 | D08 | D07 | D06 | D05 | D04 | D03 |
    // Low byte:  | D02 | D01 | D00 | xxx | xxx | xxx | xxx | xxx |
    // where D10 is the sign bit and D09..D00 is the value of the temp * 0.125
    // if temp is negative, then temp is stored as 2's complement
    i2c_rep_start(LM75_ADR + I2C_READ);
    high_temp_byte = i2c_readAck();
    low_temp_byte = i2c_readNak();
    i2c_stop();

    if ((high_temp_byte & 0x80) == 0)
    { // temp. >= 0
        temp_data = (((high_temp_byte & 0x7F) << 3) | (low_temp_byte >> 5));
        temperature = temp_data * 0.125;
    }
    else
    { // temp. < 0
        temp_data = (((high_temp_byte & 0x7F) << 3) | (low_temp_byte >> 5));
        temp_data = ~temp_data + 1;
        temperature = 0.00 - temp_data;
    }
#endif // SOFTWARE_EMULATION

    return temperature;
}
