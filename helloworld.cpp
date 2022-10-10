#include <iostream>
#include "gpio.h"

using namespace std;



int main()
{
  gpio leds((char *) "/dev/uio1");
  leds.enableInterrupt(false, true);
  leds.enableInterruptGlobal(true);
  leds.clearInt(); 
  uint32_t i=0;
  while(1)
  {
    leds.waitInt();
    leds.setCh1Data(0xFFFF);
    cout << "switch changed " << leds.getCh2Data() << endl;
    leds.clearInt();
  }
}
