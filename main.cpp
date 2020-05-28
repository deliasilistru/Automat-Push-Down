#include <fstream>
#include <string>
#include <iostream>
using namespace std;
ifstream fin;
int nrSt, nrAlfSt, nrTr, nrCuv, nrAlf;
char stari[101], stInit, alfIn[101], alfSt[101], InitSt, fcQ[101], fcIn[101], fcSt[101], fcQ2[101];
string cuv, fcSt2[101];

void citire() {
       int i;
    fin >> nrSt; // numarul de stari
    for (i = 0; i < nrSt; i++)
    {
        fin >> stari[i]; //starile
    }

    fin >> nrAlf; //nr de elemente ale alfabetului de intrare
    for (i = 0; i < nrAlf; i++)
    {
        fin >> alfIn[i]; //alfabetul de intrare
    }

    fin >> nrAlfSt; //nr de elemente ale alfabetului stiva
    for (i = 0; i < nrAlfSt; i++)
    {
        fin >> alfSt[i]; //alfabetul stiva
    }

    fin >> stInit; //starea initiala
    fin >> InitSt; //initial in stiva
    fin >> nrTr; //numar tranzitii

    for (i = 0; i < nrTr; i++)
    {
        fin>>fcQ[i]>>fcIn[i]>>fcSt[i]>>fcQ2[i]>>fcSt2[i];
    }
}

int verificare(char stare, string cuv, string stiva) {
    int j;
    string stiva2, s;
    if ((cuv == "")&&(stiva == ""))
        return 1;
    else {
        j = 0;
        while (j<nrTr) {
        if (fcIn[j] == '*') {
        if ((stare==fcQ[j])&&(stiva[0]==fcSt[j]))
        {
        s = stiva.substr(1);
        if (!(fcSt2[j] == "*"))
        stiva2 = fcSt2[j];
        else
        stiva2 = "";
        stiva2 += s;
        if (verificare(fcQ2[j], cuv, stiva2))
        return 1;
        }
        if ((stare==fcQ[j])&&(fcSt[j]=='*')) {
        s = stiva;
        if (!(fcSt2[j] == "*"))
        stiva2 = fcSt2[j];
        else
        stiva2 = "";
        stiva2 += s;
        if (verificare(fcQ2[j], cuv, stiva2))
        return 1;
        }
        }
        if ((stare==fcQ[j])&&(cuv[0]==fcIn[j])&&(fcSt[j]=='*')) {
        s = stiva;
        if (!(fcSt2[j] == "*"))
        stiva2 = fcSt2[j];
        else
        stiva2 = "";
        stiva2 += s;
        if (verificare(fcQ2[j], cuv.substr(1), stiva2))
        return 1;
        }
        if ((stare==fcQ[j])&&(cuv[0]==fcIn[j])&&(stiva[0]==fcSt[j])) {
        s = stiva.substr(1);
        if (fcSt2[j] != "*")
        stiva2 = fcSt2[j];
        else
        stiva2 = "";
        stiva2 += s;
        if (verificare(fcQ2[j], cuv.substr(1), stiva2))
        return 1;
        }
        j++;
        }
    }
    return 0;
}


int main () {
    int i;
    string st;
    fin.open("apd.in");
    citire();
    cin >> nrCuv;
    for (i = 0; i < nrCuv; i++) {
        cin >> cuv;
        st = InitSt;
        if (verificare(stInit, cuv, st))
            cout  << " Cuvantul este acceptat\n";
        else
            cout  << " Cuvantul NU este acceptat\n";
    }

    fin.close();

    return 0;
}
