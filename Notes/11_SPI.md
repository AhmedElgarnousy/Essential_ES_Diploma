## Serial Peripheral Interface (SPI)

### SPI Hardware Interface

- MOSI: Master Out Slave Input
- MISO: Master Input Slave output
- SCK: Clock
- SS: Slave Select (Bar: Active Low)
  ![spi1](imgs/spi1.JPG)

Observation: SS pin for master unused pin
Master select slaves with DIO pins

Master Means whos is initiate the communication but can send/receive also

![spi2](imgs/spi2.JPG)

### SPI Specs

- wired
- serial (has only i wire to data tx, and other to rx data)
- synchronous(means slave doesn't need to know speed)
- master/slave relationship: Single master multi slave
- full duplex
- Tp = 100%
  - so it's high speed
  - but doesn't provide any kind of error check mechanism
    ![specs](imgs/spi5.JPG)

#### So how spi works

Shift Register Concept

- Assume master sends now
  ![spi3](imgs/spi3.JPG)
- And Repeats this action 8 times
  ![spi4](imgs/spi4.JPG)

- observation: i send to slave and receive also from slave

---

#### SPI Concepts مصطلحات

##### clock polarity, Leading Edge

- Intuation, How we know that communication starts?

###### clock polarity

Idle state of clock pin(sck)

- at no communcication: state can be LOW/HIGH
- when communication starts : idle state(clock polarity) changes to low/high

###### Leading Edge

- 1st edge that lead communication to start called **Leading edge** (Rising / Falling)
- 2nd edge called **Tralling edge**.
- Observation: Leading Edge always opposite to Tralling Edge

  ![spi6](imgs/spi6.JPG)

##### Clock Phase

Action will happened when communication starts

- if clock phase

  - High: sending(SETUP) first
  - Low: receive (SAMPLE)first

- so We set the clock phase and clock polarity as same as the comunicated device setting
  ![spi7](imgs/spi7.JPG)

- so we have 4 modes
  ![spi8](imgs/spi8.JPG)
- use case
  <!-- ![spi7](imgs/spi7.JPG) -->
      - so SPI is a full duplux with half duplex functionality (because i am not intersed in the received data while sending)

##### #of slaves

![spi9](imgs/spi9.JPG)

##### SPI can send Broadcasting meassage?

![spi10](imgs/spi10.JPG)
yes but what about content of master data regitser if we have more than slave ?

- if we send broadcasting messages continuously
  - disconnect master miso pin
- if u send broadcast within communication
  - this can cause short circuit if slave1 send 0 and slave2 send 1
- here we can use additional hardware (TRI state buffer) on master DIo pin to select between slaves MISO and master MISO pin.
  while sending broadcast message

##### SPI can be simplex

yesm for sure
![spi11](imgs/spi11.JPG)

##### Daisy chain

it's NOT practical concept (NOT used)

- comes to make #slaves not limited to DIO pins but failed
  ![spi12](imgs/spi12.JPG)
- if master wants to send to slave2 , should send2 times
- if master wants to receive from slave2, receive 1 time
- if master wants to receives from slave1 , should receive 2 times

#### Daisy problems

- Transmission time is not constant
- Not able to program each slave to receive 1 or 2 or 3 as i can't control this in the communicated devices

---

### SPI Features

![spi13](imgs/spi13.JPG)

- master can be slave in sometime if needed and master another slave to be master

![spi14](imgs/spi14.JPG)
![spi15](imgs/spi15.JPG)
user: means the slave the will be master

---

#### SPI SWC
