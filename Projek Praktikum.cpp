#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;
FILE *input;
FILE *output;
FILE *searching;
FILE *input_penumpang;
FILE *output_penumpang;
FILE *read;
#define JUM_BLOK 1
typedef struct{
	char tanggal[3];
	char bulan[20];
	char tahun[6];
	char jam_keberangkatan[6];
	char jam_kedatangan[6];
}data1;
typedef struct{
	int harga;
	char nama[20];
	int ID;
	char tujuan[20];
	char asal[20];
	char tempat_duduk[4];
	string kelas;
	char nama_kereta[20];
	data1 waktu;
}data;
typedef struct{
	int harga;
	char nama[20];
	int ID;
	char tujuan[20];
	char asal[20];
	char tempat_duduk[4];
	string kelas;
	char nama_kereta[20];
	data1 waktu;
}data2;

typedef struct{
	int harga_tiket;
	char nama_tiket[20];
	int ID_tiket;
	char tujuan_tiket[20];
	char asal_tiket[20];
	char tempat_duduk_tiket[4];
	string kelas_tiket;
	string nama_kereta_tiket;
	data1 waktu_tiket;
}tiket1;

int main (){
int menu;
int banyak_tiket;
data tiket;
tiket1 penumpang;
bool found;
found = false;
char keberangkatan[20];
char kedatangan[20];
char pesan_nama[20];
int banyak_penumpang;
char hapus;
data2 sort[100];
int i;


	cout << "1.Input Database Tiket" << endl;
	cout << "2.Lihat Database Tiket" << endl;
	cout << "3.Pemesanan Tiket" << endl;
	cout << "Menu	: ";cin >> menu; cin.ignore();

	switch(menu){
		case 1 :
		input=fopen("Database.txt","a");
		cout << "Banyaknya tiket yang ingin di input	: ";cin >> banyak_tiket;
		for(int p=0;p<banyak_tiket;p++){
			cout << "Nama kereta		: ";cin>>tiket.nama_kereta;
			cout << "Kelas			: ";cin >> tiket.kelas;
			cout << "Asal			: ";cin>>tiket.asal;
			cout << "Tujuan			: ";cin>>tiket.tujuan;
			cout << "Harga			: ";cin>>tiket.harga;
			cout << "Jam keberangkatan	: ";cin>>tiket.waktu.jam_keberangkatan;
			cout << "Jam kedatangan		: ";cin>>tiket.waktu.jam_kedatangan;
			cout << endl;
			fwrite(&tiket,sizeof(tiket),1,input);
		}
		fclose(input);
		break;

		case 2 :
		cout << "===============TIKET YANG TERSEDIA===============" << endl;
		output=fopen("Database.txt","rb");
		while(fread(&tiket,sizeof(tiket),JUM_BLOK,output)==JUM_BLOK){
			cout << "Nama kereta		: " << tiket.nama_kereta << endl;
			cout << "Kelas			: " << tiket.kelas << endl;
			cout << "Asal			: " << tiket.asal << endl;
			cout << "Tujuan			: " << tiket.tujuan << endl;
			cout << "Harga			: " << tiket.harga << endl;
			cout << "Jam keberangkatan	: " << tiket.waktu.jam_keberangkatan << endl;
			cout << "Jam kedatangan		: " << tiket.waktu.jam_kedatangan << endl;
			cout << "=================================================" << endl;
		}
		fclose(output);
		break;

		case 3 :
		cout << "1.Pesan Tiket" << endl;
		cout << "2.Lihat Tiket yang Dipesan" << endl;
		cout << "3.Cancel Tiket" << endl;
		cout << "Menu	: ";cin >> menu;
		
		switch(menu){
			case 1 :
			system("cls");
			cout << "===============PEMESANAN TIKET!===============" << endl;
			cout << "Keberangkatan	: ";cin >> keberangkatan;
			cout << "Kedatangan	: ";cin >> kedatangan;
			cout << "	Tanggal	: ";cin >> tiket.waktu.tanggal;
			cout << "	Bulan	: ";cin >> tiket.waktu.bulan;
			cout << "	Tahun	: ";cin >> tiket.waktu.tahun;
			searching = fopen("Database.txt","rb");
			i = 0;
			while (fread(&tiket,sizeof(tiket),1,searching)){
				strcpy(sort[i].nama_kereta,tiket.nama_kereta);
				sort[i].kelas=tiket.kelas;
				strcpy(sort[i].asal,tiket.asal);
				strcpy(sort[i].tujuan,tiket.tujuan);
				sort[i].harga=tiket.harga;
				strcpy(sort[i].waktu.jam_keberangkatan,tiket.waktu.jam_keberangkatan);
				strcpy(sort[i].waktu.jam_kedatangan,tiket.waktu.jam_kedatangan);
				i++;
			}
			fclose(searching);
			int temp,j,k;
				for(j = 0;j<i-1;j++)
				{
					for(k = 0;k<i-1-j;k++)
					{
						if(sort[k].harga > sort[k+1].harga)
						{
							temp = sort[k].harga;
							sort[k].harga = sort[k+1].harga;
							sort[k+1].harga = temp;
							swap(sort[k].nama_kereta , sort[k+1].nama_kereta);
							swap(sort[k].kelas , sort[k+1].kelas);
							swap(sort[k].asal , sort[k+1].asal);
							swap(sort[k].tujuan,sort[k+1].tujuan);
							swap(sort[k].waktu.jam_keberangkatan , sort[k+1].waktu.jam_keberangkatan);
							swap(sort[k].waktu.jam_kedatangan , sort[k+1].waktu.jam_kedatangan);
						}
					}
				}
					for(j=0;j<10;j++){
						if( (strcmp(keberangkatan,sort[j].asal)==0)&&(strcmp(kedatangan,sort[j].tujuan)==0) ){
							cout << "Nama kereta		: " << sort[j].nama_kereta << endl;
							cout << "Kelas			: " << sort[j].kelas << endl;
							cout << "Asal			: " << sort[j].asal << endl;
							cout << "Tujuan			: " << sort[j].tujuan << endl;
							cout << "Harga			: " << sort[j].harga << endl;
							cout << "Jam keberangkatan	: " << sort[j].waktu.jam_keberangkatan << endl;
							cout << "Jam kedatangan		: " << sort[j].waktu.jam_kedatangan << endl;
							cout << "------------------------------" << endl;
							cout << endl;
							found = true ;
						}
					}
			if (found){
	 			input_penumpang=fopen("Tiket.txt","a");
	 			searching = fopen("Database.txt","rb");
	 			cout << "Masukkan nama kereta yang ingin di pesan : ";cin >> pesan_nama;
	 			while (fread(&tiket,sizeof(tiket),1,searching)){
	 			if(strcmp(pesan_nama,tiket.nama_kereta)==0){
					cout << "Masukkan banyaknya penumpang	: ";cin >> banyak_penumpang; cin.ignore();
	 				for( i=0;i<banyak_penumpang;i++){ 
	 					cout << "Masukkan nama anda		: ";cin.getline(penumpang.nama_tiket,sizeof(penumpang.nama_tiket));
						cout << "Masukkan nomor identitas anda	: ";cin >> penumpang.ID_tiket;
	 					penumpang.nama_kereta_tiket = tiket.nama_kereta;
	 					penumpang.kelas_tiket = tiket.kelas;
	 					strcpy(penumpang.asal_tiket,tiket.asal);
	 					strcpy(penumpang.tujuan_tiket,tiket.tujuan);
	 					penumpang.harga_tiket = tiket.harga;
	 					strcpy(penumpang.waktu_tiket.jam_keberangkatan,tiket.waktu.jam_keberangkatan);
	 					strcpy(penumpang.waktu_tiket.jam_kedatangan,tiket.waktu.jam_kedatangan);
	 					fwrite(&penumpang,sizeof(penumpang),1,input_penumpang);
	 				}
	 			}
	 			}
	 			fclose(searching);
	 			fclose (input_penumpang);
			}
	 		else {
				cout<<"Tiket yang dicari tidak ada";
	 		}
	 		break;

	 		case 2 :
	 		cout << "===============TIKET ANDA===============" << endl;
	 		output_penumpang=fopen("Tiket.txt","rb");
			while(fread(&penumpang,sizeof(penumpang),1,output_penumpang)==1){
				if(penumpang.harga_tiket==0){
					cout << "Anda belum memesan tiket" << endl;
					break;
				}
				cout << "Nama Pemesan		: " << penumpang.nama_tiket << endl;
				cout << "Nomor Identitas		: " << penumpang.ID_tiket << endl;
				cout << "Nama kereta		: " << penumpang.nama_kereta_tiket << endl;
				cout << "Kelas			: " << penumpang.kelas_tiket << endl;
				cout << "Asal			: " << penumpang.asal_tiket << endl;
				cout << "Tujuan			: " << penumpang.tujuan_tiket << endl;
				cout << "Harga			: " << penumpang.harga_tiket << endl;
				cout << "Jam keberangkatan	: " << penumpang.waktu_tiket.jam_keberangkatan << endl;
				cout << "Jam kedatangan		: " << penumpang.waktu_tiket.jam_kedatangan << endl;
				cout << "========================================" << endl;
			}
			fclose(output_penumpang);
			break;

			case 3 :
			cout << "Apakah anda yaking ingin membatalkan pesanan tiket anda?" << endl << "Semua tiket anda akan terhapus (Y/N)" << endl;
			cin >> hapus;
			if(hapus=='y'||hapus=='Y'){
			remove("Tiket.txt");
			}


		}
	}
}
/* Pembatalan Tiket
Tempat Duduk
Sorting Tiket
*/