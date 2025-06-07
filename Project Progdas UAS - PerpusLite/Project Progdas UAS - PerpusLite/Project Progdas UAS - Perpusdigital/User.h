// User.h
#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string id, nama, alamat, noTelp;
public:
    User(string id, string nama, string alamat, string noTelp);
    void logout();
    string getId();
    string getNama();
    void setNama(string nama);
    virtual ~User() {}
};
