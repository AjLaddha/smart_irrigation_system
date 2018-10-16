#include<LiquidCrystal.h>
#include<SoftwareSerial.h>

 #define moisture_sensorPin A0
 #define moisture_sensorPin2 A2
 #define float_switchPin A1
 #define soil_statusPin 2
 #define tank_statusPin 3
 #define motorPin1 A4
 #define motorPin2 A5
 
 LiquidCrystal lcd(13,12,11,10,9,8);
 SoftwareSerial BTserial(6,5);//rx,tx
 
 const int avg_moisture = 800; 
 int percent_moisture;
 int percent_moisture1; 
void setup() 
{
  //delay(2000);

   BTserial.begin(9600);
   Serial.begin(9600);
 lcd.begin(16,2);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print(" AUTOMATIC ");
 lcd.setCursor(0,1);
 lcd.print(" IRRIGATION S/M ");
 delay(2000);
 
 
 pinMode(moisture_sensorPin,INPUT);
 pinMode(moisture_sensorPin2,INPUT);
 pinMode(float_switchPin,INPUT);
 pinMode(soil_statusPin,OUTPUT);
 pinMode(tank_statusPin,OUTPUT);
 pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);

 digitalWrite(motorPin1,LOW);
  digitalWrite(motorPin2,LOW);
 digitalWrite(soil_statusPin,LOW);
 digitalWrite(tank_statusPin,LOW);

}

