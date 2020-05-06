#include <iostream>
#include <persoana.h>
#include <abonat.h>
#include <abonat_skype.h>
#include <abonat_skype_romania.h>
#include <abonat_skype_extern.h>
#include <agenda.h>
#include <string>

using namespace std;

int main(){
    persoana Andrei(1,"Andrei");
    cout<<Andrei.get_id()<<endl;
    cout<<Andrei.get_nume()<<endl;

    persoana Mirel(Andrei);
    cout<<Mirel.get_id();

    persoana Dorel;
    cout<<Dorel.get_id()<<" "<<Dorel.get_nume()<<endl;

    cout<<"================================================================="<<endl;

    abonat George;
    cout<<"abonat george fara parametri: "<<George.get_id()<<" "<<George.get_nume()<<" "<<George.get_nr_telefon()<<endl;
    George.set_id(2);
    George.set_nume("George");
    George.set_nr_telefon("0722222222");
    cout<<"abonat george cu parametri: "<<George.get_id()<<" "<<George.get_nume()<<" "<<George.get_nr_telefon()<<endl;

    abonat Dumi(George);
    cout<<"abonat dumi copiat: "<<Dumi.get_id()<<" "<<Dumi.get_nume()<<" "<<Dumi.get_nr_telefon()<<endl;

    cout<<"================================================================="<<endl;

    abonat_skype Laur;
    cout<<"abonat skype laur fara parametri: "<<Laur.get_id()<<" "<<Laur.get_nume()<<" "<<Laur.get_nr_telefon()<<" "<<Laur.get_id_skype()<<endl;
    Laur.set_id(3);
    Laur.set_nume("Laur");
    Laur.set_nr_telefon("0733333333");
    Laur.set_id_skype("laur99.coman");
    cout<<"abonat skype laur cu parametri: "<<Laur.get_id()<<" "<<Laur.get_nume()<<" "<<Laur.get_nr_telefon()<<" "<<Laur.get_id_skype()<<endl;

    cout<<"================================================================="<<endl;

    abonat_skype_romania Alex;
    cout<<"abonat skype alex fara parametri: "<<Alex.get_id()<<" "<<Alex.get_nume()<<" "<<Alex.get_nr_telefon()<<" "<<Alex.get_id_skype()<<" "<<Alex.get_adresa_mail()<<endl;
    Alex.set_id(4);
    Alex.set_nume("Alex");
    Alex.set_nr_telefon("0744444444");
    Alex.set_id_skype("alex.eu%");
    Alex.set_adresa_mail("alexandru1994@gmail.com");
    cout<<"abonat skype alex cu parametri: "<<Alex.get_id()<<" "<<Alex.get_nume()<<" "<<Alex.get_nr_telefon()<<" "<<Alex.get_id_skype()<<" "<<Alex.get_adresa_mail()<<endl;

    cout<<"================================================================="<<endl;

    abonat_skype_extern Michael;
    cout<<"Michael fara parametri: "<<Michael.get_id()<<" "<<Michael.get_nume()<<" "<<Michael.get_nr_telefon()<<" "<<Michael.get_id_skype()<<" "<<Michael.get_tara()<<endl;
    Michael.set_id(5);
    Michael.set_nume("Michael");
    Michael.set_nr_telefon("0755555555");
    Michael.set_id_skype("mike.stevens1");
    Michael.set_tara("England");
    cout<<"Michael cu parametri: "<<Michael.get_id()<<" "<<Michael.get_nume()<<" "<<Michael.get_nr_telefon()<<" "<<Michael.get_id_skype()<<" "<<Michael.get_tara()<<endl;

    cout<<"================================================================="<<endl;

    abonat_skype_extern Steve(Michael);
    cout<<Steve.get_id()<<" "<<Steve.get_nume()<<" "<<Steve.get_nr_telefon()<<" "<<Steve.get_id_skype()<<" "<<Steve.get_tara()<<endl;

    cout<<"================================================================="<<endl;

    agenda a1;
    a1.adauga_element_in_agenda(Alex);
    cout<<a1.get_elem_agenda(0).get_nume()<<endl;

    a1.afisare_element_agenda_dupa_indice(0);

    a1.afisare_abonat_dupa_nume("Alex");
    a1.afisare_abonat_dupa_nume("Alexutz");

    cout<<"================================================================="<<endl;

    int n;
    agenda a2;
    cout<<"Cati abonati vreti in agenda? N=";cin>>n;
    for(int i=0;i<=n-1;i++){
        abonat_skype_romania temporar;
        cout<<"Dati numele: ";
        string nume_temporar;
        cin>>nume_temporar;
        temporar.set_nume(nume_temporar);

        cout<<"Dati ID: ";
        int id_temporar;
        cin>>id_temporar;
        temporar.set_id(id_temporar);

        cout<<"Dati numar de telefon: ";
        string nr_temporar;
        cin>>nr_temporar;
        temporar.set_nr_telefon(nr_temporar);

        cout<<"Dati id skype: ";
        string id_skype_temporar;
        cin>>id_skype_temporar;
        temporar.set_id_skype(id_skype_temporar);

        cout<<"Dati adresa de mail: ";
        string email_temporar;
        cin>>email_temporar;
        temporar.set_adresa_mail(email_temporar);

        a2.adauga_element_in_agenda(temporar);
    }
    a2.afisare_agenda();


}
