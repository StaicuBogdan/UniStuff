#include "cec.h"
#include <iostream>

cec::cec(string data_val)
    :tranzactie(data_val){
        //cout<<"Cec C"<<endl;
}

cec::~cec(){
}

int cec::get_suma() const{
    return suma;
}

string cec::get_data() const{
    return data;
}

void cec::afiseazaTranzactie(){
    cout<<"Suma: "<<suma<<" Numele: "<<nume<<" Data: "<<data<<endl;
}

istream &operator>>(istream &input, cec &ce){
    tranzactie *temp= &ce;
    input >> *temp;
    cout<<"Numele dumneavoastra: ";
    input>>ce.nume;
    return input;
}
