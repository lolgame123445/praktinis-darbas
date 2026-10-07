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
    cout << fixed << setprecision(2);
    do
    {
        cout <<"......................................"<<endl;
        cout <<"Sveiki atvyke i valiuto keitimo menu!"<<endl;
        cout <<"           Kuo galime padeti?        "<<endl;
        cout<<"1.Valutio palyginimo funkcija"<<endl;
        cout<<"2.Euru iskeitimo i valiuta funkcija"<<endl;
        cout<<"3.Valiuto pardavimo i eurus funkcija"<<endl;
        cout<<"4.Iseiti"<<endl;
        cout<<"........................................"<<endl;
        cin>>veiksmas;
        if (veiksmas <1 || veiksmas > 4)
        {
            cout<<"atsiprasome bet veiksmas neegzistuoja musu sistemoje."<<endl;
            continue;
        }


        if (veiksmas == 1)
        {
            int kuval;
            do
            {
                cout<<"pasirinkite valiuto palyginima:"<<endl;
                cout<<"1.GBP"<<endl;
                cout<<"2.USD"<<endl;
                cout<<"3.INR"<<endl;
                cout << "----------------------------------------" << endl;
                cin>>kuval;
                if (kuval <1 || kuval > 3)
                {
                    cout <<"atsiprasome bet tokia valiuta neegzistuoja."<<endl;
                }
            }

            while (kuval < 1 || kuval > 3);

            if (kuval == 1)
            {
                cout << "1 EUR = " << GBP_Bendras << " GBP" << endl;
                cout << "1 GBP = " << (1.0 / GBP_Bendras) << " EUR" << endl;
            }
            else if (kuval == 2)
            {
                cout << "1 EUR = " << USD_Bendras << " USD" << endl;
                cout << "1 USD = " << (1.0 / USD_Bendras) << " EUR" << endl;
            }
            else if (kuval == 3)
            {
                cout << "1 EUR = " << INR_Bendras << " INR" << endl;
                cout << "1 INR = " << (1.0 / INR_Bendras) << " EUR" << endl;
            }
            cout << "----------------------------------------" << endl;
        }
        else if (veiksmas == 2)
        {
            double rez=0;
            int kuval;
            do
            {
                cout <<"I koki valiuta norite iskeisti eurus: "<<endl;
                cout<<"1.GBP"<<endl;
                cout<<"2.USD"<<endl;
                cout<<"3.INR"<<endl;
                cin >> kuval;
                cout<<"Iveskite kiek euru norite iskeisti i valiuta: "<<endl;
                cin >> eur;
                if (kuval <1 || kuval > 3)
                {
                    cout<<"valiutas neegzistuoja rinkites dar karta is naujo."<<endl;
                }
                if (eur < 0)
                {
                    cout << "Ivesta pinigu suma negali buti neigama."<<endl;
                }
            }
            while (kuval < 1 || kuval > 3 || eur < 0);
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
            do
            {
                cout<<"Iveskite koki valiuta norite iskeisti i eurus: "<<endl;
                cout<<"1.GBP"<<endl;
                cout<<"2.USD"<<endl;
                cout<<"3.INR"<<endl;
                cin >> kuval;
                cout<<"Iveskite kiek norite valiuto pinigu iskeisti i eurus: "<<endl;
                cin >> eur;
                if (kuval <1 || kuval > 3)
                {
                    cout<<"Atsiprasome bet toks valiutas neegzistuoja."<<endl;
                }
                if (eur < 0)
                {
                    cout<<"Euru suma negali buti neigiama."<<endl;
                }
            }
            while (kuval < 1 || kuval > 3 || eur < 0);

            if (kuval == 1)
            {
                rez=eur/GBP_Parduoti;
                cout << "Parduota: " << eur << " GBP | Gauta: " << rez << " EUR" << endl;
            }
            else if (kuval == 2)
            {
                rez=eur/USD_Parduoti;
                cout << "Parduota: " << eur << " USD | Gauta: " << rez << " EUR" << endl;
            }
            else if (kuval == 3)
            {
                rez=eur/INR_Parduoti;
                cout << "Parduota: " << eur << " INR | Gauta: " << rez << " EUR" << endl;
            }
        }
        else if (veiksmas == 4)
        {
            cout<<"Aciu jog renkatese mus!"<<endl;
        }
    }
    while (veiksmas!=4);

    return 0;
}
