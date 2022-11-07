#include<stdio.h>

int main()
{
	char dio[]={"dio.txt"};
	int err;
	char c;
	FILE* puntaFile;
	puntaFile=fopen(dio,"r");
	if(puntaFile!=NULL)
	{
		while(!feof(puntaFile))
		{
			c=fgetc(puntaFile);
			printf("%c",c);
		}
		err=fclose(puntaFile);
	}
	else
	{
		printf("\nil file non puo'essere aperto!");
	}
}
