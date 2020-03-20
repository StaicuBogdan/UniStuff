#include <iostream>

using namespace std;

class Matrice{
    int mat[100][100];
    int m,n;
public:
    Matrice(int x=0,int nr_linii=1,int nr_col=1);
    void Citire_matrice();
    void Afisare_matrice();
    void Reactualizare_matrice(int x,int nr_linii,int nr_col);
    friend void Citire_n_obiecte(int n,Matrice v[]);
};

Matrice::Matrice(int x,int nr_linii,int nr_col)
    :m{nr_linii},n{nr_col}{
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                mat[i][j]=x;
}

void Citire_n_obiecte(int n, Matrice v[]){
    for(int i=0;i<=n-1;i++){
        int a,b;cout<<"Dati a:";cin>>a;
        cout<<"dati b";cin>>b;
        Matrice X(0,a,b);
        X.Citire_matrice();
        v[i]=X;
        v[i].Afisare_matrice();
    }
}
void Matrice::Citire_matrice(){
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>mat[i][j];
}

void Matrice::Afisare_matrice(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

void Matrice::Reactualizare_matrice(int x,int nr_linii,int nr_col){
    m=nr_linii;
    n=nr_col;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            mat[i][j]=x;
}

int main(){
    Matrice A(0,4,5);///matrice cu 4 linii,5 coloane, toate elementele == 0
    A.Afisare_matrice();
    Matrice B(4);///matrice cu 1 linie si 1 coloana, singurul element e == 4
    B.Afisare_matrice();
    Matrice C;///matrice construita fara niciun parametru, ramane cu o linie,o coloana si singurul element e 0
    C.Afisare_matrice();
    Matrice D(A);///matrice identica cu prima (A)
    D.Afisare_matrice();
    A.Reactualizare_matrice(15,6,8);///prima matrice modificata dupa parametrii noi, 6 linii, 8 col, elem. ==15
    A.Afisare_matrice();
}
