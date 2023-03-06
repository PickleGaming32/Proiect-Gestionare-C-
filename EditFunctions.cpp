#include <iostream>
#include <cstring>
#include <windows.h>
#include <fstream>
#include <ctime>

#pragma warning(disable: 4996)

struct USER {
    char* username = new char();
    char* password = new char();
};

USER mainuser;
USER* user = new USER[100];

struct carte {
    char titlu[256];
    char tip[256];
    char autor[256];
    int timp;
};

struct client {
    char nume[256];
    int varsta;
    int cod;
    carte carte_client[100];
};

// x este numarul de utilizatori cu tot cu parole

int n, x;
client CLIENT[100];
carte CARTE[100];


// Functie ce sterge ecranul
void clrscr()
{
    system("@cls||clear");
}



// Functie ce afiseaza toate datele despre fiecare client in mod vertical
void afisare(client CLIENT[100], int n)
{
    int i;
    char x[10];
    for (i = 0; i < n; i++)
    {
        cout << "===== " << CLIENT[i].nume << " =====" << endl;
        cout << "COD CLIENT: " << CLIENT[i].cod << endl;
        cout << "VARSTA: " << CLIENT[i].varsta << " ani" << endl << endl;
        cout << "TITLU CARTE: " << CARTE[i].titlu << endl;
        cout << "AUTOR: " << CARTE[i].autor << endl;
        cout << "TIP CARTE: " << CARTE[i].tip << endl;
        cout << "TIMP RAMAS: " << CARTE[i].timp << " zile" << endl << endl << endl << endl << endl;
    }
    cin.get();
    cin.getline(x, 2);
}

// Functie ce adauga un client. Odata ce utilizatorul este intrebat de carte, se poate raspunde "Da" (case insensitive)
// pentru a adauga o carte atasata clientului, impreuna cu toate datele necesare
void adaugare_client(client CLIENT[100], int& n)
{
    int y, i;
    y = rand();
    for (i = 0; i < n; i++)
        if (CLIENT[i].cod == y)
            y++;
    char rasp[10];
    cin.get();
    cout << "Introduceti numele noului client: ";
    cin.getline(CLIENT[n].nume, 100);
    cout << "Introduceti varsta noului client: ";
    cin >> CLIENT[n].varsta;
    CLIENT[n].cod = y;
    cin.get();
    cout << "Detine clientul vreo carte? ";
    cin.getline(rasp, 9);
    if (stricmp(rasp, "Da") == 0)
    {
        cout << "Introduceti titlul cartii: ";
        cin.getline(CARTE[n].titlu, 100);
        cout << "Introduceti autorul cartii: ";
        cin.getline(CARTE[n].autor, 100);
        cout << "Introduceti tipul cartii: ";
        cin.getline(CARTE[n].tip, 100);
        cout << "Introduceti data returului [z/l/a] \n";
        cin >> CARTE[n].timp;
        n++;
    }
    else
    {
        strcpy(CARTE[n].titlu, "N/A");
        strcpy(CARTE[n].autor, "N/A");
        strcpy(CARTE[n].tip, "N/A");
        CARTE[n].timp = 0;
        n++;
    }
}

// Functie ce elimina un client impreuna cu toate datele sale. Se aplica si n--
void stergere_client(client CLIENT[100], int& n)
{
    int i, k, j, conditie = 0;
    char select[51];
    for (j = 0; j < n; j++)
    {
        cout << "===== " << CLIENT[j].nume << " =====" << endl;
        cout << "COD CLIENT: " << CLIENT[j].cod << endl;
        cout << "VARSTA: " << CLIENT[j].varsta << " ani" << endl << endl;
        cout << "TITLU CARTE: " << CARTE[j].titlu << endl;
        cout << "AUTOR: " << CARTE[j].autor << endl;
        cout << "TIP CARTE: " << CARTE[j].tip << endl;
        cout << "TIMP RAMAS: " << CARTE[j].timp << " zile" << endl << endl << endl;
    }
    cout << endl << endl;
    cout << "Ce client doriti sa eliminati?" << endl << endl;
    cin.get();
    cin.getline(select, 49);
    for (k = 0; k < n; k++)
        if (stricmp(CLIENT[k].nume, select) == 0)
        {
            for (i = k; i <= n; i++)
            {
                strcpy(CLIENT[i].nume, CLIENT[i + 1].nume);
                CLIENT[i] = CLIENT[i + 1];
                user[i] = user[i + 1];
            }
            x--;
            n--;
            conditie = 1;
        }
    if (conditie == 1)
    {
        cout << endl << endl << "Succes! Datele clientului '" << x << "' au fost eliminate." << endl << endl;
        system("Pause");
    }
    if (conditie == 0)
    {
        cout << endl << endl << "Nu s-a putut gasi un client cu acest nume." << endl << endl;
        system("Pause");
    }

}

