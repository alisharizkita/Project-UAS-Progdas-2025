// Peminjaman.h
#pragma once
#include <string>
using namespace std;

class Peminjaman {
private:
    string idBuku;
    string idPeminjam;
    string status;
public:
    Peminjaman(string idBuku, string idPeminjam);
    string getIdBuku();
    string getIdPeminjam();
    string getStatus();
    void setStatus(string status);
};