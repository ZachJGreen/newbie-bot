// Address :14:3:508ba

#include "Move.h"

int state;
int beeppin = 13;


int pwm1 = 6;
int pwm2 = 5;;
int dir1 = 7;
int dir2 = 4;

Move move(pwm1, pwm2, dir1, dir2);

void setup() {
  Serial.begin(38400);
  pinMode(beeppin, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  move.power(120);
}

void loop() {
  if(Serial.available()>0){
    state = Serial.read();
  }

  if (state == '0'){
    digitalWrite(4, HIGH);
  }
  else if(state == '1'){
    digitalWrite(5, HIGH); 
  }
  else {
    digitalWrite(4, LOW);
    digitalWrite(5,LOW);
  }

  /*
  else if (state == '1'){
    move.backward();
  }
  else if (state == '2'){
    move.left();
  }
  else if (state == '3'){
    move.right();
  }
  else if (state == '4'){
    move.northeast();
  }
  else if (state == '5'){
    move.northwest();
  }
  else if (state == '6'){
    digitalWrite(beeppin, HIGH);
    delay(10);
    digitalWrite(beeppin, LOW);
    delay(200);
    digitalWrite(beeppin, HIGH);
    delay(10);
    digitalWrite(beeppin, LOW);
  }
  else {
    move.halt();
  }
  */
}
