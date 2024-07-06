#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "lfs.h"

// variables used by the filesystem
extern const struct lfs_config PICO_FLASH_CFG;

void led_task() {
	while (true) {
		printf("Hello");
		vTaskDelay(1000);
	}
}

int main() {
	stdio_init_all();

	xTaskCreate(led_task, "LED_Task", 256, NULL, 1, NULL);
	vTaskStartScheduler();

	return 0;
}
