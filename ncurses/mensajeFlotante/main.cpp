#include <iostream>
#include <ncurses.h>

void drawA();

int main(int argc, char *argv[])
{
	initscr();			/* Start curses mode 		  */
    drawA();
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */

    WINDOW *win = newwin(3, 20, 1, 1);
    box(win, 0 , 0);	
    wmove(win, 1, 1);
    wprintw(win, "texto en ventana");
    wrefresh(win);
	getch();			/* Wait for user input */
    delwin(win);
    win = nullptr;

	endwin();			/* End curses mode		  */

    return EXIT_SUCCESS;
}

void drawA()
{
    printw("   *   \n");
    printw("  ***  \n");
    printw("  * *  \n");
    printw(" ***** \n");
    printw(" *   * \n");
    printw("**   **\n");
}

