//
// Created by kulka on 10/15/2026.
//

#include "Antras_Praktinis_darbas.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main()
{

    int x=1, y=1, z=0;
    string mok[101];
    int veiks=0;
    int mokpazym[101][101];
    int check, kiek=0, mokskaic=0;




    do
    {
        cout<<"______________________________________"<<endl;
        cout<<"pasirinkite ka norite daryti"<<endl;
        cout<<"1. Įvesti mokinį ir jo pažymius."<<endl;
        cout<<"2. Peržiūrėti visų mokinių pažymius."<<endl;
        cout<<"3. Peržiūrėti konkretaus mokinio pažymius."<<endl;
        cout<<"4. Atnaujinti pažymį."<<endl;
        cout<<"5. Apskaičiuoti mokinio vidurkį."<<endl;
        cout<<"6. Pašalinti mokinį."<<endl;
        cout<<"7. Išeiti."<<endl;
        cout<<"______________________________________"<<endl;
        cin>>veiks;
        if (veiks<1 || veiks>7) //ivestas skaicius negali buti didesnis negu 7 arba mazesnis negu 1.
        {
            cout<<"Prasome ivesti teisinga veiksma."<<endl;
            veiks=0; //jeigu vartotojas ivede virs ribu tai yra nunilinamas ir perspejamas.
        }
        if (cin.fail()) //jeigu vartotojas iveda ne skaiciu yra perspejamas ir istrina kas buvo kintamaji
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Prasome nenaudoti raidziu "<<endl;
        }

        if (veiks == 1)
        {
            cin.ignore(10000, '\n'); //uztikrina jog getline neives netinkamai
            do
            {
                cout<<"koks yra jusu mokinio vardas? "<<endl;
                getline(cin,mok[x]);
                if (mok[x].empty()) //jeigu yra iveda tiesiog tarpa arba nieko yra perspejamas vartotojas
                {
                    cout << "Vardas negali buti tuscias. Bandykite dar karta." << endl;
                }
                else if (all_of(mok[x].begin(), mok[x].end(), ::isdigit)) //komanda ::isdigit skaito visa mok[x] simboli po simbolio ieskodama ar bus skaicius ar ne jeigu bus tai sugris "true" jeigu ne tai sugris "false"
                {
                    cout << "Ivedete skaiciu vietoj vardo. Bandykite dar karta." << endl;
                }


            }
            while (mok[x].empty() || all_of(mok[x].begin(), mok[x].end(), ::isdigit)); //jeigu sugrizta "true" ciklas toliau eina prasome ivesti teisinga kintamaji jeigu "false" jis nustos cikla.
            cout<<"praejo sia dali"<<endl;
            z++;
            cout<<"kiek mokinys turi pazymiu?"<<endl;
            cin>>kiek;
            for (int i=1; i<kiek; i++)
            {
                cout<<"iveskite"<<i<<" pazymi"<<endl;
                cin>>mokpazym[x][y];
                y++;
            }

        }
    }
    while (veiks!=7);

}
