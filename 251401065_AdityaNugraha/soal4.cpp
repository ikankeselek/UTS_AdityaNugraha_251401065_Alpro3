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


