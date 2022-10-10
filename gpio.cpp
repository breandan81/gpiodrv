#include "gpio.h"
#include <iostream>

using namespace std;

gpio::gpio(char *filename)
{
  char *addr;
  fd = open (filename, O_RDWR | O_SYNC);

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
void gpio::enableInterrupt(bool ch1, bool ch2)
{
  uint32_t val = 0;
  if(ch1)
  {
    val |= 0x1;
  }
  if(ch2)
  {
    val |= 0x2; 
  }
  map->intEn = val;
}
void gpio::enableInterruptGlobal(bool en)
{
  if(en)
  {
    map->globalInt = 0x80000000;  
  }
  else
  {
    map->globalInt = 0;
  }
}
void gpio::clearInt()
{
  uint32_t info = 1;
  uint32_t intStatus;

  intStatus = map->intStatus;
  if(intStatus)
  {
    map->intStatus = intStatus;
  }
  ssize_t nb = write(fd, &info, sizeof(info));
  
  if( nb != (ssize_t)sizeof(info))
  {
    cout << "write error" << endl;
    exit(1);
  }

}
void gpio::waitInt()
{
  
  uint32_t info = 1;

  ssize_t nb = read(fd, &info, sizeof(info));
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



