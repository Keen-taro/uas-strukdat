#include <iostream>

struct apoteker{
    std::string namaAptkr;
    std::string IdAptkr;
    apoteker* nextAptkr;    
};
typedef apoteker *apotekerPtr;
typedef apotekerPtr *First;

struct pasien{
    std::string namaPsn;
    std::string alamat;
    std::string namaObt;
    int jumlahObt;
    int priority;
    pasien* nextPsn;
};
typedef pasien *pasienPtr;

struct Queue{
    pasienPtr head;
    pasienPtr tail;
};
Queue Q;

struct obat{
    std::string namaObat;
    int harga;
    int stok;
    obat* nextObat;
};
typedef obat* obatPtr;