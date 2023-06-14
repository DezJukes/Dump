#include <stdio.h>
#include <conio.h>
#include <windows.h>
void gotoxy(short x, short y){
	COORD c = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct EmpRecord{
      int    No;
      char   Name[25];
      char   Pos[15];
      float  Salary;
    };
int main()
{
 struct EmpRecord  EMPLOYEE[2];
 float      DED,NSal,TSalary;
 int        ctr;
 char       Temp;

 
 for(ctr=0;ctr<=1;ctr++)
   {
     
     printf("<@@@ EMPLOYEE INFORMATION @@@>\n\n");
     printf("Record No. %d:\n",ctr+1);
     printf("Enter Employee No. : ");
     scanf("%d",&EMPLOYEE[ctr].No);
     scanf("%c",&Temp);
     printf("Enter Employee Name: ");
     gets(EMPLOYEE[ctr].Name);
     printf("Enter Position     : ");
     gets(EMPLOYEE[ctr].Pos);
     printf("Enter Employee Salary: PhP ");
     scanf("%f",&TSalary);
     EMPLOYEE[ctr].Salary=TSalary;
     printf("\n\nPress Any Key to Continue...\n\n");
     
  }
  system("cls");
  
  gotoxy(32,3);printf("PAYROLL REPORT");
  gotoxy(5,5);printf("EMP No.      EMPLOYEE NAME    POSITION    G. SALARY  DEDUCTION   N. SALARY");
  for(ctr=0;ctr<=1;ctr++)
  {
    DED = EMPLOYEE[ctr].Salary * 0.20;
    NSal = EMPLOYEE[ctr].Salary - DED;
    gotoxy(2,ctr+7);printf("%2d.",ctr+1);
    gotoxy(6,ctr+7);printf("%d",EMPLOYEE[ctr].No);
    gotoxy(15,ctr+7);printf("%s",EMPLOYEE[ctr].Name);
    gotoxy(35,ctr+7);printf("%s",EMPLOYEE[ctr].Pos);
    gotoxy(46,ctr+7);printf("P%6.2f",EMPLOYEE[ctr].Salary);
    gotoxy(58,ctr+7);printf("P%6.2f",DED);
    gotoxy(70,ctr+7);printf("P%6.2f",NSal);
  }
 
 return(0);
}
