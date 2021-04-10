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
int tinhTong(ThucUong *thucuong, int sothucuong );
void sapxepten(ThucUong *thucuong, int sothucuong);
void sapxepma(ThucUong *thucuong, int sothucuong);
void sapxepsoluong(ThucUong *thucuong, int sothucuong);
void thongketen(ThucUong *thucuong, int sothucuong);
void thongkema(ThucUong *thucuong, int sothucuong);
void thongkesoluong(ThucUong *thucuong, int sothucuong);
void timkiemten(ThucUong *thucuong, int sothucuong);
void timkiemma(ThucUong *thucuong, int sothucuong);
void timkiemsoluong(ThucUong *thucuong, int sothucuong);
void menu(ThucUong *thucuong, int sothucuong);
int main(){
    ThucUong *thucuong;
    int sothucuong;
    thucuong=(ThucUong*)malloc(sizeof(ThucUong));
    nhapthucuong(thucuong,sothucuong);
    menu(thucuong,sothucuong);
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
}void timkiemten(ThucUong *thucuong, int sothucuong){
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
void menu(ThucUong *thucuong, int sothucuong){
    int chon;
    char k,c;
    do{
        printf("\n=========Menu=========\n");
        printf("1.Xuat thuc uong da nhap\n");
        printf("2.Thong ke thuc uong theo ten (A->Z)\n");
        printf("3.Thong ke thuc uong theo ma\n");
        printf("4.Thong ke thuc uong theo so luong\n");
        printf("5.Sap xep thuc uong theo ten\n");
        printf("6.Sap xep thuc uong theo ma\n");
        printf("7.Sap xep thuc uong theo so luong\n");
        printf("8.Tim kiem thuc uong theo ten\n");
        printf("9.Tim kiem thuc uong theo ma\n");
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
                sapxepten(thucuong,sothucuong);
                break;
            case 6:
                sapxepma(thucuong,sothucuong);
                break;
            case 7:
                sapxepsoluong(thucuong,sothucuong);
                break;
            case 8:
                timkiemten(thucuong,sothucuong);
                break;
            case 9:
                timkiemma(thucuong,sothucuong);
                break;
            default:
                printf("Khong hop le ! Vui long nhap lai:");
        }
        printf("ban co muon thoat ? (esc)");
        k=getch();
        c=k;
    }while(c!=27);
}
