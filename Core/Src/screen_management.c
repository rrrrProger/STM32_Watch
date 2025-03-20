/*
 * screen_management.c
 *
 *  Created on: Mar 7, 2025
 *      Author: user
 */


#include "st7735.h"
#include "screen_management.h"
#include "images.h"

extern uint16_t image1[IMAGE_WIDTH][IMAGE_HEIGHT];
extern uint16_t image0[IMAGE_WIDTH][IMAGE_HEIGHT];
extern uint16_t image2[IMAGE_WIDTH][IMAGE_HEIGHT];
extern uint16_t image3[IMAGE_WIDTH][IMAGE_HEIGHT];

static char __digitToChar(int dig){
	switch(dig){
	case 0:
		return '0';
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	default:
		return 'x';
	}
}

void ScreenInit(){
	ST7735_Init();
}

void ScreenDrawTheme(){
	ST7735_FillScreen(ST7735_WHITE);
}

void ScreenDrawGreeting(){
	ST7735_FillScreen(ST7735_BLACK);
	HAL_Delay(5000);
	ST7735_FillScreen(ST7735_BLACK);
}

void ScreenShowBattery(int val){
	char str[4];

	if (val >= 100){
		val = 99;
	}

	str[0] = __digitToChar((int)val / 10);
	str[1] = __digitToChar((int)val % 10);
	str[2] = '%';
	str[3] = '\0';

	ST7735_WriteString(100, 5, str, Font_7x10, ST7735_RED, ST7735_BLACK, ST7735_WIDTH, ST7735_HEIGHT);
}

void ScreenDrawImage(const uint16_t image[IMAGE_HEIGHT][IMAGE_WIDTH], int x_offset, int y_offset){
	for(int x = 0; x < IMAGE_WIDTH; x++) {
	  for(int y = 0; y < IMAGE_HEIGHT; y++) {
		  uint16_t color565 = image[y][x];
		  // fix endiness
		  color565 = ((color565 & 0xFF00) >> 8) | ((color565 & 0xFF) << 8);
		  ST7735_DrawPixel(x + x_offset, y + y_offset, color565);
	  }
	}
}

void ScreenShowAbout(void){
	ST7735_FillScreen(ST7735_WHITE);

	ST7735_WriteString(10, 5, "About me", Font_11x18, ST7735_BLACK, ST7735_WHITE, ST7735_WIDTH, ST7735_HEIGHT);

	ScreenDrawImage(image0, 68, 30);

	ST7735_WriteString(10, 30, "I am a passionate scientist, father, engineer.", Font_7x10, ST7735_BLACK, ST7735_WHITE, 60, 100);
	ST7735_WriteString(10, 95, "I came from Ukraine, live and work in Italy.", Font_7x10, ST7735_BLACK, ST7735_WHITE, 60, ST7735_HEIGHT);

	ST7735_FillRectangle(68, 95, 60, 20, ST7735_BLUE);
	ST7735_FillRectangle(68, 115, 60, 20, ST7735_YELLOW);
}

void ScreenShowContactInfo(void) {
	ST7735_FillScreen(ST7735_WHITE);

	ST7735_WriteString(10, 5, "Contact", Font_11x18, ST7735_BLACK, ST7735_WHITE, ST7735_WIDTH, ST7735_HEIGHT);
}

void ScreenShowEducation(void) {
	ST7735_FillScreen(ST7735_WHITE);

	ST7735_WriteString(10, 5, "Education", Font_11x18, ST7735_BLACK, ST7735_WHITE, ST7735_WIDTH, ST7735_HEIGHT);
}

void ScreenShowExperience(void) {
	ST7735_FillScreen(ST7735_WHITE);

	ST7735_WriteString(10, 5, "Experience", Font_11x18, ST7735_BLACK, ST7735_WHITE, ST7735_WIDTH, ST7735_HEIGHT);
}
