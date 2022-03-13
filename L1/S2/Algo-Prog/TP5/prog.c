#include <stdio.h>
#include <ncurses.h>


int main()
{
	initscr();
	int x, y;
	getmaxyx(stdscr, y, x);
	x--;
	mvprintw(y/2,x-1,"#");
	for(;x != 0;x--)
		mvprintw(y/2,x,"#");                                                      
		napms(50);
		refresh();
	getch();
	endwin();
}
