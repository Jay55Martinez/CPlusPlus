#include <ncurses.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {

    /* -- Hello World Example -- */
    /*
    initscr();
    printw("Hello World!");
    refresh();
    getch();
    endwin();
    */

    /* -- Reading Chr from User Keyboard -- */
    
    int ch;
    initscr(); // initialize the screen
    raw(); // line buffering disabled
    keypad(stdscr, TRUE);
    noecho();

    printw("Type any character to see it in bold: \n");
    ch = getch(); // get chr from user

    if(ch == KEY_F(1)) // with out keypad enabled this will
        printw("F1 Key pressed");

    else {
        printw("The pressed key is ");
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD);
    }
    refresh();
    getch();
    endwin();
    

    /* -- Print Example -- */
    /*
    char mesg[]="Just a string"; // message to be appeared on the screen
    int row,col; // to store the number of rows and the number of colums of the screen
    initscr(); // start the curses mode 
    getmaxyx(stdscr,row,col); // get the number of rows and columns 
    mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg); // print the message at the center of the screen 
    mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
    printw("Try resizing your window(if possible) and then run this program again");
    refresh();
    getch();
    endwin();
    */

    /*
    1. getch() class: Get a character

    2. scanw() class: Get formatted input

    3. getstr() class: Get strings
    */

    /* -- Example scanw -- */
    /*
    char mesg[]="Enter a string: "; // message to be appeared on the screen
    char str[80];
    int row,col; // to store the number of rows and the number of colums of the screen
    initscr(); // start the curses mode
    getmaxyx(stdscr,row,col); // get the number of rows and columns
    mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg); // print the message at the center of the screen
    getstr(str);
    mvprintw(LINES - 2, 0, "You Entered: %s", str);
    getch();
    endwin();
    */
    /*
    int argc = 2;
    char* argv[2];
    int ch, prev, row, col;
    prev = EOF;
    FILE *fp;
    int y, x;

    if(argc != 2)
    {
        printf("Usage: %s <a c file name>\n", argv[0]);
        exit(1);
    }
    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        perror("Cannot open input file");
        exit(1);
    }
    initscr(); // Start curses mode 
    getmaxyx(stdscr, row, col); // find the boundaries of the screeen
    while((ch = fgetc(fp)) != EOF) // read the file till we reach the end
    {
        printw("%c", ch);
        getyx(stdscr, y, x); // get the current curser position
        if(y == (row - 1)) // are we are at the end of the screen
        {
            printw("<-Press Any Key->"); // tell the user to press a key
            getch();
            clear(); //clear the screen 
            move(0, 0); // start at the beginning of the screen
        }
        if(prev == '/' && ch == '*') // If it is / and * then only switch bold on   
        {
            attron(A_BOLD); // cut bold on 
            getyx(stdscr, y, x); // get the current curser position 
            move(y, x - 1); // back up one space 
            printw("%c%c", '/', ch); // The actual printing is done here
        }
        else
            printw("%c", ch);

        refresh();

        if(prev == '*' && ch == '/')
            attroff(A_BOLD); // Switch it off once we got and then
        prev = ch;
    }
    endwin(); // End curses mode
    fclose(fp);
    */
    return 0;
}