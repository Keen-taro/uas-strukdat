#include <iostream>
#include <string>
#include "func.hpp"
#include "apoteker.hpp"
#include "obat.hpp"

int main(){
    std::string namaP, namaA, ID, alamat, namaObt;
    int pil, pil2, pil3, pil4, pil5, jmlh, harga;
    pasienPtr newPasien;
    obatList head;
    obatPtr newObat;
    apotekerPtr newAptkr;
    stack top;
    Queue q;
    createQueue(q);
    createPasien(newPasien, 3, "Lily", "Jakarta", "Paracetamol", 2);
    enQueuePsn(q, newPasien);
    createPasien(newPasien, 2, "Kiki", "Bogor", "OBH", 3);
    enQueuePsn(q, newPasien);
    createPasien(newPasien, 4, "James", "Bandung", "Comix", 1);
    enQueuePsn(q, newPasien);

    createStack(top);
    createApoteker(newAptkr, "Jim", "128903");
    pushAptkr(top, newAptkr);
    createApoteker(newAptkr, "Tom", "187563");
    pushAptkr(top, newAptkr);
    createApoteker(newAptkr, "Adam", "179543");
    pushAptkr(top, newAptkr);
    createApoteker(newAptkr, "Ben", "194633");
    pushAptkr(top, newAptkr);
    
    createElemnt(newObat, 30000, 5, "Paracetamol");
    insertObat(head, newObat);
    createElemnt(newObat, 24000, 4, "Comix");
    insertObat(head, newObat);
    createElemnt(newObat, 18000, 7, "OBH");
    insertObat(head, newObat);
    createElemnt(newObat, 5000, 10, "Antangin");
    insertObat(head, newObat);

    std::cout<<"===============================\n";
    std::cout<<"       Aplikasi Apotek\n";
    std::cout<<"===============================\n";
    std::cout<<"       Masuk Sebagai\n";
    std::cout<<"    1. Pasien\n";
    std::cout<<"    2. Apoteker\n";
    std::cout<<"    Pilihan (1/2) : "; 
    std::cin>>pil;

    switch (pil){
        case 1:
            std::cout<<"=======================\n";
            std::cout<<"       Pasien\n";
            std::cout<<"=======================\n";
            std::cout<<"    Nama   : "; std::cin>>namaP;
            std::cout<<"    Alamat : "; std::cin>>alamat;

            std::cout<<"=======================\n";
            std::cout<<"      Menu Pasien      \n";
            std::cout<<"=======================\n";
            std::cout<<"    1. Pemesanan Obat\n";
            std::cout<<"    2. List Obat\n";
            std::cout<<"    Pilihan (1/2) : "; std::cin>>pil2;
            switch(pil2){
                case 1:
                    std::cout<<"=======================\n";
                    std::cout<<"     Pemesanan Obat\n";
                    std::cout<<"=======================\n";
                    std::cout<<"Nama Obat : "; std::cin>>namaObt;
                    std::cout<<"Jumlah    : "; std::cin>>jmlh;
                    createPasien(newPasien, 1, namaP, alamat, namaObt, jmlh);
                    enQueuePsn(q, newPasien);
                    std::cout<<"\n=====================\n";
                    std::cout<<"        Check-Out\n";
                    std::cout<<"======================\n";
                    std::cout<<"Nama Obat   : "<<namaObt<<"\n";
                    std::cout<<"Jumlah      : "<<jmlh<<"\n";
                    std::cout<<"Harga Total : "<<hargaObt(head, namaObt) * jmlh;
                    minObat(head, namaObt, jmlh);
                    traversal(head);
                    break;
                case 2:
                    traversal(head);
            }
            break;
        case 2:
            std::cout<<"=======================\n";
            std::cout<<"       Apoteker\n";
            std::cout<<"=======================\n";
            std::cout<<"    Nama   : "; std::cin>>namaA;
            std::cout<<"    ID     : "; std::cin>>ID;
            
            std::cout<<"======================\n";
            std::cout<<"     Menu Apoteker\n";
            std::cout<<"======================\n";
            std::cout<<"   1. Update Obat\n";
            std::cout<<"   2. Restock Obat\n";
            std::cout<<"   3. Antrian Pasien\n";
            std::cout<<"   Pilihan (1/2/3) : "; std::cin>>pil3;
            switch(pil3){
                case 1:
                    std::cout<<"====================\n";
                    std::cout<<"    Update Obat\n";
                    std::cout<<"====================\n";
                    std::cout<<"  Nama Obat : "; std::cin>>namaObt;
                    std::cout<<"  Harga     : "; std::cin>>harga;
                    std::cout<<"  Jumlah    : "; std::cin>>jmlh;
                    createElemnt(newObat, harga, jmlh, namaObt);
                    insertObat(head, newObat);
                    traversal(head);
                    break;

                case 2:
                    std::cout<<"====================\n";
                    std::cout<<"    Restok Obat\n";
                    std::cout<<"====================\n";
                    std::cout<<"  Nama Obat                     : "; std::cin>>namaObt;
                    std::cout<<"  Jumlah yang ingin ditambahkan : "; std::cin>>jmlh;
                    Restock(head, namaObt, jmlh);
                    traversal(head);
                    break;
                case 3:
                    traversalPsn(q);
                    break;
            }
            break;
    }
}