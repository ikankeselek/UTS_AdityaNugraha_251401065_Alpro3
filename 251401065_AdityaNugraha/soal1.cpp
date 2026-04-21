#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    string NK, awalan, jenisKartu;
    int panjang, total = 0;
    system("cls")
    cout << "Masukkan nomor kartu digital: ";
    cin >> NK;

    panjang = NK.length();
    awalan = NK.substr(0, 2);

    if (panjang == 14 && awalan == "65"){
        jenisKartu = "NUSANTARA";
        cout << "Tipe kartu: " << jenisKartu << endl;
      
            if (jenisKartu != "TIDAK DIKENAL") {
                for (int i = panjang - 1; i >= 0; i -= 2)
                    total += NK[i] - '0';
                for (int i = panjang - 2; i >= 0; i -= 2) {
                    int angka = (NK[i] - '0') * 2;
                    if (angka > 9)
                        angka = (angka / 10) + (angka % 10);
                    total += angka;
                }

                if (total % 10 == 0)
                    cout << "Nomor kartu VALID." << endl;
                else
                    cout << "Nomor kartu TIDAK VALID." << endl;
            }
}


    else if (panjang == 16 && (awalan == "77" || awalan == "78")){
        jenisKartu = "GARUDA";
        cout << "Tipe kartu: " << jenisKartu << endl;
      
            if (jenisKartu != "TIDAK DIKENAL") {
                for (int i = panjang - 1; i >= 0; i -= 2)
                    total += NK[i] - '0';
                for (int i = panjang - 2; i >= 0; i -= 2) {
                    int angka = (NK[i] - '0') * 2;
                    if (angka > 9)
                        angka = (angka / 10) + (angka % 10);
                    total += angka;
                }

                if (total % 10 == 0)
                    cout << "Nomor kartu VALID." << endl;
                else
                    cout << "Nomor kartu TIDAK VALID." << endl;
            }
}


    else if (panjang == 15 && awalan == "91"){
        jenisKartu = "MERDEKA";
        cout << "Tipe kartu: " << jenisKartu << endl;
      
            if (jenisKartu != "TIDAK DIKENAL") {
                for (int i = panjang - 1; i >= 0; i -= 2)
                    total += NK[i] - '0';
                for (int i = panjang - 2; i >= 0; i -= 2) {
                    int angka = (NK[i] - '0') * 2;
                    if (angka > 9)
                        angka = (angka / 10) + (angka % 10);
                    total += angka;
                }

                if (total % 10 == 0)
                    cout << "Nomor kartu VALID." << endl;
                else
                    cout << "Nomor kartu TIDAK VALID." << endl;
            }
}


    else{jenisKartu = "TIDAK DIKENAL";
        cout << "Tipe kartu: " << jenisKartu << endl;
        cout << "Nomor kartu TIDAK VALID." << endl;      
    }

}

//Code ini saya tes di vscode saya, hasiln pada test case c dan d error, tetapi pada saat saya test di online compiler, codenya berjalan tanpa masalah.
//Mungkin ada kesalahan dengan compiler yang saya install, jika pada saat mengetes code saya error, boleh di tes menggunakan online compiler

//diawal saya menggunakan system("cls") untuk membersihkan layar output
//untuk bagian algoritma luhn, saya taruh pada setiap percabangan if atau else if yang awal
//fungsinya sebenarnya untuk readability, pada awalnya, saya memisahkan algoritmanya, tetapi malah ngebuat saya bingung
//saya menggunakan for loop for (int i = panjang - 1; i >= 0; i -= 2) 
// total += NK[i] - '0'; ini berfungsi untuk mengambil data pada index ke- i. angka tersebut dikurang 0 karena angka yg disimpan menjadi kode ASCII, di kurang 0 untuk mengembalikannya ke angka asli
