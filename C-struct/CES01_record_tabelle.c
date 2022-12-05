/** ****************************************************************************************
* \mainpage <es6>
*
* @brief <lavorando in struct facendo carica, stampa, ricerca, ordina>
* <specifiche del progetto>
* <specifiche del collaudo>
* 
* @author <zeng oscar>
* @date <17/10/2022> 
*/
//inclusione di librerie
#include<stdio.h>					//utilizato per input e output
#include<stdlib.h>					//utilizato per srand e system
#include<time.h>					//utilizato per rand
#include<limits.h>					//utilizato per INT_MIN nella funzione TrovaVotoAlto
#include<strings.h>					//utilizato per strcmp e strcpy nella funzione Ordine_Cognome
//inclusione dei costanti
#define N 3							//numero di studebti	
#define V 5							//quanti voti
#define L 10						//lunghezza delle parole
//dichiarazione struct
struct data
{
	int gg;
	char mm[L];
	int aaaa;
}typedef data;
struct student
{
	int matricola;					//numero in classifica
	char cognome[L];
	data nascita;
	int voti[V];
	int media;
}typedef student;

//dichiarazione funzioni

/** ****************************************************************************************
* @brief <InsrimentoRandVoti inserimento numero matricola, cognome e data di nascita generando voti a caso da 1 a 10 e calcolando la media>
* @param  <una arrey di struct student>
* @retval <nessuna>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
*/
void InsrimentoRandVoti(student[]);

/** ****************************************************************************************
* @brief <vissualizza tutto il arrey di struct student>
* @param  <una arrey di struct student>
* @retval <nessuna>
*
* @author <zeng oscar>
*/
void visualizza(student[]);

/** ****************************************************************************************
* @brief <vissualizza il cognome e la media di ogni arrey di struct student>
* @param  <una arrey di struct student>
* @retval <nessuna>
*
* @author <zeng oscar>
*/
void media_studente(student []);

/** ****************************************************************************************
* @brief <trova il voto piÃ¹ alto tra arrey di struct student>
* @param  <una arrey di struct student>
* @retval <restituise un valore int che rapresenta la posizione della cella>
*
* @author <zeng oscar>
*/
int TrovaVotoAlto(student[]);

/** ****************************************************************************************
* @brief <converte la prima lettera in maiuscolo e il resto dopo minuscolo del cognome>
* @param  <una arrey di struct student>
* @retval <nessuna>
*
* @author <zeng oscar>
*/
void M_cog(student[]);

/** ****************************************************************************************
* @brief <questa funzione cerca il numero della matricola con richiesta all'utente>
* @param  <una arrey di struct student>
* @retval <rida la posizione che ha chiesto l'utente>
*
* @author <zeng oscar>
*/
int RicercaMatricola(student[]);

/** ****************************************************************************************
* @brief <questa funzione cerca il cognome della matricola con richiesta all'utente>
* @param  <una arrey di struct student>
* @retval <valori restituiti>
* @see <strcmp serve per confrontare, è nella string.h>
*
* @author <zeng oscar>
*/
int RicercaCognome(student[]);

/** ****************************************************************************************
* @brief <ordina arrey per matricola>
* @param  <una arrey di struct student>
* @retval <nessuno>
* @see <strcmp e strcpy serve per copiare sono nella string.h e ho utilizato il metodo bubble sort>
*
* @author <zeng oscar>
*/
void Ordine_Cognome(student[]);

//programma principale
int main()
{
	int a;							//a utilizzato per prendere i valori dai funzioni
	student st[N];
	srand(time(NULL));				//quata riga fa funzionare rand
	InsrimentoRandVoti(st);
	M_cog(st);
	visualizza(st);
	media_studente(st);
	a=TrovaVotoAlto(st);
	printf("%s\n",st[a].cognome);
	system("pause");
	system("cls");
	a=RicercaMatricola(st);
	printf("e' nella cella:%d\n",a);
	system("pause");
	system("cls");
	a=RicercaCognome(st);
	printf("e' nella cella:%d\n",a);
	system("pause");
	system("cls");
	Ordine_Cognome(st);
	visualizza(st);
}
void InsrimentoRandVoti(student st[])
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
		for(i=0;i<V;i++)
		{
			st[j].voti[i]=rand()%10+1;					//genera voti casuali
			t+=st[j].voti[i];							//somma tutti i voti
		}
		m=t/V;											//calcola la media
		st[j].media=m;
		t=0;
		m=0;
		system("pause");
		system("cls");
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
		printf("voti\n");
		for(i=0;i<V;i++)
		{
			printf("%d\t",st[j].voti[i]);
		}
		printf("\nmedia\n");
		printf("%d\n",st[j].media);
	}
	system("pause");
	system("cls");
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
	system("pause");
	system("cls");
}
int TrovaVotoAlto(student st[])
{
	int i,j,v=INT_MIN,r;
	for(j=0;j<N;j++)										//qua cerca quale studente ha il voto piÃ¹ alto
	{
		for(i=0;i<V-1;i++)
		{
			if(v<st[j].voti[i])
			{
				v=st[j].voti[i];
				r=j;
			}
		}
	}
	return r;												//il risultato Ã¨ sempre il primo studente con il voto piÃ¹ alto che incontra
}
void M_cog(student st[])
{
	int i,j;
	for(j=0;j<N;j++)										//qua rende il prima lettera maiuscolo e il resto munuscolo
	{
		i=0;
		if(st[j].cognome[i]>='a'&&st[j].cognome[i]<='z')
		{
			st[j].cognome[i]-=32;
		}
		i++;
		while(st[j].cognome[i]!='\0')
		{
			if(st[j].cognome[i]>='A'&&st[j].cognome[i]<='Z')
			{
				st[j].cognome[i]+=32;
			}
			i++;
		}
	}
}
int RicercaMatricola(student st[])
{
	int j,a;
	printf("insrisci la numero matricola\n");
	scanf("%d",&a);
	for(j=0;j<N;j++)										//qua cerca il numero della matricola
	{
		if(st[j].matricola==a)
		{
			return j;
		}
	}
	return -1;
}
int RicercaCognome(student st[])
{
	int i=0;
	char a[L];
	printf("insrisci il cognome\n");
	scanf("%s",a);
	if(a[i]>='a'&&a[i]<='z')								//qua rende il prima lettera maiuscolo e il resto munuscolo
	{
		a[i]-=32;
	}
	i++;
	while(a[i]!='\0')
	{
		if(a[i]>='A'&&a[i]<='Z')
		{
			a[i]+=32;
		}
		i++;
	}
	for(i=0;i<N;i++)										//in questo for cerca il cognome che stai cercando
	{
		if(strcmp(st[i].cognome,a)==0)
		{
			return i;
		}
	}
	return -1;
}
void Ordine_Cognome(student st[])
{
	student st2;
	int i,s;
	do														//in questo do e while ho utilizzato ordina con sentinella
	{
		s=0;
		for(i=0;i<N-1;i++)
		{
			if(strcmp(st[i].cognome,st[i+1].cognome)==1)
			{
				st2=st[i];
				st[i]=st[i+1];
				st[i+1]=st2;
				s=1;
			}
		}
	}while(s==1);
}
