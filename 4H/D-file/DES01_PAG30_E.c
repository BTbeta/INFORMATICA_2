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
*/
#include<stdio.h>

/** ****************************************************************************************
* @brief <crypta il messagio nel file di testo>
* @param  <un FILE e una stringa>
* @retval <nessuna>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <data> <Descrivere le modifiche apportate>
*/
void cesareCrypt(char[]);

/** ****************************************************************************************
* @brief <decrypta il messagio nel file di testo>
* @param  <un FILE e una stringa>
* @retval <nessuna>
* @see <rand serve genera numeri casuali e con srand nel main serve per funzionare rand sono nella libreia stdlib.h e time.h>
*
* @author <zeng oscar>
* @version 1.0 <data> <Descrivere le modifiche apportate>
*/
void cesareDecrypt(char[]);

int main()
{
	char dio[]={"dio.txt"};							//dichiarando il nomo del file
	FILE* pFile1;									//il segno del file dio
	pFile1=fopen(dio,"r");							//apre numeri
	cesareCrypt(dio);								//cripta il messagio
	cesareDecrypt(dio);								//de cripta il messagio
}

void cesareCrypt(char d[])
{
	char c;											//è utilizato per prendere le lettera
	int err;										//intero utilizzato per funzionare fclose
	FILE* pFile;									//il segno del file dio
	pFile=fopen(d,"w");								//apre dio
	while(!feof(pFile))								//il ciclo continua fino quando è uguale a \0
	{
		c=fgetc(pFile);								//prende un caratere
		if(c>='a'&&c<='z'||c>='A'&&c<='Z')			//se è una letera
		{
			if(c!='a'||c!='A')						//se è a
			{
				if(c=='b'||c=='B')					//se è b
				c+=24;								//mette z
				else
				c-=3;								//mette 3 letere prima
			}
			else
			c+=24;									//mette y
		}
	}
	err=fclose(pFile);								//chiude file di testo
}

void cesareDecrypt(char d[])
{
	char c;											//è utilizato per prendere le lettera
	int err;										//intero utilizzato per funzionare fclose
	FILE* pFile;									//il segno del file dio
	pFile=fopen(d,"w");								//apre dio
	while(!feof(pFile))								//il ciclo continua fino quando è uguale a \0
	{
		c=fgetc(pFile);								//prende un caratere
		if(c>='a'&&c<='z'||c>='A'&&c<='Z')			//se è una letera
		{
			if(c!='y'||c!='Y')						//se è y
			{
				if(c=='z'||c=='Z')					//se è z
				c-=24;								//mette b
				else
				c+=3;								//mette 3 letere dopo
			}
			else
			c-=24;									//mette a
		}
	}
	err=fclose(pFile);								//chiude file di testo
}
