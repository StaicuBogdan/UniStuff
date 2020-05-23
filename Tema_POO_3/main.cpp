#include <iostream>
#include <tranzactie.h>
#include <cash.h>
#include <cec.h>
#include <card.h>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

template <class T> class gestiune{
        int n;
        vector<T> tranzactiiClienti;
    public:
        gestiune();
        virtual ~gestiune();

        gestiune &operator+=(T &ob);
        void afiseazaVectorDeTranzactii();

};

template<class T>
    gestiune<T>::gestiune()
        :n{0}{
}

template<class T>
    gestiune<T>::~gestiune(){
}

template <class T>
     gestiune<T> &gestiune<T>::operator+=(T &ob){
        n++;
        tranzactiiClienti.push_back(ob);
}

template <class T>
    void gestiune<T>::afiseazaVectorDeTranzactii(){
        for(int i=0;i<tranzactiiClienti.size();i++){
            cout<<"Tranzactia numarul "<<i<<endl;
            tranzactiiClienti[i].afiseazaTranzactie();
            cout<<endl;
        }
}

unordered_map<int, tranzactie*> tranzactii;

gestiune<cash> tranzactiiCash;
gestiune<card> tranzactiiCard;
gestiune<cec> tranzactiiCec;

void dataValida(string s){
    int l=s.size();
    string sep="/.";
    if(l<10 || l>10)
        throw "data trebuie sa aiba 10 caractere!\n";
    if(sep.find(s[2])==-1 || sep.find(s[5])==-1)
        throw "data trebuie sa aiba formatul dd/mm/yyyy sau dd.mm.yyyy\n";
    if((int(s[0])-48)*10 + (int(s[1])-48) > 31)
        throw "ziua invalida\n";
    if((int(s[3])-48)*10 + (int(s[4])-48) > 12)
        throw "luna invalida\n";
    if((int(s[6])-48)*1000 + (int(s[7])-48)*100 + (int(s[8])-48)*10 + (int(s[9])-48) > 2020)
        throw "tranzactia nu poate fi in viitor\n";
}
void adaugaTranzactie(string tip, string data){
    if(tip!="cash"&& tip!="card" && tip!="cec"){
        cout<<"tipul tranzactiei nu exista."<<endl;
        return;
    }
    else{
        if(tip=="cash"){
            cash *C=new cash(data);
            cin>>*C;
            C->increase_nr_tranzactii();
            int nrTr=C->get_nr_tranzactii();
            //tranzactii[nrTr]=C;
            tranzactii.insert(pair<int,tranzactie*>(nrTr,C));
            tranzactiiCash+=*C;
        }
        if(tip=="card"){
            card *C=new card(data);
            cin>>*C;
            C->increase_nr_tranzactii();
            int nrTr=C->get_nr_tranzactii();
            //tranzactii[nrTr]=C;
            tranzactii.insert(pair<int,tranzactie*>(nrTr,C));
            tranzactiiCard+=*C;
        }
        if(tip=="cec"){
            cec *C=new cec(data);
            cin>>*C;
            C->increase_nr_tranzactii();
            int nrTr=C->get_nr_tranzactii();
            //tranzactii[nrTr]=C;
            tranzactii.insert(pair<int,tranzactie*>(nrTr,C));
            tranzactiiCec+=*C;
        }
    }
}

void afiseazaTranzactii(){
    //unordered_map<int, tranzactie>::iterator i;
    cout<<"%---------------------------%"<<endl;
    for(auto &it: tranzactii){
        cout<<"Tranzactia numarul "<<it.first<<endl;
        it.second->afiseazaTranzactie();
        cout<<"%---------------------------%"<<endl;
    }
}

void sumaMica(int suma2){
    int sem=0;
    for(auto &it: tranzactii){
        if(it.second->get_suma()<suma2){
            sem++;
            cout<<"Tranzactia numarul "<<it.first<<endl;
            it.second->afiseazaTranzactie();
            cout<<"%---------------------------%"<<endl;
        }
    }
    if(sem==0)
        cout<<"Nu exista astfel de tranzactii"<<endl;
}

void sumaMare(int suma2){
    int sem=0;
    for(auto &it: tranzactii){
        if(it.second->get_suma()>suma2){
            sem++;
            cout<<"Tranzactia numarul "<<it.first<<endl;
            it.second->afiseazaTranzactie();
            cout<<"%---------------------------%"<<endl;
        }
    }
    if(sem==0)
        cout<<"Nu exista astfel de tranzactii"<<endl;
}

