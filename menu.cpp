#include<iostream>
#include<conio.h>
#include<string>
#include<windows.h>
#include<stdlib.h>
#include "menu.h"
#include "board.h"

using namespace std;

void otioc(tipmenu a, int color)
{	
	set(a.x, a.y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout <<a.pm<< endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

int menu(tipmenu *pmenu, int *dmenu, int kmenu, int curs){   
	int ch,q;
	ch = _getch();
	if (ch==72||ch==80)
	{	
		switch (ch)
		{
		case 72:q = -1; break;
		case 80:q = 1; break;
		}
		otioc(*(pmenu + curs), 15);  
		
		do
		{
			curs = (q + kmenu + curs) % kmenu;
		} while (*(dmenu + curs) == 0);
		otioc(*(pmenu + curs), 11); 
	}

	return curs;
}


void xeroksmenu(tipmenu *pmenu, int *dmenu, int kmenu, int curs) {
	int i;
	Board mainBoard(0,0,83,38);
	
	for (i = 0; i < kmenu; i++)
	{
		if(*(dmenu+i)==1)
		{
			if (curs==i) 	otioc(*(pmenu + curs), 11); 
			else otioc(*(pmenu + i), 7); 
	 }
		else otioc(*(pmenu + i), 8); 
	}
}



