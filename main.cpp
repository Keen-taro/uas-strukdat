#include <iostream>
#include <string>

int main(){
    std::string namaP, namaA, ID, alamat;
    int pil;
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
            break;
        
        case 2:
            std::cout<<"=======================\n";
            std::cout<<"       Apoteker\n";
            std::cout<<"=======================\n";
            std::cout<<"    Nama   : "; std::cin>>namaA;
            std::cout<<"    ID     : "; std::cin>>ID;
            break;
    }
}