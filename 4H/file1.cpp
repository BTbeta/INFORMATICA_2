#include<stdio.h>

int main()
{
	char dio[]={"C:\\Users\\Gejin\\OneDrive\\Desktop\\programmi_di_scuola\\2022_2023"};
	int err;
	char c;
	FILE *puntaFile;
	puntaFile=fopen_s(dio,"r");
	if(puntaFile==0)
	{
		while(!feof(puntaFile))
		{
			c=fgetc(puntaFile);
			printf("%s",c);
		}
		err=fclose(puntaFile);
	}
	else
	{
		printf("\nil file non puo'essere aperto!");
	}
}
