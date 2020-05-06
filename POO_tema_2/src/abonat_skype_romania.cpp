#include "abonat_skype_romania.h"
#include <iostream>

string abonat_skype_romania::get_adresa_mail() const{
    return adresa_mail;
}

void abonat_skype_romania::set_adresa_mail(string adresa_mail_val){
    adresa_mail=adresa_mail_val;
}

abonat_skype_romania::abonat_skype_romania(string adresa_mail_val)
    :adresa_mail{adresa_mail_val}{
        cout<<"abonat skype romania constructor called"<<endl;
}
/*
abonat_skype_romania::abonat_skype_romania(const abonat_skype_romania &x)
    :abonat_skype_romania(x.adresa_mail){
        cout<<"abonat skype romania copy constructor called"<<endl;
}
*/
abonat_skype_romania::~abonat_skype_romania(){
}
