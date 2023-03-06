/*

Sistem gestionare date clienti si date bibiloteca, cu tot cu un sistem simplu de login/username/password etc.
Din pacate, fiecare user poate avea o singura carte fiindca matricele sunt complicate.

Duta Vlad, Roberto Maciuceanu

(!!! Inca s-ar putea sa fie gandacei prin cod cu referire la sistemul de login, faptul ca o functie se apeleaza pe ea e un mister !!!)


*/

#include "CalcFunctions.cpp" // Custom header file!!!
#include "MenuFunctions.cpp"

using namespace std;

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
    login(userstate);
    switch (userstate)
    {
    case 1:
        clrscr();
        show_main_menu();
        break;
    case 0:
        clrscr();
        showUsermenu();
        break;
    }
}
