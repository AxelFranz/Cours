#include <stdio.h>
#include <ncurses.h>


int main()
{
	initscr();
	int x, y;
	getmaxyx(stdscr, y, x);
	for(;x>0;x--)
	{
		mvprintw(y,x,"a");
	}
	refresh();
	getch();
	endwin();
}
