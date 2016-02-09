/*
 Arduino Voltmeter and Ammeter
 * The voltage will be measured through the circuit:

A0------|
        Measure Voltage
        In between these 2
Ground--|


5V------|
        Measure Current
        In between these 2
A1------|
        1.55 ohm resistor
        In between these 2
Ground--|


 Version: 1.0
 Note:
 *This project was created solely to measure the recharge/discharge
  of a AA Alkaline Rechargeable battery
 * 
 */

int sensorPin = A0; //select the input pin for voltage
int sensorPin2 = A1;  //select the input pin for current
int sensorValue = 0;  //variable to store value coming from sensor 1
int sensorValue2 = 0; // variable to store the value coming from sensor 2
int resis = 1.55; //select the value that R1 is in our voltage divider
int voltage = 0; // variable for voltage for 1st circuit location
int volts = 0; //variable for Vout in the voltage divider circuit
int current = 0; // variable for current
int resistance = 0; // variable for resistance
int time = 1; //time for between readings (in seconds)


void setup() { 
  Serial.begin(9600); //initialiaze the 9600 baud serial connection between Arduino and computer
}

void loop() { //begin the loop
  delay(time*1000); //wait this much time before taking another reading
  sensorValue = analogRead(sensorPin); //get reading from voltage sensor (1-1023)
  sensorValue2 = analogRead(sensorPin2); //get reading from Vout sensor (1-1023)
  voltage = sensorValue/204.6; //map the sensor byte value to a 0-5 volt range
  volts = sensorValue2/204.6 //map the sensor byte value to a 0-5 volt range
  resistance = ((resis*5.00)/(volts))-resis; //calculate the value for R2 in the voltage divider circuit
  current = voltage/resistance; //use ohm's formula to calculate the circuit voltage
  Serial.println(voltage); //print to the Serial monitor the voltage
  Serial.println(current); //print to the Serial monitor the current
  Serial.println(resistance); //print to the Serial monitor the resistance
} //close the loop
