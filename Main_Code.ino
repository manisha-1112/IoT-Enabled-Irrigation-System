/************** IoT-Enabled Smart Irrigation System **************/
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <LiquidCrystal.h>
#include <DHT.h>

// ---------------- WiFi + Blynk Setup ----------------
char auth[] = "X7f8dK9L3mQ2wT1zV6pB5aN0cR";   
char ssid[] = "SmartFarm_IoT_WiFi";         
char pass[] = "Manisha484#";              


// ---------------- Pin Definitions ----------------
#define SOIL_PIN A0
#define RELAY_PIN D1
#define DHTPIN D2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int threshold = 410;  // Soil moisture threshold
int pumpStatus = 0;   // 0 = OFF, 1 = ON

BlynkTimer timer;

// ---------------- Pump Control Function ----------------
void controlPump() {
  int moisture = analogRead(SOIL_PIN);
  float temp = dht.readTemperature();
  float humid = dht.readHumidity();

  // Send data to Blynk App
  Blynk.virtualWrite(V1, moisture);
  Blynk.virtualWrite(V2, temp);
  Blynk.virtualWrite(V3, humid);
  Blynk.virtualWrite(V4, pumpStatus);

  // LCD Display
  lcd.setCursor(0,0);
  lcd.print("M:"); lcd.print(moisture);
  lcd.print(" T:"); lcd.print(temp,0); lcd.print((char)223); lcd.print("C");
  
  lcd.setCursor(0,1);
  lcd.print("H:"); lcd.print(humid,0); lcd.print("% P:");

  if (moisture > threshold && pumpStatus == 0) {
    digitalWrite(RELAY_PIN, HIGH);  // Pump ON
    pumpStatus = 1;
    Blynk.notify("Pump Turned ON - Soil Dry");
  } else if (moisture <= threshold && pumpStatus == 1) {
    digitalWrite(RELAY_PIN, LOW);   // Pump OFF
    pumpStatus = 0;
    Blynk.notify("Pump Turned OFF - Soil Wet");
  }

  lcd.print(pumpStatus ? "ON " : "OFF");
}

// ---------------- Manual Control from App ----------------
BLYNK_WRITE(V5) {
  int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(RELAY_PIN, HIGH);
    pumpStatus = 1;
  } else {
    digitalWrite(RELAY_PIN, LOW);
    pumpStatus = 0;
  }
}

// ---------------- Setup ----------------
void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  lcd.begin(16,2);
  lcd.print("Smart Irrigation");
  dht.begin();

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2000L, controlPump); // every 2 sec
}

// ---------------- Loop ----------------
void loop() {
  Blynk.run();
  timer.run();
}