// Functie ce permite modificarea numelui unui client
void editare_nume(client CLIENT[100], int n)
{
    int i, conditie = 1, j;
    char x[10];
    char numeclient[30], numenouclient[30];
    for (j = 0; j < n; j++)
    {
        cout << "===== " << CLIENT[j].nume << " =====" << endl;
        cout << "COD CLIENT: " << CLIENT[j].cod << endl;
        cout << "VARSTA: " << CLIENT[j].varsta << " ani" << endl << endl;
        cout << "TITLU CARTE: " << CARTE[j].titlu << endl;
        cout << "AUTOR: " << CARTE[j].autor << endl;
        cout << "TIP CARTE: " << CARTE[j].tip << endl;
        cout << "TIMP RAMAS: " << CARTE[j].timp << " zile" << endl << endl << endl;
    }
    cout << endl << endl;
    cout << "Al carui client doriti sa schimbati numele? " << endl << endl;
    cin.get();
    cin.getline(numeclient, 29);
    for (i = 0; i < n; i++)
    {
        if (stricmp(numeclient, CLIENT[i].nume) == 0)
        {
            cout << "Introduceti noul nume al clientului." << endl << endl;
            cin.getline(numenouclient, 29);
            strcpy(CLIENT[i].nume, numenouclient);
            conditie = 0;
        }
    }
    if (conditie == 0)
    {
        cout << endl << "Succes! Numele clientului a fost modificat." << endl;
        system("Pause");
    }
    if (conditie != 0)
    {
        cout << endl << endl;
        cout << "Nu s-a putut gasi niciun client cu acest nume." << endl;
        cin.get();
        cin.getline(x, 2);
    }
}

// Functie ce permite editarea codului de identificare a unui client. Din pacate functia rand() nu este random.
void editare_cod(client CLIENT[100], int n)
{
    int i;
    char numeclient[30], j;
    for (j = 0; j < n; j++)
    {
        cout << "===== " << CLIENT[j].nume << " =====" << endl;
        cout << "COD CLIENT: " << CLIENT[j].cod << endl;
        cout << "VARSTA: " << CLIENT[j].varsta << endl << endl;
        cout << "TITLU CARTE: " << CARTE[j].titlu << endl;
        cout << "AUTOR: " << CARTE[j].autor << endl;
        cout << "TIP CARTE: " << CARTE[j].tip << endl;
        cout << "TIMP RAMAS: " << CARTE[j].timp << " zile" << endl << endl << endl;
    }
    cout << endl << endl;
    cout << "Al carui client doriti sa schimbati codul de identificare? " << endl << endl;
    cin.get();
    cin.getline(numeclient, 29);
    for (i = 0; i < n; i++)
    {
        if (stricmp(numeclient, CLIENT[i].nume) == 0)
        {
            cout << "Introduceti noul cod al clientului. " << endl << endl;
            cin >> CLIENT[i].cod;
        }
    }
}

// Functie ce modifica varsta unui client (CLIENT[i].varsta)
void editare_varsta(client CLIENT[100], int n)
{
    int i;
    char numeclient[30], j;
    for (j = 0; j < n; j++)
    {
        cout << "===== " << CLIENT[j].nume << " =====" << endl;
        cout << "COD CLIENT: " << CLIENT[j].cod << endl;
        cout << "VARSTA: " << CLIENT[j].varsta << endl << endl;
        cout << "TITLU CARTE: " << CARTE[j].titlu << endl;
        cout << "AUTOR: " << CARTE[j].autor << endl;
        cout << "TIP CARTE: " << CARTE[j].tip << endl;
        cout << "TIMP RAMAS: " << CARTE[j].timp << " zile" << endl << endl << endl;
    }
    cout << endl << endl;
    cout << "Al carui client doriti sa schimbati varsta? " << endl << endl;
    cin.get();
    cin.getline(numeclient, 29);
    for (i = 0; i < n; i++)
    {
        if (stricmp(numeclient, CLIENT[i].nume) == 0)
        {
            cout << "Introduceti noua varsta a clientului. " << endl << endl;
            cin >> CLIENT[i].varsta;
        }
    }
}

