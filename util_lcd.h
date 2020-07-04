#ifndef UTIL_LCD_H_
#define UTIL_LCD_H_

#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET 	-1 // This display does not have a reset pin accessible

// define functions
void lcd_print_number(double n);
void lcd_print(String s);
void lcd_print_str_number(String s, double n);
void lcd_print_array(int id, volatile uint32_t *sample);
void lcd_init();

#endif