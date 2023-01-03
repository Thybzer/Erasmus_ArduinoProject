// Sample using LiquidCrystal library
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int lcd_key = 0;
int adc_key_in = 0;
#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5
int data1;
int data2;
int data3;
int data4;
unsigned int nbDice = 0;

int read_LCD_buttons()
{

  adc_key_in = analogRead(0);

  if (adc_key_in > 1000)
    return btnNONE;
  if (adc_key_in < 50)
    return btnRIGHT;
  if (adc_key_in < 250)
    return btnUP;
  if (adc_key_in < 450)
    return btnDOWN;
  if (adc_key_in < 650)
    return btnLEFT;
  if (adc_key_in < 850)
    return btnSELECT;

  return btnNONE; 
}

void setup()
{

  lcd.begin(16, 2); 
  lcd.setCursor(0, 0);
  lcd.print("Welcome to The");
  lcd.setCursor(0, 1);
  lcd.print("Dice Game");
  delay(3000);
  lcd.clear();
  lcd.begin(16, 2); 
  lcd.setCursor(0, 0);
  lcd.print("Up=+1 Down=-1");
  lcd.setCursor(0, 1);
  lcd.print("Select=Play enjoy :)");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("How many dice?");
}

void loop()
{
data1=random(1,6);
data2=random(1,6);
data3=random(1,6);
data4=random(1,6);

  lcd_key = read_LCD_buttons();
  switch (lcd_key)
  {
  case btnUP:
  {
    if (!digitalRead(adc_key_in))
    {
      delay(100);

      if (digitalRead(btnUP))
      {
        nbDice = nbDice + 1;
      }
    }
    break;
  }
  }
    switch (lcd_key)
  {
  case btnDOWN:
  {
    if (!digitalRead(adc_key_in))
    {
      delay(100);

      if (digitalRead(btnDOWN))
      {
        nbDice = nbDice - 1;
      }
    }
    break;
  }
  }
  switch(lcd_key){
  case btnSELECT:
  {
    lcd.setCursor(9,0);
if (nbDice >4){
  lcd.clear();
  lcd.print("choose 1 or 4");
  }
if (nbDice ==0){
  lcd.clear();
  lcd.print("choose 1 or 4");
  }
if (nbDice == 4){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("throw: ");
  lcd.print(data1);
  lcd.print(data2);
  lcd.print(data3);
  lcd.print(data4);
 }
if (nbDice==3){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("throw: ");
  lcd.print(data1);
  lcd.print(data2);
  lcd.print(data3);
  }
  if (nbDice==2){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("throw: ");
  lcd.print(data1);
  lcd.print(data2);
  }
  if (nbDice==1){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("throw: ");
  lcd.print(data1);}
      break;
  }
  case btnNONE:
  {
    lcd.print("  ");
    break;
  }
  }
  lcd.setCursor(0, 1);
  lcd.print("nb dice : ");
  lcd.print(nbDice);
}