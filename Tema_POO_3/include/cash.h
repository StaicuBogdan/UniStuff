#ifndef CASH_H
#define CASH_H

#include <tranzactie.h>

using namespace std;

class cash : public tranzactie{
    public:
        cash(string data_val="");
        virtual ~cash();

        int get_suma() const;
        string get_data() const;
        friend istream &operator>>(istream &input, cash &c);

        void afiseazaTranzactie();
};

#endif // CASH_H
