#include<iostream>
#include"mylib.h"
#include"vetuong.h"
using namespace std;
#define MAX 100
int sl = 4;

void Initial_snake(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int &xqua, int &yqua);
void them(int a[], int x);
void xoa(int a[], int vt);
void xoa_du_lieu_cu(int toadox[], int toadoy[]);
bool ran_cham_tuong(int x0, int y0);
bool kt_cham_duoi(int toadox[], int toadoy[]);
bool kt_ran(int toadox[], int toadoy[]);
void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[]);
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]);
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0);

int main() {
	
	bool gameover = false;
	int toadox[MAX];
	int toadoy[MAX];
	ve_tuong();
	Initial_snake(toadox, toadoy);
	ve_ran(toadox, toadoy);
	//===========kt va tao qua=========//
	srand(time(NULL));
	int xqua = 0, yqua = 0;
	//tao qua;
	tao_qua(xqua, yqua, toadox, toadoy);

	int x = 50;
	int y = 13;//dinh hinh vi tri can di chuyen cho ran
	int check = 2;//kiểm tra biên
	while (gameover==false)
	{
		xoa_du_lieu_cu(toadox, toadoy);
	//0 nhắm vào biên trên đi xuống
	//1 nhắm vào biên dưới đi lên
	//2 chạm vào biên phải-đi qua trái
	//3 chạm vào biên trái - đi qua phải
		if (_kbhit()) {
			char kitu = _getch();
			if (kitu == -32) {
				kitu = _getch();
				if (kitu == 72 && check != 0)
					check = 1;//đi lên
				else if (kitu == 80 && check != 1)
					check = 0;//di xuong
				else if (kitu == 77 && check != 3)
					check = 2;
				else if (kitu == 75 && check != 2)
					check = 3;
			}
		}
		if (check == 0) {
			//đi xuống
			y++;
		}
		else if (check == 1) {
			//di le
			y--;
		}
		else if (check == 2) {
			//di qua phai
			x++;

		}
		else if (check == 3) {
			//di qua trai
			x--;
		}
		gameover = kt_ran(toadox, toadoy);
		xu_ly_ran(toadox, toadoy, x, y,xqua,yqua);
		Sleep(100);
	}
	_getch();
	return 0;
}



void Initial_snake(int toadox[], int toadoy[]) {
	int x = 50;
	int y = 13;
	for (int i = 0; i < sl; i++) {
		toadox[i] = x;
		toadoy[i] = y;
		x--;

	}
}
//void ve_ran(int toadox[], int toadoy[]) {
//	for (int i = 0; i < sl; i++) {
//
//
//		gotoXY(toadox[i], toadoy[i]);
//		if (i == 0)
//			cout << "0";
//		else
//			cout << "o";
//	
//	}
//}
void ve_ran(int toadox[], int toadoy[]) {
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 34);
	for (int i = 0; i < sl; i++) {
		gotoXY(toadox[i], toadoy[i]);
		cout << " ";
	}
	SetConsoleTextAttribute(hConsoleColor, 15);
}

void xoa_du_lieu_cu(int toadox[], int toadoy[]) {
	for (int i = 0; i < sl; i++) {


		gotoXY(toadox[i], toadoy[i]);
		cout << " ";
	}
}
void xu_ly_ran(int toadox[],int toadoy[],int x,int y,int &xqua,int &yqua){
	//b1: them 1 toa do moi vaof dau mang
	them(toadox, x);
	them(toadoy, y);
	if (kt_ran_an_qua(xqua ,yqua, toadox[0], toadoy[0])==false) {
		//b2: xoa toado cuoi mang
		xoa(toadox, sl - 1);
		xoa(toadoy, sl - 1);
	}
	else {
		tao_qua(xqua, yqua, toadox, toadoy);
	}
	//b3: ve ran
	ve_ran(toadox, toadoy);
	


}
void them(int a[], int x) {
	for (int i = sl; i > 0; i--) {
		a[i] = a[i - 1];
	}
	a[0] = x;
	sl++;
}
void xoa(int a[], int vt) {
	for (int i = vt; i < sl; i++) {
		a[i] = a[i + 1];
	}
	sl--;
}
//game over
bool ran_cham_tuong(int x0, int y0) {
	//ran cham tuong tren
	if (y0 == 1 && (x0 >= 0 && x0 <= 100)) {
		return true;
		//game over
	}
	//ran cham tuong duoi
	else if (y0 == 26 && (x0 >= 0 && x0 <= 100)) {
		return true;
	}
	//cham tuong phai
	else if (x0 == 100 && (y0 >= 1 && y0 <= 26)) {
		return true;
	}
	//cham tuong trai
	else if (x0 == 0 && (y0 >= 1 && y0 <= 26)) {
		return true;
	}
	return false;
}
bool kt_cham_duoi(int toadox[], int toadoy[]) {
	for (int i = 1; i < sl; i++) {
		if (toadox[0] == toadoy[i] && toadoy[0] == toadoy[i]) {
			return true;
		}
	}
	return false;
}
bool kt_ran(int toadox[], int toadoy[]) {
	bool kt1 = kt_cham_duoi(toadox, toadoy);
	bool kt2 = ran_cham_tuong(toadox[0], toadoy[0]);
	if (kt1 == true || kt2 == true) {
		return true;
	}
	return false;
}
/////////////////////////////////////////////////////////////////////
void tao_qua(int& xqua, int &yqua, int toadox[], int toadoy[]) {
	
	do {
		//1 <=xqua <= 99
		xqua = rand() % (99 - 1 + 1) + 1;
		//2 <=yqua <=25
		yqua = rand() % (25 - 2 + 1) + 2;
	} while (kt_ran_de_qua(xqua, yqua, toadox, toadoy)==true);
	gotoXY(xqua, yqua);
	int i = rand() % (15 - 1 + 1) + 1;
	SetColor(i);
	cout << "$";
}
bool kt_ran_de_qua(int xqua, int yqua,int toadox[], int toadoy[]){
	for (int i = 0; i < sl; i++) {
		if (xqua == toadox[i] && yqua == toadoy[i]) {
			return true;
			//ran de lem qua
		}
	}
	return false;
}
//tăng độ dài của rắn khi ăn quả
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0) {
	if (x0 == xqua && y0 == yqua) {
		return true;
		//ran an qua
	}
	return false;
}