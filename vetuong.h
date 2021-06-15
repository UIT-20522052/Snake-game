#pragma once
#include<iostream>
#include"mylib.h"
using namespace std;

//void tuongTren() {
//	int x = 10;
//	int y = 1;
//	while (x < 100) {
//		gotoXY(x, y);
//		cout << "+";
//		x++;
//	}
//}
//void tuongDuoi() {
//	int x = 10;
//	int y = 26;
//	while (x < 100) {
//		gotoXY(x, y);
//		cout << "+";
//		x++;
//	}
//}
//void tuongPhai() {
//	int x = 100, y = 1;
//	while (y <= 26) {
//		gotoXY(x, y);
//		cout << "+";
//		y++;
//	}
//}
//void tuongTrai() {
//	int x = 10, y = 1;
//	while (y <= 26) {
//		gotoXY(x, y);
//		cout << "+";
//		y++;
//	}
//}
//void ve_tuong() {
//	SetColor(11);
//	tuongTren();
//	tuongDuoi();
//	tuongTrai();
//	tuongPhai();
//	SetColor(7);
//}
void ve_tuong() {
	//color
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	// 34: xanh la
	// 119: trang
	// 15: den
	// 68: do

	int column = 100;
	int line = 26;


	//V? khung ? trên và 2 bên
	for (int i = 0; i < column; i++) {
		SetConsoleTextAttribute(hConsoleColor, 119);
		cout << " ";
	}
	SetConsoleTextAttribute(hConsoleColor, 15);
	cout << endl;
	for (int i = 0; i < line; i++) {
		gotoXY(0, i);
		SetConsoleTextAttribute(hConsoleColor, 119);
		cout << " ";
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoXY(column - 1, i);
		SetConsoleTextAttribute(hConsoleColor, 119);
		cout << " ";
		SetConsoleTextAttribute(hConsoleColor, 15);
	}
	//V? khung ? trên và 2 bên

	//V? khung ? d??i ?áy
	gotoXY(0, line);
	for (int i = 0; i < column; i++) {
		SetConsoleTextAttribute(hConsoleColor, 119);
		cout << " ";
	}
	SetConsoleTextAttribute(hConsoleColor, 15);
	//V? khung ? d??i ?áy
}