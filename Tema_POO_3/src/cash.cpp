#include "cash.h"
#include <iostream>

cash::cash(string data_val)
    :tranzactie(data_val){
        //cout<<"Cash C"<<endl;
}

cash::~cash(){
}

int cash::get_suma() const{
    return suma;
}

string cash::get_data() const{
    return data;
}

void cash::afiseazaTranzactie(){
    cout<<"Suma: "<<suma<<" "<<"Data: "<<data<<endl;
}

istream &operator>>(istream &input, cash &c){
    tranzactie *temp= &c;
    input >> *temp;
    return input;
}
