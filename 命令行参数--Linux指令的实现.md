命令行参数--Linux指令的C实现
===
　　我们平常在写控制台程序时，main()函数一般定义为int main()，很少在main()函数里面传入参数。事实上，在支持C语言的环境中，可以在程序开始执行时将命令行
参数传递给程序，调用main时，它带有两个参数，第一个参数(一般定义为int argc，用于参数计数)的值表示运行程序时命令行中参数的个数;第二个参数(一般定义为
char* argv[],用于参数向量)是一个指向字符串数组的指针,每个字符串对应一个参数,按照C语言的规定,argv[0]的值是启动该程序的程序名,因此argc的值至少为1,如
果argc大于1说明程序运行时带了参数.下面用C语言实现几个Linux环境中常用的几条指令来说明命令行的用法.

echo
---
echo是一个很简单的指令,其作用是将命令行参数打印在屏幕上.比如,在命令行中输入
```
echo hello world.
```
那么,在屏幕上显示
```
hello world.
```
执行这个程序的时候,argc=3,argv[0]="echo",argv[1]="hello",argv[2]="world."
下面这段代码可以实现这个功能.
```
#include<stdio.h>
int main(int argc,char* argv[])
{
	if(argc>1)
		argc--;
	else
	{
    printf("you should input something.\n");//如果没有带参数,输出提示信息
	  return 1;
  }
  while(argc--)
	{
		printf("%s",*++argv);//依次打印除程序名本身的各个命令行参数
		if(argc)
			putchar(' ');
		else
			putchar('\n');
	}
	return 0;
}
```

cat
---
cat指令也是Linux环境下经常使用的命令,其作用是把文件内容打印到标准输出上.比如输入
```
cat echo.c
```
那么echo.c的内容将会被打印到屏幕上.下面这段代码是cat指令的简单实现.
```
#include<stdio.h>
int main(int argc,char* argv[])
{
	FILE* inputfile;
	int c;
	if(argc>1)
	{
		argc--;
		inputfile=fopen(argv[1],"r");//以只读的方式打开文件.
	}
	else
		inputfile = stdin;//如果没有输入文件,那么复制标准输入到标准输出;
	if(inputfile==NULL)//判断文件是否成功打开
	{
		printf("cann't open \"%s\".\n",argv[1]);
		return 2;
	}
	while((c=getc(inputfile))!=EOF)//依次读取inputfile所指向的文件中的字符,读完为止
		putchar(c);
	fclose(inputfile);//关闭输入文件.
	return 0;
}
```
mv 
---
mv指令的作用是移动文件或修改文件名,比如输入
```
mv cat.c /home/zk/mycat.c 
```
可以将当前目录下的cat.c文件移动到/home/zk目录下,并修改文件名为mycat.c.这条指令可以由下面这段代码实现.
```
#include<stdio.h>
int main(int argc,char* argv[])
{
	if(argc<3)
	{
		printf("Please input the old file name and new file name\n");//argc小于3,说明输入格式有误
		return 1;
	}
	if(rename(argv[1],argv[2])==0)      //调用rename函数,如果函数执行正常,返回0
		printf("%s has been renamed to %s.\n",argv[1],argv[2]);
	else
		printf("cann't change %s.\n",argv[1]);//改名不成功,输出错误信息
	return 0;
}

```

cp
---
cp指令用于文件复制,比如输入以下指令
```
cp mv.c /home/mymv.c
```
可以将当前目录下的mv.c文件复制到/home目录下,并命名为mv.c.代码实现的思路是打开被复制的文件和要创建的文件,把被复制的文件内容一个字符一个字符拷贝过去
就行了,代码实现:
```
#include<stdio.h>
int main(int argc,char* argv[])
{
	char c;
	if(argc<3)
	{
		printf("Please input the source file name and new file name\n");
		return 1;
	}
	FILE* input = fopen(argv[1],"r");     //以只读方式打开源文件
	FILE* output = fopen(argv[2],"w");    //以写方式创建目标文件,如果目标文件存在会被覆盖.
	if(input==NULL)
	{
		printf("cann't open \"%s\".\n",argv[1]);
		return 2;
	}
	while((c=getc(input))!=EOF)           //挨个字符复制
	{
		putc(c,output);
	}
	fclose(input);            //关闭文件
	fclose(output);
	return 0;
}
```



