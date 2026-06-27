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

//Menambah Data
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

// Menghapus Data
Pegawai* hapusData(Pegawai* root, int id) {

    if (root == NULL)
        return NULL;

    if (id < root->id)
        root->left = hapusData(root->left, id);

    else if (id > root->id)
        root->right = hapusData(root->right, id);

    else {

        // Tidak punya anak
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Satu anak
        else if (root->left == NULL) {
            Pegawai* temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == NULL) {
            Pegawai* temp = root->left;
            delete root;
            return temp;
        }

        // Dua anak
        Pegawai* temp = cariMin(root->right);

        root->id = temp->id;
        root->nama = temp->nama;
        root->jabatan = temp->jabatan;

        root->right = hapusData(root->right, temp->id);
    }

    return root;
}

// Mencari Data
Pegawai* cariData(Pegawai* root, int id) {
    if (root == NULL || root->id == id)
        return root;

    if (root->id < id)
        return cariData(root->right, id);

    return cariData(root->left, id);
}

// Menampilkan data secara terstruktur
void tampilData(Pegawai* root) {

    if (root != NULL) {

        tampilData(root->left);

        cout << "ID      : " << root->id << endl;
        cout << "Nama    : " << root->nama << endl;
        cout << "Jabatan : " << root->jabatan << endl;
        cout << "------------------------\n";

        tampilData(root->right);
    }
}

int main() {

    Pegawai* root = NULL;
    int pilihan, id;
    string nama, jabatan;

    do {

        cout << "\n===== SISTEM DATA PEGAWAI =====\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Cari Data\n";
        cout << "4. Tampilkan Data\n";
        cout << "5. Keluar\n";
        cout << "Pilih : ";
        cin >> pilihan;

        switch (pilihan) {

        case 1:
            cout << "ID Pegawai    : ";
            cin >> id;

            cin.ignore();

            cout << "Nama Pegawai  : ";
            getline(cin, nama);

            cout << "Jabatan       : ";
            getline(cin, jabatan);

            root = tambahData(root, id, nama, jabatan);
            break;

        case 2:
            cout << "Masukkan ID yang akan dihapus : ";
            cin >> id;

            root = hapusData(root, id);
            break;

        case 3: {
            cout << "Masukkan ID yang dicari : ";
            cin >> id;

            Pegawai* hasil = cariData(root, id);

            if (hasil != NULL) {
                cout << "\nData Ditemukan\n";
                cout << "ID      : " << hasil->id << endl;
                cout << "Nama    : " << hasil->nama << endl;
                cout << "Jabatan : " << hasil->jabatan << endl;
            }
            else {
                cout << "Data tidak ditemukan!\n";
            }

            break;
        }

        case 4:
            cout << "\n=== DATA PEGAWAI ===\n";
            tampilData(root);
            break;

        case 5:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 5);

    return 0;
}
