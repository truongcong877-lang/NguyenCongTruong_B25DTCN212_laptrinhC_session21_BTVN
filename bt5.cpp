#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct Product{
	char name[50];
	float price;
	int quantity;
};
int main(){
	struct Product product[5];
	for(int i = 0; i < 5; i++){
		printf("\nTen san pham %d: ", i + 1);
		fgets(product[i].name, sizeof(product[i].name), stdin);
		product[i].name[strcspn(product[i].name, "\n")] = '\0';
		printf("\nGia san pham %d: ", i + 1);
		scanf("%f", &product[i].price);
		getchar();
		printf("\nSo luong san pham %d: ", i + 1);
		scanf("%d", &product[i].quantity);
		getchar();
	}
	printf("\n----- DANH SACH SACH -----\n");
	printf("%-5s %-20s %-20s %-10s\n","STT|", "Ten sp|", "Gia sp|", "So luong|");
	printf("---------------------------------------------------------------\n");
	for(int i = 0; i < 5; i++){
		printf("%-5d %-20s %-20.2f %-10d\n", i + 1, product[i].name, product[i].price, product[i].quantity);
	}
	float total = 0;
	for(int i = 0; i < 5; i++){
		total += product[i].price * product[i].quantity; 
	}
	printf("\nTong gia tri tat ca cac san pham trong danh sach: %.2f", total);

return 0;
}

