#include "Perpustakaan.h"

void Perpustakaan::tambahBuku(const Buku& buku) {
    daftarBuku.push_back(buku);
}

void Perpustakaan::hapusBuku(const std::string& idBuku) {
    daftarBuku.erase(std::remove_if(daftarBuku.begin(), daftarBuku.end(),
        [&idBuku](const Buku &b) { return b.idBuku == idBuku; }), daftarBuku.end());
}

std::vector<Buku> Perpustakaan::cariBuku(const std::string& keyword) const {
    std::vector<Buku> hasil;
    for (const auto &b : daftarBuku) {
        if (b.judul.find(keyword) != std::string::npos) {
            hasil.push_back(b);
        }
    }
    return hasil;
}

Buku* Perpustakaan::cariBukuById(const std::string& idBuku) {
    for (auto &b : daftarBuku) {
        if (b.idBuku == idBuku) {
            return &b;
        }
    }
    return nullptr;
}
