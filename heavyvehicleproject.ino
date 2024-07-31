#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define trigPin 9

#define echoPin 8

Servo servo;

int sound = 250;
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
lcd.init();
lcd.backlight();
lcd.setCursor(0,0);
lcd.clear();

Serial.begin (9600);

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

servo.attach(4);

}

void loop() {

long duration, distance;

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1; 
if (distance < 20) {

Serial.print(distance);

Serial.println(" cm");

Serial.println("DON'T GO FORWARD!");
lcd.print("DON'T GO FORWARD! ");


lcd.setCursor(0,1);
lcd.print("TURN RIGHT");




delay(500);
lcd.clear();


servo.write(35);

}

else if (distance<71) {

Serial.print(distance);

Serial.println(" cm");
Serial.println("Happy ourney!");
lcd.print("Happy Journey!!!");

lcd.setCursor(3,1);
delay(500);

lcd.clear();


servo.write(140); }

else {

Serial.println("The distance is more than 180cm");

}

delay(500);

}
