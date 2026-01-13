#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"


// #define LED_GREEN_GPIO GPIO_NUM_10 //RED
// #define LED_YELLOW_GPIO GPIO_NUM_11 //YELLOW
// #define LED_RED_GPIO GPIO_NUM_12 //GREEN

#define LED1_GPIO GPIO_NUM_10
#define LED2_GPIO GPIO_NUM_9

void app_main(void) {
   // gpio_reset_pin(LED_RED_GPIO);
   // gpio_reset_pin(LED_YELLOW_GPIO);
   // gpio_reset_pin(LED_GREEN_GPIO);
   // gpio_set_direction(LED_RED_GPIO, GPIO_MODE_OUTPUT);
   // gpio_set_direction(LED_YELLOW_GPIO, GPIO_MODE_OUTPUT);
   // gpio_set_direction(LED_GREEN_GPIO, GPIO_MODE_OUTPUT);
   gpio_reset_pin(LED1_GPIO);
   gpio_reset_pin(LED2_GPIO);
   gpio_set_direction(LED1_GPIO, GPIO_MODE_OUTPUT);
   gpio_set_direction(LED2_GPIO, GPIO_MODE_OUTPUT);

   while (true) {
      //LEDs blink in sequence
        // LED1: Turn on for half a second
        // LED2: Turn off for half a seconf
        gpio_set_level(LED1_GPIO, 1);

        vTaskDelay(500 / portTICK_PERIOD_MS);
        gpio_set_level(LED1_GPIO, 0);

        // LED2: Turn on for a full second
        gpio_set_level(LED2_GPIO, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(LED2_GPIO, 0);

        vTaskDelay(500 / portTICK_PERIOD_MS);
    }


   // while (true) {
   //      //Green should be displayed for 2 seconds, 
   //      //yellow should be displayed for 1 second, 
   //      //and red should be displayed for 4 seconds.
   //      gpio_set_level(LED_GREEN_GPIO, 1);
   //      vTaskDelay(2000 / portTICK_PERIOD_MS);
   //      gpio_set_level(LED_GREEN_GPIO, 0);
   //      gpio_set_level(LED_YELLOW_GPIO, 1);
   //      vTaskDelay(1000 / portTICK_PERIOD_MS);
   //      gpio_set_level(LED_YELLOW_GPIO, 0);
   //      gpio_set_level(LED_RED_GPIO, 1);
   //      vTaskDelay(4000 / portTICK_PERIOD_MS);
   //      gpio_set_level(LED_RED_GPIO, 0);
   // }
}