/**************************************
 *zeng oscar                          *
 *4H                                  *
 *05/10/2022                          *
 *esercizio in classe :record         *
 **************************************/
#include<stdio.h>
#define L 10
#define V 5
#define N 5
struct s_data
{
	int gg;
	char mm[L];
	int aaaa;
}typedef s_data;
struct student
{
	int matricola;
	char cognome[L];
	s_data nascita;
	int voti[V];
	int media;
}typedef student;
void inserimento(student[]);
void media_studente(student[]);
int main()
{
	student st1[N],st2[N];
	inserimento(st1);
	media_studente(st1);
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
