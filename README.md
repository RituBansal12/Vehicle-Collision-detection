# Vehicle-Collision-detection

This application is a smart vehicle collision detector that is developed to detect accidents occuring in secluded places at an inconvineant time through survelliance cameras. 
It is built using the principles of IoT and Deep Learning.

COMPONENT 1: Measuring the sound level(dB) using microphone sensor

Materials Required:
Arduino UNO
Microphone
LM386
10K variable POT
Resistors and Capacitors

Circut set-up:
Circuit for this Arduino Sound Level Meter is a very simple in which we have used the LM386 Audio amplifier circuit to amplify the signals from a condenser microphone and supply it to the Analog port of Arduino.
The gain of this particular op-amp can be set from 20 to 200 using a resistor or capacitor across pin 1 and 8. If they are left free the gain will be set as 20 by default. For our project we the maximum gain possible by this circuit, so we use a capacitor of value 10uF between the pins 1 and 8, note that this pin is polarity sensitive and the negative pin of capacitor should be connected to pin 8. The complete amplifier circuit is powered by the 5V pin from the Arduino.  
The Capacitor C2 is used to filter the DC noise from Microphone. Basically when the microphone senses sound the sound waves will be converted to AC signals. This AC signal might have some DC noise coupled with it which will be filtered by this capacitor. Similarly, even after amplification a capacitor C3 is used to filter any DC noise that might have been added during amplification.

Measuring dB from ADC value:
A correlation between ADC value and dB has been found and can be implemented using dB = (ADC+83.2073) / 11.003

COMPONENT 2: Clicking the picture of the potential accident scene

