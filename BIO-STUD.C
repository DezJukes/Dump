#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define GXY gotoxy

int main()
{
 char STUDNO[12],STUDNAME[25],CRSYR[10];
 float GWA;

 system("cls");
 GXY(20,3);printf("<@@ STUDENT INFORMATION @@>");
 gotoxy(10,6);printf("Student No.     :");
 gotoxy(10,8);printf("Student Name    :");
 gotoxy(10,10);printf("Course & Year   :");
 gotoxy(10,12);printf("GWA             :");
 gotoxy(10,14);printf("Academic Status :");
 gotoxy(30,6);gets(STUDNO);
 gotoxy(30,8);gets(STUDNAME);
 gotoxy(30,10);gets(CRSYR);
 gotoxy(30,12);scanf("%f",&GWA);
 gotoxy(30,14);
 if (GWA > 3.00)
    printf("Dismissed!");
 else
    printf("Good Standing!");
 getch();
 return(0);
}
