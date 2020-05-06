#ifndef PERSOANA_H
#define PERSOANA_H

#include <string>

using namespace std;

class persoana{
    int id;
    string nume;
public:
    int get_id() const;
    string get_nume() const;
    void set_id(int id_val);
    void set_nume(string nume_val);

    persoana(int id=0,string nume_val="NoName");
   // persoana(const persoana &x);
    ~persoana();
};

#endif // PERSOANA_H
