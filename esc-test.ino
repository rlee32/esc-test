#include "Component.h"
#include "Esc.h"
#include "MomentaryPushButton.h"
#include "Pin.h"
#include "RgbLed.h"

OutputPin escout(10);
PowerPin escpower(9);
GroundPin escground(8);

Esc<20> esc(escout, escpower, escground);

InputPin buttoninput(5);
PowerPin buttonpower(6);
GroundPin buttonground(7);

MomentaryPushButton button(buttoninput, buttonpower, buttonground);

OutputPin red(A0);
PowerPin power(A1);
OutputPin green(A2);
OutputPin blue(A3);

RgbLed<PowerPin> led(red, power, green, blue);

void setup()
{
    led.setup();
    button.setup();
    esc.setup();
    Component::CheckSetup();
    Pin::ValidateSingleUsage();
    Serial.begin(9600);
    esc.printLevels();
}

void loop()
{
    if (button.high())
    {
        led.red();
        esc.throttle(6);
    }
    else
    {
        led.green();
        esc.off();
    }
}
