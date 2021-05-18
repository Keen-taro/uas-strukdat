#include <iostream>
#include "struct.hpp"

void createElemnt(obatPtr& newObat, int harga, int stok, std::string namaObat){
    newObat = new obat;
    newObat->harga = harga;
    newObat->stok = stok;
    newObat->namaObat = namaObat;
    newObat->nextObat = nullptr;
}
typedef obatPtr obatList;
void insertObat(obatList &head, obatPtr newObat){
    if(head == nullptr){
        head = newObat;
    } else {
        newObat->nextObat = head;
        head = newObat;
    }
}
void searchObat(obatList &head, obatPtr &pSearch, std::string obat){
    pSearch = head;
    while(pSearch != nullptr){
        if(pSearch->namaObat == obat){
            break;
        pSearch = pSearch->nextObat;
        }
    }
}
void deleteObat(obatList &head, obatPtr &pDel, std::string obat){
    searchObat(head, pDel, obat);

    if(head == nullptr || pDel == nullptr){
        std::cout << "obat yang dicari tidak ditemukan " << '\n';
    } else {
        if(pDel == head){
            head = head->next;
            pDel->next = nullptr;
        } else if(pDel->next == nullptr){
            pDel->next = nullptr;
            pDel = nullptr;
        } else {
            pDel->next = pDel->next;
            pDel->next = pDel;
            pDel->next = nullptr;
            pDel = nullptr;
        }
        delete pDel;
    }
}
void traversal(obatList &head){
    if(head == nullptr){
        std::cout << "list obat kosong! \n";
    } else {
        obatPtr pHelp = head;
        while(pHelp != nullptr){
            std::cout << "Nama Obat : " << pHelp->nextObat << '\n';
            std::cout << "Harga \t : " << pHelp->harga << '\n';
            std::cout << "Stok \t : " << pHelp->stok << '\n';
            pHelp->nextObat;
        }
        std::cout << '\n';
    }
}