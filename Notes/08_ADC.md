## ADC (Analog To Digital Converter)

#### Examples on Analog signal

- Light
- Sound
- Temperature
- Speed
- Distance
- Pressure

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

For example recording for 1 sec

- shikha freq: 3000 hz
  ![quality](imgs/quality.JPG)

when sampling rate increase qualilty increase but need more memory
for example

- we choose 42000 hz sampling rate
- and resolution is 8 bit (1 Byte) so each sample stored in 1 byte
- we will consume 42 KB ~ 4 MB for just 1 sec

---

- ADC contains DAC
  ![adc_st](imgs/adc_st.JPG)
- `max volt == reference volt`

#### DAC

![dac](imgs/dac.JPG)
![dacex](imgs/dacex.JPG)

- famous DAC circuits is `R2R`, `Weighted Resistor`.

##### R2R (Resistor, 2 Resistor)

كل ماتحب تزود بتايه زود ار نايمه و تو ار قايمه

![R2R](imgs/R2R.JPG)

- so DAC can use to control motor speed

###### How to generate this wave using DAC

![ledAss](imgs/ledAss.JPG)

### ADC

![adctask](imgs/adctask.JPG)

#### RAMP ADC

![Ramp](imgs/Ramp.JPG)

- atmega32 ADC example
  ![adc_ex](imgs/adc_ex.JPG)

##### some important parameters

###### 1- conversion time (T~c~)

Time to know what volt the signal has

- T~c~min: 1 `*` Clock Cycle Time
- T~c~max: 2^n^ `*` Clock Cycle Time, n: resolution

###### conversion time vs sampling Freq

No relationship
but conversion time should be <= to sampling time

![coversiontime](imgs/coversiontime.JPG)

- conversion time is variable
- sampling time is constant

##### Big disadvantage

That the conversion time is variable depend on input signal

##### 2- Errors

![errors](imgs/errors.JPG)

1- Quantization Error

- decreasing the ref volt to reduce step is not applicable if often want all range from 0 to 5v

2- Propagation Error
![delayErr](imgs/delayErr.JPG)

#### SAR ADC

Successive Approximation Register

- Like the RAMP circuit with a different counter
- SAR Counter initially starts with 1
- DAC Output or analog signal = Digital signal `*` Step
- DAC INPUT
  - 0 : Put 0 in current and 1 in next Bit
  - 1 : Put 1 in next Bit of current Bit

![sar](imgs/sar.JPG)

- ADC Features
  ![featuresadc](imgs/featuresadc.JPG)

- LSB == STEP
  step changes in conversions due to H/W disability
  حجم الاستب متفير كمشكله طبيعيه للهادوير
- `+or- 2 كه Adc مجموع الايروز لل `
- Coversion time is constant but in terms of i/p clk cycle
- KSPS : `k`ilo `s`ample `p`er `s`econd
  - 1/65 = 15k freq bit/sec
- 8 Multiplexed Signle Ended Input channels
  ![featuresadc](imgs/featuresadc.JPG)

###### Single Ended vs Differential