// Functie ce permite utilizatorul sa modifice titlul unei carti (CARTE[i].titlu)
// Cautarea si modificarea se fac dupa numele cartii de modificat
void editare_titlu(client CLIENT[100], int n)
{
    int i, conditie = 1, j;
    char x[10];
    char titlucarte[30], titlunoucarte[30];
    for (j = 0; j < n; j++)
    {
        cout << "===== " << CLIENT[j].nume << " =====" << endl;
        cout << "COD CLIENT: " << CLIENT[j].cod << endl;
        cout << "VARSTA: " << CLIENT[j].varsta << " ani" << endl << endl;
        cout << "TITLU CARTE: " << CARTE[j].titlu << endl;
        cout << "AUTOR: " << CARTE[j].autor << endl;
        cout << "TIP CARTE: " << CARTE[j].tip << endl;
        cout << "TIMP RAMAS: " << CARTE[j].timp << " zile" << endl << endl << endl;
    }
    cout << endl << endl;
    cout << "Al carei carti doriti sa schimbati numele?" << endl << endl;
    cin.get();
    cin.getline(titlucarte, 29);
    for (i = 0; i < n; i++)
    {
        if (stricmp(titlucarte, CARTE[i].titlu) == 0)
        {
            cout << "Introduceti titlu al cartii." << endl << endl;
            cin.getline(titlunoucarte, 29);
            strcpy(CARTE[i].titlu, titlunoucarte);
            conditie = 0;
        }
    }
    if (conditie != 0)
    {
        cout << endl << endl;
        cout << "Nu s-a putut gasi o carte cu acest titlu." << endl;
        cin.getline(x, 2);
    }
}

// Functie ce permite utilizatorul sa modifice autorul (CARTE[i].autor)
// Cautarea si modificarea se face dupa numele cartii de modificat
void editare_autor(client CLIENT[100], int n)
{
    int i, conditie = 1, j;
    char x[10];
    char autorcarte[30], autornoucarte[30];
    for (j = 0; j < n; j++)
    {
        cout << "===== " << CLIENT[j].nume << " =====" << endl;
        cout << "COD CLIENT: " << CLIENT[j].cod << endl;
        cout << "VARSTA: " << CLIENT[j].varsta << " ani" << endl << endl;
        cout << "TITLU CARTE: " << CARTE[j].titlu << endl;
        cout << "AUTOR: " << CARTE[j].autor << endl;
        cout << "TIP CARTE: " << CARTE[j].tip << endl;
        cout << "TIMP RAMAS: " << CARTE[j].timp << " zile" << endl << endl << endl;
    }
    cout << endl << endl;
    cout << "Al carei carti doriti sa schimbati autorul?" << endl << endl;
    cin.get();
    cin.getline(autorcarte, 29);
    for (i = 0; i < n; i++)
    {
        if (stricmp(autorcarte, CARTE[i].titlu) == 0)
        {
            cout << "Introduceti autorul cartii." << endl << endl;
            cin.getline(autornoucarte, 29);
            strcpy(CARTE[i].autor, autornoucarte);
            conditie = 0;
        }
    }
    cout << "CONDITIE = " << conditie << endl;
    if (conditie == 1)
    {
        cout << endl << endl;
        cout << "Nu s-a putut gasi o carte cu acest titlu." << endl;
        cin.getline(x, 2);
    }
}

