#include <iostream>   // library untuk input/output (cin, cout)
using namespace std;  // agar tidak perlu menulis std:: setiap saat

int main() {
    int n;  // variabel untuk menyimpan panjang array

    cout << "=== Selection Sort ===" << endl;
    cout << "Masukkan panjang array: ";
    cin >> n;  // baca panjang array dari user

    int arr[n];  // deklarasi array dengan panjang n

    cout << "Masukkan " << n << " nilai array:" << endl;
    for (int i = 0; i < n; i++) {       // ulangi sebanyak n kali
        cout << "  arr[" << i << "] = ";
        cin >> arr[i];                   // baca nilai ke-i dari user dan simpan ke array
    }

    // --- Output array sebelum diurutkan ---
    cout << "\nArray sebelum diurutkan : [ ";
    for (int i = 0; i < n; i++) {        // iterasi setiap elemen array
        cout << arr[i];                  // cetak nilai elemen ke-i
        if (i < n - 1) cout << ", ";     // cetak koma pemisah, kecuali elemen terakhir
    }
    cout << " ]" << endl;

    // --- Proses Selection Sort ---
    for (int i = 0; i < n - 1; i++) {       // iterasi dari elemen pertama sampai kedua terakhir
        int minIdx = i;                      // asumsikan elemen ke-i adalah nilai minimum sementara

        for (int j = i + 1; j < n; j++) {   // cari nilai minimum di sisa array (i+1 sampai akhir)
            if (arr[j] < arr[minIdx]) {      // jika ditemukan elemen yang lebih kecil
                minIdx = j;                  // perbarui indeks minimum
            }
        }

        if (minIdx != i) {                   // jika minimum bukan di posisi i (perlu ditukar)
            int temp = arr[minIdx];          // simpan nilai minimum ke variabel sementara
            arr[minIdx] = arr[i];            // isi posisi minimum dengan nilai di posisi i
            arr[i] = temp;                   // isi posisi i dengan nilai minimum tadi
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