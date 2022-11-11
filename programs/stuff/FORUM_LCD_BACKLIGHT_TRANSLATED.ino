#include <LiquidCrystal.h>

// integer library
int backgroundlightPIN = 8;      // Backlight PIN
int backgroundLightValue = 49;    // Background Value = Higher => Brighter
int contrastPIN = 9;              // Contrast PIN
int contrastValue = 49;            // Contrast value = smaller => more contrast
int analog;

// Setup of the LCD library
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  // Computer interface connection
  Serial.begin(9600);
  
  // Setup the PINs
  pinMode(backgroundlightPIN, OUTPUT);
  pinMode(contrastPIN, OUTPUT);
  
  // Contrast and background control of the LCD
  analogWrite(backgroundlightPIN, backgroundLightValue);
  analogWrite(contrastPIN, contrastValue);
  
  // Introduction of the LCD into the microcontroller
  lcd.begin(16, 2);  
  
}

void loop() {

  // Writing the analog input A0
  analog = analogRead(A0) / 100;

  // value output in the console. (Debugging)
  Serial.print(analog);
  Serial.print("\n");             // New line
  
  // Send the information to the LCD
  lcd.setCursor(0, 0);
  lcd.print("Potentiometer");
  lcd.setCursor(0, 1);
  lcd.print(analog);
  lcd.setCursor(2, 1);
  lcd.print("k");
  delay(100);
  
  // Deletion of the field (second line, second row) in the LCD
  // Otherwise a 0 will remain if you go to 10k and go back again
  lcd.setCursor(1, 1);
  lcd.print(" ");
  delay(7);

}
