
#include <OneWire.h>
#include <DallasTemperature.h>
const int oneWireBus = 23; 
#define AOUT_PIN 34  // ESP32 pin GIOP36 (ADC0) that connects to AOUT pin of moisture sensor
#define THRESHOLD 4002

OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensors.begin();

}

void loop() {
   sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  float temperatureF = sensors.getTempFByIndex(0);
   Serial.println (" the temperature is :");
  Serial.print(temperatureC);
 
  Serial.println("ºC");
  Serial.print(temperatureF);
  Serial.println("ºF");
  delay(500);

  // put your main code here, to run repeatedly:
  //int value = analogRead(AOUT_PIN); // read the analog value from sensor
  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(AOUT_PIN);
  Serial.println(sensor_analog);
  moisture_percentage = ( 100 - ( (sensor_analog/4095.00) * 100 ) );
  
  
   Serial.println(" the statue of the soil:");
 
  if (sensor_analog > THRESHOLD)
   Serial.println("the soil is dry as it has the highest resistance :");
  
  else
    Serial.println("The soil is WET ");
   
    //Serial.println(value);

  //Serial.println("");
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print("%\n\n");
  delay(1000);


  delay(500);
  

}
