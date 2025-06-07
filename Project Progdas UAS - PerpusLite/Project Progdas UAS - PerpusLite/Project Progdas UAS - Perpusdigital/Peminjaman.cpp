// Peminjaman.cpp
#include "Peminjaman.h"

Peminjaman::Peminjaman(string idBuku, string idPeminjam)
    : idBuku(idBuku), idPeminjam(idPeminjam), status("Menunggu") {}

string Peminjaman::getIdBuku() {
    return idBuku;
}

string Peminjaman::getIdPeminjam() {
    return idPeminjam;
}

string Peminjaman::getStatus() {
    return status;
}

void Peminjaman::setStatus(string status) {
    this->status = status;
}
