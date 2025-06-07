// Perpustakaan.h
#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "Buku.h"
#include "Peminjaman.h"

class Perpustakaan {
public:
    std::vector<Peminjaman> daftarPeminjaman;
    std::vector<Buku> daftarBuku;

    void tambahBuku(const Buku& b);
    void hapusBuku(const std::string& idBuku);
    std::vector<Buku> cariBuku(const std::string& keyword) const;

    // Fungsi tambahan untuk cari buku by ID (untuk update stok dll)
    Buku* cariBukuById(const std::string& idBuku);
};
