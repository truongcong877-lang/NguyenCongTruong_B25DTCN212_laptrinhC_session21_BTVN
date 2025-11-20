#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct Address{
	char street[100];
	char city[50];
	int zip;
};
struct Person{
	char name[50];
	int age;
	struct Address address;
};
int main(){
	struct Person preson1;
	printf("Nhap ten: ");
	fgets(preson1.name, sizeof(preson1.name), stdin);
	preson1.name[strcspn(preson1.name, "\n")] = '\0';
	printf("\nNhap tuoi: ");
	scanf("%d", &preson1.age);
	getchar();
	printf("\nNhap ten duong: ");
	fgets(preson1.address.street, sizeof(preson1.address.street), stdin);
	preson1.address.street[strcspn(preson1.address.street, "\n")] = '\0';
	printf("\nNhap ten thanh pho: ");
	fgets(preson1.address.city, sizeof(preson1.address.city), stdin);
	preson1.address.city[strcspn(preson1.address.city, "\n")] = '\0';
	printf("\nNhap ma zip: ");
	scanf("%d", &preson1.address.zip);
	printf("\n-----THONG TIN NGUOI DUNG------\n");
	printf("\nTen: %s",preson1.name);
	printf("\nTuoi: %d",preson1.age);
	printf("\nTen duong: %s",preson1.address.street);
	printf("\nTen thanh pho: %s",preson1.address.city);
	printf("\nMa zip thanh pho %s: %d",preson1.address.city, preson1.address.zip);

return 0;
}

