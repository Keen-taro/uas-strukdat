#include <iostream>

struct obat{
    std::string namaObat;
    int harga;
    int stok;
    obat* nextObat;
};
typedef obat* obatPtr;
typedef obatPtr obatList;

void createElemnt(obatPtr& newObat, int harga, int stok, std::string namaObat){
    newObat = new obat;
    newObat->harga = harga;
    newObat->stok = stok;
    newObat->namaObat = namaObat;
    newObat->nextObat = nullptr;
}

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
            head = head->nextObat;
            pDel->nextObat = nullptr;
        } else if(pDel->nextObat == nullptr){
            pDel->nextObat = nullptr;
            pDel = nullptr;
        } else {
            pDel->nextObat = pDel->nextObat;
            pDel->nextObat = pDel;
            pDel->nextObat = nullptr;
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
        std::cout<<"=====================\n";
        std::cout<<"      List Obat\n";
        std::cout<<"=====================\n";
        while(pHelp != nullptr){
            std::cout << "\nNama Obat : " << pHelp->namaObat << '\n';
            std::cout << "Harga \t  : " << pHelp->harga << '\n';
            std::cout << "Stok \t  : " << pHelp->stok << '\n';
            pHelp = pHelp->nextObat;
        }
        std::cout << '\n';
    }
}

int hargaObt(obatList& head, std::string namaObt){
    obatPtr temp = head;
    int hrg;
    while(temp != nullptr){
        
        if(temp->namaObat == namaObt){
            hrg = temp->harga;
        }
        temp = temp->nextObat;
    }
    return hrg;
}

void Restock(obatList& head, std::string namaObat, int jmlh){
    obatPtr temp = head;
    while(temp != nullptr){
        if(temp->namaObat == namaObat){
            temp->stok = temp->stok + jmlh;
        }
        temp = temp->nextObat;
    }
}