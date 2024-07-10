#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName ) {
    printf("Task %s caused a stack overflow!\n", pcTaskName);
}

