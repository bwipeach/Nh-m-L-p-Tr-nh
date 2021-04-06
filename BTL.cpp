#include<stdio.h>
#include<stdlib.h>
struct ThucUong{
    char ten[30];
    char ma[10];
    float sotien;
};
void nhap(ThucUong *thucuong);
void xuat(ThucUong *thucuong);
void nhapthucuong(ThucUong *&thucuong, int &n);
void xuatthucuong(ThucUong *thucuong, int n);
int main(){
    ThucUong *thucuong;
    int sothucuong;
    thucuong=(ThucUong*)malloc(sizeof(ThucUong));
    nhap(thucuong);
    xuat(thucuong);
    nhapthucuong(thucuong,sothucuong);
    xuatthucuong(thucuong,sothucuong);
    return 0;
}
void nhap(ThucUong *thucuong){
    fflush(stdin);
    printf("ten thuc uong:");
    gets(thucuong->ten);
    printf("ma thuc uong:");
    gets(thucuong->loai);
    printf("so tien:");
    scanf("%f",&thucuong->sotien);
}
void xuat(ThucUong *thucuong){
    printf("\nten:%s \nloai:%s",thucuong->ten, thucuong->ma);
    printf("sotien:%.3f", thucuong->sotien);
}
void nhapthucuong(ThucUong *&thucuong, int &sothucuong){
    fflush(stdin);
    printf("so luong thuc uong can nhap:");
    scanf("%d",&sothucuong);
    thucuong=(ThucUong*)malloc(sizeof(ThucUong));
    for(int i=0; i < sothucuong;i++){
        nhap(&*(thucuong+i));
    }
}
void xuatthucuong(ThucUong *thucuong, int sothucuong){
    for(int i=0; i < sothucuong;i++){
        xuat((thucuong+i));
    }
}
