#include "abonat.h"
#include <iostream>

string abonat::get_nr_telefon() const{
    return nr_telefon;
}

void abonat::set_nr_telefon(string nr_telefon_val){
    nr_telefon=nr_telefon_val;
}

abonat::abonat(string nr_telefon_val)
    :nr_telefon{nr_telefon_val}{
        cout<<"Abonat ctor called"<<endl;
}
/*
abonat::abonat(const abonat &x)
    :abonat(x.nr_telefon){
        cout<<"Abonat copy ctor called"<<endl;
}
*/
abonat::~abonat(){
}
