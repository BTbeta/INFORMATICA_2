/**************************************
 *zeng oscar                          *
 *4H                                  *
 *06/10/2022                          *
 *menu struct studente                *
 **************************************/
//inclusione di librerie
#include<stdio.h>		//untilizato per input e output
#include<stdlib.h>		//untilizato per  system e switch
#define N 3			
#define V 5
#define L 10
struct data
{
	int gg;
	char mm[L];
	int aaaa;
}typedef data;
struct student
{
	int matricola;
	char cognome[L];
	data nascita;
	int voti[V];
	int media;
}typedef student;
//funzione per vizzualizza i opzioni e inserimento
int opzioni(void);
//funzione per inserire informazioni nel struct
void inserimento(student[]);
//funzione per vissualizzare i valori dentro il struct
void visualizza(student[]);
//funzione per visualizare media
void media_studente(student[]);
int main()
{
	int a;
	student st1[N];
	do
	{
		a=opzioni();
		system("cls");
		switch(a)
		{
			case(0):
				printf("chiusura programma\n");
			break;
			case(1):
				inserimento(st1);
			break;
			case(2):
				visualizza(st1);
			break;
			case(3):
				media_studente(st1);
			break;
			default:
			printf("errore\n");
			break;
		}
		system("pause");
		system("cls");
	}while(a!=0);
	printf("ciao\n");
}
int opzioni()
{
	int a;
	printf("scegli un opzione\n");
	printf("0-uscire dal programma\n");
	printf("1-inserisci informazioni\n");
	printf("2-visualizza le informazioni\n");
	printf("3-visualizza media\n");
	scanf("%d",&a);
	return a;
}
void inserimento(student st[])
{
	int i,j,t=0,m;
	for(j=0;j<N;j++)
	{
		printf("inserisci informazioni studente %d\n",j+1);
		printf("matricola\n");
		scanf("%d",&st[j].matricola);
		printf("cognome\n");
		scanf("%s",st[j].cognome);
		printf("data di nascita\n");
		printf("giorno\n");
		scanf("%d",&st[j].nascita.gg);
		printf("nome mese\n");
		scanf("%s",st[j].nascita.mm);
		printf("anno\n");
		scanf("%d",&st[j].nascita.aaaa);
		printf("inserisci voti\n");
		for(i=0;i<V;i++)
		{
			scanf("%d",&st[j].voti[i]);
			t+=st[j].voti[i];
		}
		m=t/V;
		st[j].media=m;
		t=0;
		m=0;
	}
}
void visualizza(student st[])
{
	int i,j;
	for(j=0;j<N;j++)
	{
		printf("informazioni studente %d\n",j+1);
		printf("matricola\n");
		printf("%d\n",st[j].matricola);
		printf("cognome\n");
		printf("%s\n",st[j].cognome);
		printf("data di nascita\n");
		printf("giorno\n");
		printf("%d\n",st[j].nascita.gg);
		printf("mese\n");
		printf("%s\n",st[j].nascita.mm);
		printf("anno\n");
		printf("%d\n",st[j].nascita.aaaa);
		printf("inserisci voti\n");
		for(i=0;i<V;i++)
		{
			printf("%d\n",st[j].voti[i]);
		}
	}
}
void media_studente(student st[])
{
	int j;
	for(j=0;j<N;j++)
	{
		printf("informazioni studente %d\n",j+1);
		printf("cognome\n");
		printf("%s\n",st[j].cognome);
		printf("media\n");
		printf("%d\n",st[j].media);
	}
}
