#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Student {
    char name[50];
    int age;
    float grade;
};
void linearSearch(struct Student student[], int n) {
    char name[50];
    printf("Nhap ten can tim: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; 
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(student[i].name, name) == 0) {
            printf("\nTim thay: Ten: %s, Tuoi: %d, Diem trung binh: %.2f\n",
                   student[i].name, student[i].age, student[i].grade);
            found = 1;
        }
    }
    if (!found) {
        printf("\nKhong tim thay sv\n");
    }
}
int main() {
    struct Student student[5];

    for (int i = 0; i < 5; i++) {    
        printf("\nNhap ten sv %d: ", i + 1);
        fgets(student[i].name, sizeof(student[i].name), stdin);
        student[i].name[strcspn(student[i].name, "\n")] = '\0';

        printf("Nhap tuoi: ");
        scanf("%d", &student[i].age);
        getchar(); 
        printf("Nhap diem trung binh: ");
        scanf("%f", &student[i].grade);
        getchar(); 
    }
    printf("\n----- DANH SACH SINH VIEN -----\n");
    printf("%-5s %-20s %-20s %-10s\n", "STT|", "Ten sv|", "Tuoi|", "Diem trung binh|");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("%-5d %-20s %-20d %-10.2f\n",
               i + 1, student[i].name, student[i].age, student[i].grade);
    }
    linearSearch(student, 5);

    return 0;
}

