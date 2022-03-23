#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>



//funcao para definir o tempo no ar
void delay(float segundos)
{
    float milissegundos = 1000 * segundos;
    clock_t start = clock();
    while (clock() < start + milissegundos);
}

//funcao para a inicializacao da posicao do cursor no console
void gotoxy1(int x, int y)
{
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

