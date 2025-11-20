#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Product {
    char id[20];
    char name[50];
    float costPrice;
    float sellPrice;
    int quantity;
};

void inputProduct(struct Product *p) {
    printf("Nhap ma san pham: ");
    fgets(p->id, sizeof(p->id), stdin);
    p->id[strcspn(p->id, "\n")] = '\0';
    printf("Nhap ten san pham: ");
    fgets(p->name, sizeof(p->name), stdin);
    p->name[strcspn(p->name, "\n")] = '\0';
    printf("Nhap gia nhap: ");
    scanf("%f", &p->costPrice);
    getchar();
    printf("Nhap gia ban: ");
    scanf("%f", &p->sellPrice);
    getchar();
    printf("Nhap so luong: ");
    scanf("%d", &p->quantity);
    getchar();
}

void displayProducts(struct Product products[], int n) {
    printf("\n%-10s %-20s %-12s %-12s %-10s\n", "Ma SP", "Ten SP", "Gia nhap", "Gia ban", "So luong");
    printf("---------------------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%-10s %-20s %-12.2f %-12.2f %-10d\n", 
            products[i].id, products[i].name, products[i].costPrice, products[i].sellPrice, products[i].quantity);
    }
}

int findProductIndexById(struct Product products[], int n, char id[]) {
    for(int i = 0; i < n; i++) {
        if(strcmp(products[i].id, id) == 0) return i;
    }
    return -1;
}

void addProduct(struct Product products[], int *n, float *revenue) {
    struct Product p;
    inputProduct(&p);
    int idx = findProductIndexById(products, *n, p.id);
    if(idx != -1) {
        products[idx].quantity += p.quantity;
        *revenue -= p.quantity * p.costPrice;
        printf("San pham da ton tai, tang so luong.\n");
    } else {
        products[*n] = p;
        *revenue -= p.quantity * p.costPrice;
        (*n)++;
    }
}

void updateProduct(struct Product products[], int n) {
    char id[20];
    printf("Nhap ma san pham can cap nhat: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int idx = findProductIndexById(products, n, id);
    if(idx != -1) {
        inputProduct(&products[idx]);
        printf("Cap nhat thanh cong.\n");
    } else {
        printf("Khong tim thay san pham.\n");
    }
}

void sortProductsByPrice(struct Product products[], int n) {
    int choice;
    printf("Chon sap xep theo gia: 1. Tang dan  2. Giam dan: ");
    scanf("%d", &choice);
    getchar();
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if((choice==1 && products[i].sellPrice > products[j].sellPrice) ||
               (choice==2 && products[i].sellPrice < products[j].sellPrice)) {
                struct Product tmp = products[i];
                products[i] = products[j];
                products[j] = tmp;
            }
        }
    }
    printf("Sap xep xong.\n");
}

void searchProduct(struct Product products[], int n) {
    char name[50];
    printf("Nhap ten san pham can tim: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    int found=0;
    for(int i = 0; i < n; i++) {
        if(strstr(products[i].name, name) != NULL) {
            printf("%-10s %-20s %-12.2f %-12.2f %-10d\n", 
                products[i].id, products[i].name, products[i].costPrice, products[i].sellPrice, products[i].quantity);
            found=1;
        }
    }
    if(!found) printf("Khong tim thay san pham.\n");
}

void sellProduct(struct Product products[], int n, float *revenue) {
    char id[20];
    int qty;
    printf("Nhap ma san pham muon ban: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int idx = findProductIndexById(products, n, id);
    if(idx == -1) {
        printf("Khong tim thay san pham.\n");
        return;
    }
    if(products[idx].quantity == 0) {
        printf("Het hang.\n");
        return;
    }
    printf("Nhap so luong muon ban: ");
    scanf("%d", &qty);
    getchar();
    if(qty > products[idx].quantity) {
        printf("Khong con du hang.\n");
        return;
    }
    products[idx].quantity -= qty;
    *revenue += qty * products[idx].sellPrice;
    printf("Ban thanh cong.\n");
}

int main() {
    struct Product products[100];
    int n=0;
    float revenue=0;
    int choose;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Doanh thu hien tai\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);
        getchar();
        switch(choose) {
            case 1: {
                printf("Nhap so luong san pham: ");
                scanf("%d", &n);
                getchar();
                for(int i=0;i<n;i++) {
                    printf("Nhap san pham thu %d:\n", i+1);
                    inputProduct(&products[i]);
                    revenue -= products[i].quantity * products[i].costPrice;
                }
                break;
            }
            case 2: displayProducts(products, n); break;
            case 3: addProduct(products, &n, &revenue); break;
            case 4: updateProduct(products, n); break;
            case 5: sortProductsByPrice(products, n); break;
            case 6: searchProduct(products, n); break;
            case 7: sellProduct(products, n, &revenue); break;
            case 8: printf("Doanh thu hien tai: %.2f\n", revenue); break;
            case 9: printf("Thoat chuong trinh\n"); break;
            default: printf("Lua chon khong hop le\n");
        }
    } while(choose != 9);
    return 0;
}

