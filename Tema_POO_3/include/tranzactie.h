#ifndef TRANZACTIE_H
#define TRANZACTIE_H
#include <string>

using namespace std;

class tranzactie{
    protected:
        static int nrTranzactii;
        int suma;
        string data;
    public:
        tranzactie(string data_val="");
        virtual ~tranzactie();

        virtual int get_suma() const;
        virtual string get_data() const;
        virtual void afiseazaTranzactie();
        static int get_nr_tranzactii();
        void increase_nr_tranzactii();

        friend istream &operator>>(istream &input, tranzactie &t);
};

#endif // TRANZACTIE_H
