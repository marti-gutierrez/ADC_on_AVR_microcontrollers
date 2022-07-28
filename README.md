# ADC on microcontrollers (Atmega328p) or *Arduino UNO*

This project is intended to show how the ADC (Analog Digital Converter) can be configured in the **ASM** and **C** languages of the AVR microcontroller architecture. This way we can use less memory capacity (Flash memory), compared to arduino, and understand what Arduino is doing when we use the function `analogRead(pin)`

The *ATmega328p* was chosen because it's the uC that is in the **Arduino UNO** and we can make use of its bootloader to not spend on expensive programmer.


# Table of contents

- [Fundamentos ADC](#fundamentos-del-adc)
- [Demo](#demo)
    - [Consetive samples](#consecutive-samples)
    - one sample
- Eschematic
- Installation step

# Fundamentos del ADC

Antes de iniciar con la configuración del ADC tenemos que saber que valores estamos obteniendo del ADC.

$V_{min} = \frac{V_{max}}{2^n-1}$

En este caso el $V_{max}=5v$ y *n=10 bits*

$V_{min} = \frac{5v}{2^{10}-1}=\frac{5v}{1023}=4.88 mv$

Esto nos dice que cada bit (1 bit) tendra un incremento de *4.88 mv*, por ejemplo el dato binario 

$0b0100 \rightarrow 4 $ 

valdria ($4.88mv \cdot 4 ) = 19.52mv$ aproximadamente.
Por lo tanto obtendriamos la ecuación

$ADC \times V_{ref} = V_{min}$

Pero para este proyecto se bajara la resolución a $8 bits$ así que obtenemos:

$V_{min} = \frac{5v}{2^8-1}=\frac{5v}{255}=19.60mv$

# Demo
## Consecutive samples
![adc en funcionamiento](https://media.giphy.com/media/GETaiFQgjzHZXZr7D3/giphy.gif)
