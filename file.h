void OpenMenu(void);


void AddContact(char contactName[],char contactNumber[])
{

FILE *contactPtr,*forName;
 contactPtr=fopen("My Conatcts.txt","a");
 forName=fopen("Name only.txt","a");
SetConsoleTitle("My Contacts Himanshu");
fputs(strupr(contactName),contactPtr);
fprintf(contactPtr,"\t");
fputs(contactNumber,contactPtr);
fprintf(contactPtr,"\n");
fputs(strupr(contactName),forName);
      fprintf(forName,"\n");
fclose(contactPtr);

}
/*
void openFileLocation()
{

    printf("hello world");
}*/


void seeAllContacts(void)
{

    FILE *printContact;
    printContact=fopen("My Conatcts.txt","r");
    char ch;
    if(printContact == NULL)
    {

            system("cls");
        printf("It seems that file has been deleted");
        getch();
        OpenMenu();
    }
    ch=fgetc(printContact);
    while(ch!=EOF)
    {

        printf("%c",ch);

        ch=fgetc(printContact);

    }
    fclose(printContact);
}

void SaveTheNotes(char myNotes[])
{
    time_t t;
    time(&t);

    FILE *MyNotesRaed;
    MyNotesRaed=fopen("My Notes.txt","a");

    fprintf(MyNotesRaed,"=======================================================\n");
    fprintf(MyNotesRaed,"%s\n",ctime(&t));
    fputs(myNotes,MyNotesRaed);
     fprintf(MyNotesRaed,"\n=======================================================\n");

fclose(MyNotesRaed);


}

void seemyAllNotes(void)
{

    FILE *readNotes;
    char ch;
    myfile:
        SetConsoleTitle("See Notes Himanshu");
    readNotes=fopen("My Notes.txt","r");
    system("cls");
    makeExitFunctio();

    if(readNotes==NULL)
    {
        system("cls");
        printf("It seems that file has been deleted");
        getch();
        OpenMenu();

    }else
    {
        gotoxy(5,8);
        ch=fgetc(readNotes);
        while(ch!=EOF)
        {

            printf("%c",ch);
            ch=fgetc(readNotes);
        }
    fclose(readNotes);
    {

        char exi;
        exi=getch();
        if(exi == ESC)
        {

            ExitFunction();
        } else if(exi == BKSP)
        {
            OpenMenu();


        }else{
            printf("\a");
            goto myfile;
        }
    }

    }
}

void  DeleteAllContacts(void)
{
    int k;
    k=remove("My Conatcts.txt");
    if(k==0)
    {

        system("cls");
        gotoxy(40,12);
        printf("File has been deleted Successfully !");
        getch();
        OpenMenu();
    }else{

        system("cls");
        gotoxy(40,12);
        printf("File has  already been deleted !!");
        getch();
        OpenMenu();
    }
}

void  DeleteAllNotes(void)
{
    int k;
    k=remove("My Notes.txt");
    if(k==0)
    {

        system("cls");
        gotoxy(40,12);
        printf("File has been deleted Successfully !");
        getch();
        OpenMenu();
    }else{

        system("cls");
        gotoxy(40,12);
        printf("File has  already been deleted !!");
        getch();
        OpenMenu();
    }
}
