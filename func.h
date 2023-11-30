struct shop{
	char name[40];
	int price;
	int quantity;
};
int ch(int *p);
void write(struct shop *arr, int n);
void read(struct shop **arr, int *n); 
void create(struct shop **arr, int *n);  
void find(struct shop *arr, int *n, int nn);  
