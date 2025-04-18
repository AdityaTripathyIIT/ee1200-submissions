#include "driver/gpio.h"
#include "driver/ledc.h"
#include "esp_err.h"
#include "freertos/idf_additions.h"
#include "freertos/projdefs.h"
#include <stdio.h>

#define CLK_PIN 4
#define FREQ_HZ 1
#define DUTY_PERCENT 50
#define INPUT_BIT_PIN 5
void setup() {
  gpio_set_direction(CLK_PIN, GPIO_MODE_OUTPUT);
  gpio_set_direction(INPUT_BIT_PIN, GPIO_MODE_OUTPUT);
}

void test1() {
  // tests for 11011
  gpio_set_level(INPUT_BIT_PIN, 1);
}
void app_main() {
  ledc_timer_config_t ledc_timer = {.speed_mode = LEDC_LOW_SPEED_MODE,
                                    .timer_num = LEDC_TIMER_0,
                                    .duty_resolution = LEDC_TIMER_10_BIT,
                                    .freq_hz = FREQ_HZ,
                                    .clk_cfg = LEDC_AUTO_CLK};
  ledc_timer_config(&ledc_timer);

  ledc_channel_config_t ledc_channel = {.channel = LEDC_CHANNEL_0,
                                        .duty = (1023 * DUTY_PERCENT) / 100,
                                        .gpio_num = CLK_PIN,
                                        .speed_mode = LEDC_LOW_SPEED_MODE,
                                        .hpoint = 0,
                                        .timer_sel = LEDC_TIMER_0};
  ledc_channel_config(&ledc_channel);
}
