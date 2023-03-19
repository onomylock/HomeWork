#include <ncurses.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void read_file(char* buf);
void save_file(char* buf);
void sig_winch(int signo);

int main(void)
{
    WINDOW *wnd;
    errno = 0;
    int height, width, ch;

    initscr();
    signal(SIGWINCH, sig_winch);
    raw();
    printw("F1<open>    F2<save>    F3<close>");    
    refresh();
    wnd = newwin(LINES-2, COLS-1, 2, 2);
    curs_set(TRUE);    
    getyx(wnd, height, width);
    keypad(wnd, TRUE);
    wrefresh(wnd);

    while((ch = wgetch(wnd)) != KEY_F(3))
    {
        switch (ch)
        {
        case 10:
        {
            buf[i++]='\n';
            height++;            
            wmove(wnd, height, 0);
            break;
        }
        case KEY_BACKSPACE:
        {
            getyx(wnd, height, width);
            mvwaddch(wnd, height, width, ' ');            
            wmove(wnd, height, width); 
            break;           
        }
        case KEY_F(1):
        {
            wclear(wnd);
            wrefresh(wnd);            
            read_file(buf);
            int j = 0;
            // for(size_t j = 0; j < sizeof(buf); j++)
            // {
            //     waddch(wnd, buf[j]);
            // }
            while(buf[j] != '\0')
            {
                waddch(wnd, buf[j]);
                j++;
            }
            //waddstr(wnd, buf);
            break;
        }   
        case KEY_F(2):
        {
            buf[i++] = '\n';
            save_file(buf);
            break;
        }
        case KEY_LEFT:
        {
            width--;         
            wmove(wnd, height, width);
            break;
        }
        case KEY_RIGHT:
        {
            width++;            
            wmove(wnd, height, width);
            break;
        }
        case KEY_UP:
        {
            height--;            
            wmove(wnd, height, width);
            break;
        }
        case KEY_DOWN:
        {
            height++;            
            wmove(wnd, height, width);
            break;
        }
        default:
        {
            buf[i++] = ch;
            width++;            
            break;
        }            
                       
    }
    
    delwin(wnd);
    endwin();
    return 0;
    }
}