/** ****************************************************************************************
* \mainpage <DES01_PAG30_A>
*
* @brief <inserire una breve descrizione del progetto>
* <il programma copia le frasi nel file di testo del file1 e rende tutto maiuscolo e lo mette nel file di testo del file2>
* <se non si aprono i uno dei due file fa visualizzare un messagio di errore e se si apre visualozza il completamento>
* 
* @author <zeng osacr hao>
* @date <12/11/2022> 
* @version 1.0 <12/11/2022> Versione iniziale
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/
#include<stdio.h>

int main()
{
	char file1[]={"dio.txt"},file2[]={"dio(1).txt"};
	int err1,err2;
	FILE* pFile1;
	FILE* pFile2;
	char c;
	pFile1=fopen(file1,"r");
	pFile2=fopen(file2,"w");
	if(pFile1!=NULL&&pFile2!=NULL)
	{
		while(!feof(pFile1))
		{
			c=fgetc(pFile1);
			if(c>='a'&&c<='z')
			c-=32;
			fputs(c,pFile2);
		}
		err1=fclose(pFile1);
		err2=fclose(pFile2);
		printf("operazione completo");
	}
	else
	{
		printf("\nil file non puo'essere aperto");
	}
}
