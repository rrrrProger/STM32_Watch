/*
 * screen_management.h
 *
 *  Created on: Mar 7, 2025
 *      Author: user
 */

#ifndef INC_SCREEN_MANAGEMENT_H_
#define INC_SCREEN_MANAGEMENT_H_

#include "images.h"

void ScreenInit		 (void);
void ScreenDrawTheme (void);
void ScreenDrawGreeting(void);
void ScreenShowHomeTown(void);
void ScreenShowBattery(int val);
void ScreenDrawImage(const uint16_t image[IMAGE_HEIGHT][IMAGE_WIDTH], int x_offset, int y_offset);
void ScreenShowAbout(void);
void ScreenShowContactInfo(void);
void ScreenShowEducation(void);
void ScreenShowExperience(void);

#endif /* INC_SCREEN_MANAGEMENT_H_ */
