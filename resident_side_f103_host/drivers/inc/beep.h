#ifndef _BEEP_H
#define _BEEP_H

#include "stm32f10x.h"

#define BEEP_ON()  do { GPIO_ResetBits(GPIOC, GPIO_Pin_9); } while (0)
#define BEEP_OFF() do { GPIO_SetBits(GPIOC, GPIO_Pin_9); } while (0)

void beep_init(void);

#endif
