#include "driver/gpio.h"
#include "driver/ledc.h"
#include "freertos/idf_additions.h"
#include "freertos/projdefs.h"
#include <stdio.h>

#define CLK_PIN 4
#define FREQ_HZ 5
#define DUTY_PERCENT 50
#define INPUT_BIT_PIN 5
#define READ_PIN 18
void setup() {
  gpio_set_direction(CLK_PIN, GPIO_MODE_OUTPUT);
  gpio_set_direction(INPUT_BIT_PIN, GPIO_MODE_OUTPUT);
  gpio_set_direction(READ_PIN, GPIO_MODE_INPUT);
}
void test1() {
  // tests for 11011
  gpio_set_level(INPUT_BIT_PIN, 1);
  vTaskDelay(pdMS_TO_TICKS(500));
  gpio_set_level(INPUT_BIT_PIN, 1);
  vTaskDelay(pdMS_TO_TICKS(500));
  gpio_set_level(INPUT_BIT_PIN, 0);
  vTaskDelay(pdMS_TO_TICKS(500));
  gpio_set_level(INPUT_BIT_PIN, 1);
  vTaskDelay(pdMS_TO_TICKS(500));
  gpio_set_level(INPUT_BIT_PIN, 1);
  vTaskDelay(pdMS_TO_TICKS(500));
}

void test2() {
  int bits[] = {1, 1, 0, 1, 1, 0, 1, 1};
  for (int i = 0; i < sizeof(bits) / sizeof(bits[0]); i++) {
    gpio_set_level(INPUT_BIT_PIN, bits[i]);
    vTaskDelay(
        pdMS_TO_TICKS(1000 / FREQ_HZ)); // Give time to set up the input bit
    int output = gpio_get_level(READ_PIN);
    printf("%d", output);
  }
  printf("\n");
}

void test3() {
  int bits[] = {1, 0, 0, 1, 0, 1, 0, 1};
  for (int i = 0; i < sizeof(bits) / sizeof(bits[0]); i++) {
    gpio_set_level(INPUT_BIT_PIN, bits[i]);
    vTaskDelay(pdMS_TO_TICKS(1000 / FREQ_HZ));
    printf("%d", gpio_get_level(READ_PIN));
  }
  printf("\n");
}

void test4() {
  int bits[] = {1, 1, 0, 1, 1};
  for (int i = 0; i < sizeof(bits) / sizeof(bits[0]); i++) {
    gpio_set_level(INPUT_BIT_PIN, bits[i]);
    vTaskDelay(pdMS_TO_TICKS(1000 / FREQ_HZ));
    printf("%d", gpio_get_level(READ_PIN));
  }
  printf("\n");
}

void test5() {
  int bits[] = {1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1};
  for (int i = 0; i < sizeof(bits) / sizeof(bits[0]); i++) {
    gpio_set_level(INPUT_BIT_PIN, bits[i]);
    vTaskDelay(pdMS_TO_TICKS(1000 / FREQ_HZ));
    printf("%d", gpio_get_level(READ_PIN));
  }
  printf("\n");
}
void test6() {
  int bits[] = {1, 1, 0, 1, 1, 0, 1, 1, 0};
  for (int i = 0; i < sizeof(bits) / sizeof(bits[0]); i++) {
    gpio_set_level(INPUT_BIT_PIN, bits[i]);
    vTaskDelay(pdMS_TO_TICKS(1000 / FREQ_HZ));
    printf("%d", gpio_get_level(READ_PIN));
  }
  printf("\n");
}
void test7() {
  int bits[] = {1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1};
  for (int i = 0; i < sizeof(bits) / sizeof(bits[0]); i++) {
    gpio_set_level(INPUT_BIT_PIN, bits[i]);
    vTaskDelay(pdMS_TO_TICKS(1000 / FREQ_HZ));
    printf("%d", gpio_get_level(READ_PIN)); // Expected output: 0000100000001
  }
  printf("\n");
}
void test8() {
  int bits[] = {1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1};
  for (int i = 0; i < sizeof(bits) / sizeof(bits[0]); i++) {
    gpio_set_level(INPUT_BIT_PIN, bits[i]);
    vTaskDelay(pdMS_TO_TICKS(1000 / FREQ_HZ));
    printf("%d", gpio_get_level(READ_PIN)); // Expected output: 000010000000010
  }
  printf("\n");
}
void app_main() {
  setup();
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

  while (1) {
    test5();
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}