// Functie ce permite modificarea timpul ramas pentru returnarea cartii (CARTE[i].timp)
// Cautarea cartii se face dupa titlul ei.
void editare_timp(client CLIENT[100], int n)
{
    int i, conditie = 1, timpnoucarte, j;
    char x[10];
    char titlucarte[30];
    for (j = 0; j < n; j++)
    {
        cout << "===== " << CLIENT[j].nume << " =====" << endl;
        cout << "COD CLIENT: " << CLIENT[j].cod << endl;
        cout << "VARSTA: " << CLIENT[j].varsta << " ani" << endl << endl;
        cout << "TITLU CARTE: " << CARTE[j].titlu << endl;
        cout << "AUTOR: " << CARTE[j].autor << endl;
        cout << "TIP CARTE: " << CARTE[j].tip << endl;
        cout << "TIMP RAMAS: " << CARTE[j].timp << " zile" << endl << endl << endl;
    }
    cout << endl << endl;
    cout << "Al carei carti doriti sa schimbati timpul?" << endl << endl;
    cin.get();
    cin.getline(titlucarte, 29);
    for (i = 0; i < n; i++)
    {
        if (stricmp(titlucarte, CARTE[i].titlu) == 0)
        {
            cout << "Introduceti timpul cartii." << endl << endl;
            cin >> timpnoucarte;
            CARTE[i].timp = timpnoucarte;
            conditie = 0;
        }
    }
    if (conditie != 0)
    {
        cout << endl << endl;
        cout << "Nu s-a putut gasi o carte cu acest titlu." << endl;
        cin.getline(x, 2);
    }
}

// Functie ce permite modificarea tipului (genului) de carte.
// Cautarea cartii se face dupa titlul ei.
void editare_tip(client CLIENT[100], int n)
{
    int i, conditie = 1, j;
    char x[10];
    char titlucarte[30], tipnoucarte[30];
    for (j = 0; j < n; j++)
    {
        cout << "===== " << CLIENT[j].nume << " =====" << endl;
        cout << "COD CLIENT: " << CLIENT[j].cod << endl;
        cout << "VARSTA: " << CLIENT[j].varsta << " ani" << endl << endl;
        cout << "TITLU CARTE: " << CARTE[j].titlu << endl;
        cout << "AUTOR: " << CARTE[j].autor << endl;
        cout << "TIP CARTE: " << CARTE[j].tip << endl;
        cout << "TIMP RAMAS: " << CARTE[j].timp << " zile" << endl << endl << endl;
    }
    cout << endl << endl;
    cout << "Al carei carti doriti sa schimbati tipul?" << endl << endl;
    cin.get();
    cin.getline(titlucarte, 29);
    for (i = 0; i < n; i++)
    {
        if (stricmp(titlucarte, CARTE[i].titlu) == 0)
        {
            cout << "Introduceti tipul cartii." << endl << endl;
            cin.getline(tipnoucarte, 29);
            strcpy(CARTE[i].tip, tipnoucarte);
            conditie = 0;
        }
    }
    cout << "CONDITIE = " << conditie << endl;
    if (conditie != 0)
    {
        cout << endl << endl;
        cout << "Nu s-a putut gasi o carte cu acest titlu." << endl;
        cin.getline(x, 2);
    }
}

// Functie ce sorteaza dar nu afiseaza toti clientii si datele acestora in ordine alfabetica
void sort_nume(client CLIENT[100], int n)
{
    int i, j;
    client CLIENT_TEMP;
    USER TEMP_USER;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (strcmp(CLIENT[i].nume, CLIENT[j].nume) > 0)
            {
                strcpy(CLIENT_TEMP.nume, CLIENT[i].nume);
                CLIENT_TEMP = CLIENT[i];
                strcpy(CLIENT[i].nume, CLIENT[j].nume);
                CLIENT[i] = CLIENT[j];
                strcpy(CLIENT[j].nume, CLIENT_TEMP.nume);
                CLIENT[j] = CLIENT_TEMP;
                TEMP_USER = user[i];
                user[i] = user[j];
                user[j] = TEMP_USER;
            }
}

// Functie ce sorteaza dar nu afiseaza toti clientii si datele acestora in ordine crescatoare, dupa codul de client
void sort_cod(client CLIENT[100], int n)
{
    int i, j;
    client CLIENT_TEMP;
    USER TEMP_USER;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (CLIENT[i].cod > CLIENT[j].cod)
            {
                strcpy(CLIENT_TEMP.nume, CLIENT[i].nume);
                CLIENT_TEMP = CLIENT[i];
                strcpy(CLIENT[i].nume, CLIENT[j].nume);
                CLIENT[i] = CLIENT[j];
                strcpy(CLIENT[j].nume, CLIENT_TEMP.nume);
                CLIENT[j] = CLIENT_TEMP;
                TEMP_USER = user[i];
                user[i] = user[j];
                user[j] = TEMP_USER;
            }
}

