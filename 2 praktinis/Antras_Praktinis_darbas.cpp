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
    int pazskait=0;




    do
    {
        cout<<"______________________________________"<<endl;
        cout<<"pasirinkite ka norite daryti"<<endl;
        cout<<"1. ivesti mokini ir jo pazymius."<<endl;
        cout<<"2. Perziureti visu mokiniu pazymius."<<endl;
        cout<<"3. Perziureti konkretaus mokinio pazymius."<<endl;
        cout<<"4. Atnaujinti pazymi."<<endl;
        cout<<"5. Apskaiciuoti mokinio vidurki."<<endl;
        cout<<"6. Pasalinti mokini."<<endl;
        cout<<"7. Iseiti."<<endl;
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
                if (mok[x].empty()) // jeigu yra iveda tiesiog tarpa arba nieko yra perspejamas vartotojas
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
            mokskaic++;
            do
            {
                cout<<"kiek mokinys turi pazymiu?"<<endl;
                cin>>kiek;
                cin.fail();
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"prasome ivesti skaiciu."<<endl;

            }
            while (cin.fail());
            int temp=0;
            for (int i=1; i<=kiek; i++)
            {
                cout<<"iveskite"<<i<<" pazymi"<<endl;
                cin>>temp;
                mokpazym[x][y+1]=temp;
                y++;
            }
            y=1;
            x++; //ka rodytu programa teisinga numeri mokinio visada reikia atimti vieneta.
            veiks=0;

        }
        if (veiks==2)
        {
            cin.ignore(10000, '\n');
            for (int i=1; i<=mokskaic; i++)
            {
                cout<< "mokinys "<<mok[i]<<" turi tiek pazymiu: "<<endl;
                pazskait=mokpazym[i][1];
                for (int j=2; j<=pazskait; j++)
                {
                    cout<< mokpazym[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        if (veiks==3)
        {
            cin.ignore(10000, '\n');
            string vardas;
            do
            {
                cout<<"koks yra jusu mokinio vardas? "<<endl;
                getline(cin,vardas);
                if (vardas.empty()) // jeigu yra iveda tiesiog tarpa arba nieko yra perspejamas vartotojas
                {
                    cout << "Vardas negali buti tuscias. Bandykite dar karta." << endl;
                }
                else if (all_of(vardas.begin(), vardas.end(), ::isdigit)) //komanda ::isdigit skaito visa mok[x] simboli po simbolio ieskodama ar bus skaicius ar ne jeigu bus tai sugris "true" jeigu ne tai sugris "false"
                {
                    cout << "Ivedete skaiciu vietoj vardo. Bandykite dar karta." << endl;
                }
            }
            while (vardas.empty() || all_of(vardas.begin(), vardas.end(), ::isdigit));
            string atsk="False";
            for (int i=1; i<=mokskaic; i++)
            {
                if (vardas==mok[i])
                {
                    cout<<"mokinio "<<vardas<<" pazymiai: "<<endl;
                    pazskait=mokpazym[i][1];
                    for (int j=2; j<=pazskait; j++)
                    {
                        cout<< mokpazym[i][j]<<" ";
                    }
                    atsk="True";
                }

            }
            if (atsk=="False")
            {
                cout<<"Mokinys neegzistuoja."<<endl;
            }
            cout<<endl;
        }
        if (veiks==4)
        {

        }

    }

    while (veiks!=7);


}
