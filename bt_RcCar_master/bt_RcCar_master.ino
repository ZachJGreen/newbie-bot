
int state=0;
int vert, hor;

void setup() 
{
  Serial.begin(38400);
  Serial.flush();

}

void loop() 
{
  vert = analogRead(A0);
  hor  = analogRead(A1);

  if(vert >= 800 && hor > 200 && hor < 800)
  {
    Serial.write('n');
  }
  else if(vert <= 200 && hor > 200 && hor < 800)
  {
    Serial.write('s');
  }
  else if(hor <= 200 && vert > 200 && vert < 800){
    Serial.write('w');  
  }
  else if (hor >= 800 && vert > 200 && vert < 800){
    Serial.write('e');  
  } else{
      Serial.write('0');
    }
  delay(10);
}
