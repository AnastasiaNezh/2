#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
int ch(int *p){
   if (scanf("%u", p)==1)
	return 0;
   else{
	printf("error\n");
	while(getchar()!='\n');
	return 1;
   }
}
void write(struct shop *arr, int n){
   if (n<=0)
	return;
   FILE *f=fopen("file.txt","w");
   if (!f)
	return;
   fprintf(f,"%d\n", n);
   for(int i=0;i<n;i++)
	fprintf(f,"%s %d %d\n", arr[i].name, arr[i].price, arr[i].quantity);
   fclose(f);
}
void read(struct shop **arr, int *n){
   FILE *f=fopen("file.txt","r");
   if (!f)
        return;
   if (fscanf(f, "%d", n)!=1)
	return;
   if (*n<=0) 
	return;
   *arr=(struct shop *)calloc(*n,sizeof(struct shop));
   for (int i=0;i<*n;i++)
        fscanf(f,"%s %d %d",(*arr)[i].name, &(*arr)[i].price, &(*arr)[i].quantity);
   fclose(f);
}
void create(struct shop **arr, int *n){
   printf("n=");
   if(ch(n))
	return;
   if (*n<=0)
	return;
   *arr=(struct shop *)calloc(*n,sizeof(struct shop));
   for (int i=0;i<*n;i++){
	printf("name product=");
	scanf("%s",(*arr)[i].name);
	printf("price=");
        if (ch(&(*arr)[i].price))
                return;
	printf("quantity=");
	if (ch(&(*arr)[i].quantity))
		return;
}
}
void find(struct shop *arr, int *n, int nn){
   char x1[40];
   switch(nn){
	case 1:
		int f1=0;
		printf("enter the product name\n");
		scanf("%40s",x1);
		while(getchar()!='\n');
		for (int i=0; i<*n; i++){
		   if (!strcmp(arr[i].name, x1)){
			printf("name product = %s, price = %d, quantity = %d\n", arr[i].name, arr[i].price, arr[i].quantity);
			f1=1;
		   }
		}
		if (f1==0)
			printf("not found\n");
		break;
	case 2:
                int f2=0;
		int x2;
		printf("enter the price\n");
		if(ch(&x2))
		   return;
                for (int i=0; i<*n; i++){
                   if (x2==arr[i].price){
                        printf("name product = %s, price = %d, quantity = %d\n", arr[i].name, arr[i].price, arr[i].quantity);
			f2=1;
                   }
                }
                if (f2==0)
                        printf("not found\n");
                break;
	case 3:
		int f3=0;
		int x3;
                printf("enter the price\n");
                if(ch(&x3))
                   return;
                for (int i=0; i<*n; i++){
                   if (x3==arr[i].quantity){
                        printf("name product = %s, price = %d, quantity = %d\n", arr[i].name, arr[i].price, arr[i].quantity);
			f3=1;
                   }
                }
                if (f3==0)
                        printf("not found\n");
                break;
	default:
		break;

}
}



