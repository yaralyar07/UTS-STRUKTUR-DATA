#include <iostream>
using namespace std;

int main() {
    int n;     // n = banyaknya data
    int mode;  // mode = pilihan urutan, 1 untuk ascending dan 2 untuk descending

    cout << "=== Selection Sort ===" << endl;
    cout << "Masukkan panjang array: ";
    cin >> n;

    int arr[n];  // arr = tempat menyimpan semua angka yang akan diurutkan

    // Langkah 1: input semua data ke dalam array
    cout << "Masukkan " << n << " nilai array:" << endl;
    for (int i = 0; i < n; i++) {       // i = nomor indeks array, dimulai dari 0 sampai n-1
        cout << "  arr[" << i << "] = ";
        cin >> arr[i];                   // simpan nilai ke posisi arr[i]
    }

    // Langkah 2: pilih jenis pengurutan
    cout << "\nPilih mode pengurutan:" << endl;
    cout << "  1. Ascending  (kecil ke besar)" << endl;
    cout << "  2. Descending (besar ke kecil)" << endl;
    cout << "Pilihan: ";
    cin >> mode;

    // Langkah 3: tampilkan isi array sebelum diurutkan
    cout << "\nArray sebelum diurutkan : [ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " ]" << endl;

    // Langkah 4: proses selection sort
    // i         = posisi yang sedang diisi
    // targetIdx = indeks nilai terbaik yang ditemukan
    // j         = indeks untuk mengecek sisa data di sebelah kanan
    for (int i = 0; i < n - 1; i++) {
        int targetIdx = i;                   // awalnya anggap arr[i] adalah nilai terbaik

        for (int j = i + 1; j < n; j++) {
            if (mode == 1 && arr[j] < arr[targetIdx]) {  // ascending: cari nilai yang lebih kecil
                targetIdx = j;
            }
            if (mode == 2 && arr[j] > arr[targetIdx]) {  // descending: cari nilai yang lebih besar
                targetIdx = j;
            }
        }

        // Jika nilai terbaik bukan di posisi i, tukar posisinya
        if (targetIdx != i) {
            int temp = arr[targetIdx];          // temp = variabel sementara saat pertukaran
            arr[targetIdx] = arr[i];
            arr[i] = temp;
        }
    }

    // Langkah 5: tampilkan array setelah diurutkan
    cout << "Array setelah selection sort: [ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " ]" << endl;

    return 0;  // program selesai
}
