# arduino-ioexpander-lib
IO Expander Device Library with Arduino

## Installation
1. Download the zip file.
2. Move the zip file to your libraries directory.
3. In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library.
4. Select the zip file.

## Example

 - ready now

```IOExpanderDemo.ino
#include "ArduinoIOExpander.h"

ArduinoIOExpander expander;

void setup()
{
    Serial.begin(115200);
    expander.init();
}

void loop()
{
  delay(1000);
}

```
