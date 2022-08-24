#define BLYNK_TEMPLATE_ID "TMPLiRKjjJ4b"
#define BLYNK_DEVICE_NAME "servo"
#define BLYNK_AUTH_TOKEN "XwqtT26HeVEuqCChdZUCoddp42CjWZz-"


#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

#include <Servo.h>



Servo servo;



char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "venkat";
char pass[] = "venkat@1";


void setup()

{

  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);



  servo.attach(15,700,2300); // NodeMCU D8 pin

  

 }

  

void loop()

{

  Blynk.run();
}

BLYNK_WRITE(V1)

{

   servo.write(param.asInt());

}



BLYNK_WRITE(V2)

{

  servo.write(0);

}

BLYNK_WRITE(V3)

{

  servo.write(90);

}
