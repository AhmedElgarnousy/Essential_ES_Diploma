## Electrical Switches

##### LCD & KeyPad Assignments

1. 3 Buttons Calculator
2. Complete Calculator
3. Stop Watch

![LCD_KPD](imgs/LCD_KPD.JPG)

#### Types of Switches

##### Inituation

###### Why we need electrical switches?

- `Recommended` current can be provided be ATmega32 `20mA`.
- `Max` current cab be provided be ATmega32 `40mA`.
- Min current for small motor around 100mA

![swIntuation](imgs/swIntuation.JPG)

###### so why we didn't use a driving circuit with lEDs and Seven Segment?

- because it consume a little bit power, but it will be better to use

#### Electronis or Physics behind the electrical switches

##### PN-junction

![PN](imgs/pn.JPG)

##### NPN , PNP

- Th goal is to pass electrons from E to C (Emiiter to Base)

- case1 (cutoff): reverse biasing on emitter and base

  ![case1](imgs/cuttoff.JPG)

![case1](imgs/case1.JPG)

- case 2(Saturation):

![case2](imgs/case2.JPG)

- case 3(Active Mode):
  ![case3](imgs/case3.JPG)

##### This is the transistor

![trasistor](imgs/trasistor.JPG)

- CutOFF Circuit

![cutoffCircuit](imgs/cutoffCircuit.JPG)

- Saturation Circuit

![satCircuit](imgs/satCircuit.JPG)

- How to calculate the R~B~
- Onhm Law
- I~B~ from differ from each transistor
- V~B~ around 0.7V

![rb](imgs/rb.JPG)

- option2 not avaialable on ATmega32 due to current limitiation from MCU so (MAX current is 40mA)

  ![option2](imgs/option2.JPG)

- 270 and 330 ohm only available in Market
- 330 Not valid because V~B~ will be less than 0.6V
  ![rbcalc](imgs/rbcalc.JPG)

- control motor through electrical switch
  ![oneDirc](imgs/oneDirc.JPG)

---

##### DC Motor working Principle

![principleDC](imgs/principleDC.JPG)

- add more coils

![coils](imgs/coils.JPG)

##### Advantages of DC Motor

1. Simple in H/W
2. simple in SW
3. Lower power consumption
4. smallest size

##### How to control DC Motor direction

![hwMotor](imgs/hwMotor.JPG)

##### our own H-bridge connection Issue

![Hissue](imgs/Hissue.JPG)

- 2 ways to solve this by software

  - to prevent this case

- **but if we call these 2 functions after each other
  short circuit (BOOM) will happened**

![shortCircuit](imgs/shortCircuit.JPG)

- **JUST replace lines of code**
  ![counterclockwise](imgs/counterclockwise.JPG)

- **second way to solve this issue by hardware**

- change the mapping of H-Bridge connection

- for solution to add NOT Gate

![notGateSol](imgs/notGateSol.JPG)

- or to change the npn to pnp transistor
- and this is the solution in the H-bridge IC
  and with diodes the prevent the BEMF by motor coils
- ![Hbridge](imgs/Hbridge.JPG)

###### Assignments

![assMotor](imgs/assMotor.JPG)

- transistor disadvantage (No Complete Isolation)
- MCU current I~B~ goes with current of power circuit I~C~

from Kirchoff Volt Law : I~E~ = I~C~ + I~B~

![DISADV](imgs/DISADV.JPG)
That means no complete isolation may be MCU effected by motor BEMF

##### Adv / disadv of transistor

![transistorcharachteristics](imgs/transistorcharachteristics.JPG)

##### Optocoupler (Complete Isolation)

![optocoupler](imgs/optocoupler.JPG)

---

- **USB to TTL**
  convert from uart to usb protocols to allow interfacing between MCU and Computer

---

##### Relay (Electromechanical switch)

![relay](imgs/relay.JPG)

- coil is a source to electric magnetism
- switch is made of ferromagnetic material like iron, ..

###### Relay Advantages

- complete power isolation
- high power delivery
- `control AC load`
  - in smart homes,
  - automotive such as (كتاوت) come from cutout word

###### Relay Disadvantages

- low frequency (Mechanical action)
  - switching time more than 50ms
- low life endurrance
- high cost
- big size
- very high consumed power
  - more than 30mA
- high noise
- back emf

###### Relay types

- SPST ريلي 2 طرف عشان الملف ثابت دايما
  ![spst](imgs/spst.JPG)

- SPDT
  ![spdt](imgs/spdt.JPG)
- DPST
  ![dpdt](imgs/dpst.JPG)
