/** ****************************************************************************************
* \mainpage <DES01_PAG30_A>
*
* @brief <visualizzare quante letere,parole e righe>
* <carateri conta quanti carateri cisono senza \0, parola conta quante parole ci sono e anche righe>
* <se non si aprono i uno dei due file fa visualizzare un messagio di errore e se si apre visualozza quante letere,parole e frasi>
* 
* @author <zeng osacr hao>
* @date <12/11/2022> 
* @version 1.0 <14/11/2022> Versione iniziale
*/
#include<stdio.h>

int main()
{
	char file1[]={"dio.txt"};						//dichiarando il nomi del file
	int err1;										//intero utilizzato per funzionare fclose
	FILE* pFile1;									//il seglo del file1
	char c;	   										//è utilizato per prendere le lettera
	char d=0;								//utilzato per confrontare
	int carateri=0,parole=0,righe=1;				
	pFile1=fopen(file1,"r");						//apre file1
	if(pFile1!=NULL)								//se il file si aprono
	{
		while(!feof(pFile1))						//il ciclo continua fino quando è uguale a \0
		{
			c=fgetc(pFile1);						//prende una lettera 
			if(!feof(pFile1))						//se è diverso da \n
			carateri++;
			//se d è una letera e c è uno spazio o invio o \0
			if(d>='a'&&d<='z'||d>='A'&&d<='B')	
			{
				if(c==' '||c=='\0'||c=='\n')
				parole++;
			}
			if(c==13)								//se c=invio
			righe++;
			d=c;
		}
		err1=fclose(pFile1);						//chiusura del file1
		//visualizza i valori
		printf("carateri=%d\n",carateri);
		printf("parole=%d\n",parole);
		printf("righe=%d\n",righe);
	}
	else											//se è falso visializza un errore
	{
		printf("\nil file non puo'essere aperto");
	}
}
