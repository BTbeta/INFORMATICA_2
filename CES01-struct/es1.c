/**************************************
 *zeng oscar                          *
 *4H                                  *
 *26/09/2022                          *
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
void inserimento(student*);
void visualizza(student*);
int main()
{
	student st1,st2;
	inserimento(&st1);
	visualizza(&st1);
}
void inserimento(student*st)
{
	int i;
	printf("inserisci informazioni studente\n");
	printf("matricola\n");
	scanf("%d",&st->matricola);
	printf("cognome\n");
	scanf("%s",st->cognome);
	printf("data di nascita\n");
	printf("giorno\n");
	scanf("%d",&st->nascita.gg);
	printf("nome mese\n");
	scanf("%s",st->nascita.mm);
	printf("anno\n");
	scanf("%d",&st->nascita.aaaa);
	printf("inserisci voti\n");
	for(i=0;i<V;i++)
	{
		scanf("%d",&st->voti[i]);
	}
}
void visualizza(student*st)
{
	int i;
	printf("informazioni studente\n");
	printf("matricola\n");
	printf("%d\n",st->matricola);
	printf("cognome\n");
	printf("%s\n",st->cognome);
	printf("data di nascita\n");
	printf("giorno\n");
	printf("%d\n",st->nascita.gg);
	printf("mese\n");
	printf("%s\n",st->nascita.mm);
	printf("anno\n");
	printf("%d\n",st->nascita.aaaa);
	printf("inserisci voti\n");
	for(i=0;i<V;i++)
	{
		printf("%d\n",st->voti[i]);
	}
}
