// Buku.cpp
#include "Buku.h"

string Buku::getInfo() {
    return "[" + idBuku + "] " + judul + " oleh " + penulis + " (" + to_string(tahunTerbit) + ") - Stok: " + to_string(stok);
}

bool Buku::isTersedia() {
    return stok > 0;
}

void Buku::kurangiStok() {
    if (stok > 0) stok--;
}

void Buku::tambahStok() {
    stok++;
} 
