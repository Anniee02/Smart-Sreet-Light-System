/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. 

	The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 */
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int sensorPin = A0;
const int ledPin = 9;
int lightCal;
int lightVal;
void setup() {
  
   pinMode(ledPin, OUTPUT);
   pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  lightCal = analogRead(sensorPin);
  //we will take a single reading from the light sensor and store it in the lightCal
  //variable. This will give us a preliminary value to compare against in the loop
  
  // set up the LCD's number of columns and rows:
  
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println(lightCal);
  
}
int read_val=0;
int car=0,bus=0,truck=0,bike=0,person=0;
void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  
  lcd.clear();
  
  if(Serial.available()){
  	read_val=Serial.read();
    if(read_val!=0){
    //Serial.println(read_val);
	  lightVal = analogRead(sensorPin);
      if(lightVal<=599){
        //lcd.print(lightVal);
        if(lightVal==6){
          	lcd.print("Person/Living");
          
          	lcd.setCursor(0,1);
        	lcd.print("_thing");//single rgb led
          	digitalWrite(6,HIGH);
          	digitalWrite(7,HIGH);
          	delay(4000);
          	
          	
        }
        else if(lightVal>6 && lightVal<=300){
         
          lcd.print("Bike/Scooty");//2to rgb led
          //delay(500);
          	digitalWrite(8,HIGH);
          	digitalWrite(9,HIGH);
          	delay(1000);

		//digitalWrite(7,LOW);
          	digitalWrite(8,LOW);
          	digitalWrite(9,LOW);
        }
        else if(lightVal>300 && lightVal<=450){
         
          lcd.print("Car");

          	digitalWrite(8,HIGH);
          	digitalWrite(9,HIGH);
          	delay(2000);
          	digitalWrite(8,LOW);
          	digitalWrite(9,LOW);
        }
        else if(lightVal>450 && lightVal<=550){
         
          lcd.print("Bus");//4 te bulb
          digitalWrite(6,HIGH);
          digitalWrite(7,HIGH);
          digitalWrite(8,HIGH);
          digitalWrite(9,HIGH);
          	delay(1500);
          	digitalWrite(6,LOW);
          	digitalWrite(7,LOW);
          	digitalWrite(8,LOW);
          	digitalWrite(9,LOW);
        }
        else{
         
          lcd.print("Truck");//4 te led bulb
          digitalWrite(6,HIGH);
          digitalWrite(7,HIGH);
          digitalWrite(8,HIGH);
          	digitalWrite(9,HIGH);
          	delay(3000);
          	digitalWrite(6,LOW);
          	digitalWrite(7,LOW);
          	digitalWrite(8,LOW);
          	digitalWrite(9,LOW);
        }
      }
      else
        lcd.print("Daytime");
  	}
    else{
  	lcd.print("too far to");
    lcd.setCursor(0,1);
    lcd.print("detect");
    }
    
    delay(2000);
    
  
 // delay(2000);
  }
}
 
