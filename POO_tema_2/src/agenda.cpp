#include "agenda.h"
#include <iostream>
abonat_skype_romania agenda::get_elem_agenda(int i){
    return v[i];
}

void agenda::adauga_element_in_agenda(const abonat_skype_romania &x){
    v.push_back(x);
}

void agenda::afisare_abonat_dupa_nume(string nume_val){
    int sem=0;
    for(int i=0;i<=v.size()-1;i++){
        if(v[i].get_nume()==nume_val){
            cout<<"Nume: "<<v[i].get_nume()<<endl;
            cout<<"ID: "<<v[i].get_id()<<endl;
            cout<<"Nr. telefon: "<<v[i].get_nr_telefon()<<endl;
            cout<<"ID skype: "<<v[i].get_id_skype()<<endl;
            cout<<"Email: "<<v[i].get_adresa_mail()<<endl;
            sem=1;
            break;
        }
    }
    if(sem==0)
        cout<<"Nu exista abonatul cu numele "<<nume_val<<endl;
}

void agenda::afisare_element_agenda_dupa_indice(int i){
    cout<<"Nume: "<<v[i].get_nume()<<endl;
    cout<<"ID: "<<v[i].get_id()<<endl;
    cout<<"Nr. telefon: "<<v[i].get_nr_telefon()<<endl;
    cout<<"ID skype: "<<v[i].get_id_skype()<<endl;
    cout<<"Email: "<<v[i].get_adresa_mail()<<endl;
}

void agenda::afisare_agenda(){
    for(int i=0;i<=v.size()-1;i++){
        cout<<"Abonatul numarul "<<i+1<<":"<<endl;
        cout<<"Nume: "<<v[i].get_nume()<<endl;
        cout<<"ID: "<<v[i].get_id()<<endl;
        cout<<"Nr. telefon: "<<v[i].get_nr_telefon()<<endl;
        cout<<"ID skype: "<<v[i].get_id_skype()<<endl;
        cout<<"Email: "<<v[i].get_adresa_mail()<<endl;
        cout<<"===================="<<endl;
    }
}
agenda::agenda(){
}
agenda::~agenda(){
}
