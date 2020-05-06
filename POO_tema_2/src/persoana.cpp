#include "persoana.h"
#include <iostream>

int persoana::get_id() const{
    return id;
}
string persoana::get_nume() const{
    return nume;
}
void persoana::set_id(int id_val){
    id=id_val;
}
void persoana::set_nume(string nume_val){
    nume=nume_val;
}

persoana::persoana(int id_val,string nume_val)
    :id{id_val},nume{nume_val}{
        cout<<"Persoana Ctor called"<<endl;
}
/*
persoana::persoana(const persoana &x)
    :persoana(x.id,x.nume){
        cout<<"Persoana Copy ctor called"<<endl;
}
*/
persoana::~persoana(){
}
