#ifndef __MENU_H_INCLUDED__
#define __MENU_H_INCLUDED__

#include<iostream>
#include<conio.h>
#include<string>
#include<Windows.h>
#include<stdlib.h>
#include "board.h"

using namespace std;

class tipmenu
{
public:
	int x, y;
	string pm;
};

void otioc(tipmenu a, int color);

int menu(tipmenu *pmenu, int *dmenu, int kmenu, int curs);
void xeroksmenu(tipmenu *pmenu, int *dmenu, int kmenu, int curs);

#endif
