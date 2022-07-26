#ifndef ADC_H_
#define ADC_H_

#include <stdbool.h>
#include "../../include/header.h"

void ADC_init(uint8_t channel,bool mode);
uint16_t ADC_read(uint8_t channel);
void ADC_consecutive_samples(void);
void ADC_one_sample(void);

#define mode_one_sample true
#define mode_consecutive_samples false

#endif /* ADC_H_ */
