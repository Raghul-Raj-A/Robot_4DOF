int IN1 =9;
int IN2 =10;

int EN1 =8;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN1, OUTPUT);
  
}

void forward()
{
  digitalWrite(EN1, HIGH);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
}
void backward()
{
  digitalWrite(EN1, HIGH);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  forward();
  delay(2000);
  backward();
  delay(2000);
}
