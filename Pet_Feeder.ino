#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo;
Servo kservo;
int m;
int gateStart = 90;
int gateEnd = 180;
int gateOpenTime = 200;

char auth[] = "gyFYeygYpetXZhg9MGUFgTB-GK_KCPjO";
char ssid[] = "RC KEPO";
char pass[] = "nasigoreng13k";

void setup()
{
  Serial.begin(9600);
  //Blynk.begin(auth, ssid, pass);
    Blynk.begin(auth, ssid, pass, "blynk-cloud.com",8080);
  servo.attach(15); // NodeMcu D8 Pin 
  kservo.attach(13); // NodeMcu D7 Pin
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V3)
{
  servo.write(gateEnd);
  delay(gateOpenTime);
  servo.write(gateStart);
}

BLYNK_WRITE(V0)
{
  m = param.asInt();
}


BLYNK_WRITE(V1)
{
  for(int i=0;i<=m;i++)
  {
    servo.write(gateEnd);
    delay(gateOpenTime);
    servo.write(gateStart);
  }
}

BLYNK_WRITE(V2) 
{
  int pinData = param.asInt();
  if(pinData == 1)
  {
    servo.write(gateEnd);
    delay(gateOpenTime);
    servo.write(gateStart); 
  }
}
