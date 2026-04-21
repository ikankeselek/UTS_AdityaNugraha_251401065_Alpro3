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
        jenisout = "salah masuk tu";

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

/*
Algoritma

1. Program meinta input kode parkir digital 10 digit dan jam keluar kendaraan dengan format HHMM
2. Program memisahkan kode parkir menjadi 3 bagian:
   - 2 digit pertama untuk jenis kendaraan
   - 4 digit berikutnya untuk waktu masuk
   - 4 digit terakhir untuk lokasi parkir

3. Program mengambil jam dan menit dari waktu masuk serta jam dan menit dari waktu keluar
4. Program menentukan jenis kendaraan berdasarkan 2 digit pertama:
   - 10 = Mobil
   - 20 = Motor
   - 30 = Bus
   - Selain itu = salah masuk tu

5. Program menampilkan jenis kendaraan, waktu masuk, waktu keluar, dan lokasi parkir
6. Program menghitung lama parkir dalam menit dengan rumus:
   lama parkir = waktu keluar - waktu masuk

7. Jika hasil lama parkir negatif, berarti kendaraan keluar pada hari berikutnya,
   sehingga ditambahkan 1440 menit (24 jam) biar gk negatip

8. Program mengubah lama parkir dari menit ke jam dan dibulatkan ke atas
   menggunakan rumus:
   (lamamenit + 59) / 60

9. Program menghitung biaya parkir berdasarkan jenis kendaraan:
   - Mobil: Rp 5000 untuk jam pertama, Rp 3000 untuk setiap jam berikutnya
   - Motor: Rp 3000 untuk jam pertama, Rp 2000 untuk setiap jam berikutnya
   - Bus: Rp 10000 untuk jam pertama, Rp 7000 untuk setiap jam berikutnya

10. Program mengoutputkan hasil
*/

//sama seperti di kode soal pertama, kodenya jalan dan tidak ada error dan juga pas dengan test case yang diberikan saat di run di online compiler
//sepertinya memang ada kesalahan pada compiler yang saya gunakan di vscode saya

//saya menjadikan kode parkirnya menjadi string agar lebih mudah dipisah pisah menggunakan substr
//untuk mengubah KP menjadi integer, saya menggunakan stoi yang mengubah string ke integer
//untuk menampilkan waktu masuk dan keluar, awalnya saya ingin menggunakan if else, tetapi terlalu panjang, jaddi saya gunakan operator ternary
//untuk menghitung durasi, saya ubah jam masuk dan keluar jadi menit, lalu durasi = keluar - masuk
//untuk mengatasi hasil negatif, saya menambahkan logika : kalau durasi < 0 maka ditambah 1440 (24 jam), jadi nilainya tetap tapi gk negatif
//agar bisa sama dengan test case b, durasi saya bulatkan ke atas
