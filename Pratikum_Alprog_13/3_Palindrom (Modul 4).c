#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

void judul();
void lanjut1();
void lanjut2();
void keluar();
FILE *kamuskata;

void judul(){
    system("cls");
	printf("======================================================\n");
    printf("|                                                    |\n");
    printf("|         PROGRAM PENGECEKAN KATA PALINDROM          |\n");
    printf("|                   KELOMPOK 13                      |\n");
    printf("|                                                    |\n");
    printf("| Anggota:                                           |\n");
    printf("| 2105551023	I Ketut Putra Jaya                   |\n");
    printf("| 2105551052    Kadek Cahyadi Yogachandra            |\n");
    printf("| 2105551102	Dyah Putri Maheswari                 |\n");
    printf("| 2105551104	Velicia Varrel Valiant               |\n");
    printf("| 2105551105    Greace Amanda R.Y                    |\n");
    printf("| 2105551125    A.A. Sagung Mirah Indira Wardhana    |\n");
    printf("|                                                    |\n");
    printf("======================================================\n");
}

void keluar(){
	system("cls");
	printf("\n==========================================================");
	printf("\n|         TERIMAKASIH SUDAH MENGGUNAKAN PROGRAM!         |");
    printf("\n==========================================================");
    printf("\n");
    exit(0);
}

//validasi character
int validasi(char masukan[]){
    int i = 0;
    int salah = 0;

    while(masukan[i] != '\0'){
        if((masukan[i] >= 65 && masukan[i] <= 90) || (masukan[i] >= 97 && masukan[i] <= 122) || masukan[i] == ' '){
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }
    if(salah == 1){
        return 0;
    }else{
        return 1;
    }
}

//validasi integer
int validasiPilihan(){
	char ch; 
	char *data; 
	data= (char *) malloc (sizeof(char)); 
	
	int index=0;
	
	while ((ch=getch()) !=13) {
		if (ch>='0' && ch<='9'){
			printf("%c", ch); 
			data[index]=ch; 
			index++;
		}
	}
	data [index]='\0';
	return atoi(data); 
}

int main(){
    int pilih;
    judul(); 
    printf("\n======================================================\n");
    printf("|             1. Pengecekan Kata Palindrom           |\n");
    printf("|             2. History Daftar Kata                 |\n");
    printf("|             3. Keluar Program                      |\n");
    printf("======================================================\n");
    printf("\nMasukkan Pilihan : ");
    pilih = validasiPilihan();
    system ("cls");

    switch(pilih){
	    case 1:
        tentukan_palindrom();
	    break;
	    case 2:
	    daftar_palindrom();
	    break;
	    case 3:
	    keluar();
	    break;
	    default:
	    main();
	    break;
    }
    return 0;
}

char *palindrom(char x[]){
	int i,n=0;
	int p = strlen(x);
	char y[p];
	int p1=p;
	for(i=0;i<p1;i++){
		y[i]=x[p-1];
		p--;
	}
    for(i=0;i<p1;i++){
        if(y[i]!=x[i]){
            n=1;
        }
    }
	if(n==0){
		return("Palindrom");
	}
	else{
		return ("Bukan Palindrom");
	}
}

void kata(char x[]){
	kamuskata=fopen("kamuskata.txt","a+");
	int i, k, count[100];
	bool isSame;
	int p= strlen(x);

	for(i=0;i< p;i++){
		count[i]=0;
		for(k=0;k<p;k++){
			if (x[i]==x[k]){
				count[i]++;
			}
		}
	}
	printf("==============================================\n\n");
	printf("Kata\t\t= %s",x);
	fprintf(kamuskata, "Kata\t\t : %s \nJumlah huruf\t : ",x);
	printf("\nJumlah Huruf\t= ");
	for(i=0;i<p;i++){
		isSame=false;
		for(k=i-1;k>=0;k--){
			if (x[i]==x[k]){
				isSame=true;
				break;
			}
		}
		if(!isSame){
            if(x[i]==' '){

            }else{
			printf("%c=%d ",x[i],count[i]);
			fprintf(kamuskata,"%c=%d ",x[i],count[i]);
            }
		}
	}
	printf("\nKeterangan\t= %s",palindrom(x));
	fprintf(kamuskata,"\n>>> %s <<<\n\n",palindrom(x));
	fclose(kamuskata);
}



int tentukan_palindrom(){
    int cek;
	char str[100];

    printf("==============================================\n");
    printf("|         Pengecekan Kata Palindrom          |\n");
    printf("==============================================\n\n");
    printf("Masukkan kata : ");
    fflush(stdin);
    scanf("%[^\n]", &str);

    cek = validasi(str);
    while(cek == 0){
    	system ("cls");
        printf("Masukkan input dengan benar! \n");
        tentukan_palindrom();
        fflush(stdin);
        scanf("%[^\n]", &str);
        cek = validasi(str);
    }

    printf("\n");
    kata(str);
    lanjut1();
}

int daftar_palindrom(){
    int pilih;
    char buff[255];
    FILE *fptr;

    printf("==============================================\n");
    printf("|             History Daftar Kata            |\n");
    printf("==============================================\n\n");
    printf("History Daftar Kata : \n\n");
    fflush(stdin);

    if ((fptr = fopen("kamuskata.txt","r")) == NULL){
        printf("Error : File tidak ada!");
        exit(1);
    }
    while(fgets(buff, sizeof(buff), fptr)){
        printf("%s", buff);
    }
    lanjut2();
}

void lanjut1(){
	int pilih; 
    printf("\n\n==============================================\n");
    printf("|                  1.Ulangi                  |\n");
    printf("|                  2.Menu                    |\n");
    printf("|                  3.Keluar Program          |\n");
    printf("==============================================\n");
    printf("Masukkan Pilihan : ");
    pilih = validasiPilihan();
    system("cls");

    switch(pilih){
	    case 1:
        tentukan_palindrom();
	    break;
	    case 2:
	    main();
	    break;
	    case 3:
	    keluar();
	    break;
	    default:
	    tentukan_palindrom();
	    break;
    }
}

void lanjut2(){
	int pilih;
	printf("==============================================\n");
    printf("|                 1.Menu                     |\n");
    printf("|                 2.Keluar Program           |\n");
    printf("==============================================\n");
    printf("Masukkan Pilihan : ");
    pilih = validasiPilihan();
    system("cls");

    switch(pilih){
	    case 1:
        main();
	    break;
	    case 2:
        keluar();
	    break;
	    default:
	    daftar_palindrom();
	    lanjut1();
	    break;
    }
}
