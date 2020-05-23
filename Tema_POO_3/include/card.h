#ifndef CARD_H
#define CARD_H

#include <tranzactie.h>

using namespace std;

class card : public tranzactie{
        string nume;
        string nrCard;
    public:
        card(string data_val="");
        virtual ~card();

        int get_suma() const;
        string get_data() const;
        void afiseazaTranzactie();
        friend istream &operator>>(istream &input, card &ca);
};

#endif // CARD_H