// Functie ce sorteaza dar NU  afiseaza toti clientii dupa timpul ramas de retur, in ordine crescatoare
void sort_timp(client CLIENT[100], int n)
{
    int i, j;
    client CLIENT_TEMP;
    USER TEMP_USER;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (CLIENT[i].carte_client->timp > CLIENT[j].carte_client->timp)
            {
                strcpy(CLIENT_TEMP.nume, CLIENT[i].nume);
                CLIENT_TEMP = CLIENT[i];
                strcpy(CLIENT[i].nume, CLIENT[j].nume);
                CLIENT[i] = CLIENT[j];
                strcpy(CLIENT[j].nume, CLIENT_TEMP.nume);
                CLIENT[j] = CLIENT_TEMP;
                TEMP_USER = user[i];
                user[i] = user[j];
                user[j] = TEMP_USER;
            }
}

// Functie ce cauta SI afiseaza toate datele despre un client anume.
void search_carte(client CLIENT[100], int n)
{
    int i, conditie = 0, j;
    char x[10], cartecautata[41];
    for (j = 0; j < n; j++)
    {
        cout << "===== " << CLIENT[j].nume << " =====" << endl;
        cout << "COD CLIENT: " << CLIENT[j].cod << endl;
        cout << "VARSTA: " << CLIENT[j].varsta << endl << endl;
        cout << "TITLU CARTE: " << CARTE[j].titlu << endl;
        cout << "AUTOR: " << CARTE[j].autor << endl;
        cout << "TIP CARTE: " << CARTE[j].tip << endl;
        cout << "TIMP RAMAS: " << CARTE[j].timp << " zile" << endl << endl << endl;
    }
    cout << endl << endl;
    cout << "Introduceti titlul cartii cautate: " << endl << endl;
    cin.get();
    cin.getline(cartecautata, 40);
    for (i = 0; i < n; i++)
    {
        if (stricmp(cartecautata, CARTE[i].titlu) == 0)
        {
            clrscr();
            cout << "===== " << CLIENT[i].nume << " =====" << endl;
            cout << "COD CLIENT: " << CLIENT[i].cod << endl;
            cout << "VARSTA: " << CLIENT[i].varsta << " ani" << endl << endl;
            cout << "TITLU CARTE: " << CARTE[i].titlu << endl;
            cout << "AUTOR: " << CARTE[i].autor << endl;
            cout << "TIP CARTE: " << CARTE[i].tip << endl;
            cout << "TIMP RAMAS: " << CARTE[i].timp << " zile" << endl << endl;
            conditie = 1;
        }
    }
    if (conditie == 0)
    {
        cout << "Nu s-a putut gasi o carte cu acest titlu." << endl << endl;
    }
    cin.getline(x, 2);
}

// Functie ce cauta SI afiseaza toate datele despre un client anume
void search_client(client CLIENT[100], int n)
{
    int i, conditie = 0, j;
    char x[10], clientcautat[41];
    for (j = 0; j < n; j++)
    {
        cout << "===== " << CLIENT[j].nume << " =====" << endl;
        cout << "COD CLIENT: " << CLIENT[j].cod << endl;
        cout << "VARSTA: " << CLIENT[j].varsta << endl << endl;
        cout << "TITLU CARTE: " << CARTE[j].titlu << endl;
        cout << "AUTOR: " << CARTE[j].autor << endl;
        cout << "TIP CARTE: " << CARTE[j].tip << endl;
        cout << "TIMP RAMAS: " << CARTE[j].timp << " zile" << endl << endl << endl;
    }
    cout << endl << endl;
    cout << "Introduceti numele clientului cautat: " << endl << endl;
    cin.get();
    cin.getline(clientcautat, 40);
    for (i = 0; i < n; i++)
    {
        if (stricmp(clientcautat, CLIENT[i].nume) == 0)
        {
            clrscr();
            cout << "===== " << CLIENT[i].nume << " =====" << endl;
            cout << "COD CLIENT: " << CLIENT[i].cod << endl;
            cout << "VARSTA: " << CLIENT[i].varsta << " ani" << endl << endl;
            cout << "TITLU CARTE: " << CARTE[i].titlu << endl;
            cout << "AUTOR: " << CARTE[i].autor << endl;
            cout << "TIP CARTE: " << CARTE[i].tip << endl;
            cout << "TIMP RAMAS: " << CARTE[i].timp << " zile" << endl << endl;
            conditie = 1;
        }
    }
    if (conditie == 0)
    {
        cout << "Nu s-a putut gasi un client cu acest nume." << endl << endl;
    }
    cin.getline(x, 2);
}

