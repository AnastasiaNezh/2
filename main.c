#include <stdio.h>
#include <stdlib.h>
#include "func.h"
int main(){
   struct shop *arr = NULL;
   int n=0;
   int stop=0;
   while (stop!=1){
	int key=0;
	printf("1-create, 2-read, 3-print, 4-find\n");
	ch(&key);
	switch(key){
	   case 1:
		create(&arr,&n);
		if (arr)
		   write(arr,n);;
		break;
	   case 2:
		read(&arr,&n);
		if (!arr)
		   printf("read error\n");
		else
		   printf("loaded %d\n", n);
		break;
	   case 3:
		for (int i=0; i<n; i++)
		   printf("name product = %s, price = %d, quantity = %d\n", arr[i].name, arr[i].price, arr[i].quantity);
		break;
	   case 4:
		printf("1-name product, 2-price, 3-quantity\n");
		int x;
		scanf("%d", &x);
		find(arr, &n, x);
		break;
	   default:
	   stop=1;
	   break;
	}
   }
if (arr)
   free(arr);
return 0;
}

