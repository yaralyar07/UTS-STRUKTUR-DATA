#include <iostream>   // library untuk input/output (cin, cout)
using namespace std;  // agar tidak perlu menulis std:: setiap saat

int main() {
    int n;     // variabel untuk menyimpan panjang array
    int mode;  // variabel untuk menyimpan pilihan mode (1=ascending, 2=descending)

    cout << "=== Selection Sort ===" << endl;
    cout << "Masukkan panjang array: ";
    cin >> n;  // baca panjang array dari user

    int arr[n];  // deklarasi array dengan panjang n

    cout << "Masukkan " << n << " nilai array:" << endl;
    for (int i = 0; i < n; i++) {       // ulangi sebanyak n kali
        cout << "  arr[" << i << "] = ";
        cin >> arr[i];                   // baca nilai ke-i dari user dan simpan ke array
    }

    // --- Pilihan mode pengurutan ---
    cout << "\nPilih mode pengurutan:" << endl;
    cout << "  1. Ascending  (kecil ke besar)" << endl;
    cout << "  2. Descending (besar ke kecil)" << endl;
    cout << "Pilihan: ";
    cin >> mode;  // baca pilihan mode dari user

    // --- Output array sebelum diurutkan ---
    cout << "\nArray sebelum diurutkan : [ ";
    for (int i = 0; i < n; i++) {        // iterasi setiap elemen array
        cout << arr[i];                  // cetak nilai elemen ke-i
        if (i < n - 1) cout << ", ";     // cetak koma pemisah, kecuali elemen terakhir
    }
    cout << " ]" << endl;

    // --- Proses Selection Sort ---
    for (int i = 0; i < n - 1; i++) {       // iterasi dari elemen pertama sampai kedua terakhir
        int targetIdx = i;                   // asumsikan elemen ke-i adalah nilai target sementara

        for (int j = i + 1; j < n; j++) {   // cari nilai target di sisa array (i+1 sampai akhir)
            if (mode == 1 && arr[j] < arr[targetIdx]) {  // mode ascending: cari nilai terkecil
                targetIdx = j;                            // perbarui indeks target jika lebih kecil
            }
            if (mode == 2 && arr[j] > arr[targetIdx]) {  // mode descending: cari nilai terbesar
                targetIdx = j;                            // perbarui indeks target jika lebih besar
            }
        }

        if (targetIdx != i) {                   // jika target bukan di posisi i (perlu ditukar)
            int temp = arr[targetIdx];          // simpan nilai target ke variabel sementara
            arr[targetIdx] = arr[i];            // isi posisi target dengan nilai di posisi i
            arr[i] = temp;                      // isi posisi i dengan nilai target tadi
        }
    }

    // --- Output array setelah diurutkan ---
    cout << "Array setelah selection sort: [ ";
    for (int i = 0; i < n; i++) {        // iterasi setiap elemen array yang sudah terurut
        cout << arr[i];                  // cetak nilai elemen ke-i
        if (i < n - 1) cout << ", ";     // cetak koma pemisah, kecuali elemen terakhir
    }
    cout << " ]" << endl;

    return 0;  // program selesai dengan sukses
}