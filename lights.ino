// include libraries
#include "Particle.h"
#include "neopixel.h"

SYSTEM_MODE(AUTOMATIC);

// basic variables
#define PIXEL_PIN D2
#define PIXEL_COUNT 150
#define PIXEL_TYPE WS2813

// setup the strip
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int red = 0;
int green = 0;
int blue = 0;

// handler function for the Light_Color event
void color_handler(const char* eventName, const char* data) {
    strip.begin();
    strip.show();
    if (strcmp(data,"blue") == 0) {
        blue = 255;
        green = 0;
        red = 0;
        setup();
    } else if (strcmp(data,"red") == 0) {
        blue = 0;
        green = 0;
        red = 255;
        setup();
    } else if (strcmp(data,"green") == 0) {
        blue = 0;
        green = 255;
        red = 0;
        setup();
    } else if (strcmp(data,"purple") == 0) {
        blue = 221;
        red = 160;
        green = 230;
        setup();
    } else if (strcmp(data,"yellow") == 0) {
        blue = 0;
        green = 255;
        red = 255;
        setup();
    } else if (strcmp(data,"orange") == 0) {
        red = 255;
        green = 160;
        blue = 0;
        setup();
    } else if (strcmp(data,"white") == 0) {
        red = 255;
        green = 255;
        blue = 255;
        setup();
    } else if (strcmp(data,"clear") == 0) {
        red = 0;
        green = 0;
        blue = 0;
        setup();
    }
}

void setup()
{
    Particle.subscribe("Light_Color",color_handler,MY_DEVICES);
    
    strip.begin();
    strip.show();
    // set every light to the selected color
    for(int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i,strip.Color(red,green,blue));
    }
}

// continuously show lights
void loop()
{
    strip.show();
}