- DPDT
  ![dpdt](imgs/dpdt.JPG)

###### NO , NC

bottom side
![ourRelay](imgs/ourRelay.JPG)

###### motor connc

![motorIDir](imgs/motorIDir.JPG)

use a switching circuit (transistor) with the relay because the coil may burn the MCU

![relay_cir](imgs/relay_cir.JPG)

##### How we can control motor direction with relays

## ![relayMotorDir](imgs/relayMotorDir.JPG)

#### Darlington pair

intuation: to solve the minimum current delivery
TRANSISTOR Law:

- I~C~ = Beta \* I~B~

## ![darlington](imgs/darlington.JPG)

Acording to this law we can increase the current with this circuit or connection

## ![beta](imgs/beta.JPG)

## ![darlingtonfina](imgs/darlingtonfina.JPG)

- IC contains 7 darlington pairs (**ULN2003**)

###### It doesn't make sense to generate high to base to get low on collector

## ![makesense](imgs/makesense.JPG)

## ![notgate](imgs/notgate.JPG)

## ![ULN2003](imgs/ULN2003.JPG)

we will use it as controller to stepper motor

##### DC Motor

###### Disadvantages

- Can't be controlled without extra hardware
  - the given RPM @ no load and specific voltage

![dcmotor](imgs/dcmotor.JPG)

##### Encoder

- types: optical and magnetic
  ![encoder](imgs/encoder.JPG)

![yellowmotor](imgs/yellowmotor.JPG)
![yellowmotor](imgs/1_dc_motor_encoder_wheels.jpg)
![yellowmotor](imgs/dc_motor_with_encoder-1.jpg)

#### Stepper Motor

- according to flamng right hand rule
- observation: when current CW put N inside and S outside
  ![flamngrighthandrule](imgs/flamngrighthandrule.jpg)

###### Stepper motor operation theory

- activate coil one then deactivate it and activate next coil

![activate](imgs/activate.jpg)

![ccw](imgs/ccw.jpg)

#### stepper motor types

- 4 coils
  ![4coil](imgs/4coil.jpg)
- 2 coils stepper motor called ==Bipolar== bcause we want to change polarity on each coil
  ![2coils](imgs/2coils.jpg)
- how many transistors needed to control stepper motor direction?

  - each coil has H_bridge(4 transistor) to change the polarity on it like dc motor(1 coil)

- 2 types for 2coil stepper motor
  - bipolar
  - unipolar

##### unipolar (because we don't change polarity)

- here we need just for 4 transistors
  ![unipolar](imgs/unipolar.jpg)

###### Unipolar vs Bipolar

![polar](imgs/polar.jpg)

- **note**: unipolar be can used as bipolar if u neglect the pin no.5

###### stepping

For high resolotion

- full step: one coil activatation at a time
- half step: 2 coils activatation at some time
  ![steping](imgs/steping.jpg)
- Microstepping
  - added voltage control paramter
    ![microstepping](imgs/microstepping.jpg)

##### is the step is 90 deg

- they repeat the 4 coils serveral times and connected them together to decrease the deg per step
- to know resoution or stride angle(deg/step)
  - look in datasheet of the motor
- most famous stepper motors `nema`: its resolution 1.8 deg

#### stepper data sheet

each stepper has gearbox internally
![stepperdata](imgs/stepperdata.JPG)
![stepperDatainf](imgs/stepperDatainf.JPG)

- ULN2003 with stepper motor

  - to activate the coil we know that ULN2003 generate low when get low and floating when get high
  - so we should connect the red pin with vcc
    ![connctionstepper](imgs/connctionstepper.jpg)

- from datasheet: Frequency is 100H~z
- THat means 100 step/sec
- then step = 1/100 sec = 10 msec (Optimum speed)
- max speed step each 2 msec
  ![codeStepper](imgs/codeStepper.jpg)

###### we need the stepper for specific angle not continus rotation

- Req angle = 17.5 deg
- stepper motor stride angle or resolution: 0.175 deg/step
- no. of steps = req deg / motor deg
- no of iteration = no of steps / steps per iteration
  ![reqAngle](imgs/reqAngle.jpg)

- Another way to calculate a specific angle
  ![angleStepper](imgs/angleStepper.jpg)

#### Additional Resources

[switches](https://www.ermicro.com/blog/?p=423)
[encoder](https://automaticaddison.com/calculate-pulses-per-revolution-for-a-dc-motor-with-encoder/)
[encoder](https://deepbluembedded.com/arduino-motor-encoder-optical-encoder-interfacing/)
