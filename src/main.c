//#include <avr/io.h>
#include "header.h"
#include <ADC.h>

int main(void)
{
    SPL = low(RAMEND);
    SPH = high(RAMEND);
    DDRD = 0xFF;
    ADC_init(0x00,mode_consecutive_samples);
    while (1)
    {
        uint16_t data_ADC = ADC_read(0x00);
        DDRB = high(data_ADC);
    }
}