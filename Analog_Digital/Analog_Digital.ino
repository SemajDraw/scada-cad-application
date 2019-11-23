  int sensorValue = 0;  // value read from the pot
  int sensorValue1 = 0;
  int sensorValue2 = 0;
  int sensorValue3 = 0;
  int sensorValue4 = 0;
     
  char outputValue = 0;
  char outputValue1 = 0;
  char outputValue2 = 0;
  char outputValue3 = 0;
  char outputValue4 = 0;
     
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(20000); 
  for (int pin=2;pin<=18;pin++)
  { pinMode(pin,INPUT);
  digitalWrite(pin,HIGH);}

}

void loop() {
    
  sensorValue = analogRead(A0);
  sensorValue1 = analogRead(A1);
  sensorValue2 = analogRead(A2);
  sensorValue3 = analogRead(A3);
  sensorValue4 = analogRead(A4);
     
if (Serial.available())
{
  if(Serial.read()=='H')
  {
    Serial.flush();
    char bOne=0;
    char bTwo=0;
    
    digitalWrite(13,!(digitalRead(13)));
    
    if(digitalRead(2)) bitSet(bOne,0);
    if(digitalRead(3)) bitSet(bOne,1);
    if(digitalRead(4)) bitSet(bOne,2);
    if(digitalRead(5)) bitSet(bOne,3);
    if(digitalRead(6)) bitSet(bOne,4);
    if(digitalRead(7)) bitSet(bOne,5);
    if(digitalRead(8)) bitSet(bOne,6);
    if(digitalRead(9)) bitSet(bOne,7);
    if(digitalRead(10)) bitSet(bTwo,0);
    if(digitalRead(11)) bitSet(bTwo,1);
    if(digitalRead(12)) bitSet(bTwo,2);
    

   if(analogRead(A0)) bitSet(bTwo,3);
   if(analogRead(A1)) bitSet(bTwo,4);
   if(analogRead(A2)) bitSet(bTwo,5);
   if(analogRead(A3)) bitSet(bTwo,6);
   if(analogRead(A4)) bitSet(bTwo,7);
      
   outputValue =  map(sensorValue,0,1023,0,255);
   outputValue1 =  map(sensorValue1,0,1023,0,255);
   outputValue2 =  map(sensorValue2,0,1023,0,255);
   outputValue3 =  map(sensorValue3,0,1023,0,255);
   outputValue4 =  map(sensorValue4,0,1023,0,255);
     
   Serial.write(10);
   Serial.write(bOne);
   Serial.write(bTwo);
   Serial.write(outputValue);
   Serial.write(outputValue1);
   Serial.write(outputValue2);
   Serial.write(outputValue3);
   Serial.write(outputValue4);
   Serial.write(10);
    delay(200);
   
    //Serial.flush();
  }
  
  }
        
}