void sumaEgala(int suma2){
    int sem=0;
    for(auto &it: tranzactii){
        if(it.second->get_suma()==suma2){
            sem++;
            cout<<"Tranzactia numarul "<<it.first<<endl;
            it.second->afiseazaTranzactie();
            cout<<"%---------------------------%"<<endl;
        }
    }
    if(sem==0)
        cout<<"Nu exista astfel de tranzactii"<<endl;
}

void afiseazaDupaData(string data2){
    int sem=0;
    for(auto &it: tranzactii){
        if(it.second->get_data()==data2){
            sem++;
            cout<<"Tranzactie numarul "<<it.first<<endl;
            it.second->afiseazaTranzactie();
            cout<<"%---------------------------%"<<endl;
        }
    }
    if(sem==0)
        cout<<"Nu aveti nicio tranzactie in ziua "<<data2<<endl;
}

int main(){
    string data,tip;
    for(;;){
        string nr="0";
        if(nr=="0"){
            cout<<"1: Efectuati o tranzactie"<<endl;
            cout<<"2: Afisati numarul de tranzactii"<<endl;
            cout<<"3: Afisati toate tranzactiile"<<endl;
            cout<<"4: Afisati toate tranzactiile in functie de suma"<<endl;
            cout<<"5: Afisati toate tranzactiile dintr-o zi anume"<<endl;
            cout<<"6: Afisati toate tranzactiile de un tip"<<endl;
            cout<<"7: Iesire"<<endl;
            cin>>nr;
        }
        if(nr=="1"){
            cout<<"Introduceti data tranzactiei: " ;
            cin>>data;
            try{
                dataValida(data);
            }
            catch(const char *s){
                cout<<s;
                continue;
            }
            cout<<"Tipul tranzactiei: ";
            cin>>tip;
            adaugaTranzactie(tip,data);
        }
        else
            if(nr=="2"){
                if(tranzactie::get_nr_tranzactii()>1)
                    cout<<"Ati efectuat "<<tranzactie::get_nr_tranzactii()<<" tranzactii."<<endl;
                if(tranzactie::get_nr_tranzactii()==1)
                    cout<<"Ati efectuat "<<tranzactie::get_nr_tranzactii()<<" tranzactie."<<endl;
                if(tranzactie::get_nr_tranzactii()==0)
                    cout<<"Nu ati efectuat nicio tranzactie inca."<<endl;
            }
            else
                if(nr=="3"){
                    if(tranzactie::get_nr_tranzactii()!=0)
                        afiseazaTranzactii();
                    else{
                        cout<<"Nu aveti nicio tranzactie inca"<<endl;
                        continue;
                    }
                }
                else
                    if(nr=="4"){
                        int suma2,nr2;
                        cout<<"Introduceti suma dorita: ";
                        cin>>suma2;
                        cout<<endl;
                        cout<<"1: Afisati tranzactiile cu suma mai mica decat: "<<suma2<<endl;
                        cout<<"2: Afisati tranzactiile cu suma mai mare decat: "<<suma2<<endl;
                        cout<<"3: Afisati tranzactiile cu suma egala cu      : "<<suma2<<endl;
                        cin>>nr2;
                        if(nr2==1)
                            sumaMica(suma2);
                        if(nr2==2)
                            sumaMare(suma2);
                        if(nr2==3)
                            sumaEgala(suma2);

                    }
                    else
                        if(nr=="5"){
                            cout<<"Introduceti data dorita: ";
                            string data2;
                            cin>>data2;
                            cout<<endl;
                            afiseazaDupaData(data2);
                        }
                        else
                            if(nr=="6"){
                                string tipTranzactie;
                                cout<<"Ce tip de tranzactii doriti sa afisati? "<<endl;
                                cin>>tipTranzactie;
                                if(tipTranzactie=="cash")
                                    tranzactiiCash.afiseazaVectorDeTranzactii();
                                if(tipTranzactie=="card")
                                    tranzactiiCard.afiseazaVectorDeTranzactii();
                                if(tipTranzactie=="cec")
                                    tranzactiiCec.afiseazaVectorDeTranzactii();
                            }
                            else
                                if(nr=="7"){
                                    cout<<"%---------------------------%\n%  Va multumim. O zi buna!  %\n%---------------------------%";
                                    break;
                                }
                                else{
                                    cout<<"Invalid"<<endl;
                                }
    }
}
