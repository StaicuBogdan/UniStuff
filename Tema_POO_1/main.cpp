#include <iostream>

using namespace std;

class Matrice{
    int mat[100][100];
    int m,n;
public:
    int get_x(int i, int j)const{
        return mat[i][j];
    };
    void set_x(int x,int i,int j){
        mat[i][j]=x;
    };

    Matrice(int x=0,int nr_linii=1,int nr_col=1);
    void Citire_matrice();
    void Afisare_matrice();
    void Reactualizare_matrice(int x,int nr_linii,int nr_col);
    friend void Citire_n_obiecte(int n,Matrice *v);
    Matrice &operator =(const Matrice &A);

    friend Matrice& operator +(const Matrice &A, const Matrice &B);

};

Matrice::Matrice(int x,int nr_linii,int nr_col)
        :m{nr_linii}, n{nr_col}{
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            mat[i][j]=x;
}


void Matrice::Citire_matrice(){
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>mat[i][j];
}

void Matrice::Afisare_matrice()
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

void Matrice::Reactualizare_matrice(int x,int nr_linii,int nr_col)
{
    m=nr_linii;
    n=nr_col;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            mat[i][j]=x;
}
void Citire_n_obiecte(int n, Matrice *v){
    for(int i=0; i<n; i++){
        int a,b;
        cout<<"Dati a:";
        cin>>a;
        cout<<"dati b";
        cin>>b;
        Matrice X(0,a,b);
        X.Citire_matrice();
        v[i]=X;
        v[i].Afisare_matrice();
    }
}
Matrice& Matrice::operator =(const Matrice &A){
    this->m=A.m;
    this->n=A.n;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            this->mat[i][j]=A.get_x(i,j);

}
Matrice& operator +(const Matrice &A, const Matrice &B){
    Matrice *C= new Matrice(A);
    C->m=A.m;
    C->n=A.n;
    for(int i=0;i<A.m;i++){
        for(int j=0;j<A.n;j++){
            int z=C->get_x(i,j)+B.get_x(i,j);
            C->set_x(z,i,j);
        }
    }
    return *C;
}
int main()
{
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
    cout<<endl;
    Matrice v[3];
    Citire_n_obiecte(0,v);

    Matrice X(3,5,5);
    Matrice Z(4,5,5);

    C=X+Z;

    C.Afisare_matrice();


}
