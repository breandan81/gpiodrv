#ifndef GPIO_H
#define GPIO_H
#include <sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <cstdint>

struct gpio_map
{
uint32_t ch1Data;
uint32_t ch1Tristate;
uint32_t ch2Data;
uint32_t ch2Tristate;
};

class gpio
{
gpio_map *map;


	public:
gpio(char *filename);

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
