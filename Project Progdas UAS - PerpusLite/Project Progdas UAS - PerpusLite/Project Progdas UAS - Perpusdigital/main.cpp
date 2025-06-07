#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Perpustakaan.h"
#include "Buku.h"
#include "Peminjam.h"
#include "Peminjaman.h"

using namespace std;

Perpustakaan perpustakaan;

void loadBuku() {
    ifstream file("buku.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, judul, penulis, penerbit;
        int tahun, stok;
        getline(ss, id, '|');
        getline(ss, judul, '|');
        getline(ss, penulis, '|');
        getline(ss, penerbit, '|');
        ss >> tahun;
        ss.ignore();
        ss >> stok;
        Buku b(id, judul, penulis, penerbit, tahun, stok);
        perpustakaan.tambahBuku(b);
    }
}

void simpanBuku() {
    ofstream file("buku.txt");
    for (auto &b : perpustakaan.daftarBuku) {
        file << b.idBuku << "|" << b.judul << "|" << b.penulis << "|" << b.penerbit << "|"
             << b.tahunTerbit << "|" << b.stok << endl;
    }
}

void simpanPeminjaman() {
    ofstream file("peminjaman.txt");
    for (auto &p : perpustakaan.daftarPeminjaman) {
        file << p.getIdBuku() << "|" << p.getIdPeminjam() << "|" << p.getStatus() << endl;
    }
}

void tampilkanMenu() {
    cout << "=== SISTEM PERPUSTAKAAN DIGITAL ===\n";
    cout << "1. Lihat daftar buku\n";
    cout << "2. Cari buku\n";
    cout << "3. Tambah buku\n";
    cout << "4. Rekomendasi buku\n";
    cout << "5. Pinjam buku\n";
    cout << "6. Kembalikan buku\n";
    cout << "7. Edit buku\n";
    cout << "8. Hapus buku\n";
    cout << "0. Keluar\n";
    cout << "Pilih: ";
}

void lihatBuku() {
    for (auto &b : perpustakaan.daftarBuku) {
        cout << b.getInfo() << endl;
    }
}

void cariBuku() {
    cout << "Masukkan kata kunci judul: ";
    string keyword;
    cin.ignore();
    getline(cin, keyword);
    auto hasil = perpustakaan.cariBuku(keyword);
    for (auto &b : hasil) cout << b.getInfo() << endl;
    if (hasil.empty()) cout << "Buku tidak ditemukan.\n";
}

void tambahBuku() {
    string id, judul, penulis, penerbit;
    int tahun, stok;
    cin.ignore();
    cout << "ID Buku: "; getline(cin, id);
    cout << "Judul: "; getline(cin, judul);
    cout << "Penulis: "; getline(cin, penulis);
    cout << "Penerbit: "; getline(cin, penerbit);
    cout << "Tahun Terbit: "; cin >> tahun;
    cout << "Stok: "; cin >> stok;

    Buku b(id, judul, penulis, penerbit, tahun, stok);
    perpustakaan.tambahBuku(b);
    simpanBuku();
    cout << "Buku berhasil ditambahkan!\n";
}

void rekomendasiBuku() {
    cout << "Rekomendasi Buku Hari Ini:\n";
    if (!perpustakaan.daftarBuku.empty()) {
        srand(time(NULL));
        int idx = rand() % perpustakaan.daftarBuku.size();
        cout << perpustakaan.daftarBuku[idx].getInfo() << endl;
    } else {
        cout << "Tidak ada buku di perpustakaan.\n";
    }
}

void pinjamBuku() {
    string idBuku, idPeminjam, nama, alamat, noTelp, nim, jurusan;
    cin.ignore();
    cout << "ID Buku yang dipinjam: "; getline(cin, idBuku);
    cout << "ID Peminjam: "; getline(cin, idPeminjam);
    cout << "Nama: "; getline(cin, nama);
    cout << "Alamat: "; getline(cin, alamat);
    cout << "No Telp: "; getline(cin, noTelp);
    cout << "NIM: "; getline(cin, nim);
    cout << "Jurusan: "; getline(cin, jurusan);

    Peminjam peminjam(idPeminjam, nama, alamat, noTelp, nim, jurusan);
    Peminjaman p(idBuku, idPeminjam);
    peminjam.ajukanPeminjaman(p);
    perpustakaan.daftarPeminjaman.push_back(p);
    simpanPeminjaman();
    cout << "Peminjaman berhasil diproses.\n";
}

void kembalikanBuku() {
    string idBuku, idPeminjam;
    cin.ignore();
    cout << "ID Buku: "; getline(cin, idBuku);
    cout << "ID Peminjam: "; getline(cin, idPeminjam);

    for (auto &p : perpustakaan.daftarPeminjaman) {
        if (p.getIdBuku() == idBuku && p.getIdPeminjam() == idPeminjam && p.getStatus() == "Disetujui") {
            Peminjam dummy("id", "nama", "alamat", "telp", "nim", "jurusan");
            dummy.pengembalianBuku(p);
            cout << "Pengembalian berhasil dicatat.\n";
            simpanPeminjaman();
            return;
        }
    }
    cout << "Data peminjaman tidak ditemukan atau sudah dikembalikan.\n";
}

void editBuku() {
    string id;
    cin.ignore();
    cout << "Masukkan ID Buku yang ingin diedit: ";
    getline(cin, id);
    Buku* b = perpustakaan.cariBukuById(id);
    if (b != nullptr) {
        cout << "Data buku saat ini:\n" << b->getInfo() << endl;
        cout << "Masukkan data baru (kosongkan jika tidak ingin diubah):\n";
        
        string input;
        cout << "Judul baru: ";
        getline(cin, input);
        if (!input.empty()) b->judul = input;

        cout << "Penulis baru: ";
        getline(cin, input);
        if (!input.empty()) b->penulis = input;

        cout << "Penerbit baru: ";
        getline(cin, input);
        if (!input.empty()) b->penerbit = input;

        cout << "Tahun Terbit baru: ";
        getline(cin, input);
        if (!input.empty()) b->tahunTerbit = stoi(input);

        cout << "Stok baru: ";
        getline(cin, input);
        if (!input.empty()) b->stok = stoi(input);

        simpanBuku();
        cout << "Buku berhasil diperbarui.\n";
    } else {
        cout << "Buku tidak ditemukan.\n";
    }
}

void hapusBuku() {
    string id;
    cin.ignore();
    cout << "Masukkan ID Buku yang ingin dihapus: ";
    getline(cin, id);
    Buku* b = perpustakaan.cariBukuById(id);
    if (b != nullptr) {
        perpustakaan.hapusBuku(id);
        simpanBuku();
        cout << "Buku berhasil dihapus.\n";
    } else {
        cout << "Buku tidak ditemukan.\n";
    }
}


int main() {
    loadBuku();
    int pilihan;
    do {
        tampilkanMenu();
        cin >> pilihan;
        switch (pilihan) {
            case 1: lihatBuku(); break;
            case 2: cariBuku(); break;
            case 3: tambahBuku(); break;
            case 4: rekomendasiBuku(); break;
            case 5: pinjamBuku(); break;
            case 6: kembalikanBuku(); break;
            case 7: editBuku(); break;
            case 8: hapusBuku(); break;
            case 0: cout << "Terima kasih.\n"; break;
            default: cout << "Pilihan tidak valid.\n"; break;
        }
        cout << endl;
    } while (pilihan != 0);
    return 0;
}