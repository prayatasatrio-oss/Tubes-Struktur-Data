#include<iostream>
using namespace std;

struct Pegawai {
    int id;
    string nama;
    string jabatan;

    Pegawai *left;
    Pegawai *right;
};

// Membuat node baru
Pegawai* buatNode(int id, string nama, string jabatan) {
    Pegawai* baru = new Pegawai;
    baru->id = id;
    baru->nama = nama;
    baru->jabatan = jabatan;
    baru->left = NULL;
    baru->right = NULL;

    return baru;
}

// 1. Menambah Data
Pegawai* tambahData(Pegawai* root, int id, string nama, string jabatan) {

    if (root == NULL)
        return buatNode(id, nama, jabatan);

    if (id < root->id)
        root->left = tambahData(root->left, id, nama, jabatan);

    else if (id > root->id)
        root->right = tambahData(root->right, id, nama, jabatan);

    else
        cout << "ID sudah ada!\n";

    return root;
}

// Mencari node terkecil
Pegawai* cariMin(Pegawai* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}