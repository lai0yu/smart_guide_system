#ifndef _LED_H
#define _LED_H

#include "stm32f10x.h"

#define LED_R_ON()    do { GPIO_ResetBits(GPIOC, GPIO_Pin_8); } while (0)
#define LED_R_OFF()   do { GPIO_SetBits(GPIOC, GPIO_Pin_8); } while (0)

#define LED_G_ON()    do { GPIO_ResetBits(GPIOC, GPIO_Pin_7); } while (0)
#define LED_G_OFF()   do { GPIO_SetBits(GPIOC, GPIO_Pin_6); } while (0)

#define LED_B_ON()    do { GPIO_ResetBits(GPIOC, GPIO_Pin_6); } while (0)
#define LED_B_OFF()   do { GPIO_SetBits(GPIOC, GPIO_Pin_6); } while (0)

#define LED_ALL_OFF() do { GPIO_SetBits(GPIOC, GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8); } while (0)

void led_init(void);

#endif
