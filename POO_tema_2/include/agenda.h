#ifndef AGENDA_H
#define AGENDA_H

#include <abonat_skype_romania.h>
#include <vector>

using namespace std;

class agenda{
    vector <abonat_skype_romania> v;
public:
    abonat_skype_romania get_elem_agenda(int i);
    void adauga_element_in_agenda(const abonat_skype_romania &x);
    void afisare_abonat_dupa_nume(string nume_val);
    void afisare_element_agenda_dupa_indice(int i);
    void afisare_agenda();
    agenda();
    ~agenda();
};

#endif // AGENDA_H
