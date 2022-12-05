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
* @param  <un char e una intero(char fileName[], int numRecord)>
* @retval <nessuna>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <1/12/2022> <nuovo algoritmo>
*/
void inserisciRecord(char[],int);

/** ****************************************************************************************
* @brief <visualizazione dei informazioni in un file di reord>
* @param  <un char(char fileName[])>
* @retval <nessuna>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <1/12/2022> <nuovo algoritmo>
* @version 1.1 <4/12/2022> <competamento della dunzione>
*/
void stampaFile(char[]);

int ricercaRecord(char fileName[], char cognome[]);

int stampaRecord(char fileName[], int posizione);

int correggiRecord(char fileName[]);

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
	int err,n;
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
		n=fwrite(&buffer,sizeof(buffer),1,pf);
	}
	err=fclose(pf);
}
void stampaFile(char x[])
{
	stud buffer;
	int err,n;
	FILE* pf;
	pf=fopen(x,"rb");
	while(!feof(pf))
	{
		n=fread(&buffer,sizeof(buffer),1,pf);
		printf("inserisci cognome:%s",buffer.cognome);
		printf("inserisci data di nascita:");
		printf("%d/",buffer.nascita.g);
		printf("%d/",buffer.nascita.m);
		printf("%d",buffer.nascita.a);
		printf("inserisci voti:\n");
		for(int j=0;j<V;j++)
		printf("%d\n",&buffer.voti[j]);
		printf("\n");
	}
}
