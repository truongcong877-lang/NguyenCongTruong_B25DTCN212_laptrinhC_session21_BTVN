#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct Book {
    char title[100];
    char author[50];
    float price;
};
int main() {
    struct Book book[3];
    for(int i = 0; i < 3; i++){
        printf("\nNhap ten cuon sach %d: ", i + 1);
        fgets(book[i].title, sizeof(book[i].title), stdin);
        book[i].title[strcspn(book[i].title, "\n")] = '\0';

        printf("Nhap ten tac gia %d: ", i + 1);
        fgets(book[i].author, sizeof(book[i].author), stdin);
        book[i].author[strcspn(book[i].author, "\n")] = '\0';

        printf("Nhap gia sach %d: ", i + 1);
        scanf("%f", &book[i].price);
        getchar(); 
    }
    printf("\n----- DANH SACH SACH -----\n");
    printf("%-5s %-20s %-20s %-10s\n", "STT", "Ten sach", "Tac gia", "Gia");
    printf("---------------------------------------------------------------\n");

    for(int i = 0; i < 3; i++){
        printf("%-5d %-20s %-20s %-10.2f\n", i + 1, book[i].title, book[i].author, book[i].price);
    }
    return 0;
}

