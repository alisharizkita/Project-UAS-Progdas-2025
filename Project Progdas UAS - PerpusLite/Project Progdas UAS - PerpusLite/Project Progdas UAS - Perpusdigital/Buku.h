// Buku.h
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Buku {
public:
    string idBuku;
    string judul;
    string penulis;
    string penerbit;
    int tahunTerbit;
    int stok;

    Buku() {}
    Buku(string id, string j, string p, string penerbit, int tahun, int s)
        : idBuku(id), judul(j), penulis(p), penerbit(penerbit), tahunTerbit(tahun), stok(s) {}

    string getInfo();
    bool isTersedia();
    void kurangiStok();
    void tambahStok();
};
