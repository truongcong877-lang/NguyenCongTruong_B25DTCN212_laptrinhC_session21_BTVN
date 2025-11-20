#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct Student{
	char name[50];
	int age;
	float grade;
};
int main(){
	struct Student student1;
	printf("\nNhap ho ten sinh vien: ");
	fgets(student1.name, sizeof(student1.name), stdin);
	student1.name[strcspn(student1.name, "\n")] = 0;
	printf("\nNhap tuoi sinh vien: ");
	scanf("%d", &student1.age );
	printf("\nNhap diem trung binh sinh vien: ");
	scanf("%f", &student1.grade );
	printf("\nThong tin sinh vien");
	printf("\n%-30s %-6s %-15s", "Ten|", "Tuoi|", "Diem trung binh|");
	printf("\n--------------------------------------------------------\n");
	printf("\n%-30s %-6d %-15.2f", student1.name, student1.age, student1.grade);

return 0;
}

