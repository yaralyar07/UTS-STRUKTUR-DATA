#include <iostream>
using namespace std;

int main() {
    int n;     // jumlah data yang akan dimasukkan ke dalam array
    int mode;  // pilihan urutan: 1 = ascending, 2 = descending

    cout << "=== Selection Sort ===" << endl;
    cout << "Masukkan panjang array: ";
    cin >> n;  // input banyak elemen array

    int arr[n];  // arr adalah array untuk menyimpan semua angka yang akan diurutkan

    cout << "Masukkan " << n << " nilai array:" << endl;
    for (int i = 0; i < n; i++) {       // i adalah indeks array: 0, 1, 2, ... sampai n-1
        cout << "  arr[" << i << "] = ";
        cin >> arr[i];                   // simpan input user ke arr pada indeks ke-i
    }

    // --- Pilihan mode pengurutan ---
    cout << "\nPilih mode pengurutan:" << endl;
    cout << "  1. Ascending  (kecil ke besar)" << endl;
    cout << "  2. Descending (besar ke kecil)" << endl;
    cout << "Pilihan: ";
    cin >> mode;  // simpan pilihan user ke variabel mode

    // --- Output array sebelum diurutkan ---
    cout << "\nArray sebelum diurutkan : [ ";
    for (int i = 0; i < n; i++) {        // i dipakai untuk membaca isi array dari awal sampai akhir
        cout << arr[i];                  // tampilkan nilai array pada indeks ke-i
        if (i < n - 1) cout << ", ";     // tampilkan koma jika belum elemen terakhir
    }
    cout << " ]" << endl;

    // --- Proses Selection Sort ---
    for (int i = 0; i < n - 1; i++) {       // i menunjukkan posisi yang sedang akan diisi nilai yang benar
        int targetIdx = i;                   // targetIdx menyimpan indeks nilai terbaik saat pencarian
                                              // jika ascending: indeks nilai terkecil
                                              // jika descending: indeks nilai terbesar

        for (int j = i + 1; j < n; j++) {   // j dipakai untuk mengecek sisa elemen setelah posisi i
            if (mode == 1 && arr[j] < arr[targetIdx]) {  // bandingkan jika mode ascending
                targetIdx = j;                            // kalau arr[j] lebih kecil, simpan indeks j sebagai target baru
            }
            if (mode == 2 && arr[j] > arr[targetIdx]) {  // bandingkan jika mode descending
                targetIdx = j;                            // kalau arr[j] lebih besar, simpan indeks j sebagai target baru
            }
        }

        if (targetIdx != i) {                   // kalau targetIdx berbeda dari i, berarti datanya perlu ditukar
            int temp = arr[targetIdx];          // temp adalah tempat sementara untuk menyimpan nilai target
            arr[targetIdx] = arr[i];            // pindahkan nilai di posisi i ke posisi targetIdx
            arr[i] = temp;                      // pindahkan nilai yang tadi disimpan di temp ke posisi i
        }
    }

    // --- Output array setelah diurutkan ---
    cout << "Array setelah selection sort: [ ";
    for (int i = 0; i < n; i++) {        // i dipakai lagi untuk menampilkan hasil akhir array
        cout << arr[i];                  // tampilkan isi arr pada indeks ke-i
        if (i < n - 1) cout << ", ";     // tampilkan koma jika belum indeks terakhir
    }
    cout << " ]" << endl;

    return 0;  // program selesai
}
