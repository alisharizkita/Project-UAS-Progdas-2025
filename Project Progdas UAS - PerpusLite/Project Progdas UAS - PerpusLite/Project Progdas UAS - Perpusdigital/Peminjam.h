#pragma once
#include "User.h"
#include "Peminjaman.h"
#include <vector>
#include <string>

using namespace std;

class Peminjam : public User {
private:
    string nim;
    string jurusan;

public:
    Peminjam(string id, string nama, string alamat, string noTelp, string nim, string jurusan)
        : User(id, nama, alamat, noTelp), nim(nim), jurusan(jurusan) {}

    string getNIM();
    void setNIM(string nim);
    string getJurusan();
    void setJurusan(string jurusan);

    void ajukanPeminjaman(Peminjaman &p);
    void pengembalianBuku(Peminjaman &p);
};
