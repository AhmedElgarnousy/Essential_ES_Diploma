## LCD

#### Types of displays

1. LED Displays
2. Segment Display
3. LED Matrix (Dot Matrix)

##### LED Displays Disadvantages

1. High power Consumption
   for example 7 seg
   each led consume around 15 mA, 5v (75m Watt)
   so to display 1 num needs around 75m W \* 7 ~= 0.5 Watt (High Consumption)
2. #pins is big

##### LED Displays Advantages

1. Attractive
2. view angle
3. size

---

### Liquid Crystal Display

2 physics concepts

1. Light Polarization
2. Liquid Crystal

![light](imgs/light.PNG)

polarized allow light pass in one plane

in our case(LCD) the polarized is the liquid crystal
عشان كده مايفضلش تسيب ال lcd فتره كبيرهش شغاله عشان ما تنشفش

- Liquid Crystal
  has fluidity , also hard as solid زي الجيلي

- at normal conditions is liquid
- change its internal structure with voltage effect
  - has 2 shapes or state

![light](imgs/crystal.JPG)
![light](imgs/crystal2.PNG)

#### LCD Types

1. Segment LCD
2. Alphanumeric LCD (Character LCD)
3. Graphical LCD
   1. Monochrome (1 LED source) like Nokie 5110
   2. Colored (RGP source) like TV Screens

---

LCD Module:
LED Source + Liquid Crystals + Polarizers + Panel + Microcontrollers

![parrall](imgs/parral.JPG)

![pinsO](imgs/lcdPinout.JPG)

- Ctrl Pins
- resistance to volt (Voltage Divider)

![pinsO](imgs/ctrlPins.JPG)

- Enable Pin: means start reading

#### LCD Driver Configuration

no mean here to have a post build configuration
we will change hw connection in runtime

---

![lcd_instructions](imgs/lcd_instructions.JPG)

---

### LCD SWC

- send command

![sendCommand](imgs/sendCommand.JPG)

##### Datasheet 8-bit Iniialization

![init_8bitMode](imgs/init_8bitMode.JPG)

![8bitmode](imgs/8bitmode.JPG)

- Entry Mode set : advanced command doesn't matter now

C know the ASCII Table just put it in single quote like -> 'A'

- C rule: String is array of char NOT (unsigned or signed char)

##### Datasheet 4-bit Iniialization

## connecting new MCU first time

should define its clock firstly by fuses

- project Properities
  - Fuses
    - Direct hex value -> FF D9
