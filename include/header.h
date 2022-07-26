#include <avr/io.h>
#include <avr/sfr_defs.h>

//#define F_CPU 16000000UL
#define high(x) ((x) >> 8)
#define low(x) ((x) & 0x00FF)

#define set_bit(sfr,bit) (_SFR_BYTE(sfr) |= _BV(bit))
#define clear_bit(sfr,bit) (_SFR_BYTE(sfr) &=~ _BV(bit))

