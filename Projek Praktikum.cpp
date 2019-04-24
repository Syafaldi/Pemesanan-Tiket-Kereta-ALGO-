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
	int banyak_penumpang;
	char nama_kereta[20];
	data1 waktu;
}data;

typedef struct{
	int harga_tiket;
	char nama_tiket[20];
	int ID_tiket;
	char tujuan_tiket[20];
	char asal_tiket[20];
	char tempat_duduk_tiket[4];
	string kelas_tiket;
	int banyak_penumpang_tiket;
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


	cout << "1.Input Database Tiket" << endl;
	cout << "2.Lihat Database Tiket" << endl;
	cout << "3.Pemesanan Tiket" << endl;
	cout << "Menu	: ";cin >> menu;

	switch(menu){
		case 1 :
		input=fopen("Database.txt","a");
		cout << "Banyaknya tiket yang ingin di input	: ";cin >> banyak_tiket;
		for(int i=0;i<banyak_tiket;i++){
			cout << "Nama kereta		: ";cin>>tiket.nama_kereta;
			cout << "Kelas		: ";cin >> tiket.kelas;
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
		output=fopen("Database.txt","r");
		while(fread(&tiket,sizeof(tiket),1,output)==1){
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
			cout << "Keberangkatan	: ";cin >> keberangkatan;
			cout << "Kedatangan	: ";cin >> kedatangan;
			cout << "	Tanggal	: ";cin >> tiket.waktu.tanggal;
			cout << "	Bulan	: ";cin >> tiket.waktu.bulan;
			cout << "	Tahun	: ";cin >> tiket.waktu.tahun;
			searching = fopen("Database.txt","r");
			while (fread(&tiket,sizeof(tiket),1,searching)){
				if( (strcmp(keberangkatan,tiket.asal)==0)&&(strcmp(kedatangan,tiket.tujuan)==0) ){
					found = true ;
					break;
				}
			}
			if (found){
				cout << "===============TIKET DITEMUKAN!===============" << endl;
				cout << "Nama kereta		: " << tiket.nama_kereta << endl;
				cout << "Kelas			: " << tiket.kelas << endl;
				cout << "Asal			: " << tiket.asal << endl;
				cout << "Tujuan			: " << tiket.tujuan << endl;
				cout << "Harga			: " << tiket.harga << endl;
				cout << "Jam keberangkatan	: " << tiket.waktu.jam_keberangkatan << endl;
				cout << "Jam kedatangan		: " << tiket.waktu.jam_kedatangan << endl;
				cout << endl;
				cout << "Masukkan nama kereta yang ingin di pesan : ";cin >> pesan_nama;
	 			input_penumpang=fopen("Tiket.txt","a");
	 			if(strcmp(pesan_nama,tiket.nama_kereta)==0){
	 				cout << "Masukkan nama anda	: ";cin >> penumpang.nama_tiket;
					cout << "Masukkan nomor identitas anda	: ";cin >> penumpang.ID_tiket;
	 				penumpang.nama_kereta_tiket			= tiket.nama_kereta;
	 				penumpang.kelas_tiket				= tiket.kelas;
	 				strcpy(penumpang.asal_tiket,tiket.asal);
	 				strcpy(penumpang.tujuan_tiket,tiket.tujuan);
	 				penumpang.harga_tiket				= tiket.harga;
	 				strcpy(penumpang.waktu_tiket.jam_keberangkatan,tiket.waktu.jam_keberangkatan);
	 				strcpy(penumpang.waktu_tiket.jam_kedatangan,tiket.waktu.jam_kedatangan);
	 				fwrite(&penumpang,sizeof(penumpang),1,input_penumpang);

	 			}
	 			fclose (input_penumpang);
			}
	 		else {
				cout<<"Tiket yang dicari tidak ada";
	 		}
	 		
	 		break;

	 		case 2 :
	 		cout << "===============TIKET ANDA===============" << endl;
	 		output_penumpang=fopen("Tiket.txt","r");
			while(fread(&penumpang,sizeof(penumpang),1,output_penumpang)==1){
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


		}
	}
}
/* Pembatalan Tiket
Tempat Duduk
Sorting Tiket
*/