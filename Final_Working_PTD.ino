
#include <Servo.h>                                                              // We need a library called "Servo".
Servo myservo;                                                                  // The servo motor we will use, will be called "myservo".

                                                                                // Here we start to declare constants/variables we will use later.

int sensorPin = 3;                                                              // This is the Arduino pin number 3, where we will connect the Sensor, it´ll be called sensorPin.
int val = 0;                                                                    // Variable that will store readings from the sensor, initialized at zero.
int estado = 0;                                                                 // This is our servo motor status, initialized at zero, meaning "open".
int sensorMin = 1023;                                                           // Calibration Variable, initialized at zero.
int sensorMax = 0;                                                              // Calibration Variable, initialized at zero.
int sensorMed = 0;                                                              // Calibration Variable, initialized at zero.
int pos = 950;                                                                  // Initial servo motor position.
int limite = 0;                                                                 // This is our trigger limit to start moving the servo motor, initialized at zero.

                                                                                // Here we finish to declare constants/variables we will use later.

                                                                                // And then we can start the Calibration process. You need to do this with the sensor 
                                                                                // connected to you PC via USB so you can read the Serial Monitor, and check the proper 
                                                                                // Sensor readings.
                                                                                
void setup() 
{ 
  Serial.begin(9600);                                                           // Initializes the Serial Port so the PC can display Sensor readings. 
  myservo.writeMicroseconds(pos);                                               // Moves the servo motor to a known position, in this case Fully Open.
  myservo.attach(2);  			                                        // This tells the Arduino board, that the Servo Motor will be receiving signals thru pin numer 2.
  delay(2500);                                                                  // Wait for the servo to reach the Fully Open Position.                                                           
  pinMode(4, OUTPUT);                                                           // This tells the Arduino board, that we will use pin 4 as an output. 
                                                                                // This is where we connect the (+) LED leg, pin 4.
  
                                                                                // Next, we have a blinking LED, that will tell you the Sensor Calibration is about to start.
                                                                                
  digitalWrite(4, HIGH);                                                        // Turn LED (on pin 4) ON
  delay(50);                                                                    // A little time delay. 
  digitalWrite(4, LOW);                                                         // Turn LED (on pin 4) OFF
  delay(50);                                                                    // A little time delay. 
  digitalWrite(4, HIGH);                                                        // Turn LED (on pin 4) ON
  delay(50);                                                                    // A little time delay. 
  digitalWrite(4, LOW);                                                         // Turn LED (on pin 4) OFF
  delay(50);                                                                    // A little time delay. 
  digitalWrite(4, HIGH);                                                        // Turn LED (on pin 4) ON
  delay(50);                                                                    // A little time delay. 
  digitalWrite(4, LOW);                                                         // Turn LED (on pin 4) OFF
  delay(50);                                                                    // A little time delay.
  digitalWrite(4, HIGH);                                                        // Turn LED (on pin 4) ON
  delay(50);                                                                    // A little time delay. 
  digitalWrite(4, LOW);                                                         // Turn LED (on pin 4) OFF
  delay(50);                                                                    // A little time delay.
  digitalWrite(4, HIGH);                                                        // Turn LED (on pin 4) ON 



                                                                                // This is the actual moment the Calibration Process Starts.

  while (millis() < 10000) {                                                    // The Calibration Process Duration is set here(in miliseconds): 10,000 = 10 seconds.
  val = analogRead(sensorPin);                                                  // Our variable called "val" will store whatever reading we have from the Sensor.(connected to pin 3)
  
  if (val > sensorMax){                                                         // Here we start overwriting our variables called sensorMax and sensorMin, with
    sensorMax = val;                                                            // maximum and minimum readings from the sensor,
    }                                                                           // all over again and again,
    if (val < sensorMin){                                                       // all over again and again,
    sensorMin = val;                                                            // all over again and again,
    }                                                                           // for the whole 10 seconds period we stated earlier.       
  }
                                                                                // This is the actual moment the Calibration Process Ends. 
                                                                                
                                                                                // Next, we have a blinking LED, that will tell you the Sensor Calibration is about to end.
  
  digitalWrite(4, LOW);                                                         // Turn LED (on pin 4) OFF
  delay(50);                                                                    // A little time delay. 
  digitalWrite(4, HIGH);                                                        // Turn LED (on pin 4) ON
  delay(50);                                                                    // A little time delay. 
  digitalWrite(4, LOW);                                                         // Turn LED (on pin 4) OFF
  delay(50);                                                                    // A little time delay.  
  digitalWrite(4, HIGH);                                                        // Turn LED (on pin 4) ON
  delay(50);                                                                    // A little time delay. 
  digitalWrite(4, LOW);                                                         // Turn LED (on pin 4) OFF
  delay(50);                                                                    // A little time delay. 
  digitalWrite(4, HIGH);                                                        // Turn LED (on pin 4) ON
  delay(50);                                                                    // A little time delay.  
  digitalWrite(4, LOW);                                                         // Turn LED (on pin 4) OFF
  delay(50);                                                                    // A little time delay. 
  digitalWrite(4, HIGH);                                                        // Turn LED (on pin 4) ON
  delay(50);                                                                    // A little time delay.  
  digitalWrite(4, LOW);                                                         // Turn LED (on pin 4) OFF
  
                                                                                // Once the LED is OFF, the whole Calibration Process is finished.
                                                                                
                                                                                // While the Arduino Board is connected via USB to your PC, and the Serial Monitor open,
                                                                                // you should be able to see what the actual readings from the sensor are. 
  
  Serial.write("Maximum Reading From Sensor Was: ");                            // Text that will be written to the Serial Monitor.
  Serial.println(sensorMax);                                                    // Variable value that will be written to the Serial Monitor.
  Serial.write("Minimum Reading From Sensor Was: ");                            // Text that will be written to the Serial Monitor.
  Serial.println(sensorMin);                                                    // Variable value that will be written to the Serial Monitor.
  sensorMed = ((sensorMax + sensorMin)/2);                                      // Here we calculate the value for a new variable called sensorMed, to get an average of the readings.
  Serial.write("Average readings from the sensor: ");                           // Text that will be written to the Serial Monitor.
  Serial.println(sensorMed);                                                    // Variable value that will be written to the Serial Monitor.
  delay(500);                                                                   // A little time delay.
  limite = (sensorMed);                                                         // We will define a new variable based on the Average readings from the Sensor, that will help us 
                                                                                // define the trigger value.
  Serial.write("Trigger Limit will be: ");                                      // Text that will be written to the Serial Monitor.
  Serial.println(limite);                                                       // Variable value that will be written to the Serial Monitor.
}                                                                               

                                                                                // This is where the Initialization Ends.

