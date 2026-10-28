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
        cout<<"_________Mokiniu skaicius: "<< mokskaic<<"_________"<<endl;
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
            string ivest; //cia laikomas ivestas tekstas, kol patikrinama ar jis yra skaicius
            do
            {
                cout<<"kiek mokinys turi pazymiu?"<<endl;
                getline(cin,ivest);
                if (ivest.empty()) // jeigu nieko neivede yra perspejamas vartotojas
                {
                    cout<<"Kiekis negali buti tuscias. Bandykite dar karta."<<endl;
                }
                else if (!all_of(ivest.begin(), ivest.end(), ::isdigit)) //jeigu bent vienas simbolis ne skaicius, all_of sugris "false", o ! ji pavercia "true"
                {
                    cout<<"prasome ivesti skaiciu."<<endl;
                }
                else if (ivest.length()>2) //daugiau nei 2 skaitmenys yra daugiau nei 99, o tiek pazymiu netelpa i masyva
                {
                    cout<<"Pazymiu gali buti nuo 0 iki 99."<<endl;
                }
            }
            while (ivest.empty() || !all_of(ivest.begin(), ivest.end(), ::isdigit) || ivest.length()>2);
            kiek=stoi(ivest); //stoi pavercia patikrinta teksta i skaiciu
            mokpazym[x][1]=kiek; //[x][1] vietoje saugomas pazymiu kiekis, o patys pazymiai nuo [x][2]
            int temp=0;
            for (int i=1; i<=kiek; i++)
            {
                do
                {
                    cout<<"iveskite "<<i<<" pazymi"<<endl;
                    getline(cin,ivest);
                    if (ivest.empty())
                    {
                        cout<<"Pazymys negali buti tuscias. Bandykite dar karta."<<endl;
                    }
                    else if (!all_of(ivest.begin(), ivest.end(), ::isdigit))
                    {
                        cout<<"prasome ivesti skaiciu."<<endl;
                    }
                    else if (ivest.length()>2 || stoi(ivest)<1 || stoi(ivest)>10) //ilgis tikrinamas pirmas, kad stoi negautu per didelio skaiciaus
                    {
                        cout<<"Pazymys turi buti nuo 1 iki 10."<<endl;
                    }
                }
                while (ivest.empty() || !all_of(ivest.begin(), ivest.end(), ::isdigit) || ivest.length()>2 || stoi(ivest)<1 || stoi(ivest)>10);
                temp=stoi(ivest);
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
                for (int j=2; j<=pazskait+1; j++) //+1 nes pazymiai saugomi nuo [i][2] vietos
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
                    for (int j=2; j<=pazskait+1; j++) //+1 nes pazymiai saugomi nuo [i][2] vietos
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
                else if (all_of(vardas.begin(), vardas.end(), ::isdigit)) //tikrina ar vardas nera vien is skaiciu, kaip 1 punkte
                {
                    cout << "Ivedete skaiciu vietoj vardo. Bandykite dar karta." << endl;
                }
            }
            while (vardas.empty() || all_of(vardas.begin(), vardas.end(), ::isdigit));
            string atsk="False";
            for (int i=1; i<=mokskaic; i++)
            {
                if (vardas==mok[i] && atsk=="False") //atsk=="False" uztikrina, kad bus keiciamas tik pirmas rastas mokinys tokiu vardu
                {
                    atsk="True";
                    pazskait=mokpazym[i][1];
                    if (pazskait==0)
                    {
                        cout<<"Mokinys neturi pazymiu."<<endl;
                    }
                    else
                    {
                        cout<<"mokinio "<<vardas<<" pazymiai: "<<endl;
                        for (int j=2; j<=pazskait+1; j++)
                        {
                            cout<<j-1<<". "<<mokpazym[i][j]<<endl; //j-1 nes pazymiai saugomi nuo 2 vietos, o numeruojami nuo 1
                        }
                        string ivest;
                        int nr=0;
                        do
                        {
                            cout<<"kelinta pazymi norite pakeisti?"<<endl;
                            getline(cin,ivest);
                            if (ivest.empty())
                            {
                                cout<<"Numeris negali buti tuscias. Bandykite dar karta."<<endl;
                            }
                            else if (!all_of(ivest.begin(), ivest.end(), ::isdigit))
                            {
                                cout<<"prasome ivesti skaiciu."<<endl;
                            }
                            else if (ivest.length()>2 || stoi(ivest)<1 || stoi(ivest)>pazskait) //numeris turi buti nuo 1 iki pazymiu kiekio
                            {
                                cout<<"Tokio pazymio nera. Bandykite dar karta."<<endl;
                            }
                        }
                        while (ivest.empty() || !all_of(ivest.begin(), ivest.end(), ::isdigit) || ivest.length()>2 || stoi(ivest)<1 || stoi(ivest)>pazskait);
                        nr=stoi(ivest);
                        int naujas=0;
                        do
                        {
                            cout<<"iveskite nauja pazymi"<<endl;
                            getline(cin,ivest);
                            if (ivest.empty())
                            {
                                cout<<"Pazymys negali buti tuscias. Bandykite dar karta."<<endl;
                            }
                            else if (!all_of(ivest.begin(), ivest.end(), ::isdigit))
                            {
                                cout<<"prasome ivesti skaiciu."<<endl;
                            }
                            else if (ivest.length()>2 || stoi(ivest)<1 || stoi(ivest)>10) //ilgis tikrinamas pirmas, kad stoi negautu per didelio skaiciaus
                            {
                                cout<<"Pazymys turi buti nuo 1 iki 10."<<endl;
                            }
                        }
                        while (ivest.empty() || !all_of(ivest.begin(), ivest.end(), ::isdigit) || ivest.length()>2 || stoi(ivest)<1 || stoi(ivest)>10);
                        naujas=stoi(ivest);
                        mokpazym[i][nr+1]=naujas; //nr+1 nes pazymiai saugomi nuo 2 vietos
                        cout<<"Pazymys pakeistas."<<endl;
                    }
                }
            }
            if (atsk=="False")
            {
                cout<<"Mokinys neegzistuoja."<<endl;
            }
        }
        if (veiks==5)
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
                else if (all_of(vardas.begin(), vardas.end(), ::isdigit)) //tikrina ar vardas nera vien is skaiciu, kaip 1 punkte
                {
                    cout << "Ivedete skaiciu vietoj vardo. Bandykite dar karta." << endl;
                }
            }
            while (vardas.empty() || all_of(vardas.begin(), vardas.end(), ::isdigit));
            string atsk="False";
            for (int i=1; i<=mokskaic; i++)
            {
                if (vardas==mok[i] && atsk=="False")
                {
                    atsk="True";
                    pazskait=mokpazym[i][1];
                    if (pazskait==0) //jeigu pazymiu nera, dalinti is 0 negalima
                    {
                        cout<<"Mokinys neturi pazymiu, vidurkio apskaiciuoti negalima."<<endl;
                    }
                    else
                    {
                        double suma=0; //double, kad dalinant neprarastu skaiciu po kablelio
                        for (int j=2; j<=pazskait+1; j++)
                        {
                            suma=suma+mokpazym[i][j];
                        }
                        double vidurkis=suma/pazskait;
                        cout<<"mokinio "<<vardas<<" vidurkis: "<<vidurkis<<endl;
                    }
                }
            }
            if (atsk=="False")
            {
                cout<<"Mokinys neegzistuoja."<<endl;
            }
        }
        if (veiks==6)
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
                else if (all_of(vardas.begin(), vardas.end(), ::isdigit)) //tikrina ar vardas nera vien is skaiciu, kaip 1 punkte
                {
                    cout << "Ivedete skaiciu vietoj vardo. Bandykite dar karta." << endl;
                }
            }
            while (vardas.empty() || all_of(vardas.begin(), vardas.end(), ::isdigit));
            string atsk="False";
            for (int i=1; i<=mokskaic; i++)
            {
                if (vardas==mok[i] && atsk=="False")
                {
                    atsk="True";
                    string patvirt;
                    do
                    {
                        cout<<"Ar tikrai norite pasalinti mokini "<<vardas<<"? (t/n)"<<endl;
                        getline(cin,patvirt);
                        if (patvirt!="t" && patvirt!="n") //priimama tik t arba n
                        {
                            cout<<"Prasome ivesti t arba n."<<endl;
                        }
                    }
                    while (patvirt!="t" && patvirt!="n");
                    if (patvirt=="t")
                    {
                        for (int k=i; k<mokskaic; k++) //visi po jo esantys mokiniai pasislenka per viena vieta atgal
                        {
                            mok[k]=mok[k+1];
                            pazskait=mokpazym[k+1][1];
                            for (int j=1; j<=pazskait+1; j++) //perkeliamas pazymiu kiekis [k][1] ir visi pazymiai
                            {
                                mokpazym[k][j]=mokpazym[k+1][j];
                            }
                        }
                        mok[mokskaic]=""; //paskutine vieta isvaloma
                        mokskaic--;
                        x--; //x visada rodo i pirma laisva vieta, todel irgi mazinamas
                        cout<<"Mokinys pasalintas."<<endl;
                    }
                    else
                    {
                        cout<<"Mokinys nepasalintas."<<endl;
                    }
                }
            }
            if (atsk=="False")
            {
                cout<<"Mokinys neegzistuoja."<<endl;
            }
        }

    }

    while (veiks!=7);


}