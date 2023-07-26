//declaring the pins 
#include <LiquidCrystal.h>
#define trigpin1 7
#define trigpin2 9
#define echopin1 6
#define echopin2 8
const int buzzer=1;
int count=0;
long distance1,distance2,duration1,duration2;
int max_people=5;          //be permissible no. of people

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(trigpin1,OUTPUT);
  pinMode(trigpin2,OUTPUT);
  pinMode(echopin1,INPUT);
  pinMode(echopin2,INPUT);
  pinMode(buzzer,OUTPUT);
  lcd.begin(16, 2); 
}

void loop() {
  //for alert system
  if (count>max_people){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("!!ALERT!!");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
    lcd.setCursor(0,0);
    lcd.print("PEOPLE EXCEEDED");
    lcd.setCursor(0,1);
    lcd.print(count);
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
  }
  else{
  	lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("people inside");
  	lcd.setCursor(0,1);
  	lcd.print(count);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("people can enter");
    lcd.setCursor(0,1);
    lcd.print(max_people-count);
    delay(1000);
  }
  //activating sensor in outside for entering person
  digitalWrite(trigpin1,LOW);
  
  delayMicroseconds(2);
  digitalWrite(trigpin1,HIGH);
  
  delayMicroseconds(10);
  digitalWrite(trigpin1,LOW);
    
  duration1=pulseIn(echopin1,HIGH);
  
  distance1=duration1/2/29.1;
  
  if (distance1<30)
  {
    count++;
    delay(1000);        //providing time for enter
  }
  else{ 
    //activating sensor in outside for entering person
  	digitalWrite(trigpin2,LOW);
  	delayMicroseconds(2);
  	digitalWrite(trigpin2,HIGH);
  	delayMicroseconds(10);
  	digitalWrite(trigpin2,LOW);
  	duration2=pulseIn(echopin2,HIGH);
  	distance2=duration2/2/29.1;
    if (distance2<30){
      count--;
      delay(1000);        //providing time for enter
    }
  	
  } 
}
 
