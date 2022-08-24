#define BLYNK_TEMPLATE_ID "TMPL2w7mZgq-"
#define BLYNK_DEVICE_NAME "ARRV Manipulator"
#define BLYNK_AUTH_TOKEN "tVMluJlutoDhL7m6e9xWBTRQTKLqd27R"
#define BLYNK_PRINT Serial

#define RelayPin 14 //relay
#define pr1 12      //IN1
#define pr2 13      //IN2
#define en 15

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "xx";
char pass[] = "xx";

Servo s1;
Servo s2;
Servo s3;
bool relay_state = LOW;
int IN1;
int IN2;
int switc =1;
BLYNK_WRITE(V1)
{
  s1.write(param.asInt());
}

BLYNK_WRITE(V2)
{
  s2.write(param.asInt());
}

BLYNK_WRITE(V3)
{
  s3.write(param.asInt());
}
BLYNK_WRITE(V0)
{
  relay_state = param.asInt();
  if(relay_state == 1)
  {
    digitalWrite(RelayPin, HIGH);
  }
  else 
  { 
    digitalWrite(RelayPin, LOW);
  }
  
}
BLYNK_WRITE(V4) //Prismatic up
{
  IN1 = param.asInt();
  Serial.println(IN1);
  if(IN1 == 1 && switc==1)
  {
    digitalWrite(en,HIGH);
    digitalWrite(pr1,HIGH);
    digitalWrite(pr2,LOW);
    delay(9000);
    digitalWrite(en,LOW);
    switc=0;
  }
}
BLYNK_WRITE(V5) //Prismatic down
{
  IN2 = param.asInt();
  if(IN2 == 1 && switc==0)
  {
    digitalWrite(en,HIGH);
    digitalWrite(pr1,LOW);
    digitalWrite(pr2,HIGH);
    delay(9000);
    digitalWrite(en,LOW);
    switc=1;
  }
}

void setup()
{

  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  
  pinMode(RelayPin,OUTPUT);
  pinMode(pr1,OUTPUT);
  pinMode(pr2,OUTPUT);
  pinMode(en,OUTPUT);
  digitalWrite(RelayPin,LOW);
  s1.attach(2,700,2300); // D4
  s2.attach(16,700,2300); // D0
  s3.attach(5,700,2300); // D1
  
  
}

void loop()
{
  Blynk.run();
}
