# ADC on microcontrollers (Atmega328p) or *Arduino UNO*

This project is intended to show how the ADC (Analog Digital Converter) can be configured in the **ASM** and **C** languages of the AVR microcontroller architecture. This way we can use less memory capacity (Flash memory), compared to arduino, and understand what Arduino is doing when we use the function `analogRead(pin)`

The *ATmega328p* was chosen because it's the uC that is in the **Arduino UNO** and we can make use of its bootloader to not spend on expensive programmer.


# Table of contents

- [Demo](#demo)
    - [Consetive samples](#consecutive-samples)
    - one sample
- Eschematic
    - Components
- [Installation step](#installation-step)
    - [Required Software](#required-software)
    - [Steps](#steps)


# Demo

## Consecutive samples
![adc en funcionamiento](https://media.giphy.com/media/GETaiFQgjzHZXZr7D3/giphy.gif)

# Installation step

## Required Software

- git 
- platforIO

## Steps

1. clone the repository to a specific location

    `git clone https://github.com/marti-gutierrez/ADC_on_AVR_microcontrollers.git`

2. go to the clone repository *ADC_on_AVR_microcontrollers*

    `cd ADC_on_AVR_microcontrollers`

3. Process (build) all environments specified

    `pio run`

4. connect the Arduino to our USB port and type the following command

    `pio run --target upload`
