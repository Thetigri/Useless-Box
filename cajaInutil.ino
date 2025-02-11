//Written By Nikodem Bartnik - nikodembartnik.pl
#include <Servo.h>
#define SWITCH_PIN 6
#define SERVO_PIN 9
#define IR_PIN 5
#include "IRremote.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"


Servo myServo;
int step_number = 0,SWITCH;
long opcion;
void setup() {
  
pinMode(SWITCH_PIN, INPUT);
myServo.attach(SERVO_PIN);
myServo.write(80);
Serial.begin(9600);
Serial.println("IR Receiver Button Decode"); 
 IrReceiver.begin(IR_PIN,true);
}

void opcionElegida(long rand){
  switch(rand){
    case 1:
    myServo.write(30);
    delay(300);
    myServo.write(80);
    delay(300);
    
    break;
    case 2:
    myServo.write(50);
    delay(300);
    myServo.write(80);
    delay(2000);
    myServo.write(30);
    delay(300);
    myServo.write(80);
    delay(300);
    break;
    case 3:
    myServo.write(25);
    delay(300);
    for(int i=30;i<81;i++){
      myServo.write(i);
      delay(200);}
    break;
    case 4:
    myServo.write(45);
    delay(1000);
    myServo.write(30);
    delay(1000);
    myServo.write(80);
    delay(200);
    break;
    case 5:
    myServo.write(45);
    delay(300);
    break;
    case 6:
    myServo.write(30);
    delay(300);
    break;
    case 7:
    for(int i=0;i<10;i++){
      myServo.write(50);
      delay(200);
      myServo.write(60);
      delay(200);
    }
    myServo.write(80);
    break;
    case 8:
    for(int i=30;i<81;i++){
      myServo.write(i);
      delay(200);}
    break;
    case 9:
    myServo.write(80);
    delay(300);
    break;
    break;
  }
}
void loop() {

  if(digitalRead(SWITCH_PIN)==1){
    for(int i=0;i<50;i++){
      decodeIR();
      delay(10);
    }
    opcionElegida(random(0,4));
    delay(200);
  }
  decodeIR();
  
    
}
void decodeIR(){
    if (IrReceiver.decode()) {// have we received an IR signal?
    opcion=IrReceiver.decodedIRData.decodedRawData;
    Serial.println(opcion);
    IrReceiver.resume(); 
    if(opcion==-217252096){
    opcionElegida(1);
    }
    if(opcion==-417792256){
    opcionElegida(2);
    }
    if(opcion==-1587609856){
    opcionElegida(3);
    }
    if(opcion==-150405376){
    opcionElegida(4);
    } 
    if(opcion==-484638976){
    opcionElegida(5);
    } 
    if(opcion==-1520763136){
    opcionElegida(6);
    } 
    if(opcion==-1119682816){
    opcionElegida(7);
    } 
    if(opcion==-1387069696){
    opcionElegida(8);
    } 
    if(opcion==-1253376256){
    opcionElegida(9);
    } 
  }
}