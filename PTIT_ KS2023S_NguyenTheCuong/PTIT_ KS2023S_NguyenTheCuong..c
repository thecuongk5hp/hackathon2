#include <stdio.h>
#include <string.h>

struct CD{
	int id;
	char name[50];
	float duration;
	char content[100];
	int status;
};
void addCD(struct CD cdList[], int *size) {
    struct CD newCD;
    printf("Nhap thong tin CD moi:\n");
    printf("ID: ");
    scanf("%d", &newCD.id);
    printf("Ten: ");
    scanf("%s", newCD.name);
    printf("Thoi luong: ");
    scanf("%f", &newCD.duration);
    printf("Noi dung: ");
    scanf("%s", newCD.content);
    newCD.status = 0;
    
    cdList[*size] = newCD;
    (*size)++;
}
void updateCD(struct CD cdList[], int size) {
    char name[50];
    printf("Nhap ten CD muon chinh sua: ");
    scanf("%s", name);
    
    int foundIndex = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(cdList[i].name, name) == 0) {
            foundIndex = i;
            break;
        }
    }
    
    if (foundIndex != -1) {
        printf("Nhap thong tin moi cho CD:\n");
        printf("ID: ");
        scanf("%d", &cdList[foundIndex].id);
        printf("Ten: ");
        scanf("%s", cdList[foundIndex].name);
        printf("Thoi luong: ");
        scanf("%f", &cdList[foundIndex].duration);
        printf("Noi dung: ");
        scanf("%s", cdList[foundIndex].content);
        printf("Thong tin CD da duoc cap nhat.\n");
    } else {
        printf("Khong tim thay CD.\n");
    }
}
void deleteCD(struct CD cdList[], int *size) {
    char name[50];
    printf("Nhap ten CD muon xoa: ");
    scanf("%s", name);
    
    int foundIndex = -1;
    for (int i = 0; i < *size; i++) {
        if (strcmp(cdList[i].name, name) == 0) {
            foundIndex = i;
            break;
        }
    }
    
    if (foundIndex != -1) {
        for (int i = foundIndex; i < *size - 1; i++) {
            cdList[i] = cdList[i + 1];
        }
        (*size)--;
        printf("CD da duoc xoa.\n");
    } else {
        printf("Khong tim thay CD.\n");
    }
}

int main() {
	
	struct CD cdList[100];
    int size = 2;
    
    cdList[0].id = 1;
    strcpy(cdList[0].name, "CD1");
    cdList[0].duration = 4.5;
    strcpy(cdList[0].content, "Content1");
    cdList[0].status = 1;
    
    cdList[1].id = 2;
    strcpy(cdList[1].name, "CD2");
    cdList[1].duration = 3.2;
    strcpy(cdList[1].content, "Content2");
    cdList[1].status = 0;
	
	int choice;
	do{
		printf("************************MENU**************************\n");
		printf("1. In toan bo danh sach cd co o trong mang cdList tren cung mot hang\n");
		printf("2. Them moi cd vao vi tri cuoi cung cua cdList\n");
		printf("3. Cap nhat thong tin ca mot cd\n");
		printf("4. xoa mot cd\n");
		printf("5. Sap xep va in ra danh sach cdList da duoc sap xep tang dan\n");
		printf("6. Tim kiem va in ra thong tin cua cd\n");
		printf("7. Tim kiem va in ra toan bo thong tin cua cac cd theo status\n");
		printf("Lua chon cua ban: ");
		scanf("%d",&choice);
		fflush(stdin); 	
		switch(choice){
			case 1:
				printf("Danh sach CD:\n");
			    for (int i = 0; i < size; i++) {
printf("ID: %d\n", cdList[i].id);
			        printf("Ten: %s\n", cdList[i].name);
			        printf("Thoi luong: %.2f\n", cdList[i].duration);
			        printf("Noi dung: %s\n", cdList[i].content);
			        printf("Trang thai: %s\n", cdList[i].status ? "da muon" : "Chua muon");
			        printf("--------------------\n");
			    }
				break;
			case 2:
				addCD(cdList, &size);
				break;
			case 3:
				updateCD(cdList, size);
				break;
			case 4:
				deleteCD(cdList, &size);
				break;
		
			default:
                printf("Chuc nang khong hop le.\n");
                break;
        }							
		printf("\n");
		
		
	}while(choice != 6);
		return 0;
}
