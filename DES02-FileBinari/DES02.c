/** ****************************************************************************************
* \mainpage DES02.c
*
* @brief prova funzioni di file di record
* <specifiche del progetto>
* <specifiche del collaudo>
* 
* @author Zeng oscar hao
* @date 1/12/2022
* @version 1.0 <1/12/2022>  Versione iniziale
* @version 1.1 <1/12/2022>  <proseguimento del programma>
* @version 1.2 <14/12/2022>  <comentare il programma>
* @version 1.2 <14/12/2022>  <correzione al programma>
* @version 1.2 <14/12/2022>  <correzione al programma>
* @version 1.2 <14/12/2022>  <completamento>
*/
#include<string.h>		//è utilizzato per il funzionamento la funzione strcmp
#include<stdio.h>		//è utilizzato per il funzionamento del file
#include<stdlib.h>		//è utilizzato per il funzionamento del system e rand
#include<time.h>		//è utilizzato per estrare il tempo e funzionamento del srand

#define V 3				//quantità di voti
#define L 10			//quantità di carateri

struct data				//creazione di un record
{
	int g;				//giorno
	int m;				//mese
	int a;				//anno
}typedef data;			//nome di defoult data

struct stud				//creazione di un record
{
	char cognome[L];
	data nascita;
	int voti[V];
}typedef stud;			//nome di defoult stud

/** ****************************************************************************************
* @brief <inserimento dei informazioni in un file di reord>
* @param  <una stringa e una intero(char fileName[], int numRecord)>
* @retval <nessuna>
* @see <fwrite serve ad agiungere o sovrascivere le informazioni nel file e sizeof calcola la grandezza del variabile, sono nella libreia stdio.h,srand serve per funzionare rend e rand serve per generare numeri casuali si trovano stdlib.h>
*
* @author <zeng oscar>
* @version 1.0 <1/12/2022> <nuovo algoritmo>
*/
void inserisciRecord(char[],int);

/** ****************************************************************************************
* @brief <visualizazione dei informazioni in un file di reord>
* @param  <una stringa(char fileName[])>
* @retval <nessuna>
* @see <fread serve a tirare fuori le informazioni dal file, è nella libreia stdio.h>
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
* @see <strcmp serve a confrontare due stringhe e dice se sono uguali o più picolo o più grande, è nella libreia stdio.h>
*
* @author <zeng oscar>
* @version 1.0 <4/12/2022> <nuovo algoritmo>
*/
int ricercaRecord(char [], char []);

/** ****************************************************************************************
* @brief <controlla la posizione inserito nel parametro e visualizza il record>
* @param  <una stringa e una intero(char fileName[], int posizione)>
* @retval <da due valori 0 c'è il record e -1 non c'è record>
* @see <fseek serve per posizionamento del puntatore e rida la posizione sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <7/12/2022> <nuovo algoritmo>
*/
int stampaRecord(char [], int);

/** ****************************************************************************************
* @brief <controlla la posizione inserito nel parametro e modifica il record>
* @param  <una stringa e una intero(char fileName[], int posizione)>
* @retval <da due valori 0 c'è il record e -1 non c'è record>
*
* @author <zeng oscar>
* @version 1.0 <7/12/2022> <nuovo algoritmo>
*/
int correggiRecord(char [], int);

/** ****************************************************************************************
* @brief <controlla quanti record ci sono>
* @param  <un char(char fileName[])>
* @retval <un intero che rapresenta quanti record sono>
*
* @author <zeng oscar>
* @version 1.0 <7/12/2022> <nuovo algoritmo>
*/
int numeroRecord(char []);

