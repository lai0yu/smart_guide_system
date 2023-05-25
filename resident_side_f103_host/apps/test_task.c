#include "test_task.h"
#include "led.h"
#include "beep.h"

// 启动任务
#define START_TASK_PRIO 1
#define START_STK_SIZE  128
TaskHandle_t StartTask_Handler;
void start_task(void *arg);

// LED_R 任务
#define LED_R_TASK_PRIO 2
#define LED_R_STK_SIZE  50
TaskHandle_t LED_R_Task_Handler;
void led_r_task(void *arg);

// beep 任务
#define BEEP_TASK_PRIO 3
#define BEEP_STK_SIZE  50
TaskHandle_t BeepTask_Handler;
void beep_task(void *arg);

// LED_R 任务
void led_r_task(void *arg)
{
	while (1) {
		LED_R_ON();
		vTaskDelay(200);
		LED_R_OFF();
		vTaskDelay(500);
	}
}

// 创建 LED_R 任务
void create_led_r_task(void)
{
	xTaskCreate(led_r_task, "led r task", LED_R_STK_SIZE, NULL, LED_R_TASK_PRIO, &LED_R_Task_Handler);
}

// beep 任务
void beep_task(void *arg)
{
	while (1) {
		BEEP_ON();
		vTaskDelay(10);
		BEEP_OFF();
		vTaskDelay(1000);
	}
}

// 创建 beep 任务
void create_beep_task(void)
{
	xTaskCreate(beep_task, "led g task", BEEP_STK_SIZE, NULL, BEEP_TASK_PRIO, &BeepTask_Handler);
}

// 启动任务函数
void start_task(void *arg)
{
	// 进入临界区
	taskENTER_CRITICAL();
	
	// 创建 LED_R 任务
	create_led_r_task();
	
	// 创建 beep 任务
	create_beep_task();
	
	// 删除启动任务
	vTaskDelete(StartTask_Handler);
	//vTaskSuspend(StartTask_Handler);
	
		// 退出临界区
	taskEXIT_CRITICAL();
}

// 创建启动任务
void create_start_task(void)
{
	xTaskCreate(start_task, "start task", START_STK_SIZE, NULL, START_TASK_PRIO, &StartTask_Handler);
}

