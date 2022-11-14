/** ****************************************************************************************
* \mainpage <DES01_PAG30_A>
*
* @brief <inserire una breve descrizione del progetto>
* <il programma copia le frasi dal file di testo del file1 e lo copia nel file di testo del file2>
* <se non si aprono i uno dei due file fa visualizzare un messagio di errore e se si apre visualozza il completamento>
* 
* @author <zeng osacr hao>
* @date <12/11/2022> 
* @version 1.0 <14/11/2022> Versione iniziale
*/
#include<stdio.h>

int main()
{
	char file1[]={"dio.txt"},file2[]={"dio(1).txt"};	//dichiarando i nomi dei file
	int err1,err2;										//interi utilizzato per funzionare fclose
	FILE* pFile1;										//il seglo del file1
	FILE* pFile2;										//il segno del file2
	char c;												//è utilizato per prendere le lettera e modificarli
	pFile1=fopen(file1,"r");							//apre file1
	pFile2=fopen(file2,"w");							//apre file2
	if(pFile1!=NULL&&pFile2!=NULL)						//se i due file si aprono
	{
		while(!feof(pFile1))							//il ciclo continua fino quando è uguale a \0
		{
			c=fgetc(pFile1);							//prende una lettera 
			if(!feof(pFile1))							//se è diverso da \n
			fputc(c,pFile2);							//se è vero lo mette nel file2
		}
		err1=fclose(pFile1);							//chiusura del file1
		err2=fclose(pFile2);							//chiusura del file2
		printf("operazione completo");
	}
	else												//se è falso visializza un errore
	{
		printf("\nil file non puo'essere aperto");
	}
}
