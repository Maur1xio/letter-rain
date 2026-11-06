#include "pch.h"
#include <iostream>

using namespace System;
using namespace std;

const int COL = 200;
const int ROW = 45;
const int marginX = 4;

void setInitialConfig() {
    Console::SetWindowSize(COL, ROW);
    Console::SetBufferSize(COL, ROW);
    srand(time(nullptr));
}

int getRandomNum(int x, int y) {
    return rand() % (y - x + 1) + x;
}

void goToXY(int x, int y) {
    Console::SetCursorPosition(x, y);
}

char getRandomChar() {
    int boolResult = getRandomNum(0, 1);
    if (boolResult == 0) return char(getRandomNum(65, 90));
    return char(getRandomNum(97, 122));
}

int f(int x) {
    return x + (x - 1) * marginX;
}

void printLetter(int x, int y, char c){
    goToXY(x, y);
    cout << c;
}

void deleteLetter(int x, int y) {
    goToXY(x, y);
    cout << " ";
}

int main() {
    setInitialConfig();
    int n; 
    do
    {
        cout << "Cuantas letras quieres que lluevan? "; cin >> n;
    } while (f(n) >= COL);
    Console::CursorVisible = false;

    system("cls");
    int* Y = new int[n];
    int* X = new int[n];
    int* dY = new int[n];
    char* L = new char[n];
    for (int i = 0; i < n; i++) Y[i] = 0;

    X[0] = (COL - f(n)) / 2;
    for (int i = 1; i < n; i++) {
        X[i] = X[i-1] + marginX + 1;
    }

    for (int i = 0; i < n; i++) dY[i] = getRandomNum(1,3);
    for (int i = 0; i < n; i++) L[i] = getRandomChar();


    while (1) {
        //BORRAR N ENTIDADES
        for (int i = 0; i < n; i++){
            int yi = Y[i];
            int xi = X[i];
            deleteLetter(xi, yi);
        }

        //CAMBIAR COORDENADAS DE N ENTIDAD
        for (int i = 0; i < n; i++) {
            if(Y[i] + dY[i] < ROW - 1) Y[i] += dY[i];
        }

        //PINTAR N ENTIDADES
        for (int i = 0; i < n; i++) {
            int yi = Y[i];
            int xi = X[i];
            char ci = L[i];
            printLetter(xi, yi,ci);
        }

        _sleep(50);
    }


    cin.get();
    cin.ignore();

    return 0;
}
