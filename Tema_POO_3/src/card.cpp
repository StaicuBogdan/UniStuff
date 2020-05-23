#include "card.h"
#include<iostream>

card::card(string data_val)
    :tranzactie(data_val){
        //cout<<"Card C"<<endl;
}

card::~card(){
}

int card::get_suma() const{
    return suma;
}

string card::get_data() const{
    return data;
}

void card::afiseazaTranzactie(){
    cout<<"Suma: "<<suma<<" Numele: "<<nume<<" Nr card: "<<nrCard<<" Data: "<<data<<endl;
}

istream &operator>>(istream &input, card &ca){
    tranzactie *temp= &ca;
    input>>*temp;
    cout<<"Numele dumneavoastra: ";
    input>>ca.nume;
    cout<<"Numarul cardului: ";
    input>>ca.nrCard;
    return input;
}
