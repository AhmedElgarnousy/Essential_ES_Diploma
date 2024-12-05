## ADC (Analog To Digital Converter)

#### Examples on Analog signal

- light
- sound
- temperature
- speed
- distance
- pressure

#### Analog signal Characteristics

- continious
- infinity possibilities

![analog_characteristics](imgs/analog_characteristics.JPG)

- As digital world for MCU
  - we define a fixed clk cycle
  - 2 possibilities (0, 1)
- ![digitalworld](imgs/digitalworld.JPG)

### So ADC comes to make MCU understand analog world

#### Digitalization Process

##### 1- sampling

like a screenshoots at specific rate

![what_rate](imgs/what_rate.JPG)

- sampling and hold (S/H)
  hold the previous sample value as same as for the next sample value
  ![hold](imgs/hold.JPG)

holding the signal can be done by capacitors

##### 1- Quantization

change to digital value

convert the signal to be discrete (Not Continuous) and defined possibilities
![quantization](imgs/quantization.JPG)

- **Note**: ALL ADCs measures voltage convert all physical signals (Temperature) to voltage firstly

- example: convert from digital to analog
  ![digitization_ex](imgs/digitization_ex.JPG)

- example: convert from analog to digital
  ![adc](imgs/adc.JPG)

##### Quantization Error

to decrease it

1. increase resolution
2. decrease the max voltage
   ![adc](imgs/adc.JPG)

#### what if signal > 4v (max volt for previous example) or when saturation(all bits becomes 1s) happen

![sat](imgs/sat.JPG)

- another example
  ![another_adc](imgs/another_adc.JPG)

##### Conversion Quality

for example recording for 1 sec

- shikha freq: 3000Hz
  ![quality](imgs/quality.JPG)

when sampling rate increase qualilty increase but need more memory
for example

- we choose 42000 Hz sampling rate
- and resolution is 8 bit (1 Byte) so each sample stored in 1 byte
- we consumes 42 KB ~ 4 MB for just 1 sec

---

- ADC contains DAC

#### DAC
