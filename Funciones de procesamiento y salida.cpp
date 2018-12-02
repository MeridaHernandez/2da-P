#include <iostream>
using namespace std;
//Merida Hernandez
int segtotal(int hrs, int minu, int seg);
void mostrarhoras(int totalseg);
int main()
{
    int hrs,minu,seg;

    cout<<"HORAS: ";
    cin>>hrs;
    cout<<"MINUTOS: ";
    cin>>minu;
    cout<<"SEGUNDOS: ";
    cin>>seg;

    cout<<" El total de Segundos son: "<<segtotal(hrs,minu,seg)<<" y equivalen a: "<<endl;
    mostrarhoras(segtotal(hrs,minu,seg));

    return 0;
}
void mostrarhoras(int totalseg)
{
    int hrs=0,minu=0, seg=0;
    hrs=totalseg/3600;
    minu=totalseg%3600;
    seg=minu%60;
    minu=minu/60;
    cout<<" Hrs " <<" Min " << " Seg"<<endl;
    cout<<" "<<hrs <<"   " << minu <<"    " <<seg;

}
int segtotal(int hrs, int minu, int seg)
{
    int totalseg=0;
    hrs=hrs*3600;
    minu=minu*60;
    totalseg=hrs+minu+seg;
    return totalseg;
}
