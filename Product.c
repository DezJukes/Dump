#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct ProdInfo {
	int productNum;
	char productName[15];
	float price;
	int quantity;
	float total;
};

int main(int argc, char *argv[]) {
	struct ProdInfo product[5];
	int ctr;
	char Temp;
	gotoxy(6,1);printf("Product No.");
	gotoxy(23,1);printf("Product Name");
	gotoxy(40,1);printf("Unit Price");
	gotoxy(55,1);printf("QTY.");
	gotoxy(65,1);printf("Total Price");
	
	for(ctr=0; ctr<=4; ctr++){
		gotoxy(1,ctr+3);printf("%d.", ctr+1);
		gotoxy(6,ctr+3);scanf("%d", &product[ctr].productNum);
		scanf("%c",&Temp);
		gotoxy(23,ctr+3);gets(product[ctr].productName);
		gotoxy(40,ctr+3);scanf("%f", &product[ctr].price);
		gotoxy(55,ctr+3);scanf("%d", &product[ctr].quantity);
		product[ctr].total = (product[ctr].price * product[ctr].quantity) * 1.12;
		gotoxy(65,ctr+3);printf("%.2f", product[ctr].total);
			
	}
	return 0;
}
