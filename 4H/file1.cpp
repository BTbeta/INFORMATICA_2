#include<stdio.h>

int main()
{
	int c;
	FILE* puntaFile;
	fopen_s(&puntaFile,"dio.txt","r");
	if(puntaFile==0)
	{
		while(feof(puntaFile))
		{
			c=fgetc(puntaFile);
			printf("%s",c);
		}
		fclose(puntaFile);
	}
	else
	{
		printf("\nil file non puo'essere aperto!");
	}
}
