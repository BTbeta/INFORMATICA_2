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
#include<string.h>
#include<stdio.h>		//è utilizzato per il funzionamento del file
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
	char cognome[L];
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
* @version 1.0 <4/12/2022> <nuovo algoritmo>
*/
int ricercaRecord(char [], char []);

/** ****************************************************************************************
* @brief <controlla la posizione inserito nel parametro e visualizza il record>
* @param  <una stringa e una intero(char fileName[], int posizione)>
* @retval <da due valori 0 c'è il record e -1 non c'è record>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <7/12/2022> <nuovo algoritmo>
*/
int stampaRecord(char [], int);

/** ****************************************************************************************
* @brief <controlla la posizione inserito nel parametro e modifica il record>
* @param  <una stringa e una intero(char fileName[], int posizione)>
* @retval <da due valori 0 c'è il record e -1 non c'è record>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <7/12/2022> <nuovo algoritmo>
*/
int correggiRecord(char [], int);

/** ****************************************************************************************
* @brief <controlla quanti record ci sono>
* @param  <un char(char fileName[])>
* @retval <un intero che rapresenta quanti record sono>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <7/12/2022> <nuovo algoritmo>
*/
int numeroRecord(char []);

int main()
{
	char file1[]={"nome.txt"};
	int err1,n,a;	
	FILE* pFile1;									
	char c[L];							
	pFile1=fopen(file1,"rb+");					
	if(pFile1!=NULL)				
	{
		printf("quanti studenti da inserire\n");
		scanf("%d",&n);	
		inserisciRecord(file1,n);
		system("pause");
		system("cls");			
		stampaFile(file1);
		system("pause");
		system("cls");
		printf("inserisci il cognome dello studente\n");
		scanf("%c",&c);		
		a=ricercaRecord(file1,c);
		system("pause");
		system("cls");
		printf("inserisci la posizione da guardare e modificare\n");
		scanf("%d",&n);	
		a=stampaRecord(file1,n);
		if(a==-1)
		printf("record non esistente",a);	
		system("pause");
		system("cls");
		a=correggiRecord(file1,n);
		if(a==-1)
		printf("record non esistente",a);
		system("pause");
		system("cls");
		a=numeroRecord(file1);
		printf("nel file ci sono %d record\n",a);
		system("pause");
		system("cls");		
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
		if(strcmp(buffer.cognome,y)==0)
		{
			printf("cognome:%s\n",buffer.cognome);
			
			printf("eta':%s\n",eta);
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

int stampaRecord(char x[], int y)
{
	stud buffer;
	int err;
	FILE* pf;
	pf=fopen(x,"rb");
	err=fseek(pf,y,0);
	if(err!=-1)
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
		return 0;
	}
	else
	return err;
}

int correggiRecord(char x[], int y)
{
	stud buffer;
	int err;
	FILE* pf;
	pf=fopen(x,"rb");
	err=fseek(pf,y,0);
	if(err!=-1)
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
	else
	return err;
}

int numeroRecord(char x[])
{
	stud buffer;
	int err,n,record;
	FILE* pf;
	pf=fopen(x,"rb");
	err=fseek(pf,0,0);
	n=sizeof(buffer);
	record=err/n;
	return record;
}