void loop() 
{
  
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print(" MOISTURE - ");
  //percent_moisture=analogRead(moisture_sensorPin);
 // percent_moisture=map(percent_moisture,1023,0,0,100);

  if(analogRead(moisture_sensorPin) > avg_moisture&&analogRead(moisture_sensorPin2) > avg_moisture){
  lcd.print("LOW");
  digitalWrite(soil_statusPin,HIGH);
  percent_moisture=analogRead(moisture_sensorPin);
  percent_moisture=map(percent_moisture,1023,0,0,100);
  percent_moisture1=analogRead(moisture_sensorPin2);
  percent_moisture1=map(percent_moisture1,1023,0,0,100);
  BTserial.print((percent_moisture1+percent_moisture)/2);
  BTserial.print(";");
  //BTSerial.print("%");
  }
 
  if(analogRead(moisture_sensorPin) < avg_moisture&&analogRead(moisture_sensorPin2) < avg_moisture){
  lcd.print("HIGH");
//lcd.print(percent_moisture);
  //lcd.print("%");  
  digitalWrite(soil_statusPin,LOW);
  percent_moisture=analogRead(moisture_sensorPin);
  percent_moisture=map(percent_moisture,1023,0,0,100);
  
  percent_moisture1=analogRead(moisture_sensorPin2);
  percent_moisture1=map(percent_moisture1,1023,0,0,100);
  BTserial.print((percent_moisture1+percent_moisture)/2);
  BTserial.print(";");
  //Serial.print("%");
  }



 
  lcd.setCursor(0,1);
  lcd.print("TANK LEVEL- ");
 
 if( digitalRead(float_switchPin) == HIGH){
  lcd.print("LOW");
  digitalWrite(tank_statusPin,HIGH);
  }
 
  if( digitalRead(float_switchPin) == LOW){
  lcd.print("HIGH");
  digitalWrite(tank_statusPin,LOW);}


  digitalWrite(motorPin1,LOW);
  digitalWrite(motorPin2,LOW);
 

 /*if(analogRead(moisture_sensorPin) < avg_moisture && digitalRead(float_switchPin) == HIGH)
 { 
   while(analogRead(moisture_sensorPin) < avg_moisture && digitalRead(float_switchPin) == HIGH)
   { 
    lcd.setCursor(0,0);
    lcd.print(" MOISTURE - HIGH");
    lcd.setCursor(0,1);
    digitalWrite(soil_statusPin,LOW);
    digitalWrite(tank_statusPin,HIGH); 
    digitalWrite(motorPin1,HIGH);
    digitalWrite(motorPin2,LOW);  
   }
   if(analogRead(moisture_sensorPin) > avg_moisture)
   {
    lcd.setCursor(0,0);
    lcd.print(" MOISTURE - HIGH");
    lcd.setCursor(0,1);
    lcd.print(" MOTOR - OFF "); 
    digitalWrite(soil_statusPin,HIGH);
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2,LOW);
    delay(3000);
   }
    if(digitalRead(float_switchPin) == LOW)
    {
      lcd.setCursor(0,0);
      lcd.print(" TANK LEVEL- LOW");
      lcd.setCursor(0,1);
      lcd.print(" MOTOR - OFF "); 
      digitalWrite(tank_statusPin,HIGH);
      digitalWrite(motorPin1,LOW);
      digitalWrite(motorPin2,LOW);
      delay(3000);
    }
 }*/
 delay(3000);
 if(analogRead(moisture_sensorPin) < avg_moisture&&analogRead(moisture_sensorPin2) < avg_moisture)
  {
      while(analogRead(moisture_sensorPin) < avg_moisture&&analogRead(moisture_sensorPin2) < avg_moisture)
      {
       
  /*BTserial.print((percent_moisture1+percent_moisture)/2);
  //Serial.print("%");
  BTserial.print(",");
  BTserial.print("OFF");
  BTserial.print("");*/
  if(digitalRead(float_switchPin)==HIGH)
        {
           lcd.clear();
        lcd.setCursor(0,0);
       // percent_moisture=analogRead(moisture_sensorPin);
//  percent_moisture=map(percent_moisture,1023,0,0,100);

        lcd.print("MOISTURE - HIGH");
//        lcd.print(percent_moisture);
        
        lcd.setCursor(0,1);
        lcd.print("MOTOR IS OFF");
        digitalWrite(soil_statusPin,LOW);
//        digitalWrite(tank_statusPin,LOW);
        digitalWrite(motorPin1,LOW);
  digitalWrite(motorPin2,LOW);
  percent_moisture=analogRead(moisture_sensorPin);
  percent_moisture=map(percent_moisture,1023,0,0,100); 
  
  percent_moisture1=analogRead(moisture_sensorPin2);
  percent_moisture1=map(percent_moisture1,1023,0,0,100);
          BTserial.print((percent_moisture1+percent_moisture)/2);
          BTserial.print(",");
         BTserial.print("OFF");
         BTserial.print(",");
          
         BTserial.print("LOW");
         BTserial.print(";");
         digitalWrite(tank_statusPin,HIGH);
         lcd.setCursor(0,1);
         lcd.print("TANK LVEL - LOW");
         delay(1000);
        }
   if(digitalRead(float_switchPin)==LOW)
   { 
     lcd.clear();
        lcd.setCursor(0,0);
       // percent_moisture=analogRead(moisture_sensorPin);
//  percent_moisture=map(percent_moisture,1023,0,0,100);

        lcd.print("MOISTURE - HIGH");
//        lcd.print(percent_moisture);
        
        lcd.setCursor(0,1);
        lcd.print("MOTOR IS OFF");
        digitalWrite(soil_statusPin,LOW);
//        digitalWrite(tank_statusPin,LOW);
        digitalWrite(motorPin1,LOW);
  digitalWrite(motorPin2,LOW);
  percent_moisture=analogRead(moisture_sensorPin);
  percent_moisture=map(percent_moisture,1023,0,0,100); 
  
  percent_moisture1=analogRead(moisture_sensorPin2);
  percent_moisture1=map(percent_moisture1,1023,0,0,100);
          BTserial.print((percent_moisture1+percent_moisture)/2);
          BTserial.print(",");
         BTserial.print("OFF");
         BTserial.print(",");
          
         BTserial.print("HIGH");
         BTserial.print(";");
         digitalWrite(tank_statusPin,LOW);
         lcd.setCursor(0,1);
         lcd.print("TANK LVEL - HIGH");
         delay(1000);
   }
  delay(3000);
      }
  }
  if(analogRead(moisture_sensorPin) > avg_moisture&&analogRead(moisture_sensorPin2) > avg_moisture&&digitalRead(float_switchPin)==LOW)/*the return vales of both sensors are reverse of theory values*/
  {
    lcd.clear();
    lcd.setCursor(0,0);
        lcd.print("MOISTURE - LOW");
        lcd.setCursor(0,1);
        lcd.print("MOTOR IS ON");
        digitalWrite(soil_statusPin,HIGH);
        digitalWrite(tank_statusPin,LOW);
    digitalWrite(motorPin1,HIGH);
  digitalWrite(motorPin2,LOW);
  percent_moisture=analogRead(moisture_sensorPin);
  percent_moisture=map(percent_moisture,1023,0,0,100);
  
  percent_moisture1=analogRead(moisture_sensorPin2);
  percent_moisture1=map(percent_moisture1,1023,0,0,100);
  BTserial.print((percent_moisture1+percent_moisture)/2);
  //Serial.print("%");
  BTserial.print(",");
  BTserial.print("ON");
  BTserial.print(",");
  BTserial.print("HIGH");
  BTserial.print(";");
  delay(3000);
  }
if(analogRead(moisture_sensorPin) > avg_moisture&&analogRead(moisture_sensorPin2) > avg_moisture&&digitalRead(float_switchPin)==HIGH)
  {
    lcd.clear();
     lcd.setCursor(0,0);
        lcd.print("MOISTURE - LOW");
        lcd.setCursor(0,1);
        lcd.print("MOTOR IS OFF");
        digitalWrite(soil_statusPin,HIGH);
        digitalWrite(tank_statusPin,HIGH);
    digitalWrite(motorPin1,LOW);
  digitalWrite(motorPin2,LOW);
  percent_moisture=analogRead(moisture_sensorPin);
  percent_moisture=map(percent_moisture,1023,0,0,100);
  
  percent_moisture1=analogRead(moisture_sensorPin2);
  percent_moisture1=map(percent_moisture1,1023,0,0,100);
  BTserial.print((percent_moisture1+percent_moisture)/2);
  //Serial.print("%");
  BTserial.print(",");
  BTserial.print("OFF");
  BTserial.print(",");
  BTserial.print("LOW");
  BTserial.print(";");
  delay(3000);
  }
    /*if(digitalRead(float_switchPin) == HIGH){
 //lcd.setCursor(0,0);
 //lcd.print(" TANK LEVEL- LOW");
 //lcd.setCursor(0,1);
 //lcd.print(" MOTOR - OFF "); 
 //digitalWrite(tank_statusPin,HIGH);
 digitalWrite(motorPin1,LOW);
 digitalWrite(motorPin1,LOW);
 delay(3000);}*/

  delay(500);
}
