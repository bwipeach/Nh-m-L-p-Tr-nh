#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct ThucUong{
    char ten[30];
    char ma[10];
    float sotien;
    int soluong;
};
void nhap(ThucUong *thucuong);
void xuat(ThucUong *thucuong);
void nhapthucuong(ThucUong *&thucuong, int &sothucuong);
void xuatthucuong(ThucUong *thucuong, int sothucuong);
int tinhTong(ThucUong *thucuong, int sothucuong );
void sapxepten(ThucUong *thucuong, int sothucuong);
void sapxepma(ThucUong *thucuong, int sothucuong);
void sapxepsoluong(ThucUong *thucuong, int sothucuong);
void thongketen(ThucUong *thucuong, int sothucuong);
void thongkema(ThucUong *thucuong, int sothucuong);
void thongkesoluong(ThucUong *thucuong, int sothucuong);
void timkiemten(ThucUong *thucuong, int sothucuong);
void timkiemma(ThucUong *thucuong, int sothucuong);
void menu(FILE *file, char *diachi,ThucUong *thucuong, int sothucuong);
void filenhiphan(FILE *file, char *diachi, ThucUong *thucuong, int sothucuong);
int main(){
    FILE *file;
    char *diachi = "./src/classroom.out";
    ThucUong *thucuong;
    int sothucuong;
    thucuong=(ThucUong*)malloc(sizeof(ThucUong));
    nhapthucuong(thucuong,sothucuong);
    xuatthucuong(thucuong,sothucuong);
    tinhTong(thucuong,sothucuong);
    if(thucuong!=NULL);
    free(thucuong);
    return 0;
}
void nhap(ThucUong *thucuong){
    fflush(stdin);
    printf("ten thuc uong:");
    gets(thucuong->ten);
    printf("ma thuc uong:");
    gets(thucuong->ma);
    printf("so tien:");
    scanf("%f",&thucuong->sotien);
    printf("so luong thuc uong:");
    scanf("%d",&thucuong->soluong);
}
void xuat(ThucUong *thucuong){
    printf("\n=======================================================\n");
    printf("\nTen: %-10s|| Ma Thuc Uong: %-5s|| So Tien: %-8f|| So Luong: %-3d",thucuong->ten,thucuong->ma,thucuong->sotien,thucuong->soluong);
}
void nhapthucuong(ThucUong *&thucuong, int &sothucuong){
    printf("so luong thuc uong can nhap:");
    scanf("%d",&sothucuong);
    thucuong = (ThucUong*)realloc(thucuong,(sothucuong)*sizeof(ThucUong));
    for(int i=0; i < sothucuong;i++){
        nhap(&*(thucuong+i));
        printf("_______________\n");
    }
}
void xuatthucuong(ThucUong *thucuong, int sothucuong){
    for(int i=0; i < sothucuong;i++){
        xuat(thucuong+i);
    }
}
int tinhTong(ThucUong *thucuong, int sothucuong ){
    int sum = 0;
    for(int i=0; i < sothucuong; i++)
        sum+=((thucuong+i)->soluong);
    return sum;
}
void sapxepten(ThucUong *thucuong, int sothucuong){
    ThucUong temp;
    fflush(stdin);
    for(int i=0; i < sothucuong-1; i++ ){
        for(int j=i+1; j < sothucuong; j++){
            if(strcmp((thucuong+i)->ten,(thucuong+j)->ten)>0){
                temp = *(thucuong+i);
                *(thucuong+i)=*(thucuong+j);
                *(thucuong+j)=temp;
            }
        }
    }
}
void sapxepma(ThucUong *thucuong, int sothucuong){
    ThucUong temp;
    fflush(stdin);
    for(int i=0; i < sothucuong-1; i++ ){
        for(int j=i+1; j < sothucuong; j++){
            if(strcmp((thucuong+i)->ma,(thucuong+j)->ma)>0){
                temp = *(thucuong+i);
                *(thucuong+i)=*(thucuong+j);
                *(thucuong+j)=temp;
            }
        }
    }
}
void sapxepsoluong(ThucUong *thucuong, int sothucuong){
    ThucUong temp;
    for(int i=0;i < sothucuong-1; i++){
        for(int j=i+1; j < sothucuong; j++){
            if((thucuong+i)->soluong>(thucuong+j)->soluong){
                temp=*(thucuong+i);
                *(thucuong+i)=*(thucuong+j);
                *(thucuong+j)=temp;
            }
        }
    }
}
void thongketen(ThucUong *thucuong, int sothucuong){
    sapxepten(thucuong,sothucuong);
    for(int i=0;i<sothucuong;i++){
        xuat(thucuong+i);
    }
}
void thongkema(ThucUong *thucuong, int sothucuong){
    sapxepma(thucuong,sothucuong);
    for(int i=0;i < sothucuong;i++){
        xuat(thucuong+i);
    }
}
void thongkesoluong(ThucUong *thucuong, int sothucuong){
    sapxepsoluong(thucuong,sothucuong);
    for(int i=0;i < sothucuong;i++){
        xuat(thucuong+i);
    }
}
void timkiemten(ThucUong *thucuong, int sothucuong){
    char timkiem[10];
    fflush(stdin);
    printf("Nhap ten can tim: ");
    gets(timkiem);
    int dem = 0;
    for(int i=0;i < sothucuong;i++){
        if(strcmp(timkiem,(thucuong+i)->ten)==0){
            dem++;
            printf("ket qua tim kiem phu hop ");
            xuat(thucuong+i);
        }
    }
    if(dem==0)
        printf("khong co ket qua tim kiem phu hop");
}
void timkiemma(ThucUong *thucuong, int sothucuong){
    char timma[10];
    fflush(stdin);
    printf("Nhap ma can tim: ");
    gets(timma);
    int dem = 0;
    for(int i=0;i < sothucuong;i++){
        if(strcmp(timma,(thucuong+i)->ma)==0){
            dem++;
            printf("ket qua tim kiem phu hop ");
            xuat(thucuong+i);
        }
    }
    if(dem==0)
        printf("khong co ket qua tim kiem phu hop");
}
void menu(FILE *file, char *diachi,ThucUong *thucuong, int sothucuong){
    int chon;
    char k,c;
    do{
        printf("\n=========Menu=========\n");
        printf("1.Xuat thuc uong da nhap\n");
        printf("2.Thong ke thuc uong theo ten (A->Z)\n");
        printf("3.Thong ke thuc uong theo ma\n");
        printf("4.Thong ke thuc uong theo so luong\n");
        printf("5.Tim kiem thuc uong theo ten\n");
        printf("6.Tim kiem thuc uong theo ma\n");
        printf("7.Xuat ra file nhi phan\n");
        printf("Nhap lua chon cua ban:");
        scanf("%d",&chon);
        switch(chon){
            case 1:
                xuatthucuong(thucuong,sothucuong);
                break;
            case 2:
                thongketen(thucuong,sothucuong);
                break;
            case 3:
                thongkema(thucuong,sothucuong);
                break;
            case 4:
                thongkesoluong(thucuong,sothucuong);
                break;
            case 5:
                timkiemten(thucuong,sothucuong);
                break;
            case 6:
                timkiemma(thucuong,sothucuong);
                break;
            case 7:
                filenhiphan(file,diachi,thucuong,sothucuong);
                break;
            default:
                printf("Khong hop le ! Vui long nhap lai:");
                break;
        }
        printf("\nban co muon thoat ? (esc)");
        k=getch();
        c=k;
    }while(c!=27);
}
void filenhiphan(FILE *file, char *diachi, ThucUong *thucuong, int sothucuong){
    char *tinhnang = "ab";
    file = fopen(diachi,tinhnang);
    fprintf(file,"thong tin thuc uong cuoi cung la:\n");
    for(int i=0;i < sothucuong;i++){
        fprintf(file,"\nTen: %-20s|| Ma Thuc Uong: %-6s|| So Tien: %-10f|| So Luong: %-4d",(thucuong+i)->ten,(thucuong+i)->ma,(thucuong+i)->sotien,(thucuong+i)->soluong);
        fprintf(file,"\n-------------------------------------------------------------------------------------------------------\n");
    }
    fclose(file);
}
