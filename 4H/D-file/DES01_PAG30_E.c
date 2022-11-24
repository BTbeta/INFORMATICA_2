/** ****************************************************************************************
* \mainpage <DES01_PAG30_A>
*
* @brief <divide i numeri pari da queli dispari>
* <esendo che quando i numeri sono tirati fuori dal testo sono dei carateri come numeri allora controlo se sono numeri e confronto se è pari o dispari e li mette in quei due file di testo corispodenti>
* <se non si aprono i uno dei due file fa visualizzare un messagio di errore e se si apre visualozza il completamento>
* 
* @author <zeng osacr hao>
* @date <12/11/2022> 
* @version 1.0 <14/11/2022> Versione iniziale
* @version 1.1 <16/11/2022> <completamento del programma e comenti>
* @version 1.2 <23/11/2022> <si crea un secondo file ,visualizza l'apertura del file e modifiche nelle funzioni>
* @version 1.3 <23/11/2022> <correzione>
*/
#include<stdio.h>

/** ****************************************************************************************
* @brief <crypta il messagio nel file di testo>
* @param  <un FILE e una stringa>
* @retval <nessuna>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <23/11/2022> <nuovo algoritmo>
*/
void cesareCrypt(char[],char[]);

/** ****************************************************************************************
* @brief <decrypta il messagio nel file di testo>
* @param  <un FILE e una stringa>
* @retval <nessuna>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <23/11/2022> <nuovo algoritmo>
*/
void cesareDecrypt(char[],char[]);

int main()
{
	char file1[]={"dio.txt"},file2[]={"dio(1).txt"};//dichiarando i nomi dei file
	int err1,err2;									//interi utilizzato per funzionare fclose
	FILE* pFile1;									//il seglo del file1
	FILE* pFile2;									//il segno del file2
	char c;											//è utilizato per prendere le lettera e modificarli
	pFile1=fopen(file1,"r");						//apre file1
	pFile2=fopen(file2,"r+");						//apre file2
	if(pFile1!=NULL&&pFile2!=NULL)					//se i due file si aprono
	{
		cesareCrypt(file1,file2);					//cripta il messagio
		cesareDecrypt(file2,file1);					//de cripta il messagio
		printf("operazione completo");
	}
	else											//se è falso visializza un errore
	{
		printf("\nil file non puo'essere aperto");
	}
}

void cesareCrypt(char f1[],char f2[])
{
	char c;										//è utilizato per prendere le lettera
	int err1,err2;								//interi utilizzato per funzionare fclose
	FILE* pFile1;								//il seglo del file1
	FILE* pFile2;								//il segno del file2
	char c;										//è utilizato per prendere le lettera e modificarli
	pFile1=fopen(f1,"r");						//apre file1
	pFile2=fopen(f2,"w");						//apre file2
	while(!feof(pFile1))						//il ciclo continua fino quando è uguale a \0
	{
		c=fgetc(pFile1);						//prende un caratere
		c-=3									//mette 3 letere prima
		if(c<'a'&&c>'Z'||c<'A')					//se è più picolo di A nel codice ascii
		{
			c+=24;								//prende la letera correta
		}
		if(!feof(pFile1))						//se è diverso da \0
		fputc(c,pFile2);						//se è vero lo mette nel file2
	}
	err1=fclose(pFile1);						//chiusura del file1
	err2=fclose(pFile2);						//chiusura del file2
}

void cesareDecrypt(char f1[],char f2[])
{
	char c;										//è utilizato per prendere le lettera
	int err1,err2;								//interi utilizzato per funzionare fclose
	FILE* pFile1;								//il seglo del file1
	FILE* pFile2;								//il segno del file2
	char c;										//è utilizato per prendere le lettera e modificarli
	pFile1=fopen(f1,"r");						//apre file1
	pFile2=fopen(f2,"w");						//apre file2
	while(!feof(pFile1))						//il ciclo continua fino quando è uguale a \0
	{
		c=fgetc(pFile1);						//prende un caratere
		c+=3									//mette 3 letere prima
		if(c<'A'&&c>'z'||c>'Z')					//se è più grande di Z nel codice ascii
		{
			c-=24;								//prende la letera correta							
		}
		if(!feof(pFile1))						//se è diverso da \0
		fputc(c,pFile2);						//se è vero lo mette nel file2
	}
	err1=fclose(pFile1);						//chiusura del file1
	err2=fclose(pFile2);						//chiusura del file2
}
