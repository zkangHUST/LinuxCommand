#include<stdio.h>
int main(int argc,char* argv[])
{
	FILE* inputfile;
	int c;
	if(argc>1)
	{
		argc--;
		inputfile=fopen(argv[1],"r");
	}
	else
		inputfile = stdin;//如果没有输入文件，那么复制标准输入到标准输出;
	if(inputfile==NULL)
	{
		printf("cann't open \"%s\".\n",argv[1]);
		return 2;
	}
	while((c=getc(inputfile))!=EOF)
		putchar(c);
	fclose(inputfile);
	return 0;
}
