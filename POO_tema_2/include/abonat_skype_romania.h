#ifndef ABONAT_SKYPE_ROMANIA_H
#define ABONAT_SKYPE_ROMANIA_H

#include <string>
#include <abonat_skype.h>

using namespace std;

class abonat_skype_romania : public abonat_skype{
    string adresa_mail;
public:
    string get_adresa_mail() const;
    void set_adresa_mail(string adresa_mail_val);

    abonat_skype_romania(string adresa_mail_val="No_mail_adress");
    //abonat_skype_romania(const abonat_skype_romania &x);
    ~abonat_skype_romania();
};

#endif // ABONAT_SKYPE_ROMANIA_H
