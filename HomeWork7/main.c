#include <ncurses.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#define MAX_LEN 512


FILE *open_file();
WINDOW *create_win(int height, int width);
void close_win(WINDOW *win);
void read_file(char* buf, int max_row);
void save_file(char* buf, int max_row);
void sig_winch(int signo);

int main(void)
{
    WINDOW *wnd;
    FILE *fd;
    errno = 0;
    int height, width, max_row = 0;
    char buf[MAX_LEN] = {0};
    char *file_buf;
    
    int ch, i = 0;

    initscr();
    signal(SIGWINCH, sig_winch);
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_GREEN);
    init_pair(2, COLOR_YELLOW, COLOR_BLUE);    
    raw();

    printw("F1<open>    F2<save>    F3<close>");    
    refresh();
    wnd = newwin(LINES-2, COLS-1, 1, 0);
    curs_set(TRUE);    
    getyx(wnd, height, width);
    keypad(wnd, TRUE);
    wrefresh(wnd);

    while((ch = wgetch(wnd)) != KEY_F(3) && (i < MAX_LEN) )
    {
        switch (ch)
        {
        case 10:
        {
            buf[i++]='\n';
            height++;
            max_row++;           
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
            //buf = {0};         
            read_file(&buf[0], max_row);
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
            //buf[i++] = '\n';
            //buf = {0};
            save_file(&buf[0], max_row);
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
    }
    
    delwin(wnd);
    endwin();
    return 0;
    

}

void sig_winch(int signo)
{
    struct winsize size;
    ioctl(fileno(stdout), TIOCGWINSZ, (char *) &size);
    resizeterm(size.ws_row, size.ws_col);
}

void read_file(char* buf, int max_row)
{
    size_t nr;
    int ch, i=0;    
    FILE *fd;
    fd = fopen("data", "r");
    if(!fd)
    {
        printf("err open file");        
        exit(1);
    }

    while(!feof(fd) && ch != EOF)
    {
        nr = fread(&ch, sizeof(char), 1, fd);  
        if (nr == 0) break;      
        if(ch == '\n') max_row++;
        buf[i] = ch;
        //buf++;
        i++;
    }

    //fread(buf, MAX_LEN, 1, fd);

    //while(i < MAX_LEN && feof(fd))
    //{     
    //    ch = fgetc(fd);
    //    buf[i++] = ch;
    //}

    fclose(fd);
}

void save_file(char* buf, int max_row)
{
    FILE *fd;    
    int i = 0, k;    
    //char *ptr = &buf;
    fd = fopen("data", "w");
    if(!fd)
    {
        printf("err open file");        
        exit(1);
    }

    //k = fwrite(buf, sizeof(buf), 1, fd);
    while(buf[i] != 0)
    {
        k = fwrite(&buf[i], sizeof(char), 1, fd);
        i++;
    }
    //k = fwrite(buf, MAX_LEN, 1, fd);

    //while()

    // while(i <= max_row)
    // {       
    //     if (sizeof(buf) == 0 && buf[sizeof(buf)] == EOF)
    //     {
    //         break;
    //     } 
    //     k = fwrite(buf, sizeof(buf), 1, fd);        
    //     buf+=sizeof(buf);
    //     i++;
    //     if(k == 0)
    //     {
    //         break;
    //     }
    //}

    //int k = fwrite(buf, sizeof(buf), 1, fd);

    //while(!(fwrite(&buf, sizeof(char), 1, fd)) && i < MAX_LEN)
    //{
    //    i++;
    //}

    // if(!(fputc(buf fd)))
    // {
    //     printf("err write file");
    //     exit(1);
    // }
    fclose(fd);
}