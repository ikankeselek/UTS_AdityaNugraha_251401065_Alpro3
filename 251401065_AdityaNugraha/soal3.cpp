#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    string KT, hari, member;
    int poin = 0;
    system("cls");
    cout << "Masukkan kode Transaksi (8 digit): ";
    cin >> KT;

    hari = KT.substr(0, 2);
    member = KT.substr(2, 2);
    int belanja = stoi(KT.substr(4, 4));

    cout << "Jenis Hari : " << (hari == "01" ? "Hari Kerja" :
                                hari == "02" ? "Akhir Pekan" :
                                hari == "03" ? "Hari Libur Nasional" : "salah masuk tu") << endl;
    cout << "Jenis Member : "<< (member == "01" ? "Pelanggan Biasa" :
                                member == "02" ? "Member Silver" :
                                member == "03" ? "Member Gold" : "salah masuk tu") << endl;

    long belanjaout = belanja * 100000;
    cout << "Total Belanja : Rp " << belanjaout << endl;
    
    if (hari == "01"){

        if (member == "01"){
            poin = (belanjaout / 100000);
            cout <<"Total poin : " << poin << endl;
        }

        else if (member == "02"){
            poin = (belanjaout / 100000) * 2;
            cout <<"Total poin : " << poin << endl;
        }

        else{
            poin = (belanjaout / 100000) * 3;
            cout <<"Total poin : " << poin << endl;
        }

    }

    else if (hari == "02"){

        if (member == "01"){
            poin = (belanjaout / 100000) * 2;
            cout <<"Total poin : " << poin << endl;
        }

        else if (member == "02"){
            poin = (belanjaout / 100000) * 3;
            cout <<"Total poin : " << poin << endl;
        }

        else{
            poin = (belanjaout / 100000) * 5;
            cout <<"Total poin : " << poin << endl;
        }

    }

    else{

        if (member == "01"){
            poin = (belanjaout / 100000) * 3;
            cout <<"Total poin : " << poin << endl;
        }

        else if (member == "02"){
            poin = (belanjaout / 100000) * 5;
            cout <<"Total poin : " << poin << endl;
        }

        else{
            poin = (belanjaout / 100000) * 7;
            cout <<"Total poin : " << poin << endl;
        }

    }

}

//untuk kode ini lancar jaya di vscode maupun online compiler

//ini mirip sekali dengan soal sebelumnya, tetapi lebih mudah pada bagian logika itung itungannya
//saya pakai substr untuk membagi bagi kode transaksinya
//khusus untuk variabel belanja, saya buat integer karena nanti akan dipakai untuk hitung total belanja.
//untuk mengubahnya saya pakai stoi
//disini saya banyak memakai ternary pada bagian jenis hari dan member karena lebih simpel dan pendek
//variabel belanjaout saya buat jadi long, alasan saya adalah karena digitnya yg banyak
//alasan saya yg lain adalah karena long tidak menyimpan data angka menjadi notasi ilmiah
//saya menggunakan nested if pada bagian poinnya

