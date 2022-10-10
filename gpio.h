#ifndef GPIO_H
#define GPIO_H
#include <sys/mman.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstdint>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

struct gpio_map
{
uint32_t ch1Data;     // 0x00
uint32_t ch1Tristate; // 0x04 
uint32_t ch2Data;     // 0x08
uint32_t ch2Tristate; // 0x0C

uint32_t pad1[67];


uint32_t globalInt; //0x11C
uint32_t intStatus; //0x120
uint32_t pad2;		    
uint32_t intEn;     //0x128
};

class gpio
{
  private:
    gpio_map *map;
    int fd;

  public:
    gpio(char *filename);

    void     enableInterrupt(bool ch1, bool ch2);
    void     enableInterruptGlobal(bool);
    void     waitInt();
    void     clearInt();

    uint32_t getCh1Data();
    uint32_t getCh1Tristate();
    void     setCh1Data(uint32_t data);
    void     setCh1Tristate(uint32_t tristate);
    
    uint32_t getCh2Data();
    uint32_t getCh2Tristate();
    void     setCh2Data(uint32_t data);
    void     setCh2Tristate(uint32_t tristate);
};
#endif
