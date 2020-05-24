#include <iostream>
#include <fstream>
using namespace std;
int palindromy=0, parzyste=0, nieparzyste=0, w, x, a, aaa;
string s;
fstream znaki, odpowiedz;
bool sprawdz (string s)
{
    int dl=s.size();
    for (int i=0; i<dl/2; i++)
    if (s[i]!=s[dl-i-1])
    return false;
    return true;}

void sprawdznad()
{
    znaki.open("dane.txt", ios::in);
    while (znaki.good())
    {
        znaki>>s;
        if(sprawdz(s)==true && s[0]=='D')
        {
            cout<<s<<endl; odpowiedz<<s<<endl;
            palindromy++;
        }
    }
    znaki.close();}
void sprawdzileparzystych()
{
znaki.open("dane.txt", ios::in);
while (znaki.good())
{
znaki>>s;
if(sprawdz(s)==true)
    {
    a=s.length();
    if (a%2==0) parzyste++;
    else nieparzyste++;
    }
    }
    znaki.close();
    }
bool sprawdz3a (string s)
{
    znaki.open("dane.txt", ios::in);
    while (znaki.good())
    {
    znaki>>s;
    aaa=0;
    int dl=s.size();
    for (int i=0; i<dl; i++)
    {if(s[i]=='A') aaa++;}
    if(aaa>=3 && sprawdz(s)==true) {{cout<<s<<endl; odpowiedz<<s<<endl;}; a++;}}
    znaki.close();}
int main()
{
    cout<<"Aby sprawdzic palindromy zaczynajace sie na pierwsza litere imienia Dariusz wybierz 1"<<endl;
    cout<<"Aby dowiedziec sie ile jest palindromow z parzysta liczba znakow, a ile z nieparzysta wybierz 2"<<endl;
    cout<<"Aby dowiedziec sie ile jest palindromow, ktore maja conajmniej 3 A wybierz 3"<<endl;
    cout<<"Wprowadz swoj wybor: ";
    cin>>w;
    switch(w)
    {
    case 1:
    odpowiedz.open("odpowiedz.txt", ios::out);
    {cout<<"Wypisane palindromy zaczynajace sie na litere D: "<<endl; odpowiedz<<"Wypisane palindromy zaczynajace sie na litere D: "<<endl;}
    sprawdznad();
    {cout<<"Ilosc palindromow zaczynajacych sie na litere D jak Dariusz: "; odpowiedz<<"Ilosc palindromow zaczynajacych sie na litere D jak Dariusz: ";}
    {cout<<palindromy; odpowiedz<<palindromy;}
    odpowiedz.close();
    break;
    case 2:
    sprawdzileparzystych();
    odpowiedz.open("odpowiedz.txt", ios::out);
    {cout<<"Ilosc palindromow z parzysta liczba znakow: "; odpowiedz<<"Ilosc palindromow z parzysta liczba znakow: ";}
    {cout<<parzyste<<endl; odpowiedz<<parzyste<<endl;}
    {cout<<"Ilosc palindromow z nieparzysta liczba znakow: "; odpowiedz<<"Ilosc palindromow z nieparzysta liczba znakow: ";}
    {cout<<nieparzyste; odpowiedz<<nieparzyste;}
    odpowiedz.close();
    break;
    case 3:
    odpowiedz.open("odpowiedz.txt", ios::out);
    cout<<"Wypisane palindromy z 3 lub wiecej A"<<endl; odpowiedz<<"Wypisane palindromy z 3 lub wiecej A"<<endl;
    sprawdz3a(s);
    odpowiedz<<"Ilosc palindromow z 3 lub wiecej A: "<<a;
    cout<<"Ilosc palindromow z 3 lub wiecej A: "<<a;
    odpowiedz.close();
    break;
    default:
    cout<<"Nie ma takiej opcji w menu!";
    break;
    }
    return 0;
}
