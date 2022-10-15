#include "Move.h"

int up=2, right=3, down=4, left=5;
int pwm1=9, pwm2=6, dir1=8, dir2=7;
char state='0';

 Move move(pwm1,pwm2,dir1,dir2);

void setup() {
 
  move.power(150);
  
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
  }


  if(state == 'n'){
    move.forward();
  }
  else if(state == 'e'){
    move.right();
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
