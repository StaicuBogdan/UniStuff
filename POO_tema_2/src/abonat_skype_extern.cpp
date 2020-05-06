#include "abonat_skype_extern.h"
#include <iostream>

string abonat_skype_extern::get_tara() const{
    return tara;
}

void abonat_skype_extern::set_tara(string tara_val){
    tara=tara_val;
}

abonat_skype_extern::abonat_skype_extern(string tara_val)
    :tara{tara_val}{
        cout<<"abonat skype extern ctor called"<<endl;
}
/*
abonat_skype_extern::abonat_skype_extern(const abonat_skype_extern &x)
    :abonat_skype_extern(x.tara){
        cout<<"abonat skype extern copy ctor called"<<endl;
}
*/

abonat_skype_extern::~abonat_skype_extern(){
}
