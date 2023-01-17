#include <Arduino.h>

#include <GxEPD2_BW.h>
#include <Fonts/FreeSans12pt7b.h>

#include "DisplayConfig.hpp"

/**************************** DEBUG *******************************/
#define DEBUG

#ifdef DEBUG
#define DEBUG_PRINTLN(m) Serial.println(m)
#define DEBUG_PRINT(m) Serial.print(m)

#else
#define DEBUG_PRINTLN(m)
#define DEBUG_PRINT(m)

#define DEBUG_PRINTLNC(m)
#define DEBUG_PRINTC(m)
#endif

void setup() {
  Serial.begin(115200);
  while(!Serial) {}

  // display setup and printing
  display.init(115200, true, 20, false, *(new SPIClass(VSPI)), SPISettings(4000000, MSBFIRST, SPI_MODE0));
  display.setRotation(1);
  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setFont(&FreeSans12pt7b);
    display.setTextColor(GxEPD_BLACK);
    display.setCursor(25, 85);
    display.print("Philipp ist dumm :-D");
  } while (display.nextPage());

  display.powerOff();

  delay(1000);
  Serial.flush();
  esp_deep_sleep_start();
}

void loop() {
  // never executed when using deep sleep
}
