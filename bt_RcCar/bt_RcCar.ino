#include "Move.h"

int up=2, right=3, down=4, left=5;
int pwm1=9, pwm2=6, dir1=8, dir2=7;
char state='0';

 Move move(pwm1,pwm2,dir1,dir2);

void setup() {
 
  move.power(90);
  
  pinMode(up, OUTPUT);
  pinMode(down, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  Serial.begin(38400);
}

void loop() {
 


  if(Serial.available()>0){
    state = Serial.read();
    digitalWrite(up, HIGH);
  } 
  else{
    digitalWrite(up, LOW);
    //move.halt();  
  }


  if(state == 'n'){
    move.forward();
  }
  else if(state == 'e'){
    move.right();
  }
  else if(state =='r')
  {
    analogWrite(pwm1, move.getPower()/2);
  analogWrite(pwm2, move.getPower());
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, LOW);
  }
  else if(state =='l')
  {
    analogWrite(pwm1, move.getPower());
  analogWrite(pwm2, move.getPower()/2);
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, LOW);
  }
  else if(state == 's'){
    move.backward();
  }
  else if(state == 'w'){
    move.left(); 
  }
  else if(state == '0'){
    move.halt();  
  }

  }
