void ran_dai_khi_an_qua(int toadox[], int toadoy[], int x, int y, int& xqua, int& yqua) {
    //b1: them 1 toa do moi vaof dau mang
    them(toadox, x);
    them(toadoy, y);
    if (kt_ran_an_qua(xqua, yqua, toadox[0], toadoy[0]) == false) {
        //b2: xoa toado cuoi mang
        xoa(toadox, sl - 1);
        xoa(toadoy, sl - 1);
    }
    else {
        tao_qua(xqua, yqua, toadox, toadoy);//hàm tao qua và ran ko dc de qua
    }
    //b3: ve ran
    ve_ran(toadox, toadoy);//hàm ve con ran
}
////////////////ham con////////////////////////

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
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0) {
    if (x0 == xqua && y0 == yqua) {
        return true;
        //ran an qua
    }
    return false;
}
void ve_ran(int toadox[], int toadoy[]) {
    for (int i = 0; i < sl; i++) {


        gotoXY(toadox[i], toadoy[i]);
        if (i == 0)
            cout << "0";
        else
            cout << "o";

    }
}
void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[]) {

    do {
        //11 <=xqua <= 99
        xqua = rand() % (99 - 11 + 1) + 11;
        //2 <=yqua <=25
        yqua = rand() % (25 - 2 + 1) + 2;
    } while (kt_ran_de_qua(xqua, yqua, toadox, toadoy) == true);
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
