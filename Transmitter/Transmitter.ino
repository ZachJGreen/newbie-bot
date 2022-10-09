// Address :14:3:508ba

#define joyX A0
#define joyY A1
#define beeppin A2
int xValue, yValue, beep;

void setup() {
  Serial.begin(38400);
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
  pinMode(beeppin, INPUT_PULLUP);

}

void loop() {

  beep = digitalRead(beeppin);
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);

  if (yValue > 600 and xValue < 600 and xValue > 400) {
    Serial.write('0'); // forward
  }
  else if (yValue < 400 and xValue < 600 and xValue > 400) {
    Serial.write('1'); // backward
  }
  else if (xValue > 600 and yValue < 600 and yValue > 400){
    Serial.write('2'); // left
  }
  else if (xValue < 400 and yValue < 600 and yValue > 400){
    Serial.write('3'); // right
  }
  else if (xValue < 400 and yValue > 600){
    Serial.write('4'); // Diagonal Up Right
  }
  else if (xValue > 600 and yValue > 600){
    Serial.write('5'); // Diagonal Up Left
  }

  if (beep == LOW){
    Serial.write('6');
    delay(100);
  }
  
  if (yValue < 600 and xValue<600 and yValue > 400 and xValue > 400){
    Serial.write('7'); // halt
  }
  delay(10);
}
