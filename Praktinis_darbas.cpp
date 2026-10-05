//
// Created by kulka on 10/1/2026.
//

#include "Praktinis_darbas.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double GBP_Bendras   = 0.8729;
const double GBP_Pirkti    = 0.8600;
const double GBP_Parduoti  = 0.9220;
const double USD_Bendras   = 1.1793;
const double USD_Pirkti    = 1.1460;
const double USD_Parduoti  = 1.2340;
const double INR_Bendras   = 104.6918;
const double INR_Pirkti    = 101.3862;
const double INR_Parduoti  = 107.8546;
int main()
{
    int veiksmas = 0;
    double eur=0;
    cout <<"......................................"<<endl;
    cout <<"Sveiki atvyke i valiuto keitimo menu!"<<endl;
    cout <<"           Kuo galime padeti?        "<<endl;
    cout<<"1.Valutio palyginimo funkcija"<<endl;
    cout<<"2.Euru iskeitimo i valiuta funkcija"<<endl;
    cout<<"3.Valiuto pardavimo i eurus funkcija"<<endl;
    cout<<"4.Iseiti"<<endl;
    cout<<"........................................"<<endl;
    cin>>veiksmas;
    cout << fixed << setprecision(2);
   if (veiksmas <1 || veiksmas > 4)
   {
       cout<<"ivedete neteisinga veiksma"<<endl;
   }
    if (veiksmas == 1)
    {
        int kuval;
        cout<<"iveskite koki valiuta norite palygintis su eurais: "<<endl;
        cout<<"1.GBP"<<endl;
        cout<<"2.USD"<<endl;
        cout<<"3.INR"<<endl;
        cin >> kuval;
        cout<<"iveskite kiek norite palyginti euru?"<<endl;
        cin >>eur;
        double rez=0;
        if (kuval == 1)
        {
            rez=GBP_Bendras*eur;
            cout<<"eurai: "<<eur<<" GBP konvertacija: "<<rez<<endl;
            
        }
        else if (kuval == 2)
        {
            rez=USD_Bendras*eur;
            cout<<"eurai: "<<eur<<" USD konvertacija: "<<rez<<endl;
        }
        else if (kuval == 3)
        {
            rez=INR_Bendras*eur;
            cout<<"eurai: "<<eur<<" INR konvertacija: "<<rez<<endl;
        }
    }
    else if (veiksmas == 2)
    {
        double rez=0;
        int kuval;
        cout <<"I koki valiuta norite iskeisti eurus: "<<endl;
        cout<<"1.GBP"<<endl;
        cout<<"2.USD"<<endl;
        cout<<"3.INR"<<endl;
        cin >> kuval;
        cout<<"Iveskite kiek euru norite iskeisti i valiuta: "<<endl;
        cin >> eur;
        if (kuval == 1)
        {
            rez=GBP_Pirkti*eur;
            cout<<"Euru: "<<eur<<" GBP nupirkta: "<<rez<<endl;
        }
        else if (kuval == 2)
        {
            rez=USD_Pirkti*eur;
            cout<<"Euru: "<<eur<<" USD nupirkta: "<<rez<<endl;
        }
        else if (kuval == 3)
        {
            rez=INR_Pirkti*eur;
            cout<<"Euru: "<<eur<<" INR nupirkta: "<<rez<<endl;
        }
    }
    else if (veiksmas == 3)
    {
        int kuval;
        double rez=0;
        cout<<"Iveskite koki valiuta norite iskeisti i eurus: "<<endl;
        cout<<"1.GBP"<<endl;
        cout<<"2.USD"<<endl;
        cout<<"3.INR"<<endl;
        cin >> kuval;
        cout<<"Iveskite kiek norite valiuto pinigu iskeisti i eurus: "<<endl;
        cin >> eur;
        if (kuval == 1)
        {
            rez=GBP_Parduoti*eur;
            cout<<"valiuto: "<<eur<<" GBP parduota: "<<rez<<endl;
        }
        else if (kuval == 2)
        {
            rez=USD_Parduoti*eur;
            cout<<"valiuto: "<<eur<<" USD parduota: "<<rez<<endl;
        }
        else if (kuval == 3)
        {
            rez=INR_Parduoti*eur;
            cout<<"valiuto: "<<eur<<" INR parduota: "<<rez<<endl;
        }
    }
    else if (veiksmas == 4)
    {
        cout<<"Aciu jog renkatese mus!"<<endl;
    }



}
