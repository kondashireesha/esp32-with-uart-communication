#include <stdio.h>
#include <string.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_vfs_dev.h"
#include "driver/uart.h"

#define LED_PIN GPIO_NUM_2
#define BUF_SIZE 100

void app_main(void)
{
    // UART setup
    const uart_port_t uart_num = UART_NUM_0;
    uart_driver_install(uart_num, BUF_SIZE * 2, 0, 0, NULL, 0);
    esp_vfs_dev_uart_use_driver(uart_num);  // New function to avoid deprecation

    // GPIO setup
    gpio_reset_pin(LED_PIN);                      // Use this instead of gpio_pad_select_gpio
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    bool led_state = true;
    gpio_set_level(LED_PIN, led_state);

    printf("UART Communication Started.\nType input:\n");

    char input[BUF_SIZE];
    int index = 0;

    while (1) {
        int ch = getchar();
        if (ch != EOF) {
            if (ch == '\n') {
                input[index] = '\0';
                printf("Received: %s\n", input);

                // Toggle LED
                led_state = !led_state;
                gpio_set_level(LED_PIN, led_state);

                printf("You want to turn on the LED? Send data again:\n");
                index = 0;
            } else if (index < BUF_SIZE - 1) {
                input[index++] = ch;
            }
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
