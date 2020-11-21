#include<stdio.h>
#include<windows.h>
#include"welcome.h"
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include"file.h"



void gotoxy(int,int);///it will change the position of  coordinates
void setcolor(int);///it helps to change the only font color
void mkhor(int,int,int,char);///makes a horizontal bar
void OpenMenu(void);///open the menu list
int i; ///global declaration of variable
int main(int args,char *argv[])
{
    void (*p)();
    p=WelCome;
    p();
    OpenMenu();
    system("cls");
    gotoxy(4,12);
  for(i=0;i<=args;i++)
  {
      printf("%s",argv[i]);


  }
getch();
OpenMenu();
getch();


}
void gotoxy(int a ,int b)
{
COORD x;
x.X=a;
x.Y=b;


SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),x);

}

void setcolor(int ForgC)
{
     WORD wColor;


     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;


     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void mkhor(int a,int b ,int c,char d )
{

extern int i;

    for(i=0;i<=c;i++)
    {
        gotoxy(a,b);
        printf("%c",d);
        ++a;

    }
}

void mkver(int a,int b ,int c,char d )
{

extern int i;

    for(i=0;i<=c;i++)
    {
        gotoxy(a,b);
        printf("%c",d);
        ++b;

    }
}

void ExitFunction(void)
{

    system("cls");
    system("color 71");
    gotoxy(40,12);
    printf("Thanx For Visiting Us");
    getch();
    exit(0);
}

void makeExitFunctio(void)
{
    gotoxy(2,2);
    printf("BKSP : BACK ");
    gotoxy(2,4);
    setcolor(44);
    printf("Esc : EXIT");

}
