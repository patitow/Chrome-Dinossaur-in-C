#include <windows.h>// Biblioteca dos códigos do cmd
#include <stdio.h> // Biblioteca de entrada e saída de dados
#include <stdlib.h>// Biblioteca de conversão das strings
#include <time.h>// biblioteca de manipulação de periodos
#include <locale.h> // Biblioteca de acentuação de caracteres
#include <conio.h>// Biblioteca de manipulação de caracteres
#include "Funcoes.h"

//declarando variaveis globais para a inicalizaca das coordenadas do Dino
int dinoX=10, dinoY=15;
int cactoX=70, cactoY=18;
float p;
int a=1;

//funcao que determina a posicao do dino no console
void printdino(int a)
{
    gotoxy1(dinoX,dinoY-1);
    printf("                  ");
    gotoxy1(dinoX,dinoY);
    printf("          e-e     ");
    gotoxy1(dinoX,dinoY+1);
    printf("         /(\/)  ");
    gotoxy1(dinoX,dinoY+2);
    printf(" .__.-- /'-'    ");
    gotoxy1(dinoX,dinoY+3);
    printf("  `-.. )/'    ");
    gotoxy1(dinoX,dinoY+4);
    if(a==1)
    {
        gotoxy1(dinoX,dinoY+4);
        printf("     \\\\/  ");
        gotoxy1(dinoX,dinoY+5);
        printf("      ''  ");
    }
    else
    {
        gotoxy1(dinoX,dinoY+4);;
        printf("    // \\\\ ");
        gotoxy1(dinoX,dinoY+5);
        printf("    ''  ''");
    }

    if(dinoY!=15)
    {
        gotoxy1(dinoX,dinoY+6);
        printf("                ");
    }
}

// funcao que determina o movimento do cacto
void printcacto(int cac)
{

    gotoxy1(cactoX,cactoY-1);
    printf("   ...  ");
    gotoxy1(cactoX,cactoY+0);
    printf("  ..... ");
    gotoxy1(cactoX,cactoY+1);
    printf("   ... ");
    gotoxy1(cactoX,cactoY+2);
    printf("   ... ");
    gotoxy1(cactoX,cactoY+3);

}

int main()
{

    //menu
    int a=0;

    system("color 8F");
    printf("                                              BEM VINDOS AO JOGO DINO EXE!!!\n\n");
    printf("                            DICAS: Para navegar pelo menu basta digitar o numero que voce deseja.\n\n");
    printf("                                                --> 1 - JOGAR\n");
    printf("                                                --> 2 - CREDITOS\n");
    printf("                                                --> 3 - SAIR\n");


    printf("\n\n                                        xxxxxxx     x   xx    x    xxxxxxx");
    printf("\n                                        x      x    x   x x   x    x     x");
    printf("\n                                        x       x   x   x  x  x    x     x");
    printf("\n                                        x      x    x   x   x x    x     x");
    printf("\n                                        xxxxxxx     x   x     x    xxxxxxx");
    printf("\n\n");
    printf("\n                                               x xx    x    x   x xx");
    printf("\n                                               x        x  x    x");
    printf("\n                                               x xx       x     x xx");
    printf("\n                                               x        x  x    x");
    printf("\n                                               x xx    x    x   x xx");
    printf("\n\n SUA OPCAO ESCOLHIDA FOI --> ");
    scanf("%d", &a);

    //opcao inicializando
    switch(a)
    {

    //inicializando o jogo
    case 1:
        system("cls");
        system("color 1");
        gotoxy1(1,dinoY+6);
        printf("================================================================================");
        printf("\n          ==============================================================   ");
        printf("\n                   ========================================     ");
        printf("\n                               ================       ");
        float tempo=1.5;
        int movimento=0, contagem=0, morreu=0;

        do
        {
            gotoxy1(80,5);
            printf("|YOUR SCORE --> %i|", contagem);
            for(movimento=1; movimento<=70; movimento++)
            {
                if(!kbhit())
                {
                    printdino(1);
                    delay(tempo/40);
                    printdino(2);
                    delay(tempo/40);
                    cactoX-=1;
                    printcacto(1);
                    gotoxy1(80,5);
                    if((cactoX<20) && (dinoY > 14))
                    {
                        morreu++;
                    }
                }
                else if(getch()=='w')
                {
                    int subida;

                    for(subida=1; subida<=13; subida++)
                    {
                        dinoY-=1;
                        printdino(2);
                        delay( tempo/20.0  );
                        printdino(2);
                        cactoX-=1;
                        printcacto(1);
                        movimento++;
                        gotoxy1(80,5);
                    }

                    for(subida=1; subida<=13; subida++)
                    {
                        dinoY+=1;
                        printdino(2);
                        delay( tempo/20.0);
                        printdino(2);
                        cactoX-=1;
                        printcacto(1);
                        movimento++;
                        gotoxy1(80,5);
                    }
                    dinoY=15;
                }
            }
            cactoX=70;
            contagem++;
            system("cls");
            gotoxy1(1,dinoY+6);
            printf("================================================================================");
            printf("\n          ==============================================================   ");
            printf("\n                   ========================================     ");
            printf("\n                               ================       ");
            if(tempo>0.2)
            {
                tempo=tempo-0.03;
            }
        }
        while(morreu<=0);
        system("cls");
        system("color 6");
        printf("SUA PONTUACAO --> [%i]\n\nQUE PENA VC PERDEU,TENTE NOVAMENTE!!\n", contagem);
        break;

    //creditos da equipe
    case 2:

        system("cls");
        system("color 5");
        printf("Membros da equipe:\n\nMembro 1 - Tales Paiva\nMembro 2 - Djair Maynart\nMembro 3 - Davi Magalhaes\nMembro 4 - Mariana Tavares\n");

        break;

    //opçao de saida do console
    case 3:
        system("cls");
        system("color 4");
        printf("FECHANDO SEU PROGRAMA AGUARDE ALGUNS INSTANTES...");
        for(a=0; a<10; a++)
        {
            printf(".");
            Sleep(250);
        }

        break;

    default:
        system("cls");
        system("color 4");
        printf("POR FAVOR, ESCOLHA UMA OPCAO VALIDA (DENTRE 1 ATE 3)!!\n");

        break;

    }
    return 0;
}
