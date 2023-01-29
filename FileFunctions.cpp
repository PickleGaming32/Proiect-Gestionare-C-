#include "LoginSystem.cpp"

// Functie ce preia datele tuturor clientilor si le salveaza in fisierul "input.txt".
void read()
{
    int i;
    ofstream f("input.txt");
    f << n << endl;
    for (i = 0; i < n; i++)
    {
        f << CLIENT[i].nume << endl;
        f << CLIENT[i].cod << endl;
        f << CLIENT[i].varsta << endl;
        f << CARTE[i].titlu << endl;
        f << CARTE[i].autor << endl;
        f << CARTE[i].tip << endl;
        f << CARTE[i].timp << endl;
    }
}

