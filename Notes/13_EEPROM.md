## EEPROM

![eeprom](imgs/eeprom1.JPG)

- NVRAM (sw +hw)
- Brown Out Detector if detect the power reduces to 4.8
- execute ISR of this event and load data from RAM to extra Flash

ROM
![eeprom](imgs/eeprom2.JPG)

- characteristics of FGM

- Processor can not access (write/erase) ROM beecause FGM require High Power but can read

###### ROM Types

![eeprom](imgs/eeprom3.JPG)

- ![eeprom](imgs/eeprom4.JPG)
- permenat data: for example last temperature value before air conditioning shut down

1- 8kbit = 1 k B

- Features

  - Write Protect Pin for Hardware Data Protection
    (من الاخر لو حاولت تصلح اي حاجه في البورده وشيلت الذاكره كل حاجه تتمسح فلما تيجي تنشغلها ماتشتغلش قتضطر تروح الصبانه بردو)

![eeprom](imgs/eeprom5.JPG)
![eeprom](imgs/eeprom8.JPG)

- ADRRESSES
  ![eeprom](imgs/eeprom6.JPG)
- 24C02
  ![eeprom](imgs/eeprom7.JPG)
- 24C04
  ![eeprom](imgs/eeprom9.JPG)
- 24C08
  ![eeprom](imgs/eeprom10.JPG)

##### Memory organization

![eeprom](imgs/eeprom11.JPG)

##### Device Addressing

![eeprom](imgs/eeprom12.JPG)
![eeprom](imgs/eeprom13.JPG)

##### write byte operation

![eeprom](imgs/eeprom14.JPG)
![eeprom](imgs/eeprom15.JPG)

##### write byte operation example

![eeprom](imgs/eeprom16.JPG)
![eeprom](imgs/eeprom17.JPG)

- call TWI master init func()
- eeprom write byte
  ![eeprom](imgs/eeprom18.JPG)
- eeprom read byte
  ![eeprom](imgs/eeprom19.JPG)
- conection
  ![eeprom](imgs/eeprom20.JPG)
- SCL,SDA disconnected to DIO Peripheral they are open drain

- EEPROM Test APP
  ![eeprom](imgs/eeprom21.JPG)
