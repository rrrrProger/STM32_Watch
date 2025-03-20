/*
 * menu.c
 *
 *  Created on: Mar 19, 2025
 *      Author: user
 */
#include "main.h"
#include "st7735.h"
#include "screen_management.h"

#define DEFAULT_COLOR 		ST7735_WHITE
#define SELECTABLE_COLOR 	ST7735_BLACK
#define BLOCK_COLOR 		ST7735_RED

#define MENU_ITEMS 			3
#define MAIN_MENU			1
#define HELP_MENU 			2

struct menu_obj {
	char name[20];
	int x;
	int y;
	void (*showScreen)(void);
};

struct menu_obj about = {"About me", 10, 20, ScreenShowAbout};
struct menu_obj contact = {"Contact", 10, 50, ScreenShowContactInfo};
struct menu_obj education = {"Education", 10, 80, ScreenShowEducation};
struct menu_obj experience = {"Experience", 10, 110, ScreenShowExperience};

struct menu_obj *menu[] = {&about, &contact, &education, &experience};

int menu_width = 80;
int menu_height = 20;

int menu_counter = 0;

int screen = MAIN_MENU;

static void _displayObject(struct menu_obj *obj, uint16_t clr_block, uint16_t clr_text){
	ST7735_FillRectangle(obj->x, obj->y, menu_width, menu_height, clr_block);
	ST7735_WriteString(obj->x + 1, obj->y + 5, obj->name, Font_7x10, clr_text, clr_block, ST7735_WIDTH, ST7735_HEIGHT);
}

void ShowStartMenu(){
	ST7735_FillScreen(ST7735_WHITE);

	for (int i = 0; i < 4; i++){
		if (i == 0)
			_displayObject(menu[i], BLOCK_COLOR, SELECTABLE_COLOR);
		else
			_displayObject(menu[i], BLOCK_COLOR, DEFAULT_COLOR);
	}
	menu_counter = 0;
}

void IncrementMenu(){
	if (screen != MAIN_MENU){
		screen = MAIN_MENU;
		ShowStartMenu();
		return;
	}

	if (menu_counter == MENU_ITEMS){
		_displayObject(menu[menu_counter], BLOCK_COLOR, DEFAULT_COLOR);
		menu_counter = 0;
	} else {
		_displayObject(menu[menu_counter], BLOCK_COLOR, DEFAULT_COLOR);
		menu_counter++;
	}

	_displayObject(menu[menu_counter], BLOCK_COLOR, SELECTABLE_COLOR);
}

void SelectMenu(){
	if (screen == MAIN_MENU){
		screen = HELP_MENU;
		menu[menu_counter]->showScreen();
	} else if (screen == HELP_MENU){
		return;
	}
}

