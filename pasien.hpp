#include <iostream>

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

void createQueue(Queue& Q){
    Q.head = nullptr;
    Q.tail = nullptr;
}

void createPasien(pasienPtr& newPasien, int priority, std::string namaP, std::string alamat, std::string namaObt, int jumlahObt){
    newPasien = new pasien;
    newPasien->namaPsn = namaP;
    newPasien->alamat = alamat;
    newPasien->namaObt = namaObt;
    newPasien->jumlahObt = jumlahObt;
    newPasien->priority = priority;
    newPasien->nextPsn = nullptr;
}

bool emptyPsn(Queue Q){
    if(Q.head == nullptr && Q.tail == nullptr){
        return true;
    }else{
        return false;
    }
}

void enQueuePsn(Queue& Q, pasienPtr newPasien){
    pasienPtr pRev = nullptr;
    pasienPtr pHelp = Q.head;
    if(emptyPsn(Q)){
        Q.head = newPasien;
        Q.tail = newPasien;
    }
    else{
        while(newPasien->priority >= pHelp->priority){
            if(pHelp->nextPsn == nullptr){
                break;
            }
            pRev = pHelp;
            pHelp = pHelp->nextPsn;
        }
        if(pHelp == Q.head && newPasien->priority < pHelp->priority){
            newPasien->nextPsn = pHelp;
            Q.head = newPasien;
        }
        else if(pHelp == Q.tail && newPasien->priority > pHelp->priority){
            pHelp->nextPsn = newPasien;
            Q.tail = newPasien;
        }
        else{
            pRev->nextPsn = newPasien;
            newPasien->nextPsn = pHelp;
        }
    }
}

void deQueuePsn(Queue& Q, pasienPtr delPsn){
    if(emptyPsn(Q)){
        delPsn = nullptr;
    }else if(Q.head->nextPsn == nullptr){
        delPsn = Q.head;
        Q.head = nullptr;
        Q.tail = nullptr;
    }else{
        delPsn = Q.head;
        Q.head = Q.head->nextPsn;
        delPsn->nextPsn = nullptr;
    }
}

void traversalPsn(Queue& Q){
    int i = 0;
    pasienPtr pHelp = Q.head;
    if(emptyPsn(Q)){
        std::cout<<"Tidak ada antrian pemesanan obat";
    }else{
        std::cout<<"\n=========================\n";
        std::cout<<"        Antrian Obat\n";
        std::cout<<"==========================\n";
        while(pHelp != nullptr){
            std::cout<<"\n   Nama    : "<<pHelp->namaPsn<<std::endl;
            std::cout<<"   Alamat  : "<<pHelp->alamat<<std::endl;
            std::cout<<"   Pesanan : "<<pHelp->namaObt<<" x "<<pHelp->jumlahObt<<"\n";
            pHelp = pHelp->nextPsn;
        }
        
    }
}
