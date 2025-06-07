#include "Peminjam.h"
#include <iostream>
using namespace std;

string Peminjam::getNIM() {
    return nim;
}

void Peminjam::setNIM(string nim) {
    this->nim = nim;
}

string Peminjam::getJurusan() {
    return jurusan;
}

void Peminjam::setJurusan(string jurusan) {
    this->jurusan = jurusan;
}

void Peminjam::ajukanPeminjaman(Peminjaman &p) {
    p.setStatus("Disetujui");
    cout << "Peminjaman telah berhasil.\n";
}

void Peminjam::pengembalianBuku(Peminjaman &p) {
    p.setStatus("Dikembalikan");
    cout << "Pengembalian telah dicatat.\n";
}
