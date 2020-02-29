# arduino-ioexpander-lib
IO Expander Device Library with Arduino

## Installation
1. Download the zip file.
2. Move the zip file to your libraries directory.
3. In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library.
4. Select the zip file.

## Usage 
1. Programming arduino-ioexpander-fw to your IO expander arduino device (see [arduino-ioexpander-fw](https://github.com/bigw00d/arduino-ioexpander-fw))
2. Connecting this library user device to IO expander arduino device(see [arduino-ioexpander-fw](https://github.com/bigw00d/arduino-ioexpander-fw))
3. Start IO expander arduino device 
4. Start this library user device

## Example

 - still in preparation

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
