//the microphone amplifier output is connected to pin A0
const int MIC = 0;

//the variable that will hold the value read from the microphone each time
int adc;
int dB, PdB; 

void setup() {
//sets the baud rate at 9600 so we can check the values the microphone is obtaining on the Serial Monitor
Serial.begin(9600); 
pinMode(3, OUTPUT);
}

void loop(){

//store previous dB
PdB = dB;

//Read the ADC value from amplifer  
adc= analogRead(MIC);

//Convert ADC value to dB using Regression values
dB = (adc+83.2073) / 11.003; 

if (PdB!=dB)
Serial.println (dB);

if (dB>60)
{
// turn the pin on (HIGH is the voltage level)
  digitalWrite(3, HIGH);   
// wait for a few seconds
  delay(200000);                       
  digitalWrite(3, LOW); 
}

//delay(100);

}
