#include <stdio.h>
#include <stdlib.h>

//pemanggilan fungsi
void home();
void hitunggaji();
float validasi();
void ulang();

//menampung typedata dan variabel 
typedef struct{
    int harian_perjam;
    int lembur_perjam;
    int harian_jam;
    int lembur_jam;
    int lembur_gaji;
    int harian_gaji;
} Gaji;

//awalan dari program
int main(){
    system("color 2F");
    printf("+======================================================+\n");
    printf("|                                                      |\n");
    printf("|       PROGRAM PERHITUNGAN GAJI DENGAN STRUCT         |\n");
    printf("|         OLEH KELOMPOK 13 PRATIKUM ALPROG             |\n");
    printf("|                                                      |\n");
    printf("|======================================================|\n");
    printf("| Anggota:                                             |\n");
    printf("| 2105551023    I Ketut Putra Jaya                     |\n");
    printf("| 2105551052    Kadek Cahyadi Yogachandra              |\n");
    printf("| 2105551102    Dyah Putri Maheswari                   |\n");
    printf("| 2105551105    Greace Amanda R.Y		        	   |\n");
    printf("| 2105551104	Velicia Varrel Valiant                 |\n");
    printf("| 2105551125    A.A. Sagung Mirah Indira Wardhana      |\n");
    printf("+======================================================+\n\n");
    printf("Tekan apa saja untuk melanjutkan...");
	getch();
	home();
    system("cls");
    return 0;
}

//pemanggilan fungsi menu awal
void home(){
    float a;
    int b;
    system("cls");
    printf("+=================================================+\n");
	printf("|                 SELAMAT DATANG                  |\n");
	printf("|         PROGRAM PENGHITUNGAN GAJI HARIAN        |\n");
	printf("+=================================================+\n\n");
    printf("---------------------------------------------------\n");
    printf("==> Masukkan Jumlah Jam Kerja Anda : ");
    while(a!=b || a<1 || a>24){//perulangan
        a=validasi();//validasi
        b=(int)a;
        if(a!=b || a<1 || a>24){
           printf("\n------------------------------------------------\n");
            printf("|               INPUT ANDA ERROR               |\n");
            printf("|         SILAHKAN MENGULANGI INPUTAN          |\n");
            printf("------------------------------------------------\n");
            printf("==> Silahkan Masukan Angka Yang Baru : ");
            system("PAUSE");
        }
    }
    
    system("cls");
    hitunggaji(b);

}

//proses perhitungan gaji
void hitunggaji(int b){
    Gaji g;
    int total;
    g.harian_perjam;
    g.lembur_perjam;
    g.harian_jam;
    g.lembur_jam;
    g.lembur_gaji;
    g.harian_gaji;
    
    //perhitungan
    g.harian_perjam=10625;
    g.lembur_perjam=10625*8;
    g.harian_jam=b;
    if(g.harian_jam>8){
        g.lembur_jam=g.harian_jam-8;
        g.harian_jam=8;
        g.lembur_gaji=g.lembur_jam*g.lembur_perjam;
    }
    g.harian_gaji=g.harian_jam* g.harian_perjam;
    
    if(b>8){
        total=g.harian_gaji+g.lembur_gaji;
    }
    if (b>8){
    printf("       ===================================== \n");
    printf("  =============                     ==============\n");
    printf(" ============    TOTAL GAJI HARIAN    =============\n");
    printf("  ==============                   ===============\n");
    printf("       ===================================== \n");
    printf("+----------------------------------------------------------+\n");
    printf("|       GAJI HARIAN         |       GAJI LEMBUR            |\n");
    printf("|----------------------------------------------------------|\n");
    printf("| GAJI PER JAM :Rp%d     | GAJI PER JAM :    Rp%d    |\n", g.harian_perjam, g.lembur_perjam);
    printf("| JAM KERJA    :%d JAM       | JAM KERJA    : %d JAM         |\n",g.harian_jam, g.lembur_jam);
    printf("| GAJI         :Rp%d     | GAJI LEMBUR  : Rp%d      |\n",g.harian_gaji, g.lembur_gaji);
    printf("+==========================================================+\n");
    printf("| TOTAL GAJI                |      Rp%d                |\n",total);
    printf("+==========================================================+\n");

    }
    else if(b<=8){
    printf("       ===================================== \n");
    printf("  =============                     ==============\n");
    printf(" ============    TOTAL GAJI HARIAN    =============\n");
    printf("  ==============                   ===============\n");
    printf("       ===================================== \n");
    printf("+--------------------------------------------------+\n");
    printf("|                   GAJI HARIAN                    |\n");
    printf("|--------------------------------------------------|\n");
    printf("| GAJI PER JAM      :Rp%d                       |\n", g.harian_perjam);
    printf("| JAM KERJA         :%d JAM                         | \n",g.harian_jam);
    printf("| GAJI              :Rp%d                       | \n",g.harian_gaji);
    printf("+==================================================+\n");
    printf("| TOTAL GAJI        :      Rp%d                 |\n",g.harian_gaji);
    printf("+==================================================+\n");
    }
    printf("Tekan apa saja untuk melanjutkan...");
	getch();
    ulang();
}

