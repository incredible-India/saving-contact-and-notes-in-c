
#define ENTER 13
#define TAB 9
#define BKSP 8
#define ESC 27
#include<conio.h>

void gotoxy(int,int);///it will change the position of  coordinates
void setcolor(int);///it helps to change the only font color
void mkhor(int,int,int,char);///makes a horizontal bar
void mkver(int,int,int,char);///makes the vertical bar
void OpenMenu(void);///open the menu
void ExitFunction(void);///Exit label
void AddContact(char[],char[]);/// save the contact information
void makeExitFunctio(void);///templates of exit and back button
/*void openFileLocation(void);///show the file address information */
void seeAllContacts(void);///print all the contacts list
void AddNotes(void);///add your personal Notes
void SaveTheNotes(char []);///this will save the notes
void seemyAllNotes(void);///show all notes
void  DeleteAllContacts(void);///delete all the contacts list
void  DeleteAllNotes(void);///delete all the notes



void WelCome(void)
{
   extern int i;
   SetConsoleTitle("Title  Himanshu");
   char printName[]="CONTACT INFO..";
   mkhor(35,12,30,'/');
   mkhor(35,18,30,'/');
   gotoxy(45,15);
   for(i=0;i<=strlen(printName);i++)
   {
       Sleep(100);
       printf("%c",(printName[i]));

   }

   Sleep(500);
   setcolor(26);
     gotoxy(45,15);
     printf("%s",printName);

Sleep(600);
return ;

}


void OpenMenu(void)
{
    extern int i;

    readAgain:
readData:
 SetConsoleTitle("MenuBAr Himanshu");
SYSTEMTIME tellTime;
GetSystemTime(&tellTime);
 system("cls");
gotoxy(90,3);
printf("%d/%d/%d",tellTime.wDay,tellTime.wMonth,tellTime.wYear);

    setcolor(22);
    mkhor(30,7,50,'.');
    mkhor(30,25,50,'.');
    mkver(30,7,18,'.');
    mkver(80,7,18,'.');

    gotoxy(46,10);
    setcolor(20);
    printf("1 : Add Contact");
    setcolor(21);
      gotoxy(46,12);
    printf("2 : See All Contacts");
    setcolor(23);
     gotoxy(46,14);
    printf("3 : Add Note");
    setcolor(24);
     gotoxy(46,16);
    printf("4 : See All Notes");
    setcolor(25);
     gotoxy(46,18);
    printf("5 : Delete All Contacts");
    setcolor(26);
     gotoxy(46,20);
    printf("6 : Delete All Notes");
    setcolor(27);
     gotoxy(46,22);
    printf("7 : Open File Location");
    setcolor(102);
    gotoxy(50,27);
    printf("Esc : Exit");

    {

        char ch;
        ch=getch();
        if(ch=='1')
        {

           {
               char contactName[100],contactNumber[20];

               readAgain2:
                        readAgain5:
                system("cls");

                setcolor(41);
                mkhor(40,10,50,'*');
                mkhor(40,25,50,'*');
                mkver(40,10,15,'*');
                mkver(90,10,15,'*');
                setcolor(65);
                gotoxy(45,15);

                printf("Enter Name : ");
                 fflush(stdin);
                gets(contactName);

  gotoxy(45,20);
  setcolor(66);
                printf("Enter Number : ");
                fflush(stdin);
                gets(contactNumber);
                if(strlen(contactNumber)<10)
                {

                    system("cls");
                    system("color 72");
                    gotoxy(40,12);
                    printf("Please Enter at least 10 digit Number...");
                    getch();
                    goto readAgain2;
                }
                gotoxy(56,27);
                setcolor(23);
                printf("1 : Save");
                makeExitFunctio();
                {

                    char choise;
                    choise=getch();
                    if(choise=='1')
                    {
                         AddContact(contactName,contactNumber);
                          readAgain7:
                         system("cls");
                         gotoxy(40,12);
                         printf("Your Contact has been Saved");
                         gotoxy(2,6);
                         printf("M : Main Menu");
                                makeExitFunctio();
                                {
                                    char op;
                                    op=getch();
                                    if(op == ESC)
                    {
                        ExitFunction();
                    }else if(op == BKSP)
                    {
                        goto readAgain5;

                    }else if(op == 'm' || op == 'M'){

                        OpenMenu();
                        }else
                    {
                        printf("\a");
                        goto readAgain7;

                    }
                                }

                    }else if(choise == BKSP){

                        goto readData;
                    }
                    else {
                     printf("\a");
                     goto readData;
                    }

                }



           }

        }else if(ch=='2')
        {
            seeall:
   system("cls");
   SetConsoleTitle("All contacts Himanshu");
        makeExitFunctio();
        gotoxy(2,6);
        setcolor(26);
        printf("1 : Search Contacts");
       gotoxy(2,10);
       printf("================================\n");
        setcolor(27);
        seeAllContacts();
        {
            char option;
            option=getch();
            if(option == '1')
            {


            }else if(option == ESC)
            {

                ExitFunction();
            }
            else if(option == BKSP)
            {

                goto readData;
            }else{

            printf("\a");
            goto seeall;

        }
        }}else if(ch=='3')
        {
          AddNotes();

        }else if(ch=='4')
        {
            seemyAllNotes();
        }else if(ch=='5')
        {
            DeleteAllContacts();
        }else if(ch=='6')
        {
            DeleteAllNotes();

        }else if(ch=='7')
        {
            return ;

        }
        else if(ch==ESC)
        {
      ExitFunction();
        }
        else{
            printf("\a");
            goto readAgain;
        }

    }
}

void AddNotes(void)
{

    char display[]="Add Notes Press Tab to complete";

    char myNotes[10000];
   SetConsoleTitle("MAke Ur Notes himanshu");
    extern int i;

    system("cls");

    gotoxy(40,12);
    for(i=0;i<=strlen(display);i++)
    {

        printf("%c",display[i]);
        Sleep(60);

    }
    Sleep(60);
    setcolor(12);
    gotoxy(40,12);
    printf("%s",display);

    Sleep(100);
    system("cls");
    gotoxy(30,3);
    printf("%s",display);
    setcolor(17);
    mkhor(1,5,100,'.');
    gotoxy(3,7);
    fflush(stdin);
    scanf("%[^\t]",myNotes);

 makeExitFunctio();
 gotoxy(80,4);
 printf("Enter : Save");
{

    char choice ;
    readData3:
    choice=getch();
    if(choice==ESC)
    {

        ExitFunction();
    }else if(choice == ENTER)
    {

        SaveTheNotes(myNotes);
        system("cls");
        gotoxy(40,12);
        printf("Notes saved");
        getch();
        OpenMenu();

    }else if(choice == BKSP)
    {
       OpenMenu();


    }
    else {
        printf("\a");
        goto readData3;
    }
}




}