void loop() {
  val = analogRead(sensorPin);                                                  // Store the value from sensorPin in variable called "val"
  if (val >= limite && estado == 0) {                                           // We need 2 things to happen if we want to close the Servo Motor (remember we started with an "open" Servo):
                                                                                // 1.- Reading from the sensor (val) reaches a trigger limit (greater than variable called limit) AND 
                                                                                // 2.- The Servo Motor is open.
                                                                                // Then we will write it on the Serial Monitor.
    Serial.write("Value from Sensor is: ");                                     // Text that will be written to the Serial Monitor.
    Serial.println(val);                                                        // Variable value that will be written to the Serial Monitor.
                                                                                
                                                                                // Next we need to change that same reading to something the servo can interpret as "Fully Open" and "Fully Closed".
                                                                                // For this we will use a function called MAP.
                                                                                
    val = map(val, sensorMin, sensorMax, 8, 170);                               // Here we are calling the MAP function on the values from our variables, and the "Fully Open" and "Fully Closed" values for the Servo.
    Serial.write("Value that will be passed to the Servo is: ");                // Text that will be written to the Serial Monitor.
    Serial.println(val);                                                        // Variable value that will be written to the Serial Monitor.
    val = (2050);                                                               // Here we max out that value, as it is not proportional.
    digitalWrite(4, HIGH);                                                      // Turn LED (on pin 4) ON
    myservo.writeMicroseconds(val);                                             // Actually tell the Servo Motor to go to that maximized value.
    delay(2500);                                                                // A little time delay so the Servo Motor can reach its final position. Again, in miliseconds.
    digitalWrite(4, LOW);                                                       // Turn LED (on pin 4) OFF
    Serial.write("Hand has Closed");                                            // Text that will be written to the Serial Monitor.
    Serial.println("");                                                         // Jump to the next line.
    estado = 1;                                                                 // We update our state to a new value that represents a closed hand.
    Serial.write("The hand status is: (0=open, 1=closed)  ");                   // Text that will be written to the Serial Monitor.
    Serial.println(estado);                                                     // Variable value that will be written to the Serial Monitor.

  }                                                                             // Otherwise, if the trigger limit is reached, but the hand is closed, we need to open it, therefore, we 
                                                                                // rewrite the value of "val" to the equivalent of "Fully Closed" for the Servo.
  
  else if(val >= limite && estado == 1) {                                       // Everything is repeated from now on
    Serial.write("Value from Sensor is: ");                                     // Text that will be written to the Serial Monitor.
    Serial.println(val);                                                        // Variable value that will be written to the Serial Monitor.
    
    val = map(val, sensorMin, sensorMax, 8, 170);                               // Here we are calling the MAP function on the values from our variables, and the "Fully Open" and "Fully Closed" values for the Servo.
    Serial.write("El valor proporcional a pasar al servo es: ");                // Text that will be written to the Serial Monitor.
    Serial.println(val);                                                        // Variable value that will be written to the Serial Monitor.
    val = (950);                                                                // Here we max out that value, as it is not proportional.
    digitalWrite(4, HIGH);                                                      // Turn LED (on pin 4) ON
    myservo.writeMicroseconds(val);                                             // Actually tell the Servo Motor to go to that maximized value.
    delay(2500);                                                                // A little time delay so the Servo Motor can reach its final position. Again, in miliseconds.
    digitalWrite(4, LOW);                                                       // Turn LED (on pin 4) OFF
    Serial.write("Hand has Opened");                                           // Text that will be written to the Serial Monitor.
    Serial.println("");                                                         // Jump to the next line.
    estado = 0;                                                                 // We update our state to a new value that represents an open hand.
    Serial.write("The hand status is: (0=open, 1=closed)  ");                   // Text that will be written to the Serial Monitor.
    Serial.println(estado);                                                     // Variable value that will be written to the Serial Monitor.
  }
    //delay(1500);                                                              // A little delay so we can take a new reading from the Sensor. Again, in miliseconds.
  }
  

