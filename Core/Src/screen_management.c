/*
 * screen_management.c
 *
 *  Created on: Mar 7, 2025
 *      Author: user
 */


#include "st7735.h"
#include "screen_management.h"

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
	ST7735_FillScreen(ST7735_BLACK);
}

void ScreenDrawGreeting(){
	ST7735_FillScreen(ST7735_BLACK);
	ST7735_WriteString(0, 0, "Hi there! I want to introduce myself and tell my story.", Font_11x18, ST7735_WHITE, ST7735_BLACK);
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

	ST7735_WriteString(100, 5, str, Font_7x10, ST7735_RED, ST7735_BLACK);
}
