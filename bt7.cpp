#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Book{
    char id[20];
    char name[50];
    char author[50];
    float price;
    char category[30];
};


void inputBook(struct Book *b){
    printf("Nhap id sach: ");
    fgets(b->id, sizeof(b->id), stdin);
    b->id[strcspn(b->id, "\n")] = '\0';

    printf("Nhap ten sach: ");
    fgets(b->name, sizeof(b->name), stdin);
    b->name[strcspn(b->name, "\n")] = '\0';

    printf("Nhap ten tac gia: ");
    fgets(b->author, sizeof(b->author), stdin);
    b->author[strcspn(b->author, "\n")] = '\0';

    printf("Nhap gia tien: ");
    scanf("%f", &b->price);  // s?a %d -> %f
    getchar();

    printf("Nhap the loai: ");
    fgets(b->category, sizeof(b->category), stdin);
    b->category[strcspn(b->category, "\n")] = '\0';
}


void displayBook(struct Book books[], int n){
    printf("\n%-10s %-25s %-20s %-10s %-15s\n", "Ma sach", "Ten sach", "Tac gia", "Gia", "The loai");
    printf("-------------------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%-10s %-25s %-20s %-10.2f %-15s\n",
               books[i].id, books[i].name, books[i].author, books[i].price, books[i].category);
    }
}


void insertBook(struct Book books[], int *n){
    int pos;
    printf("Nhap vi tri muon them (1 - %d): ", *n + 1);
    scanf("%d", &pos);
    getchar();
    if(pos < 1 || pos > *n + 1){
        printf("\nVi tri khong hop le!\n");
        return;
    }
    for(int i = *n; i >= pos; i--){
        books[i] = books[i - 1];
    }
    printf("\nNhap thong tin sach moi:\n");
    inputBook(&books[pos - 1]);
    (*n)++;
    printf("\nThem thanh cong!\n");
}


void deleteBook(struct Book books[], int *n){
    char id[20];
    printf("Nhap ma sach muon xoa: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    int found = 0;
    for(int i = 0; i < *n; i++){
        if(strcmp(books[i].id, id) == 0){
            for(int j = i; j < *n - 1; j++){
                books[j] = books[j + 1];
            }
            (*n)--;
            found = 1;
            printf("\nXoa thanh cong!\n");
            break;
        }
    }
    if(!found){
        printf("\nKhong tim thay sach co ma %s\n", id);
    }
}


void updateBook(struct Book books[], int n){
    char id[20];
    printf("Nhap ma sach can cap nhat: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    int found = 0;
    for(int i = 0; i < n; i++){
        if(strcmp(books[i].id, id) == 0){
            printf("Nhap thong tin moi cho sach:\n");
            inputBook(&books[i]);
            printf("Cap nhat thanh cong!\n");
            found = 1;
            break;
        }
    }
    if(!found) printf("Khong tim thay sach co ma %s\n", id);
}


void sortBooksByPrice(struct Book books[], int n){
    int choice;
    printf("Chon sap xep theo gia(1. Tang dan  2. Giam dan): ");
    scanf("%d", &choice);
    getchar();
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if((choice == 1 && books[i].price > books[j].price) ||
               (choice == 2 && books[i].price < books[j].price)){
                struct Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Sap xep xong!\n");
}


void searchBookByName(struct Book books[], int n){
    char name[50];
    printf("Nhap ten sach can tim: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int found = 0;
    for(int i = 0; i < n; i++){
        if(strstr(books[i].name, name) != NULL){
            printf("%-10s %-25s %-20s %-10.2f %-15s\n",
                   books[i].id, books[i].name, books[i].author, books[i].price, books[i].category);
            found = 1;
        }
    }
    if(!found) printf("Khong tim thay sach!\n");
}

int main(){
    struct Book books[100];
    int n = 0;
    int choose;

    do{
        printf("\n===== MENU =====\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia\n");
        printf("7. Tim kiem sach theo ten\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);
        getchar(); 

        switch(choose){
            case 1:{
                printf("Nhap so luong sach: ");
                scanf("%d", &n);
                getchar();
                for(int i = 0; i < n; i++){
                    printf("\nNhap sach thu %d:\n", i+1);
                    inputBook(&books[i]);
                }
                break;
            }
            case 2:{
                displayBook(books, n);
                break;
            }
            case 3:{
                insertBook(books, &n);
                break;
            }
            case 4:{
                deleteBook(books, &n);
                break;
            }
            case 5:{
                updateBook(books, n);
                break;
            }
            case 6:{
                sortBooksByPrice(books, n);
                break;
            }
            case 7:{
                searchBookByName(books, n);
                break;
            }
            case 8:{
                printf("\nThoat chuong trinh\n");
                break;
            }
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while(choose != 8);

    return 0;
}

