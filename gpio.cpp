#include "gpio.h"
#include <iostream>

using namespace std;

gpio::gpio(char *filename)
{
  int fd;
  char *addr;
  fd = open (filename, O_RDWR);

  if(fd == -1)
  {
    cout << "failed to open device" << endl;
    exit(1);
  }
  addr = (char *)mmap(NULL, 65536, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
  if(addr == MAP_FAILED)
  {
    cout << "mmap failed";
    exit(1);
  } 
  map = (gpio_map *) addr; 
}

void gpio::setCh1Data(uint32_t data)
{
  map->ch1Data = data;
}
void gpio::setCh2Data(uint32_t data)
{
  map->ch2Data = data;
}
uint32_t gpio::getCh1Data()
{
  return map->ch1Data;
}
uint32_t gpio::getCh2Data()
{
  return map->ch2Data;
}
void  gpio::setCh1Tristate(uint32_t tristate)
{
  map->ch1Tristate = tristate;
}
uint32_t  gpio::getCh1Tristate()
{
  return map->ch1Tristate;
}
void  gpio::setCh2Tristate(uint32_t tristate)
{
  map->ch2Tristate = tristate;
}
uint32_t  gpio::getCh2Tristate()
{
  return map->ch2Tristate;
}



