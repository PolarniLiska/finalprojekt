#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include "index.html"
 
const char* ssid = "Wifi Honza";
const char* password = "honzik2001";
 
ESP8266WebServer server(80);

void handleRoot() {
String web = webstranka;
server.send(200, "text/html", web);
}
 
void handleADC() {
int rain = analogRead(A0);
int raind = analogRead(D1);
String adc = String(rain);
String adc1 = String(raind);

String data = "{\"Rain\":\""+String(rain)+"\",\"Pressuremb\":\""+String(raind)+"\"}";
server.send(200,"text/plane",data);

Serial.print("D:");
Serial.println(adc1);
Serial.print("R:");
Serial.println(adc);
}
 
void setup(){
Serial.begin(9600);
Serial.println(); 

WiFi.begin(ssid, password);
Serial.println("");

while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.print("Pripojeno k ");
Serial.println(ssid);
Serial.print("IP adresa: ");
Serial.println(WiFi.localIP());

server.on("/", handleRoot);
server.on("/readADC", handleADC);
server.on("/", setup);
server.begin();
Serial.println("Server se spustil");
}
 
void loop(){
server.handleClient();
}
