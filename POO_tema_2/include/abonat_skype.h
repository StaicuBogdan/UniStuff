#ifndef ABONAT_SKYPE_H
#define ABONAT_SKYPE_H

#include <string>
#include <abonat.h>

using namespace std;

class abonat_skype : public abonat{
    string id_skype;
public:
    string get_id_skype() const;
    void set_id_skype(string id_skype_val);

    abonat_skype(string id_skype_val="No_Skype_id");
    //abonat_skype(const abonat_skype &x);
    ~abonat_skype();
};

#endif // ABONAT_SKYPE_H
