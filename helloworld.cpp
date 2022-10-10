#include <iostream>
#include "gpio.h"

using namespace std;



int main()
{
  gpio leds((char *) "/dev/uio1");
  leds.setCh1Data(0xFFFF);
  cout << "hello world" << endl;
}
