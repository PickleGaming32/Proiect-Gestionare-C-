#include "CalcFunctions.cpp" // Custom header file!!!
#include "LoginSystem.cpp"
#include "MenuFunctions.cpp"

using namespace std;

// Mentionabil este faptul ca toate datele CLIENT.carte_client->titlu/tip/autor/timp sunt automat aduse in functie odata cu chemarea
// CLIENT[100] ca parametru, doar ca se foloseste sintaxa CARTE.tip/autor/timp pentru accesarea si modificarea datelor

int main()
{
    loading_screen();
    ifstream f("input.txt");
    int i;
    f >> n;
    f.get();
    for (i = 0; i < n; i++)
    {
        // Preluarea datelor clientilor din input.txt
        f.getline(CLIENT[i].nume, 99);
        f >> CLIENT[i].cod;
        f >> CLIENT[i].varsta;
        f.get();
        f.getline(CARTE[i].titlu, 49);
        f.getline(CARTE[i].autor, 49);
        f.getline(CARTE[i].tip, 30);
        f >> CARTE[i].timp;
        f.get();
    }
    startupLogin();
    login();
    clrscr();
    show_main_menu();
}
