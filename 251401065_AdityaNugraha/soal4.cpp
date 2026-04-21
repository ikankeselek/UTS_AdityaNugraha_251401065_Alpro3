#include <iostream>
#include <string>
using namespace std;

int main() {
    system("cls");
    int n, A=0, B=0, wsa=0, wsb=0;
    string s;
    cout << "Masukkan jumlah pertandingan: ";
    cin >> n;
    cout << "Masukkan hasil pertandingan (A/B/C): ";
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            A += 3;
            wsa++;
            wsb = 0;
            if (wsa % 3 == 0)
                A += 2;
        } 

        else if (s[i] == 'B') {
            B += 3;
            wsb++;
            wsa = 0;
            if (wsb % 3 == 0)
                B += 2;
        } 

        else { 
            A += 1;
            B += 1;
        }
    }
    cout << "Poin A: " << A << endl;
    cout << "Poin B: " << B << endl;

    cout << (A > B ? "Pemenangnya adalah pemain A" : A < B ? "Pemenangnya adalah pemain B" : "Hasil Pertandingan Seri") << endl;

}

/*
ALGORITMA PROGRAM PERTANDINGAN PEMAIN A DAN B:

1. Program meminta input jumlah babak (n) dan string hasil pertandingan (s).
2. Program menginisialisasi variabel:
   - poin A = 0
   - poin B = 0
   - streak kemenangan A (wsa) = 0
   - streak kemenangan B (wsb) = 0
3. Program melakukan perulangan untuk setiap babak dari i = 0 sampai n-1.
4. Pada setiap babak, program mengecek hasil pertandingan:
   a. Jika 'A' (Pemain A menang):
      - Tambah 3 poin ke A
      - Tambah streak kemenangan A (wsa++)
      - Reset streak B (wsb = 0)
      - Jika wsa kelipatan 3:
        → Tambahkan bonus 2 poin ke A

   b. Jika 'B' (Pemain B menang):
      - Tambah 3 poin ke B
      - Tambah streak kemenangan B (wsb++)
      - Reset streak A (wsa = 0)
      - Jika wsb kelipatan 3:
        → Tambahkan bonus 2 poin ke B

   c. Jika 'C' (Seri):
      - Tambahkan 1 poin ke A
      - Tambahkan 1 poin ke B

5. Setelah semua babak selesai, program menampilkan:
   - Total poin pemain A
   - Total poin pemain B

6. Program menentukan pemenang:
   - Jika poin A > poin B → Pemain A menang
   - Jika poin B > poin A → Pemain B menang
   - Jika sama → Hasil pertandingan seri

7. Program mengoutputkan hasil 

        

*/

//pada codingan ini, syaa menggunakan for loop for (int i = 0; i < n; i++) if (s[i] == 'A') untuk mengakses karakter di string s 
//saya menggunakan nested if untuk menghitung poinnya, jika A dpat poin, B di reset streaknya

