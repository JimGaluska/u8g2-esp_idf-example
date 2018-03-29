
#include "freertos/FreeRTOS.h"
 #include <driver/spi_master.h>
#include <esp_log.h>
#include <stdio.h>
#include <string.h>
#include <u8g2.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "apps/sntp/sntp.h"

#include "sdkconfig.h"
#include "u8g2_esp32_hal.h"

void task_test_SSD1306(void *ignore);

#define PIN_CLK   14  // CLK   - GPIO14
#define PIN_MOSI  13  // MOSI  - GPIO 13
#define PIN_RESET 26  // RESET - GPIO 26
#define PIN_DC    27  // DC    - GPIO 27
#define PIN_CS    15  // CS    - GPIO 15


esp_err_t event_handler(void *ctx, system_event_t *event)
{
    return ESP_OK;
}



void app_main(void)
{
xTaskCreate(
    task_test_SSD1306,  /* Function that implements the task. */
    "test",             /* Text name for the task. */
    3000,               /* Stack size in words, not bytes. */
    NULL,               /* Parameter passed into the task. */
    5,                  /* Priority at which the task is created. */
    NULL                /* Used to pass out the created task's handle. */
  );


  while (true) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
