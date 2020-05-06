#ifndef ABONAT_H
#define ABONAT_H

#include <string>
#include <persoana.h>

using namespace std;

class abonat : public persoana{
    string nr_telefon;
public:
    string get_nr_telefon() const;
    void set_nr_telefon(string nr_telefon_val);

    abonat(string nr_telefon_val="No_Phone_Number");
    //abonat(const abonat &x);
    ~abonat();
};

#endif // ABONAT_H
