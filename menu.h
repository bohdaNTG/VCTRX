#ifndef __MENU_H_INCLUDED__
#define __MENU_H_INCLUDED__

#include<iostream>
#include<conio.h>
#include<string>
#include<Windows.h>
#include<stdlib.h>
#include "board.h"

using namespace std;

class Menu
{
public:
	int x, y;
	string pm;
};

void otioc(Menu a, int color);

int menu(Menu *pmenu, int *dmenu, int kmenu, int curs);
void xeroksmenu(Menu *pmenu, int *dmenu, int kmenu, int curs);

#endif
