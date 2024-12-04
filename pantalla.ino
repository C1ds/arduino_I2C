#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Dirección 0x27, LCD de 16x2

int pisoActual = 5;   // Piso inicial
int pisoDestino = 3;  // Piso destino

void setup() {
  lcd.init();         // Inicializa la pantalla LCD
  lcd.clear();        // Limpia la pantalla
  lcd.backlight();    // Enciende luz de fondo
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Piso actual: ");
  lcd.print(pisoActual);
  
  lcd.setCursor(0, 1);
  if (pisoDestino < pisoActual) {
    lcd.print("Bajando       ");

    while (pisoActual > pisoDestino) {
      delay(3000);
      pisoActual--;
      lcd.setCursor(0, 0);
      lcd.print("Piso actual: ");
      lcd.print(pisoActual);
    }
    lcd.setCursor(0, 1);
    lcd.print("Piso alcanzado");
  } 
  
  else if (pisoDestino > pisoActual) {
    lcd.print("Subiendo      ");
    while (pisoActual < pisoDestino) {
      delay(3000);
      pisoActual++;
      lcd.setCursor(0, 0);
      lcd.print("Piso actual: ");
      lcd.print(pisoActual);
    }
    lcd.setCursor(0, 1);
    lcd.print("Piso alcanzado");
  } 

  delay(3000);
  pisoDestino = 6;
}