int main()
{
	char file1[]={"nome.dat"};										//nome file
	int err1;														//interi utilizzato per funzionare di funzioni di file
	int n;															//variabile per ricevere i numeri da utente
	int a;															//variabile per ricevere i numeri dalla funzione
	FILE* pFile1;													//segno del file
	char cognome[L];																												//se è vero fa queste cose sotto
	//funzione inserisciRecord
	printf("quanti studenti da inserire\n");
	scanf("%d",&n);	
	inserisciRecord(file1,n);
	system("pause");												//aspetta fino quando non schiacia qualcosa
	system("cls");													//cancella quello che c'era scritto
	//funzione stampaFile
	stampaFile(file1);
	system("pause");
	system("cls");
	//funzione ricercaRecord
	printf("inserisci il cognome dello studente\n");
	scanf("%s",cognome);		
	a=ricercaRecord(file1,cognome);
	if(a==-1)
	{
		printf("non esiste uno studente conquesto cognome\n");
	}	
	else
	{
		printf("e' nella posizione(comincia da 0): %d\n",a);
	}		
	system("pause");
	system("cls");
	//funzione stampaRecord
	printf("inserisci la posizione da guardare e modificare(comincia da 0)\n");
	scanf("%d",&n);	
	a=stampaRecord(file1,n);
	if(a==-1)
	{
		printf("record non esistente\n");	
	}
	//funzione correggiRecord
	a=correggiRecord(file1,n);
	if(a==-1)
	{
		printf("record non esistente\n");
	}
	system("pause");
	system("cls");
	//funzione numeroRecord
	a=numeroRecord(file1);
	if(a!=-1)
	{
		if(a==0)
		{
			printf("non ci sono record\n");
		}
		else
		{
			printf("nel file ci sono %d record\n",a);
		}
	}
}

void inserisciRecord(char x[],int y)
{
	srand(time(NULL));									//funzionamento del rand
	stud buffer;										//dichiarazione di un record
	int err;											//interi utilizzato per funzionare di funzioni di file
	FILE* pf;											//segno del file
	pf=fopen(x,"ab+");									//apre x è file1
	if(pf!=NULL)										//se il file si apre
	{												
		for(int i=0;i<y;i++)							//insrisce i dati dei studenti per quanto lo chiede l'utente
		{
			printf("inserisci cognome:");
			scanf("%s", buffer.cognome);
			printf("inserisci data di nascita:\n");
			printf("giorno:");
			scanf("%d",&buffer.nascita.g);
			printf("mese(numero):");
			scanf("%d",&buffer.nascita.m);
			printf("anno:");
			scanf("%d",&buffer.nascita.a);
			for(int j=0;j<V;j++)
			{
				buffer.voti[j]=rand()%10+1;				//genera voti casuali da 1-10
			}
			printf("\n");
			err=fwrite(&buffer,sizeof(buffer),1,pf);	//il record vine memorizzato nel file 
		}
		err=fclose(pf);									//salva le modifiche e chude il file
	}
	else												//seè falso	fa visualizzare un errore		
	{
		printf("\nil file non puo'essere aperto\n");
	}
}

void stampaFile(char x[])
{
	stud buffer;										//dichiarazione di un record
	int err;											//interi utilizzato per funzionare di funzioni di file
	FILE* pf;											//segno del file
	pf=fopen(x,"rb");									//apre x è file1
	if(pf!=NULL)										//se il file si apre
	{
		while(!feof(pf))								//il ciclo continua fino quando finisce il file
		{
			err=fread(&buffer,sizeof(buffer),1,pf);		//tira fuori il record dal file e messo nel record del programma
			if(err!=0)
			{
				printf("cognome:%s\n",buffer.cognome);
				printf("data di nascita:");
				printf("%d/",buffer.nascita.g);
				printf("%d/",buffer.nascita.m);
				printf("%d\n",buffer.nascita.a);
				printf("voti:\n");
				for(int i=0;i<V;i++)
				{
					printf("%d\t", buffer.voti[i]);
				}
				printf("\n");
			}
		}
		err=fclose(pf);									//chude il file
	}
	else												//se è falso fa visualizzare un errore		
	{
		printf("\nil file non puo'essere aperto\n");
	}
}

int ricercaRecord(char x[], char y[])
{
	stud buffer;										//dichiarazione di un record
	int media,eta,tot;
	/*tm time;										
	int anno=1900+time.tm_year;	*/	
	int anno=2022;			
	int n=0;											//è un segno per trovere il primo ceh trova
	int p=-1;											//posizione del primo che trova
	int err;											//interi utilizzato per funzionare di funzioni di file
	FILE* pf;											//segno del file
	pf=fopen(x,"rb");									//apre x è file1
	if(pf!=NULL)										//se il file si apre
	{
		p++;											//aumenta il contatore
		while(!feof(pf))								//il ciclo continua fino quando finisce il file
		{
			err=fread(&buffer,sizeof(buffer),1,pf);		//tira fuori il record dal file e messo nel record del programma
			if(err!=0)
			{
				if(strcmp(buffer.cognome,y)==0)			//controlla se è lo stesso cognome
				{
					printf("cognome:%s\n",buffer.cognome);
					eta=anno-buffer.nascita.a;
					printf("eta':%d\n",eta);
					tot=0;								//lo rende tot=0 perchè viene ripetuto l'operazione
					for(int i=0;i<V;i++)
					{
						tot+=buffer.voti[i];			//somma tutti i voti
					}
					media=tot/V;						//calcola media
					printf("media dei voti:%d\n\n",media);
					n=1;
				}
				if(n==0)
				{
					p++;								//continua ad aumentare il contatore fino quando n è diverso da 0
				}
			}
		}
		if(n==0)										//se nel ciclo non vine trovato
			p=-1;										//il contatore diventa -1
		err=fclose(pf);									//chude il file
	}
	else												//se è falso fa visualizzare un errore		
	{
		printf("\nil file non puo'essere aperto\n");
	}
	return p;
}

