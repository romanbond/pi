// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 
// Found with http://www.thingiverse.com/thing:212742
// Modified 4/18/15 for use with Lite Arm i2- by Armatec <Lance Pierson> armatecgroup@gmail.com
// http://www.thingiverse.com/thing:480446

#include <Servo.h> 
 
Servo myservo0;  // create servo object to control a servo 
Servo myservo1;
Servo myservo2;
Servo myservo3;


int potpin0 = 0;  // analog pin used to connect the potentiometer
int potpin1 = 1;
int potpin2 = 2;
int potpin3 = 3;


int val0;    // variable to read the value from the analog pin 
int val1;
int val2;
int val3;


 
void setup() 
{ 
 
  myservo0.attach(9);  // attaches the servo on pin 0 to the servo object 
  myservo1.attach(10);  
  myservo2.attach(11);
  myservo3.attach(6);  

}
void loop() 
{ 
   val0 = analogRead(potpin0);            // reads the value of the potentiometer (value between 0 and 1023) 
  val0 = map(val0, 500, 900, 90, 179);     // scale it to use it with the servo (value between 0 and 180) 
  myservo0.write(val0);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 

  val1 = analogRead(potpin1); 
  val1 = map(val1, 400, 1300, 0, 179);
  myservo1.write(val1);
  delay(15); 

 val2 = analogRead(potpin2); 
  val2 = map(val2, 0, 1379, 0, 179);
  myservo2.write(val2);
  delay(15); 

  val3 = analogRead(potpin3); 
  val3 = map(val3, 0, 1379, 0, 179);
  myservo3.write(val3);
  delay(15); 
  

  
} 

/*   Here is the original code:
// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo0;  // create servo object to control a servo 
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
Servo myservo7;

int potpin0 = 0;  // analog pin used to connect the potentiometer
int potpin1 = 1;
int potpin2 = 2;
int potpin3 = 3;
int potpin4 = 4;
int potpin5 = 5;
int potpin6 = 6;
int potpin7 = 7;

int val0;    // variable to read the value from the analog pin 
int val1;
int val2;
int val3;
int val4;
int val5;
int val6;
int val7;

 
void setup() 
{ 
 
  myservo0.attach(0);  // attaches the servo on pin 0 to the servo object 
  myservo1.attach(1);  
  myservo2.attach(2);
  myservo3.attach(3);  
  myservo4.attach(4);
  myservo5.attach(5);
  myservo6.attach(6);
  myservo7.attach(7);
}
void loop() 
{ 
   val0 = analogRead(potpin0);            // reads the value of the potentiometer (value between 0 and 1023) 
  val0 = map(val0, 500, 900, 90, 160);     // scale it to use it with the servo (value between 0 and 180) 
  myservo0.write(val0);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 

  val1 = analogRead(potpin1); 
  val1 = map(val1, 400, 1300, 0, 179);
  myservo1.write(val1);
  delay(15); 

 val2 = analogRead(potpin2); 
  val2 = map(val2, 0, 1379, 0, 179);
  myservo2.write(val2);
  delay(15); 

  val3 = analogRead(potpin3); 
  val3 = map(val3, 0, 1379, 0, 179);
  myservo3.write(val3);
  delay(15); 
  
  val4 = analogRead(potpin4); 
  val4 = map(val4, 0, 1379, 0, 179);
  myservo4.write(val4);
  delay(15); 
 
  val5 = analogRead(potpin5); 
  val5 = map(val5, 0, 1379, 0, 179);
  myservo5.write(val5);
  delay(15); 
  
  val6 = analogRead(potpin6); 
  val6 = map(val6, 0, 1379, 0, 179);
  myservo6.write(val6);
  delay(15); 
 
  val7 = analogRead(potpin7); 
  val7 = map(val7, 0, 1379, 0, 179);
  myservo7.write(val7);
  delay(15); 
  
} 

