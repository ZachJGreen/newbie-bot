
int state=0;

void setup() 
{
  Serial.begin(38400);
  

}

void loop() 
{
//  Serial.write(1);
//state=analogRead(A0);
  Serial.println(analogRead(A0));

  if(analogRead(A0)>800)
  {
    Serial.println();
    Serial.write('1');
    Serial.println();
    
  }
  if(analogRead(A0)<=400)
  {
    Serial.println();
    Serial.write('3');
    Serial.println();
  }
}
