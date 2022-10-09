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
    
  }

      
      Serial.println((state));
     
    
      if(state=='1')
      {
        digitalWrite(up, HIGH);
        move.forward();
        
      }
      else if(state==2)
      {
        digitalWrite(right, HIGH);
      }
      else if(state=='3')
      {
        digitalWrite(down, HIGH);
      }
      else if(state==4)
      {
        digitalWrite(left, HIGH);
        
      }
      else
      {
        digitalWrite(up, LOW);
        digitalWrite(right, LOW);
        digitalWrite(down, LOW);
        digitalWrite(left, LOW);
        move.halt();
      }

      
      {
        
      }
//    
//    if(Serial.state()==1)
//    {
//      
//    }
//    if(Serial.state()==0)
//    {
//      digitalWrite(led, LOW);
//      
//    }

  }
