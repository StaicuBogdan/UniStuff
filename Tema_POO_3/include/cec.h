#ifndef CEC_H
#define CEC_H

#include <tranzactie.h>

using namespace std;

class cec : public tranzactie{
        string nume;
    public:
        cec(string data_val="");
        virtual ~cec();

        int get_suma() const;
        string get_data() const;
        void afiseazaTranzactie();

        friend istream &operator>>(istream &input, cec &ce);
};

#endif // CEC_H
