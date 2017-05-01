#include<stdio.h>
int main(int argc,char* argv[])
{
	if(argc<3)
	{
		printf("Please input the old file name and new file name\n");
		return 1;
	}
	if(rename(argv[1],argv[2])==0)
		printf("%s has been renamed to %s.\n",argv[1],argv[2]);
	else
		printf("cann't change %s.\n",argv[1]);
	return 0;
}
