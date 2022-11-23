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
* @version 1.2 <23/11/2022> <si crea un secondo file>
*/
#include<stdio.h>

int main()
{
	char numeri[]={"numeri.txt"},pari[]={"pari.txt"},dispari[]={"dispari.txt"};	//dichiarando il nomi del file
	int err1,err2,err3;															//intero utilizzato per funzionare fclose
	FILE* pFile1;																//il segno del file numeri
	FILE* pFile2;																//il segno del file pari
	FILE* pFile3;																//il segno del file dispari
	char c;	   																	//è utilizato per prendere le lettera
	pFile1=fopen(numeri,"r");													//apre numeri
	pFile2=fopen(pari,"w+");													//apre pari
	pFile3=fopen(dispari,"w+");													//apre dispari
	if(pFile1!=NULL&&pFile2!=NULL&&pFile3!=NULL)								//se i file si aprono
	{
		while(!feof(pFile1))													//il ciclo continua fino quando è uguale a \0
		{
			c=fgetc(pFile1);													//prende un caratere
			if(c>='0'&&c<='9')													//se è un numero
			{
				if(c%2==0)														//se è fari 
				{
					//se è vero mete il numero nel file pari e uno spazio
					fputc(c,pFile2);											
					fputc((int)' ',pFile2);
				}
				else
				{
					//se è falso mete il numero nel file dispari e uno spazio
					fputc(c,pFile3);
					fputc((int)' ',pFile3);
				}
			}
		}
		err1=fclose(pFile1);													//chiusura del numeri
		err2=fclose(pFile2);													//chiusura del pari
		err3=fclose(pFile3);													//chiusura del dispari
	}
	else																		//se è falso visializza un errore
	{
		printf("\nil file non puo'essere aperto");
	}
}
