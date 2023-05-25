#include "test_task.h"
#include "led.h"
#include "beep.h"

// ��������
#define START_TASK_PRIO 1
#define START_STK_SIZE  128
TaskHandle_t StartTask_Handler;
void start_task(void *arg);

// LED_R ����
#define LED_R_TASK_PRIO 2
#define LED_R_STK_SIZE  50
TaskHandle_t LED_R_Task_Handler;
void led_r_task(void *arg);

// beep ����
#define BEEP_TASK_PRIO 3
#define BEEP_STK_SIZE  50
TaskHandle_t BeepTask_Handler;
void beep_task(void *arg);

// LED_R ����
void led_r_task(void *arg)
{
	while (1) {
		LED_R_ON();
		vTaskDelay(200);
		LED_R_OFF();
		vTaskDelay(500);
	}
}

// ���� LED_R ����
void create_led_r_task(void)
{
	xTaskCreate(led_r_task, "led r task", LED_R_STK_SIZE, NULL, LED_R_TASK_PRIO, &LED_R_Task_Handler);
}

// beep ����
void beep_task(void *arg)
{
	while (1) {
		BEEP_ON();
		vTaskDelay(10);
		BEEP_OFF();
		vTaskDelay(1000);
	}
}

// ���� beep ����
void create_beep_task(void)
{
	xTaskCreate(beep_task, "led g task", BEEP_STK_SIZE, NULL, BEEP_TASK_PRIO, &BeepTask_Handler);
}

// ����������
void start_task(void *arg)
{
	// �����ٽ���
	taskENTER_CRITICAL();
	
	// ���� LED_R ����
	create_led_r_task();
	
	// ���� beep ����
	create_beep_task();
	
	// ɾ����������
	vTaskDelete(StartTask_Handler);
	//vTaskSuspend(StartTask_Handler);
	
		// �˳��ٽ���
	taskEXIT_CRITICAL();
}

// ������������
void create_start_task(void)
{
	xTaskCreate(start_task, "start task", START_STK_SIZE, NULL, START_TASK_PRIO, &StartTask_Handler);
}

