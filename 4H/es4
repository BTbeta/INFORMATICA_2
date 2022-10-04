/**************************************
 *zeng oscar                          *
 *4H                                  *
 *04/10/2022                          *
 *esercizio in classe :record         *
 **************************************/
#include<stdio.h>
#define N 10
#define V 5
struct s_data
{
	int gg;
	char mm[N];
	int aaaa;
}typedef s_data;
struct student
{
	int matricola;
	char cognome[N];
	s_data nascita;
	int voti[V];
}typedef student;
void inserimento(student[]);
void visualizza(student[]);
int main()
{
	student st1[V],st2[V];
	inserimento(st1);
	visualizza(st1);
}
void inserimento(student st[])
{
	int i,j;
	for(j=0;j<V;j++)
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
		}
	}
}
void visualizza(student st[])
{
	int i,j;
	for(j=0;j<V;j++)
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
