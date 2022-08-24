#define BLYNK_TEMPLATE_ID "xxxxxxxx"
#define BLYNK_DEVICE_NAME "yyyyyyyy"
#define BLYNK_AUTH_TOKEN "zzzzzzzz"
#define BLYNK_PRINT Serial

#define RelayPin 14 //(Master)

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "SSID";
char pass[] = "Password";

Servo s1;
Servo s2;
Servo s3;

BLYNK_WRITE(V1) //virtual pin
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



void setup()
{

  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  
  s1.attach(16,700,2300); // D0
  s2.attach(5,700,2300); // D1
  s3.attach(4,700,2300); // D2
  
  
  
}

void loop()
{
  Blynk.run();
}
