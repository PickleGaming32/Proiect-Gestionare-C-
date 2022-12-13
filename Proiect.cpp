/*
DE FACUT:
-> functie sortare modulara x
-> afisare completa    x
-> stergere client     x
-> adaugare client     x
-> editare client      x
-> editare carte       x
-> search client       x
-> search carte        x
-> exit                x
-> statistici
-> back
-> secret
*/

#include <iostream>
#include <cstring>
#include <string.h>
#include <windows.h>

using namespace std;

// Mentionabil este faptul ca toate datele CLIENT.carte_client->titlu/tip/autor/timp sunt automat aduse in functie odata cu chemarea
// CLIENT[100] ca parametru, doar ca se foloseste sintaxa CARTE.tip/autor/timp pentru accesarea si modificarea datelor
struct carte{
    char titlu[256];
    char tip[256];
    char autor[256];
    int timp;
};

struct client{
    char nume[256];
    int varsta;
    int cod;
    carte carte_client[100];
};

int SHOWCONDITION = 0, n;
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
    cin.getline(x,2);
    SHOWCONDITION = 0;
}



// Functie ce modifica varsta unui client (CLIENT[i].varsta)
void editare_varsta(client CLIENT[100], int n)
{
    int i;
    char x[10], numeclient[30], j;
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
    cin.getline(numeclient,29);
    for (i = 0; i < n; i++)
    {
        if (strcasecmp(numeclient,CLIENT[i].nume) == 0)
        {
            cout << "Introduceti noua varsta a clientului. " << endl << endl;
            cin >> CLIENT[i].varsta;
        }
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
    cin.getline(titlucarte,29);
    for (i = 0; i < n; i++)
    {
        if (strcasecmp(titlucarte,CARTE[i].titlu) == 0)
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
        cin.getline(x,2);
        SHOWCONDITION = 0;
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
    cin.getline(titlucarte,29);
    for (i = 0; i < n; i++)
    {
        if (strcasecmp(titlucarte,CARTE[i].titlu) == 0)
        {
            cout << "Introduceti tipul cartii." << endl << endl;
            cin.getline(tipnoucarte,29);
            strcpy(CARTE[i].tip,tipnoucarte);
            conditie = 0;
        }
    }
    cout << "CONDITIE = " << conditie << endl;
    if (conditie != 0)
    {
        cout << endl << endl;
        cout << "Nu s-a putut gasi o carte cu acest titlu." << endl;
        cin.getline(x,2);
        SHOWCONDITION = 0;
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
	cin.getline(cartecautata,40);
	for (i = 0; i < n; i++)
	{
		if (strcasecmp(cartecautata,CARTE[i].titlu) == 0)
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
	cin.getline(x,2);
    SHOWCONDITION = 0;
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
	cin.getline(clientcautat,40);
	for (i = 0; i < n; i++)
	{
		if (strcasecmp(clientcautat,CLIENT[i].nume) == 0)
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
	cin.getline(x,2);
    SHOWCONDITION = 0;
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
    cin.getline(autorcarte,29);
    for (i = 0; i < n; i++)
    {
        if (strcasecmp(autorcarte,CARTE[i].titlu) == 0)
        {
            cout << "Introduceti autorul cartii." << endl << endl;
            cin.getline(autornoucarte,29);
            strcpy(CARTE[i].autor,autornoucarte);
            conditie = 0;
        }
    }
    cout << "CONDITIE = " << conditie << endl;
    if (conditie == 1)
    {
        cout << endl << endl;
        cout << "Nu s-a putut gasi o carte cu acest titlu." << endl;
        cin.getline(x,2);
        SHOWCONDITION = 0;
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
    cin.getline(titlucarte,29);
    for (i = 0; i < n; i++)
    {
        if (strcasecmp(titlucarte,CARTE[i].titlu) == 0)
        {
            cout << "Introduceti titlu al cartii." << endl << endl;
            cin.getline(titlunoucarte,29);
            strcpy(CARTE[i].titlu,titlunoucarte);
            conditie = 0;
        }
    }
    if (conditie != 0)
    {
        cout << endl << endl;
        cout << "Nu s-a putut gasi o carte cu acest titlu." << endl;
        cin.getline(x,2);
        SHOWCONDITION = 0;
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
    cin.getline(numeclient,29);
    for (i = 0; i < n; i++)
    {
        if (strcasecmp(numeclient,CLIENT[i].nume) == 0)
        {
            cout << "Introduceti noul nume al clientului." << endl << endl;
            cin.getline(numenouclient,29);
            strcpy(CLIENT[i].nume,numenouclient);
            conditie = 0;
        }
    }
    if (conditie == 0)
    {
        cout << endl << "Succes! Numele clientului a fost modificat." << endl;
        system("Pause");
        SHOWCONDITION = 0;
    }
    if (conditie != 0)
    {
        cout << endl << endl;
        cout << "Nu s-a putut gasi niciun client cu acest nume." << endl;
        cin.get();
        cin.getline(x,2);
        SHOWCONDITION = 0;
    }
}

// Functie ce sorteaza dar nu afiseaza toti clientii si datele acestora in ordine alfabetica
void sort_nume(client CLIENT[100], int n)
{
    int i, j;
    client CLIENT_TEMP;
    for (i = 0; i < n - 1; i++)
        for (j = i+1; j < n; j++)
            if (strcmp(CLIENT[i].nume, CLIENT[j].nume) > 0)
            {
                strcpy(CLIENT_TEMP.nume, CLIENT[i].nume);
                CLIENT_TEMP = CLIENT[i];
                strcpy(CLIENT[i].nume, CLIENT[j].nume);
                CLIENT[i] = CLIENT[j];
                strcpy(CLIENT[j].nume, CLIENT_TEMP.nume);
                CLIENT[j] = CLIENT_TEMP;
            }
}

// Functie ce sorteaza dar nu afiseaza toti clientii si datele acestora in ordine crescatoare, dupa codul de client
void sort_cod(client CLIENT[100], int n)
{
    int i, j;
    client CLIENT_TEMP;
    for (i = 0; i < n - 1; i++)
        for (j = i+1; j < n; j++)
            if (CLIENT[i].cod > CLIENT[j].cod)
            {
                strcpy(CLIENT_TEMP.nume, CLIENT[i].nume);
                CLIENT_TEMP = CLIENT[i];
                strcpy(CLIENT[i].nume, CLIENT[j].nume);
                CLIENT[i] = CLIENT[j];
                strcpy(CLIENT[j].nume, CLIENT_TEMP.nume);
                CLIENT[j] = CLIENT_TEMP;
            }
}

// Functie ce sorteaza dar NU  afiseaza toti clientii dupa timpul ramas de retur, in ordine crescatoare
void sort_timp(client CLIENT[100], int n)
{
    int i, j;
    client CLIENT_TEMP;
    for (i = 0; i < n - 1; i++)
        for (j = i+1; j < n; j++)
            if (CLIENT[i].carte_client->timp > CLIENT[j].carte_client->timp)
            {
                strcpy(CLIENT_TEMP.nume, CLIENT[i].nume);
                CLIENT_TEMP = CLIENT[i];
                strcpy(CLIENT[i].nume, CLIENT[j].nume);
                CLIENT[i] = CLIENT[j];
                strcpy(CLIENT[j].nume, CLIENT_TEMP.nume);
                CLIENT[j] = CLIENT_TEMP;
            }
}

// Functie ce elimina un client impreuna cu toate datele sale. Se aplica si n--
void stergere_client(client CLIENT[100], int &n)
{
    int i, k, j, conditie = 0;
    char x[51];
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
    cin.getline(x,49);
    for (k = 0; k < n; k++)
        if (strcasecmp(CLIENT[k].nume,x) == 0)
        {
            for (i = k; i <= n; i++)
            {
                strcpy(CLIENT[i].nume,CLIENT[i+1].nume);
                CLIENT[i] = CLIENT[i+1];
            }
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

// Functie ce adauga un client. Odata ce utilizatorul este intrebat de carte, se poate raspunde "Da" (case insensitive)
// pentru a adauga o carte atasata clientului, impreuna cu toate datele necesare
void adaugare_client(client CLIENT[100], int &n)
{
    int x, y;
    y = rand();
    char rasp[10];
    cin.get();
    cout << "Introduceti numele noului client: ";
    cin.getline(CLIENT[n].nume,100);
    cout << "Introduceti varsta noului client: ";
    cin >> CLIENT[n].varsta;
    CLIENT[n].cod = y;
    cin.get();
    cout << "Detine clientul vreo carte? ";
    cin.getline(rasp,9);
    if (strcasecmp(rasp,"Da") == 0)
    {
        cout << "Introduceti titlul cartii: ";
        cin.getline(CARTE[n].titlu,100);
        cout << "Introduceti autorul cartii: ";
        cin.getline(CARTE[n].autor,100);
        cout << "Introduceti tipul cartii: ";
        cin.getline(CARTE[n].tip,100);
        CARTE[n].timp = 14;
        n++;
    }
    else
        n++;
}

void gigachad()
{
    char x[10];
    cin.getline(x,2);
    SHOWCONDITION = 0;
}

void show_secret_menu()
{
    int choice_submenu;
    cout << "============== Secret ==============" << endl;
    cout << "#                                  #" << endl;
    cout << "#   [1] GigaChad                   #" << endl;
    cout << "#   [2] Editare Autor              #" << endl;
    cout << "#   [3] Editare Tip                #" << endl;
    cout << "#   [4] Editare Timp Ramas         #" << endl;
    cout << "#   [5] Back                       #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "====================================" << endl;
    cout << endl;
    cin >> choice_submenu;
    switch(choice_submenu)
    {
        case 1:
        clrscr();
        gigachad();
        break;
    }
}

// Meniu pentru accesarea functiilor search_client si search_carte.
void show_search_menu()
{
    int choice_submenu;
    cout << "============== Search ==============" << endl;
    cout << "#                                  #" << endl;
    cout << "#   [1] Search Client              #" << endl;
    cout << "#   [2] Search Carte               #" << endl;
    cout << "#   [3] Back                       #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "====================================" << endl;
    cout << endl;
    cin >> choice_submenu;
    switch (choice_submenu)
    {
        case 1:
        clrscr();
        search_client(CLIENT,n);
        break;
        case 2:
        clrscr();
        search_carte(CLIENT,n);
        break;
        case 3:
        clrscr();
        SHOWCONDITION = 0;
        break;
    }
}

// Meniu pentru accesare functiilor editare_titlu, editare_tip, editare_autor, editare_timp.
void show_editcarte_menu()
{
    int choice_submenu;
    cout << "========== Editare  Carte ==========" << endl;
    cout << "#                                  #" << endl;
    cout << "#   [1] Editare Titlu              #" << endl;
    cout << "#   [2] Editare Autor              #" << endl;
    cout << "#   [3] Editare Tip                #" << endl;
    cout << "#   [4] Editare Timp Ramas         #" << endl;
    cout << "#   [5] Back                       #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "====================================" << endl;
    cout << endl;
    cin >> choice_submenu;
    switch (choice_submenu)
    {
        case 1:
        clrscr();
        editare_titlu(CLIENT,n);
        SHOWCONDITION = 0;
        break;
        case 2:
        clrscr();
        editare_autor(CLIENT,n);
        SHOWCONDITION = 0;
        break;
        case 3:
        clrscr();
        editare_tip(CLIENT,n);
        SHOWCONDITION = 0;
        break;
        case 4:
        clrscr();
        editare_timp(CLIENT,n);
        SHOWCONDITION = 0;
        break;
        case 5:
        clrscr();
        SHOWCONDITION = 0;
        break;
    }
}

// Meniu pentru accesarea functiile editare_nume, editare_varsta, si show_editcarte.
void show_edit_menu()
{
    int choice_submenu;
    cout << "========== Editare Client ==========" << endl;
    cout << "#                                  #" << endl;
    cout << "#   [1] Editare Nume               #" << endl;
    cout << "#   [2] Editare Varsta             #" << endl;
    cout << "#   [3] Editare Carte              #" << endl;
    cout << "#   [4] Back                       #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "====================================" << endl;
    cout << endl;
    cin >> choice_submenu;
    switch(choice_submenu)
    {
        case 1:
        clrscr();
        editare_nume(CLIENT,n);
        SHOWCONDITION = 0;
        break;
        case 2:
        clrscr();
        editare_varsta(CLIENT,n);
        SHOWCONDITION = 0;
        break;
        case 3:
        clrscr();
        show_editcarte_menu();
        SHOWCONDITION = 0;
        break;
        case 4:
        SHOWCONDITION = 0;
        break;
    }
}

// Meniu pentru accesarea functiilor adaugare_client, stergere_client. Se poate accesa si submeniul de editare_client etc.
void gestionare_show_menu()
{
    int choice_submenu;
    cout << "========= Gestionare Client ========" << endl;
    cout << "#                                  #" << endl;
    cout << "#   [1] Adaugare Client            #" << endl;
    cout << "#   [2] Stergere Client            #" << endl;
    cout << "#   [3] Editare Client             #" << endl;
    cout << "#   [4] Back                       #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "====================================" << endl;
    cout << endl;
    cin >> choice_submenu;
    switch (choice_submenu)
    {
        case 1:
        clrscr();
        adaugare_client(CLIENT,n);
        SHOWCONDITION = 0;
        break;
        case 2:
        clrscr();
        stergere_client(CLIENT,n);
        SHOWCONDITION = 0;
        break;
        case 3:
        clrscr();
        show_edit_menu();
		 break;
        case 4:
        SHOWCONDITION = 0;
        break;
    }
}

// Meniu prin care se acceseaza toate functiile sort_nume/cod/timp.
void show_sort_menu()
{
    int choice_submenu;
    cout << "=============== SORT ===============" << endl;
    cout << "#                                  #" << endl;
    cout << "#    DUPA:                         #" << endl;
    cout << "#                                  #" << endl;
    cout << "#   [1] Nume Client                #" << endl;
    cout << "#   [2] Cod Client                 #" << endl;
    cout << "#   [3] Timp Ramas Imprumut        #" << endl;
    cout << "#   [4] Back                       #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "====================================" << endl;
    cout << endl;
    cin >> choice_submenu;
    switch (choice_submenu)
    {
        case 1:
        clrscr();
        sort_nume(CLIENT,n);
        afisare(CLIENT,n);
        break;
        case 2:
        clrscr();
        sort_cod(CLIENT,n);
        afisare(CLIENT,n);
        break;
        case 3:
        clrscr();
        sort_timp(CLIENT,n);
        afisare(CLIENT,n);
        break;
        case 4:
        SHOWCONDITION = 0;
        break;
    }
}

// Main menu. Self-explanatory
void show_main_menu()
{
    int choice_menu;
    cout << "=============== MENU ===============" << endl;
    cout << "#                                  #" << endl;
    cout << "#  [1] Sortare                     #" << endl;
    cout << "#  [2] Afisare Clienti             #" << endl;
    cout << "#  [3] Gestionare Clienti          #" << endl;
    cout << "#  [4] Cautare                     #" << endl;
    cout << "#  [5] Secret                      #" << endl;
    cout << "#  [6] Exit                        #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "====================================" << endl;
    cout << endl;
    cin >> choice_menu;
    switch(choice_menu)
    {
        case 1:
        clrscr();
        show_sort_menu();
        break;
        case 2:
        clrscr();
        afisare(CLIENT,n);
        break;
        case 3:
        clrscr();
        gestionare_show_menu();
        break;
        case 4:
        clrscr();
        show_search_menu();
        break;
        case 6:
        clrscr();
        exit(0);
        case 5:
        clrscr();
        show_secret_menu();
        break;
    }
}

int main()
{
    int i;
    cout << "Cati clienti vreti sa introduceti? " << endl << endl;
    cin >> n;
    clrscr();
    cin.get();
    for (i = 0; i < n; i++)
        cin.getline(CLIENT[i].nume,100);
    cout << endl << endl;
    //SHOWCONDITION este variabla ce rezolva problema cu functii ce se apeleaza una pe alta
    //SHOWCONDITION 0: Show Main Menu
    while (SHOWCONDITION == 0)
    {
        clrscr();
        SHOWCONDITION = 1;
        show_main_menu();
    }
}
