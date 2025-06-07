// User.cpp
#include "User.h"

User::User(string id, string nama, string alamat, string noTelp)
    : id(id), nama(nama), alamat(alamat), noTelp(noTelp) {}

bool User::login(string username, string password) {
    return username == id && password == "password";
}

void User::logout() {
    cout << nama << " telah logout.\n";
}

string User::getId() {
    return id;
}

string User::getNama() {
    return nama;
}

void User::setNama(string nama) {
    this->nama = nama;
}