// Functie ce compara, ca numere intregi, aparitiile titlurilor cartilor din data de baza.
// Daca numarul de aparitii este egal la doua titluri ale carti diferite nu se arata un raspuns concret.
void statistic_titlu(client CLIENT[100], int n)
{
    int i, j, ok = 0, maxx = 0, save;
    cin.get();
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
            if (stricmp(CARTE[i].titlu, CARTE[j].titlu) == 0)
                ok++;

        if (maxx < ok)
        {
            maxx = ok;
            save = i;
        }
        else
        {
            if (maxx == ok)
                maxx = 0;
        }
        ok = 0;
    }
    if (maxx != 0)
        cout << endl << "Cartea cea mai citita este " << CARTE[save].titlu << ".";
    else
        cout << "Exista carti egal citite in data de baza.";

    cout << endl << endl;
    system("Pause");
}

// Functie ce compara, ca numere intregi, aparitiile tipurilor cartilor din data de baza.
// Daca numarul de aparitii este egal la doua tipuri diferite nu se arata un raspuns concret.
void statistic_tip(client CLIENT[100], int n)
{
    int i, j, ok = 0, maxx = 0, save;
    cin.get();
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
            if (stricmp(CARTE[i].tip, CARTE[j].tip) == 0)
                ok++;

        if (maxx < ok)
        {
            maxx = ok;
            save = i;
        }
        else
        {
            if (maxx == ok)
                maxx = 0;
        }
        ok = 0;
    }
    if (maxx != 0)
        cout << endl << "Tipul de carte cea mai citita este de tip " << CARTE[save].tip << ".";
    else
        cout << "Exista carti citite in cantitate egala de tipuri diferite in data de baza.";

    cout << endl << endl;
    system("Pause");
}

// Functie ce compara, ca numere intregi, aparitiile numelor autorilor din data de baza.
// Daca numarul de aparitii este egal la doi autori diferiti nu se arata un raspuns concret
void statistic_autor(client CLIENT[100], int n)
{
    int i, j, ok = 0, maxx = 0, save;
    cin.get();
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
            if (stricmp(CARTE[i].autor, CARTE[j].autor) == 0)
                ok++;

        if (maxx < ok)
        {
            maxx = ok;
            save = i;
        }
        else
        {
            if (maxx == ok)
                maxx = 0;
        }
        ok = 0;
    }
    if (maxx != 0)
        cout << endl << "Cartea cea mai citita este scrisa de autorul " << CARTE[save].autor << ".";
    else
        cout << "Exista carti scrise de acelasi autor egal citite in data de baza.";

    cout << endl << endl;
    system("Pause");
}

// Functie ce returneaza un numar de tip float (rational). Aduna valoarea varstelor tuturor clientilor din data de baza
// si returneaza media generala.
void statistic_varsta(client CLIENT[100], int n)
{
    float result = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        result = result + CLIENT[i].varsta;
    }
    result = result / i;
    cout << "Varsta medie a tuturor clientilor este de " << result << " ani." << endl << endl;
    system("Pause");
}

void encrypt()
{
    int i;
    char input[1000];
    cout << "Introduceti textul pe care doriti sa il criptati: " << endl;
    cin.get();
    cin.getline(input, 999);
    cout << endl;
    for (i = 0; i < strlen(input); i++)
        tolower(input[i]);
    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] == 122)
            input[i] = 97;
        else
            input[i]++;
    }
    cout << endl;
    cout << "Text criptat: " << input << endl;
    system("Pause");
}

