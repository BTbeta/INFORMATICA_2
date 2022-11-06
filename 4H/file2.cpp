#include<stdio.h>

int main()
{
	char buffer[MAXSTR+1];
	char nomeFileIN[]={"dio.txt"};
	printf("nome del file da scrivere:");
	scanf("%s"nomeFileIN);
	int err1;
	FILE* pFile;
	fopen_s(pFile,nomeFileIN,"w");
	if(err1==0)
	{
		for(int i=0;i<PAROLE;x++)
		{
			printf("inserisci il nome del frutto:");
			scanf("%s"buffer);
			fputs(buffer,pFile);
			fputc((int)'\n',pFile);
		}
		err=fclose(puntaFile);
	}
	else
	{
		printf("\nil file non puo'essere aperto");
	}
}
