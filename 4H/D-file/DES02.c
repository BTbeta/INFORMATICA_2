/** ****************************************************************************************
* \mainpage <DES02>
*
* @brief <prova funzioni >
* <esendo che quando i numeri sono tirati fuori dal testo sono dei carateri come numeri allora controlo se sono numeri e confronto se è pari o dispari e li mette in quei due file di testo corispodenti>
* <se non si aprono i uno dei due file fa visualizzare un messagio di errore e se si apre visualozza il completamento>
* 
* @author <zeng oscar hao>
* @date <12/11/2022> 
* @version 1.0 <14/11/2022> Versione iniziale
*/
#include<stdio.h>
#include<stdlib.h>

#define V 3

struct stud
{
	char cognome;
	data nascita;
	int voti[V];
}typedef stud;
struct data
{
	int g;
	int m;
	int a;
}typedef data;

/** ****************************************************************************************
* @brief <crypta il messagio nel file di testo>
* @param  <un FILE e una stringa>
* @retval <nessuna>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <23/11/2022> <nuovo algoritmo>
*/
void carica(char[],int);
void stampa(char[]);

int main()
{
	char file1[]={"nome.txt"};
	int err1;	
	printf("quanti studenti da inserire\n");
	scanf("%d",&n);				
	FILE* pFile1;									
	char c;							
	pFile1=fopen(file1,"rb+");					
	if(pFile1!=NULL&&pFile2!=NULL)				
	{
		carica(file1,n);
		system("pause");
		system("cls");			
		stampa(file1);					
		printf("operazione completo");
	}
	else										
	{
		printf("\nil file non puo'essere aperto");
	}
}

void carica(char x[],int y)
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
void stampa(char x[])
{
	stud buffer;
	int err,n;
	FILE* pf;
	pf=fopen(x,"rb");
	while(!feof())
	{
		n=fread(&buffer,sizeof(buffer),1,pf);
		printf("inserisci cognome:%s",buffer.cognome);
		printf("inserisci data di nascita:%d/%d/%d",buffer.nascita.g,buffer.nascita.m,buffer.nascita.a);
		printf("inserisci voti:\n");
		for(int j=0;j<V;j++)
		printf("%d\n"&buffer.voti[j]);
		printf("\n");
	}
}
