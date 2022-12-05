#include<stdio.h>
#define MAXSTR 20
#define PAROLE 3

int main()
{
	char buffer[MAXSTR+1];
	char nomeFileIN[]={"dio.txt"};
	//printf("nome del file da scrivere:");
	//scanf("%s",nomeFileIN);
	int err;
	FILE* pFile;
	pFile=fopen(nomeFileIN,"w");
	if(pFile!=NULL)
	{
		for(int i=0;i<PAROLE;i++)
		{
			printf("inserisci il nome del frutto:");
			scanf("%s",buffer);
			fputs(buffer,pFile);
			fputc((int)'\n',pFile);
		}
		err=fclose(pFile);
	}
	else
	{
		printf("\nil file non puo'essere aperto");
	}
}
