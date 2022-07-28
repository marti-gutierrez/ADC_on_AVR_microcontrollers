#include "ADC.h"

void ADC_init(uint8_t channel,bool mode)
{
  ADMUX |= (0<<REFS1)|_BV(REFS0)|_BV(ADLAR);
  //       | Vcc with external C| enable ADC left adjust
  //Prescaler Selection
  ADCSRA |= (0<<ADIE)|(0<<ADPS2)|_BV(ADPS1)|(0<<ADPS0);
  //     |disable Int|factor(4) => 16MHz / 4 = 4MHz --> 0.25us
  (mode) ? ADC_one_sample() : ADC_consecutive_samples();
  ADCSRB = (0<<ACME)|(0<<ADPS2)|(0<<ADPS1)|(0<<ADPS0);
  channel &= 0x0F;
  set_bit(DIDR0,channel);// disable Digital Input
  set_bit(ADCSRA,ADEN);  // ACtivate ADC
}
void ADC_consecutive_samples(void)
{
  set_bit(ADCSRA,ADATE); // ADC auto-trigger enable
  set_bit(ADCSRA,ADSC); // Start consecutive sample
}
void ADC_one_sample(void)
{
  clear_bit(ADCSRA,ADEN);
}

uint16_t ADC_read(uint8_t chanel)
{
  set_bit(ADCSRA,ADIF); //clear flag to ADC
  chanel &= 0x0F;
  ADMUX = (ADMUX  & 0xF0) | chanel;
  while(!bit_is_set(ADCSRA,ADIF));
  return ADC;
}