//validasi 
float validasi(){

    char input[100];
    int a, i;
    int negatif=0;
    int salah=0;
    int koma=0;
    int belakang=0;
    int deret=0;
    int depan=0;
    float nolKoma=1;
    float hasil;

    scanf("%[^\n]", &input);
    fflush(stdin);

    if(input[a]=='\0'){
        salah=1;
    }

    while(input[a]!='\0'){
        if(input[a]=='.'){
            koma++;
            if(input[0]=='.' || input[a+1]=='\0' || koma>1 ){
                salah=1;
                input[a]='\0';
            }
            a++;
        }else if(input[a]>='0' && input[a]<='9'){
            if(koma==1){
                belakang=(belakang*10)+(input[a]-48);
                deret++;
                a++;
            }else{
                depan=(depan*10)+(input[a]-48);
                a++;
            }
        }else{
            salah=1;
            input[a]='\0';
        }
    }

    if(koma==1){
        for(i=0;i<deret;i++){
            nolKoma=nolKoma/10;
        }
        hasil=belakang*nolKoma+depan;

    }else{
        hasil=depan;
    }

    if(salah==1){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");
        system("PAUSE");
        system("cls");
        printf("+=================================================+\n");
		printf("|                 SELAMAT DATANG                  |\n");
		printf("|         PROGRAM PENGHITUNGAN GAJI HARIAN        |\n");
		printf("+=================================================+\n\n");
    	printf("---------------------------------------------------\n");
   	 printf("==> Masukkan Ulang Jumlah Jam Kerja Anda : ");
        return validasi();
    }else{
        return hasil;
    }

}

void ulang(){
    float a;
    int b;

    system("cls");
    printf("+-------------------------------------------------------+\n");
    printf("|  APAKAH ANDA INGIN MENGULANG PERHITUNGAN GAJI HARIAN? |\n");
    printf("+-------------------------------------------------------+\n");
    printf("| PILIHAN :                                             |\n");
    printf("| --> YA    = 1                                         |\n");
    printf("| --> TIDAK = 2                                         |\n");
    printf("+-------------------------------------------------------+\n");
    printf("==> Masukkan Pilihan : ");
    a=validasi();
    b=(int)a;
    
    while(a!=b || a<1 || a>2){
      printf("\n+----------------------------------------------+\n");
        printf("|               INPUT ANDA ERROR               |\n");
        printf("|         SILAHKAN MENGULANGI INPUTAN          |\n");
        printf("+----------------------------------------------+\n");
        system("PAUSE");
        system("cls");
        printf("+-------------------------------------------------------+\n");
    	printf("|  APAKAH ANDA INGIN MENGULANG PERHITUNGAN GAJI HARIAN? |\n");
    	printf("+-------------------------------------------------------+\n");
    	printf("| PILIHAN :                                             |\n");
    	printf("| --> YA    = 1                                         |\n");
    	printf("| --> TIDAK = 2                                         |\n");
    	printf("+-------------------------------------------------------+\n");
        printf("==> Silahkan Masukan Angka Yang Baru : ");
        a=validasi();
        b=(int)a;
    }

    system("cls");

    if(a==1){
        home();
    }else if(a==2){
        printf("+===============================================+\n");
        printf("|                 Terima  Kasih                 |\n");
        printf("+===============================================+\n\n");
				sleep(1);
				printf(".");
				sleep(1);
				printf(".");
				sleep(1);
				printf(".");
				sleep(1);
				printf(" :)");
				sleep(1);
    }
    exit(0);
}
