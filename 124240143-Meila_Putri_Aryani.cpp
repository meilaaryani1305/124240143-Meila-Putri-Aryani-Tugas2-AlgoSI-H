#include <iostream>
using namespace std;

struct Pasien
{
    int nomor;
    string nama;
    string keluhan;
    Pasien *next;
    Pasien *prev;
};

Pasien *head = nullptr;
Pasien *tail = nullptr;

bool isEmpty()
{
    return head == nullptr;
}

void tambahPasien()
{
    int nomor;
    string nama, keluhan;

    cout << "Masukkan Nomor Antrian : ";
    cin >> nomor;
    cin.ignore();
    cout << "masukkan Nama Pasien   : ";
    getline(cin, nama);
    cout << "Masukkan Keluhan       : ";
    getline(cin, keluhan);

    Pasien *newNode = new Pasien;
    newNode->nomor = nomor;
    newNode->nama = nama;
    newNode->keluhan = keluhan;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    cout << "Pasien berhasil ditambahkan ke daftar!\n";
}

void antrianAwal()
{
    if (isEmpty())
    {
        cout << "Antrian kosong.\n";
        return;
    }

    Pasien *temp = head;
    cout << "=== Antrian dari Awal ===\n";
    cout << "===============================" << endl;
    while (temp != nullptr)
    {
        cout << "Nomor      : " << temp->nomor << endl;
        cout << "Nama       : " << temp->nama << endl;
        cout << "Keluhan    : " << temp->keluhan << endl;
        cout << "------------------------------" << endl;
        temp = temp->next;
    }
}

void antrianAkhir()
{
    if (isEmpty())
    {
        cout << "Antrian kosong.\n";
        return;
    }

    Pasien *temp = tail;
    cout << "=== Antrian dari Akhir ===\n";
    cout << "===============================" << endl;
    while (temp != nullptr)
    {
        cout << "Nomor      : " << temp->nomor << endl;
        cout << "Nama       : " << temp->nama << endl;
        cout << "Keluhan     : " << temp->keluhan << endl;
        cout << "------------------------------" << endl;
        temp = temp->prev;
    }
}

void cariPasien()
{
    if (isEmpty())
    {
        cout << "Antrian kosong.\n";
        return;
    }

    int cariNomor;
    cout << "Masukkan nomor antrian yang dicari: ";
    cin >> cariNomor;

    Pasien *temp = head;
    while (temp != nullptr)
    {
        if (temp->nomor == cariNomor)
        {
            cout << "Data Pasien Ditemukan!\n";
            cout << "Nomor      : " << temp->nomor << endl;
            cout << "Nama       : " << temp->nama << endl;
            cout << "Keluhan    : " << temp->keluhan << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Pasien dengan nomor " << cariNomor << " tidak ditemukan.\n";
}

void hapusPasien()
{
    if (isEmpty())
    {
        cout << "Antrian kosong, tidak ada yang bisa dihapus.\n";
        return;
    }

    int nomor;
    cout << "Masukkan nomor antrian yang akan dihapus: ";
    cin >> nomor;

    Pasien *hapus = head;

    if (hapus->nomor == nomor)
    {
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete hapus;
        cout << "Pasien berhasil dihapus.\n";
        return;
    }

    while (hapus != nullptr && hapus->nomor != nomor)
    {
        hapus = hapus->next;
    }

    if (hapus == nullptr)
    {
        cout << "Pasien tidak ditemukan.\n";
        return;
    }

    if (hapus == tail)
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
    else
    {
        hapus->prev->next = hapus->next;
        hapus->next->prev = hapus->prev;
    }

    delete hapus;
    cout << "Data pasien berhasil dihapus.\n";
}

int main()
{
    int pilih;
    do
    {
        cout << "=== MENU ANTRIAN PASIEN KLINIK SEHAT SELALU ===" << endl;
        cout << "1. Tambah Data Pasien" << endl;
        cout << "2. Tampilkan Antrian dari Awal" << endl;
        cout << "3. Tampilkan Antrian dari Akhir" << endl;
        cout << "4. Cari Data Pasien" << endl;
        cout << "5. Hapus Data Pasien" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih Menu: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            tambahPasien();
            break;
        case 2:
            antrianAwal();
            break;
        case 3:
            antrianAkhir();
            break;
        case 4:
            cariPasien();
            break;
        case 5:
            hapusPasien();
            break;
        case 6:
            cout << "Terima Kasih!\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilih);

    return 0;
}
