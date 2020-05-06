#include "abonat_skype.h"
#include <iostream>

string abonat_skype::get_id_skype() const{
    return id_skype;
}

void abonat_skype::set_id_skype(string id_skype_val){
    id_skype=id_skype_val;
}

abonat_skype::abonat_skype(string id_skype_val)
    :id_skype{id_skype_val}{
        cout<<"abonat skype ctor called"<<endl;
}
/*
abonat_skype::abonat_skype(const abonat_skype &x)
    :abonat_skype(x.id_skype){
        cout<<"abonat skype copy ctor called"<<endl;
}
*/
abonat_skype::~abonat_skype(){
}
