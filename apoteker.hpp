#include <iostream>

struct apoteker{
    std::string namaAptkr;
    std::string IdAptkr;
    apoteker* nextAptkr;    
};
typedef apoteker *apotekerPtr;
typedef apotekerPtr stack;
stack top;

void createStack(stack& top){
    top = nullptr;
}
void createApoteker(apotekerPtr& newAptkr, std::string namaAptkr, std::string IdAptkr){
    newAptkr = new apoteker;
    newAptkr->namaAptkr = namaAptkr;
    newAptkr->IdAptkr = IdAptkr;
    newAptkr->nextAptkr = nullptr;
}

bool emptyAptkr(stack& top){
    if(top == nullptr){
        return true;
    }else{
        return false;
    }
}

void pushAptkr(stack& top, apotekerPtr newAptkr){
    if(emptyAptkr(top)){
        top = newAptkr;
    }else{
        newAptkr->nextAptkr = top;
        top = newAptkr;
    }
}

/*void validasi(stack& top, std::string namaAptkr, std::string IdAptkr){
    apotekerPtr temp = top;
    while(temp != nullptr){
        if(temp->namaAptkr == namaAptkr && temp->IdAptkr == IdAptkr){
            continue;
        }
        temp = temp->nextAptkr;
    }if(temp->namaAptkr != namaAptkr || temp->IdAptkr != IdAptkr){
            std::cout<<"    Nama / ID yang dimasukkan salah!!";
            std::exit(0);
        }
}*/

void traversalA(stack& top){
    apotekerPtr temp = top;
    while(temp != nullptr){
        std::cout<<"Nama : "<<temp->namaAptkr<<"\n";
        std::cout<<"ID   : "<<temp->IdAptkr;
        temp = temp->nextAptkr;
    }
}

