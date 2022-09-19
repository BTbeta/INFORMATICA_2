/**************************************
 *zeng oscar                          *
 *4H                                  *
 *15/09/2022                          *
 *esercizio in classe                 *
 **************************************/
//dichiarazione delle librerie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//dichiarazione dei costanti
#define R 3
#define C 3
//dichiarazione dei funzioni
void caricaVET_rand(int[]);//carica numeri casuali nel vettore
void caricaMAT_rand(int[][C]);//carica numeri casuali nella matrice
void caricaVET_manuale(int[]);//carica numeri manualmente nel vettore
void caricaMAT_manuale(int[][C]);//carica numeri manualmente nella matrice
void visualizzaVET(int[]);//vissualizza i numeri nel vettore
void visualizzaMAT(int[][C]);//vissualizza i numeri nella matrice
void visualizzaMAT_orinzontale(int[][C],int);//vissualizza una delle righe
void visualizzaMAT_verticale(int[][C],int);//vissualizza una delle collone
void visualizzaMAT_diagonale(int[][C]);//vissualizza i numeri che stanno diagonalmente nella matrice
int main()
{
	int v[R],m[R][C],a;
	srand(time(NULL));
	caricaVET_rand(v);
	visualizzaVET(v);
	printf("\n");
	caricaMAT_rand(m);
	visualizzaMAT(m);
	printf("\n");
	caricaVET_manuale(v);
	visualizzaVET(v);
	printf("\n");
	caricaMAT_manuale(m);
	visualizzaMAT(m);
	printf("\n");
	do
	{
		printf("inserisci un numero tra 0 a 2\n");
		scanf("%d",&a);
	}while(a<0||a>=R);
	visualizzaMAT_orinzontale(m,a);
	printf("\n");
	visualizzaMAT_verticale(m,a);
	printf("\n");
	visualizzaMAT_diagonale(m);
	printf("\n");
}
void caricaVET_rand(int x[])
{
	int i;
	for(i=0;i<R;i++)
	{
		x[i]=rand()%101;
	}
}
void caricaMAT_rand(int x[][C])
{
	int i;
	for(i=0;i<C;i++)
	{
		caricaVET_rand(x[i]);
	}
}
void caricaVET_manuale(int x[])
{
    int i;
	for(i=0;i<C;i++)
	{
		scanf("%d",&x[i]);
	}
}
void caricaMAT_manuale(int x[][C])
{
	int i;
	for(i=0;i<R;i++)
	{
		caricaVET_manuale(x[i]);
	}
}
void visualizzaVET(int x[])
{
	int i;
	for(i=0;i<R;i++)
	{
		printf("%d\t",x[i]);
	}
	printf("\n");
}
void visualizzaMAT(int x[][C])
{
	int i;
	for(i=0;i<R;i++)
	{
		visualizzaVET(x[i]);
	}
}
void visualizzaMAT_orinzontale(int x[][C],int y)
{
	int i;
	for(i=0;i<R;i++)
	{
		printf("%d\t",x[y][i]);
	}
	printf("\n");
}
void visualizzaMAT_verticale(int x[][C],int y)
{
	int i;
	for(i=0;i<R;i++)
	{
		printf("%d\t",x[i][y]);
	}
	printf("\n");
}
void visualizzaMAT_diagonale(int x[][C])
{
	int i;
	for(i=0;i<R;i++)
	{
		printf("%d\t",x[i][i]);
	}
	printf("\n");
}
