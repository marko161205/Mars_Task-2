const int dirPin = 2;
const int enPin = 8;
const int pulPin = 5;
const int stepsPerRevolution = 1600;
int ir1Pin = 4;
int ir2Pin = 6;
int ir2 = 3;
int ir1Val;
int ir2Val;
void setup()
{
  pinMode(ir2, OUTPUT);
  pinMode(ir1Pin,INPUT);
  pinMode(ir1Pin,INPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(pulPin,OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);
  Serial.begin(9600);

}
void loop()
{
  digitalWrite(ir2,HIGH);
  ir1Val = digitalRead(ir1Pin);
  ir2Val = digitalRead(ir2Pin);
  if(ir1Val && !ir2Val)
  {
    digitalWrite(dirPin,HIGH);
    for (int i=0; i < stepsPerRevolution; i++) {
      // These four lines result in 1 step:
      digitalWrite(pulPin, HIGH);
      delayMicroseconds(500);
      digitalWrite(pulPin, LOW);
      delayMicroseconds(500);
    }
  }
  if(ir2Val && !ir1Val)
  {
    digitalWrite(dirPin,LOW);
    for (int i=0; i < stepsPerRevolution; i++) {
      // These four lines result in 1 step:
      digitalWrite(pulPin, HIGH);
      delayMicroseconds(500);
      digitalWrite(pulPin, LOW);
      delayMicroseconds(500);
    }
  }


}