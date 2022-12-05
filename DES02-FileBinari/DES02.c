/** ****************************************************************************************
* \mainpage <DES02>
*
* @brief <prova funzioni di file di record>
* <specifiche del progetto>
* <specifiche del collaudo>
* 
* @author <zeng oscar hao>
* @date <1/12/2022> 
* @version 1.0 <1/12/2022>  Versione iniziale
* @version 1.0 <1/12/2022>  <proseguimento del programma>
*/
#include<stdio.h>
#include<stdlib.h>

#define V 3
#define L 10

struct data
{
	int g;
	int m;
	int a;
}typedef data;
struct stud
{
	char cognome[Lgcc];
	data nascita;
	int voti[V];
}typedef stud;

/** ****************************************************************************************
* @brief <inserimento dei informazioni in un file di reord>
* @param  <una stringa e una intero(char fileName[], int numRecord)>
* @retval <nessuna>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <1/12/2022> <nuovo algoritmo>
*/
void inserisciRecord(char[],int);

/** ****************************************************************************************
* @brief <visualizazione dei informazioni in un file di reord>
* @param  <una stringa(char fileName[])>
* @retval <nessuna>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <1/12/2022> <nuovo algoritmo>
* @version 1.1 <4/12/2022> <competamento della dunzione>
*/
void stampaFile(char[]);

/** ****************************************************************************************
* @brief <cerca quelli con lo stesso cognome e visualizza cognome,età e media>
* @param  <due stringe(char fileName[], char cognaome)>
* @retval <un intero che rapresenta la posizione del primo record che trova>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <5/12/2022> <nuovo algoritmo>
*/
int ricercaRecord(char [], char []);

/** ****************************************************************************************
* @brief <visualizazione dei informazioni in un file di reord>
* @param  <una stringa e una intero(char fileName[], int posizione)>
* @retval <nessuna>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <1/12/2022> <nuovo algoritmo>
*/
int stampaRecord(char [], int);

/** ****************************************************************************************
* @brief <visualizazione dei informazioni in un file di reord>
* @param  <un char(char fileName[])>
* @retval <nessuna>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <1/12/2022> <nuovo algoritmo>
*/
int correggiRecord(char []);

/** ****************************************************************************************
* @brief <visualizazione dei informazioni in un file di reord>
* @param  <un char(char fileName[])>
* @retval <nessuna>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <1/12/2022> <nuovo algoritmo>
*/
int numeroRecord(char fileName[]);

int main()
{
	char file1[]={"nome.txt"};
	int err1,n;	
	FILE* pFile1;									
	char c;							
	pFile1=fopen(file1,"rb+");					
	if(pFile1!=NULL)				
	{
		printf("quanti studenti da inserire\n");
		scanf("%d",&n);	
		inserisciRecord(file1,n);
		system("pause");
		system("cls");			
		stampaFile(file1);					
	}
	else										
	{
		printf("\nil file non puo'essere aperto\n");
	}
}

void inserisciRecord(char x[],int y)
{
	stud buffer;
	int err;
	FILE* pf;
	pf=fopen(x,"wb");
	for(int i=0;i<y;i++)
	{
		printf("inserisci cognome:");
		scanf("%s", buffer.cognome);
		printf("inserisci data di nascita:");
		scanf("%d",&buffer.nascita.g);
		printf("/");
		scanf("%d",&buffer.nascita.m);
		printf("/");
		scanf("%d",&buffer.nascita.a);
		printf("inserisci voti:\n");
		for(int j=0;j<V;j++)
		scanf("%d",&buffer.voti[j]);
		printf("\n");
		err=fwrite(&buffer,sizeof(buffer),1,pf);
	}
	err=fclose(pf);
}

void stampaFile(char x[])
{
	stud buffer;
	int err;
	FILE* pf;
	pf=fopen(x,"rb");
	while(!feof(pf))
	{
		err=fread(&buffer,sizeof(buffer),1,pf);
		printf("cognome:%s\n",buffer.cognome);
		printf("data di nascita:");
		printf("%d/",buffer.nascita.g);
		printf("%d/",buffer.nascita.m);
		printf("%d\n",buffer.nascita.a);
		printf("voti:\n");
		for(int i=0;i<V;i++)
		printf("%d\n",&buffer.voti[i]);
		printf("\n");
	}
}

int ricercaRecord(char x[], char y[])
{
	stud buffer;
	int err,n=0,p=0,media,eta,tot=0;
	FILE* pf;
	pf=fopen(x,"rb");
	while(!feof(pf)&&n==0)
	{
		err=fread(&buffer,sizeof(buffer),1,pf);
		if(buffer.cognome==y)
		{
			printf("cognome:%s\n",buffer.cognome);
			
			printf("eta':%s\n",media);
			for(int i=0;i<V;i++)
			tot+=buffer.voti[i];
			media=tot/V;
			printf("media dei voti:%s\n",media);
			n=1;
		}
		if(n==0)
		{
			p++;
		}
	}
	return p;
}

int stampaRecord(char [], int)

int correggiRecord(char [])

int numeroRecord(char fileName[])