void decrypt()
{
    int i;
    char input[1000];
    cout << "Introduceti textul pe care doriti sa il decriptati: " << endl;
    cin.get();
    cin.getline(input, 999);
    cout << endl;
    for (i = 0; i < strlen(input); i++)
        tolower(input[i]);
    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] == 97)
            input[i] = 122;
        else
            input[i]--;
    }
    cout << endl;
    cout << "Text decriptat: " << input << endl;
    system("Pause");
}

// Luat de pe net, nu scris de mine (obv). Nu am nicio idee de ce merge dar arata smecher
// Modificat doar pentru a permite durata custom a animatiei.
void spinning_donut()
{
    int end;
    cout << "Set duration for animation: ";
    cin >> end;
    int gleebus;
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];
    printf("\x1b[2J");
    for (gleebus = 0; gleebus <= end; gleebus++) {
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for (j = 0; j < 6.28; j += 0.07) {
            for (i = 0; i < 6.28; i += 0.02) {
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[H");
        for (k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);
            A += 0.00004;
            B += 0.00002;
        }
        Sleep(30);
    }
}

// Functie ce face o pseudo-stergere a datelor clientilor. Mai exact face ca datele care nu sunt overwritten cu alte date sa fie "N/A" in caz
// de afisare fara editare/adaugare client.
void clear_data(client CLIENT[100], int& n)
{
    int i;
    char x[10], y[10];
    cout << R"(                                                         c=====e
                                                            H
   ____________                                         _,,_H__
  (__((__((___()                                       //|     |
 (__((__((___()()_____________________________________// |ACME |
(__((__((___()()()------------------------------------'  |_____|)" << endl << endl;
    cout << "Are you sure? This cannot be undone!" << endl;
    cin.get();
    cin.getline(x, 4);
    cout << endl << endl;
    if (stricmp(x, "Yes") == 0)
    {
        cout << "Are you REALLY sure?" << endl;
        cin.getline(y, 4);
        if (stricmp(y, "Yes") == 0)
        {
            cout << "3... " << endl;
            Sleep(630);
            cout << "2... " << endl;
            Sleep(630);
            cout << "1... " << endl;
            Sleep(630);
            cout << "BOOM!" << endl;
            Sleep(550);
            clrscr();
            cout << R"(                               ________________
                          ____/ (  (    )   )  \___
                         /( (  (  )   _    ))  )   )\
                       ((     (   )(    )  )   (   )  )
                     ((/  ( _(   )   (   _) ) (  () )  )
                    ( (  ( (_)   ((    (   )  .((_ ) .  )_
                   ( (  )    (      (  )    )   ) . ) (   )
                  (  (   (  (   ) (  _  ( _) ).  ) . ) ) ( )
                  ( (  (   ) (  )   (  ))     ) _)(   )  )  )
                 ( (  ( \ ) (    (_  ( ) ( )  )   ) )  )) ( )
                  (  (   (  (   (_ ( ) ( _    )  ) (  )  )   )
                 ( (  ( (  (  )     (_  )  ) )  _)   ) _( ( )
                  ((  (   )(    (     _    )   _) _(_ (  (_ )
                   (_((__(_(__(( ( ( |  ) ) ) )_))__))_)___)
                   ((__)        \\||lll|l||///          \_))
                            (   /(/ (  )  ) )\   )
                          (    ( ( ( | | ) ) )\   )
                           (   /(| / ( )) ) ) )) )
                         (     ( ((((_(|)_)))))     )
                          (      ||\(|(|)|/||     )
                        (        |(||(||)||||        )
                          (     //|/l|||)|\\ \     )
                        (/ / //  /|//||||\\  \ \  \ _))";
            cout << endl << endl << endl;
            for (i = 0; i < n; i++)
            {
                strcpy(CARTE[i].titlu, "N/A");
                strcpy(CARTE[i].autor, "N/A");
                strcpy(CARTE[i].tip, "N/A");
                CARTE[i].timp = 0;
            }
            n = 0;
            Sleep(1100);
            cout << "Done. All client data cleared." << endl << endl;
            system("Pause");
        }
        else
        {
            cout << endl << "Returning to menu..." << endl << endl;
            system("Pause");
        }
    }
    else
    {
        cout << endl << "Returning to menu..." << endl << endl;
        system("Pause");
    }
}




