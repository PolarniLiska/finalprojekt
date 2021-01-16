#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include "index.h"
 
const char* ssid = "Wifi Honza";
const char* password = "honzik2001";
 
ESP8266WebServer server(80);
 
void handleRoot() {
String s = webstranka;
server.send(200, "text/html", s);
}
 
void handleADC() {
int rain = analogRead(A0);
String adc = String(rain);

String data = "{\"Rain\":\""+String(rain)+"\"}";
server.send(200,"text/plane",data);

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
server.begin();
Serial.println("Server se spustil");
}
 
void loop(){
server.handleClient();
}