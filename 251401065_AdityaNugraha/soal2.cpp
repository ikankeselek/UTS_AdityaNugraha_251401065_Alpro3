#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    string KP, jenis, jenisout, waktu, waktukeluar, lokasi;
    cout << "Masukkan kode parkir digital (10 digit): ";
    cin >> KP;
    cout << "Masukkan jam keluar (format HHMM): ";
    cin >> waktukeluar;

    jenis = KP.substr(0, 2);
    waktu = KP.substr(2, 4);
    lokasi = KP.substr(6, 4);

    int jam = stoi(waktu.substr(0, 2));
    int menit = stoi(waktu.substr(2, 2));
    int jamKeluar = stoi(waktukeluar.substr(0, 2));
    int menitKeluar = stoi(waktukeluar.substr(2, 2));

    cout << "\n--- Ringkasan Parkir ---" << endl;

    if (jenis == "10")
        jenisout = "Mobil";
    else if (jenis == "20")
        jenisout = "Motor";
    else if (jenis == "30")
        jenisout = "Bus";
    else
        jenisout = "Tidak Dikenal";

    cout << "Jenis kendaraan: " << jenisout << endl;
    cout << "Waktu masuk: " << jam << ":" << (menit < 10 ? "0" : "") << menit << endl;
    cout << "Waktu keluar: " << jamKeluar << ":" << (menitKeluar < 10 ? "0" : "") << menitKeluar << endl;

    int lamamenit = (jamKeluar * 60 + menitKeluar) - (jam * 60 + menit);
    if (lamamenit < 0)
        lamamenit += 1440;

    int lamajam = (lamamenit + 59) / 60;

    cout << "lama parkir: " << lamajam << " jam" << endl;
    cout << "Lokasi parkir: " << lokasi << endl;

    int biaya = 0;
    if (lamajam <= 1) {
        if (jenis == "10") biaya = 5000;
        else if (jenis == "20") biaya = 3000;
        else if (jenis == "30") biaya = 10000;
    } else {
        if (jenis == "10") biaya = 5000 + (lamajam - 1) * 3000;
        else if (jenis == "20") biaya = 3000 + (lamajam - 1) * 2000;
        else if (jenis == "30") biaya = 10000 + (lamajam - 1) * 7000;
    }

    cout << "Total biaya: Rp " << biaya << endl;

    return 0;
}

//sama seperti di kode soal pertama, kodenya jalan dan tidak ada error dan juga pas dengan test case yang diberikan saat di run di online compiler
//sepertinya memang ada kesalahan pada compiler yang saya gunakan di vscode saya

//saya menjadikan kode parkirnya menjadi string agar lebih mudah dipisah pisah menggunakan substr
//untuk mengubah KP menjadi integer, saya menggunakan stoi yang mengubah string ke integer
//untuk menampilkan waktu masuk dan keluar, awalnya saya ingin menggunakan if else, tetapi terlalu panjang, jaddi saya gunakan operator ternary
//untuk menghitung durasi, saya ubah jam masuk dan keluar jadi menit, lalu durasi = keluar - masuk
//untuk mengatasi hasil negatif, saya menambahkan logika : kalau durasi < 0 maka ditambah 1440 (24 jam), jadi nilainya tetap tapi gk negatif
//agar bisa sama dengan test case b, durasi saya bulatkan ke atas
