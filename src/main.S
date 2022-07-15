;ADC of free Running Auto-trigering

#define __SFR_OFFSET 0
#include "avr/io.h"

.global main
.org 0

main:
  ldi   r16,lo8(RAMEND)
  out   SPL,r16
  ldi   r16,hi8(RAMEND)
  out   SPH,r16
  ;Configurar Output Leds
  ldi   r16,0xFF
  out   DDRD,r16
  out   PORTD,r16
  ldi   R16,(1<<ADEN)|(1<<ADSC)|(1<<ADATE)|(1<<ADPS2)|(0<ADPS1)|(0<<ADPS0)
  //      |enable ADC|start conv|auto-trig | factor(16) = 16 MHz / 16 = 1 MHZ = 1 us
  sts   ADCSRA,R16
  ldi   R16,(0<<ACME)|(0<<ADTS2)|(0<<ADTS1)|(0<<ADTS0)
  //                 | free Running mode
  sts   ADCSRB,R16   
  ldi   R16,(1<<ADC0D)
  //  the digital Input (PC0) is disabled
  sts   DIDR0,R16
read_converted_data:
  ldi   R16,(0<<REFS1)|(1<<REFS0)|(1<<ADLAR)|(0<<MUX3)|(0<<MUX2)|(0<<MUX1)|(0<<MUX0)
  //       | vr = AVcc with C    |left Ajust| chanel ADC0(single ended)
  sts   ADMUX,R16
  nop
  nop
  nop
  nop
  nop
  nop
  nop
  nop
  nop
  nop
  nop
  nop
  nop
  nop            ;13.5 cycles para asegurar la lectura (first conversiion + Auto Trigger)
  lds   R30,ADCL
  lds   R29,ADCH
  out   PORTD,R29
  rjmp  read_converted_data

wait:
rjmp  wait
