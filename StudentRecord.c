#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct StudInfo {
	char name[50];
	int age;
	int gwa;
};

int main(int argc, char *argv[]) {
	struct StudInfo student[2];
	int ctr;
	char Temp;
	
	system("cls");
	for(ctr=0; ctr<=1; ctr++){
		system("cls");
		
	printf("Enter your name: ");
	gets(student[ctr].name);
	
	printf("Enter your age: ");
	scanf("%d", &student[ctr].age);
	
	printf("Enter your GWA: ");
	scanf("%d", &student[ctr].gwa);
	scanf("%c",&Temp);
	printf("\n\nPress Any Key to Continue...\n\n");
    getch();
	}
	system("cls");
	gotoxy(32,1);
	printf("Student Record");
	gotoxy(5,3);
	printf("NO.");
	gotoxy(15,3);
	printf("NAME");
	gotoxy(25,3);
	printf("AGE");
	gotoxy(35,3);
	printf("GWA");
	
	for(ctr=0; ctr<=1; ctr++){
		gotoxy(5,ctr+5);printf("%d", ctr+1);
		gotoxy(15,ctr+5);printf("%s", student[ctr].name);
		gotoxy(25,ctr+5);printf("%d", student[ctr].age);
		gotoxy(35,ctr+5);printf("%d", student[ctr].gwa);
	}
	getch();
	return 0;
}
