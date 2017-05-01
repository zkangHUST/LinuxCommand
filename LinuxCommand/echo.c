#include<stdio.h>
int main(int argc,char* argv[])
{
	if(argc>1)
		argc--;
	else
	{
		printf("you should input something.\n");
		return 1;
	}
	while(argc--)
	{
		printf("%s",*++argv);
		if(argc)
			putchar(' ');
		else
			putchar('\n');
	}
	return 0;
}
