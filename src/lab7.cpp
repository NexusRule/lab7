/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/fxxsj/OneDrive/Desktop/lab7/src/lab7.ino"
// SYSTEM_MODE(MANUAL)
void setup();
void loop();
#line 2 "c:/Users/fxxsj/OneDrive/Desktop/lab7/src/lab7.ino"
SYSTEM_THREAD(ENABLED);
#define TEMP_SCAN A4
#define GIORNO A0
#include "oled-wing-adafruit.h"
#include <blynk.h>
OledWingAdafruit display;

void setup()
{
    Blynk.begin("3ooCt2NcBosv3c9DV-MGSexZ0aBKUMTc", IPAddress(167, 172, 234, 162), 8080);
    display.setup();
    display.clearDisplay();
}

/*BLYNK_WRITE() {
    if (param.asInt() == 1) {
        Blynk.notify("You pressed the button and I know it ;)");
    }
}*/

void loop()
{
    display.loop();
    Blynk.run();
    //int kakyoin = 0;
    uint64_t reading = analogRead(TEMP_SCAN);

    double voltage = (reading * 3.3) / 4095.0;
    double temperature = (voltage - 0.5) * 100;

    double f2 = (reading * 3.3) / 4095.0;
    double f1 = (f2 - 0.5) * 100;
    double f = (f1 * 1.8) + 32;

    /*if (display.pressedA())
    {
        kakyoin = 1;
    }*/

    if (display.pressedA())
    {
        Blynk.notify("jojo no kimi yo na bouken ... eyes of heaven!");
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(15, 15);
        display.println("push sent");
        display.display();
        delay(5000);
    }
    else
    {
        display.clearDisplay();
        display.setCursor(15, 15);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.print(temperature);
        display.print("C  |  ");
        display.print(f);
        display.print("F");
        display.display();
        delay(100);
    }
}