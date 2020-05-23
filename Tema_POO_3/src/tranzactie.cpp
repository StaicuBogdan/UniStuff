#include "tranzactie.h"
#include <iostream>

using namespace std;

int tranzactie::nrTranzactii=0;

tranzactie::tranzactie(string data_val)
    :data{data_val}{
        //cout<<"Tranzactie C"<<endl;
}

tranzactie::~tranzactie(){
}

int tranzactie::get_suma() const{
    return suma;
}

string tranzactie::get_data() const{
    return data;
}

void tranzactie::afiseazaTranzactie(){
    cout<<"Suma: "<<suma<<" "<<"Data: "<<data<<endl;
}

int tranzactie::get_nr_tranzactii(){
    return nrTranzactii;
}

void tranzactie::increase_nr_tranzactii(){
    nrTranzactii++;
}

istream &operator >> (istream &input, tranzactie &t){
    cout<<"Introduceti suma: ";
    cin>>t.suma;
}

