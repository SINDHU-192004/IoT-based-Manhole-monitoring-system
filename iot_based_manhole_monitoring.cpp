#define BLYNK_TEMPLATE_ID "TMPL36e-R2KBa" 
#define BLYNK_TEMPLATE_NAME "MANHOLE2"
#define BLYNK_AUTH_TOKEN "VrTXzaNZY3kO-XjXqhq3Pr8wg3a8jrEY" 
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>
#include <NewPing.h> // Library for the ultrasonic sensor



#define sensor D5 
#define ECHOPIN D7 
#define TRIGPIN D6 int sensorPin = A0;


char auth[] = "VrTXzaNZY3kO-XjXqhq3Pr8wg3a8jrEY"; 
char ssid[] = "Redmi 9 Power"; // Type your wifi name 
char pass[] = "756f9bf538c2"; // Type your wifi password


BlynkTimer timer;

NewPing sonar(TRIGPIN, ECHOPIN, 200); // Max distance set to 200 cm 
void setup() {
Serial.begin(9600); 
pinMode(sensor, INPUT);
pinMode(ECHOPIN, INPUT_PULLUP); 
pinMode(TRIGPIN, OUTPUT);
 
digitalWrite(ECHOPIN, HIGH); 
Blynk.begin(auth, ssid, pass); 
timer.setInterval(2500L, sendSensor);
}

void sendSensor() {

int readings = digitalRead(sensor); 
int val = analogRead(A0); 
digitalWrite(TRIGPIN, LOW); 
delayMicroseconds(2); 
digitalWrite(TRIGPIN, HIGH); 
delayMicroseconds(15); 
digitalWrite(TRIGPIN, LOW);
int distance1 = pulseIn(ECHOPIN, HIGH, 26000); 
int distance = distance1 / 58; 
Serial.print("Distance: ");
Serial.print(distance); 
Serial.println(" cm"); 
Blynk.virtualWrite(V0, distance); 
Blynk.virtualWrite(V1, val); 
Blynk.virtualWrite(V2, readings); 
if (readings == 1) { 
Serial.println("Tilt Detected");
Blynk.logEvent("tilt_alert", "Tilt Detected");
}

if (distance <= 20) {
Serial.println("Water Level Reached"); Blynk.logEvent("water_alert", "Water Level Reached");
}

if (val > 500) { Serial.println(val); Serial.println("Gas Detected");
Blynk.logEvent("gas_alert", "Gas Detected");

}

}

void loop() { Blynk.run();
timer.run();

}
