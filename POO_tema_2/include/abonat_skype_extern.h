#ifndef ABONAT_SKYPE_EXTERN_H
#define ABONAT_SKYPE_EXTERN_H

#include <string>
#include <abonat_skype.h>

using namespace std;

class abonat_skype_extern : public abonat_skype{
    string tara;
public:
    string get_tara() const;
    void set_tara(string tara_val);

    abonat_skype_extern(string tara_val="Unknown");
    //abonat_skype_extern(const abonat_skype_extern &x);
    ~abonat_skype_extern();

};

#endif // ABONAT_SKYPE_EXTERN_H