int stampaRecord(char x[], int y)
{
	stud buffer;										//dichiarazione di un record
	int err;											//interi utilizzato per funzionare di funzioni di file
	FILE* pf;											//segno del file
	pf=fopen(x,"rb");									//apre x è file1
	if(pf!=NULL)										//se il file si apre
	{
		err=fseek(pf,y*sizeof(buffer),0);				//posiziona il puntatore alla posizione inserita nel parametro
		if(err!=-1)										//controlla se esiste il record
		{												//se è vero
			err=fread(&buffer,sizeof(buffer),1,pf);		//tira fuori il record dal file e messo nel record del programma
			printf("cognome:%s\n",buffer.cognome);
			printf("data di nascita:");
			printf("%d/",buffer.nascita.g);
			printf("%d/",buffer.nascita.m);
			printf("%d\n",buffer.nascita.a);
			printf("voti:\n");
			for(int i=0;i<V;i++)
			{
				printf("%d\t",buffer.voti[i]);
			}
			printf("\n");
			return 0;									//rida 0 al int
		}
		else											//se è falso
		{
			return err;									//rida -1 al int
		}
	}
	else												//se è falso fa visualizzare un errore		
	{
		printf("\nil file non puo'essere aperto\n");
		return 0;
	}
}
int correggiRecord(char x[], int y)
{
	srand(time(NULL));									//funzionamento del rand
	stud buffer;										//dichiarazione di un record
	int err;											//interi utilizzato per funzionare di funzioni di file
	FILE* pf;											//segno del file
	pf=fopen(x,"rb+");									//apre x è file1
	if(pf!=NULL)										//se il file si apre
	{
		err=fseek(pf,y*sizeof(buffer),0);				//posiziona il puntatore alla posizione inserita nel parametro
		if(err!=-1)										//controlla se esiste il record
		{
			printf("inserisci cognome:");
			scanf("%s", buffer.cognome);
			printf("inserisci data di nascita:\n");
			printf("giorno:");
			scanf("%d",&buffer.nascita.g);
			printf("mese(numero):");
			scanf("%d",&buffer.nascita.m);
			printf("anno:");
			scanf("%d",&buffer.nascita.a);
			for(int j=0;j<V;j++)
			{
				buffer.voti[j]=rand()%10+1;				//genera voti casuali da 1-10
			}
			printf("\n");
			err=fwrite(&buffer,sizeof(buffer),1,pf);	//sovrascrive il record esistente con il record corretto
			err=fclose(pf);								//chude il file
			return 0;									//rida 0 al int
		}
		else											//se è falso
		{
			return err;									//rida -1 al int
		}
	}
	else												//se è falso fa visualizzare un errore		
	{
		printf("\nil file non puo'essere aperto\n");
		return 0;
	}
}

int numeroRecord(char x[])
{
	stud buffer;										//dichiarazione di un record
	int err;											//interi utilizzato per funzionare di funzioni di file
	int n=sizeof(buffer);								//la grandezza del record
	int record;											//quantità di record ci sono
	FILE* pf;											//segno del file
	pf=fopen(x,"rb");									//apre x è file1
	if(pf!=NULL)										//se il file si apre
	{
		err=fseek(pf,0,2);								//mette il puntatore alla fine del file e err viene salvato il numero di bit
		err=ftell(pf);									//restituisce un intero che è la posizione corrente del puntatore.
		record=err/n;									//divido err con n per trovare quanti record sono
		err=fclose(pf);									//chude il file
		return record;									//rida record al int
	}
	else												//se è falso fa visualizzare un errore		
	{
		printf("\nil file non puo'essere aperto\n");
		return -1;
	}
}
