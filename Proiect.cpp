/*

DE FACUT: 
-> functie sortare modulara x
-> afisare completa    x
-> stergere client     x
-> adaugare client     x
-> editare client
-> search client
-> search carte
-> exit

*/

#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

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

void clrscr()
{
    system("@cls||clear");
}

void afisare(client CLIENT[100], int n)
{
    int i;
    char x[10];
    for (i = 0; i < n; i++)
    {
        cout << "===== " << CLIENT[i].nume << " =====" << endl;
        cout << "COD CLIENT: " << CLIENT[i].cod << endl;
        cout << "VARSTA: " << CLIENT[i].varsta << endl << endl;
        cout << "TITLU CARTE: " << CARTE[i].titlu << endl;
        cout << "AUTOR: " << CARTE[i].autor << endl;
        cout << "TIP CARTE: " << CARTE[i].tip << endl;
        cout << "TIMP RAMAS: " << CARTE[i].timp << " zile" << endl << endl << endl << endl << endl;
    }
    cin.get();
    cin.getline(x,2);
    SHOWCONDITION = 0;
}

void editare_varsta(client CLIENT[100], int n)
{
    int i;
    char x[10], numeclient[30];
    cout << "Al carui client doriti sa schimbati numele? " << endl << endl;
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

void editare_titlu(client CLIENT[100], int n)
{
    int i, conditie = 1;
    char x[10];
    char titlucarte[30], titlunoucarte[30];
    cout << "Al carui client doriti sa schimbati numele? " << endl << endl;
    cin.get();
    cin.getline(titlucarte,29);
    for (i = 0; i < n; i++)
    {
        if (strcasecmp(titlucarte,CLIENT[i].carte_client->titlu) == 0)
        {
            cout << "Introduceti titlu al cartii." << endl << endl;
            cin.getline(titlunoucarte,29);
            strcpy(CLIENT[i].nume,titlunoucarte);
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

void editare_nume(client CLIENT[100], int n)
{
    int i, conditie = 1;
    char x[10];
    char numeclient[30], numenouclient[30];
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
    cout << "CONDITIE = " << conditie << endl;
    if (conditie != 0)
    {
        cout << endl << endl;
        cout << "Nu s-a putut gasi niciun client cu acest nume." << endl;
        cin.getline(x,2);
        SHOWCONDITION = 0;
    }     
}

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

void stergere_client(client CLIENT[100], int &n)
{
    int i, k, j;
    char x[51];
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
    cout << "Ce client doriti sa eliminati?" << endl << endl;
    cin.get();
    cin.getline(x,49);
    for (k = 0; k < n; k++)
        if (strcasecmp(CLIENT[k].nume,x) == 0)
            for (i = k; i <= n; i++)
            {
                strcpy(CLIENT[i].nume,CLIENT[i+1].nume);
                CLIENT[i] = CLIENT[i+1];
            }
    n--;
}

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
    cout << "#   [6] Main Menu                  #" << endl;
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

        case 2:

        case 3:

        case 4:

        case 5:
        clrscr();
        SHOWCONDITION = 1;
        break;
        case 6:
        SHOWCONDITION = 0;
        break;
    }
}


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
        case 2:
        clrscr();
        editare_varsta(CLIENT,n);
        SHOWCONDITION = 0;
        case 3:
        clrscr();
        show_editcarte_menu();
        SHOWCONDITION = 0;
        case 4:
        SHOWCONDITION = 0;
        break;
    }
}


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
        stergere_client(CLIENT,n);
        SHOWCONDITION = 0;
        break;
        case 3:
        clrscr();
        show_edit_menu();
        case 4:
        SHOWCONDITION = 0;
        break;
    }
}

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
    cout << endl; // aici tb clrscr flush
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

void show_main_menu()
{
    int choice_menu;
    cout << "=============== MENU ===============" << endl;
    cout << "#                                  #" << endl;
    cout << "#  [1] Sortare                     #" << endl;
    cout << "#  [2] Afisare Clienti             #" << endl;
    cout << "#  [3] Gestionare Clienti          #" << endl;
    cout << "#  [4] Cautare                     #" << endl;
    cout << "#  [5] Exit                        #" << endl;
    cout << "#                                  #" << endl;
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

        case 5:
        clrscr();
        exit(0);
    }

}




int main()
{
    int i;
    cout << "Cati ologi vreti sa introduceti? " << endl << endl;
    cin >> n;
    clrscr();
    cin.get();
    for (i = 0; i < n; i++)
        cin.getline(CLIENT[i].nume,100);
    cout << endl << endl;
    //SHOWCONDITION este variabla ce rezolva problema cu functii ce se apeleaza una pe alta
    //SHOWCONDITION 0: Show Main Menu
    //SHOWCONDITION 1: Show Edit Menu
    while (SHOWCONDITION == 0)
    {
        clrscr();
        SHOWCONDITION = -1;
        show_main_menu();
    }
    while (SHOWCONDITION == 1)
    {
        clrscr();
        SHOWCONDITION = -1;
        show_edit_menu();
    }
    
}