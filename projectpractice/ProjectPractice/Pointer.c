# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

typedef struct girlfriend
{
	double height;
	int weight;
	char name[100];
}girlfriend;
void changeName(girlfriend* gf);
int main()
{
	girlfriend myGF;
	myGF.height = 1.63;
	myGF.weight = 45;
	strcpy(myGF.name,"cmt");
	printf("name: %s\n", myGF.name);
	printf("height: %f\n", myGF.height);
	printf("weight: %d\n", myGF.weight);
	changeName(&myGF);
	printf("name: %s\n", myGF.name);
}
void changeName(girlfriend* gf) {
	scanf("%s", gf->name);
}