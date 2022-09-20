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
#include<limits.h>
//dichiarazione dei costanti
#define R 5
#define C 5
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
void ordinaVET(int[]);//ordina il vettore
void ordinaMAT(int[][C]);//ordina la matrice
void ordinaMATorizontale(int[][C],int);//ordina una delle righe della matrice
void ordinaMATverticale(int[][C],int);//ordina una delle collonne della matrice
int ricercaConSentinellaVET(int[],int);//ricerca sentinella nel vettore
int ricercaConSentinellaMATR(int[][C],int,int);//ricerca sentinella riga della matrice
int ricercaConSentinellaMATC(int[][C],int,int);//ricerca sentinella collonna della matrice
int cercaMassimoVET(int[]);//cerca il più grande in un vettore
int cercaMinimoVET(int[]);//cerca il più piccolo in un vettore
int cercaMassimoVET_MAT(int[],int);//cerca il più grande in un vettore per il matrice
int cercaMinimoVET_MAT(int[],int);//cerca il più piccolo in un vettore per il matrice
int cercaMassimoMAT(int[][C]);//cerca il più grande in un matrice
int cercaMinimoMAT(int[][C]);//cerca il più piccolo in un matrice
int main()
{
	int v[R],m[R][C],a,b,c;
	srand(time(NULL));
	//test funzione caricaVET_rand e visualizzaVET
	caricaVET_rand(v);
	visualizzaVET(v);
	printf("\n");
	//test funzione caricaMAT_rand e visualizzaMAT
	caricaMAT_rand(m);
	visualizzaMAT(m);
	printf("\n");
	//test funzione caricaVET_manuale
	caricaVET_manuale(v);
	visualizzaVET(v);
	printf("\n");
	//test funzione caricaMAT_manuale
	caricaMAT_manuale(m);
	visualizzaMAT(m);
	printf("\n");
	//test funzione visualizzaMAT_orinzontale, visualizzaMAT_verticale e visualizzaMAT_diagonale
	do
	{
		printf("inserisci un numero tra 0 a %d\n",R-1);
		scanf("%d",&a);
	}while(a<0||a>=R);
	visualizzaMAT_orinzontale(m,a);
	printf("\n");
	visualizzaMAT_verticale(m,a);
	printf("\n");
	visualizzaMAT_diagonale(m);
	printf("\n");
	//test funzione ordinaVET
	ordinaVET(v);
	visualizzaVET(v);
	printf("\n");
	//test funzione ordinaMAT
	ordinaMAT(m);
	visualizzaMAT(m);
	printf("\n");
	//test funzione cercaMassimoVET
	a=cercaMassimoVET(v);
	printf("%d\n",a);
	//test funzione cercaMinimoVET
	a=cercaMinimoVET(v);
	printf("%d\n",a);
	//test funzione cercaMassimoVET_MAT e cercaMassimoMAT
	a=cercaMassimoMAT(m);
	printf("%d\n",a);
	//test funzione cercaMinimoVET_MAT e cercaMinimoMAT
	a=cercaMinimoMAT(m);
	printf("%d\n",a);
	//test funzione ordinaMATorizontale
	ordinaMATorizontale(m,a);
	visualizzaMAT(m);
	printf("\n");
	//test funzione ordinaMATverticale
	ordinaMATverticale(m,a);
	visualizzaMAT(m);
	printf("\n");
	printf("inserisci un numero da cercare\n");
	scanf("%d",&b);
	//test funzione ricercaConSentinellaVET
	c=ricercaConSentinellaVET(v,b);
	if(c==C)
	printf("non c'e'\n");
	else
	printf("e' nella cella %d\n",c);
	//test funzione ricercaConSentinellaMATR
	c=ricercaConSentinellaMATR(m,a,b);
	if(c==C)
	printf("non c'e'\n");
	else
	printf("e' nella cella %d\n",c);
	//test funzione ricercaConSentinellaMATC
	c=ricercaConSentinellaMATC(m,a,b);
	if(c==C)
	printf("non c'e'\n");
	else
	printf("e' nella cella %d\n",c);
}
void caricaVET_rand(int x[])
{
	int i;
	for(i=0;i<C;i++)
	{
		x[i]=rand()%101;
	}
}
void caricaMAT_rand(int x[][C])
{
	int i;
	for(i=0;i<R;i++)
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
	for(i=0;i<C;i++)
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
	for(i=0;i<C;i++)
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
void ordinaVET(int x[])
{
	int i,s,a;
	do
	{
		s=0;
		for(i=0;i<C-1;i++)
		{
			if(x[i]>x[i+1])
			{
				a=x[i];
				x[i]=x[i+1];
				x[i+1]=a;
				s=1;
			}
		}
	}while(s==1);
}
void ordinaMAT(int x[][C])
{
	int i,j,y=0,vet[R*C];
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			vet[y]=x[i][j];
			y++;
		}
	}
	ordinaVET(vet);
	y=0;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			x[i][j]=vet[y];
			y++;
		}
	}
}
void ordinaMATorizontale(int x[][C],int y)
{
	ordinaVET(x[y]);
}
void ordinaMATverticale(int x[][C],int y)
{
	int i,s,a;
	do
	{
		s=0;
		for(i=0;i<C-1;i++)
		{
			if(x[i][y]>x[i+1][y])
			{
				a=x[i][y];
				x[i][y]=x[i+1][y];
				x[i+1][y]=a;
				s=1;
			}
		}
	}while(s==1);
}
int ricercaConSentinellaVET(int x[],int y)
{
	int i,vet[C+1];
	for(i=0;i<C;i++)
	{
		vet[i]=x[i];
	}
	vet[C]=y;
	for(i=0;i<C+1;i++)
	{
		if(vet[i]==y)
		return i;
	}
}
int ricercaConSentinellaMATR(int x[][C],int y,int z)
{
	ricercaConSentinellaVET(x[y],z);
}
int ricercaConSentinellaMATC(int x[][C],int y,int z)
{
	int i,vet[C+1];
	for(i=0;i<R;i++)
	{
		vet[i]=x[i][y];
	}
	vet[C]=z;
	for(i=0;i<C+1;i++)
	{
		if(vet[i]==z)
		return i;
	}
}
int cercaMassimoVET(int x[])
{
	int i,a=INT_MIN;
	for(i=0;i<C;i++)
	{
		if(a<x[i])
		{
			a=x[i];
		}
	}
	return a;
}
int cercaMinimoVET(int x[])
{
	int i,a=INT_MAX;
	for(i=0;i<C;i++)
	{
		if(a>x[i])
		{
			a=x[i];
		}
	}
	return a;
}
int cercaMassimoVET_MAT(int x[],int y)
{
	int i;
	for(i=0;i<C;i++)
	{
		if(y<x[i])
		{
			y=x[i];
		}
	}
	return y;
}
int cercaMinimoVET_MAT(int x[],int y)
{
	int i;
	for(i=0;i<C;i++)
	{
		if(y>x[i])
		{
			y=x[i];
		}
	}
	return y;
}
int cercaMassimoMAT(int x[][C])
{
	int i,a=INT_MIN;
	for(i=0;i<R;i++)
	{
		a=cercaMassimoVET_MAT(x[i],a);
	}
	return a;
}
int cercaMinimoMAT(int x[][C])
{
	int i,a=INT_MAX;
	for(i=0;i<R;i++)
	{
		a=cercaMinimoVET_MAT(x[i],a);
	}
	return a;
}
