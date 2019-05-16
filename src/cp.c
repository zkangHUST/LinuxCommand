#include<stdio.h>
int main(int argc,char* argv[])
{
	char c;
	if(argc<3)
	{
		printf("Please input the source file name and new file name\n");
		return 1;
	}
	FILE* input = fopen(argv[1],"r");
	FILE* output = fopen(argv[2],"w");
	if(input==NULL)
	{
		printf("cann't open \"%s\".\n",argv[1]);
		return 2;
	}
	while((c=getc(input))!=EOF)
	{
		putc(c,output);
	}
	fclose(input);
	fclose(output);
	/*if(rename(argv[1],argv[2])==0)
		printf("%s has been renamed to %s.\n",argv[1],argv[2]);
	else
		printf("cann't change %s.\n",argv[1]);
	return 0;*/
	return 0;
}
