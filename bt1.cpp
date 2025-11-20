#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct car{
	char model[100];
	int year;
	float price;
};
int main(){
	struct car myCar = {"Koenigsegg agera", 2010, 49.931};
		printf("\nThong tin xe\n");
		printf("\nModel: %s", myCar.model);
		printf("\nYear: %d", myCar.year );
		printf("\nPrice: %.f ty VND", myCar.price);

return 0;
}

