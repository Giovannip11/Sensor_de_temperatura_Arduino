#include <OneWire.h>      
#include <DallasTemperature.h>
#include <LiquidCrystal.h>    


#define ONE_WIRE_BUS 2


OneWire oneWire(ONE_WIRE_BUS);


DallasTemperature sensors(&oneWire);


LiquidCrystal lcd(7, 6, 5, 4, 3, 8);

void setup() {
  Serial.begin(9600);  
  sensors.begin();      
  lcd.begin(16, 2);   
  lcd.print("Medindo temp...");
  delay(1000);
  lcd.clear();
}

void loop() {
 
  sensors.requestTemperatures();
  
  // Captura a temperatura em Celsius
  float tempC = sensors.getTempCByIndex(0);
  

  float tempF = (tempC * 9.0 / 5.0) + 32.0;
  float tempK = tempC + 273.15;

  Serial.print("Celsius: ");
  Serial.print(tempC);
  Serial.print(" *C  |  Fahrenheit: ");
  Serial.print(tempF);
  Serial.print(" *F  |  Kelvin: ");
  Serial.print(tempK);
  Serial.println(" K");


  lcd.setCursor(0, 0);
  lcd.print("C:");
  lcd.print(tempC);
  lcd.print((char)223); 
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("F:");
  lcd.print(tempF);
  lcd.print((char)223);
  lcd.print("F");

  delay(2000); 

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("K:");
  lcd.print(tempK);
  lcd.print(" K");

  delay(2000); 
  lcd.clear();
}
