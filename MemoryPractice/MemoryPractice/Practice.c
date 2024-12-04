#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char *str, *p;
	int len;
	printf("please input max length\n");
	scanf("%d",&len);
	getchar();
	str = (char*)malloc(sizeof(char) * (len + 1));
	fgets(str,len+1,stdin);
	if ((p = strchr(str, '\n')) != NULL) {
		*p = '\0';
	}
	printf("%s\n",str);
	free(str);
	return 0;
}