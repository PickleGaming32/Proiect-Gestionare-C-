#include "FileFunctions.cpp"
#include <windows.h>

#pragma warning(disable: 4996)

void show_sort_menu();
void show_secret_menu();
void show_statistic_menu();
void gestionare_show_menu();
void show_search_menu();
void show_edit_menu();
void show_editcarte_menu();
void show_code_menu();

// Main menu. Self-explanatory
void show_main_menu()
{
    int choice_menu;
    clrscr();
    cout << "=============== MENU =============== \n";
    cout << "#                                  # \n";
    cout << "#  [1] Sortare                     # \n";
    cout << "#  [2] Afisare Clienti             # \n";
    cout << "#  [3] Gestionare Clienti          # \n";
    cout << "#  [4] Cautare                     # \n";
    cout << "#  [5] Statistics                  # \n";
    cout << "#  [6] Exit                        # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#  [0] Extra                       # \n";
    cout << "#                                  # \n";
    cout << "==================================== \n \n";
    cin >> choice_menu;
    switch (choice_menu)
    {
    case 1:
        clrscr();
        show_sort_menu();
        break;
    case 2:
        clrscr();
        afisare(CLIENT, n);
        show_main_menu();
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
        read();
        exit(0);
        break;
    case 5:
        clrscr();
        show_statistic_menu();
        break;
    case 0:
        clrscr();
        show_secret_menu();
        break;
    }
}

// Meniu pentru accesarea functiilor adaugare_client, stergere_client. Se poate accesa si submeniul de editare_client etc.
void gestionare_show_menu()
{
    int choice_submenu;
    cout << "========= Gestionare Client ======== \n";
    cout << "#                                  # \n";
    cout << "#   [1] Adaugare Client            # \n";
    cout << "#   [2] Stergere Client            # \n";
    cout << "#   [3] Editare Client             # \n";
    cout << "#   [4] Back                       # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "==================================== \n \n";
    cin >> choice_submenu;
    switch (choice_submenu)
    {
    case 1:
        clrscr();
        adaugare_client(CLIENT, n);
        clrscr();
        gestionare_show_menu();
        break;
    case 2:
        clrscr();
        stergere_client(CLIENT, n);
        clrscr();
        gestionare_show_menu();
        break;
    case 3:
        clrscr();
        show_edit_menu();
        break;
    case 4:
        clrscr();
        show_main_menu();
        break;
    }
}

// Meniu prin care se acceseaza toate functiile sort_nume/cod/timp.
void show_sort_menu()
{
    int choice_submenu;
    cout << "=============== SORT =============== \n";
    cout << "#                                  # \n";
    cout << "#    DUPA:                         # \n";
    cout << "#                                  # \n";
    cout << "#   [1] Nume Client                # \n";
    cout << "#   [2] Cod Client                 # \n";
    cout << "#   [3] Timp Ramas Imprumut        # \n";
    cout << "#   [4] Back                       # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "==================================== \n \n";
    cin >> choice_submenu;
    switch (choice_submenu)
    {
    case 1:
        clrscr();
        sort_nume(CLIENT, n);
        afisare(CLIENT, n);
        show_sort_menu();
        break;
    case 2:
        clrscr();
        sort_cod(CLIENT, n);
        afisare(CLIENT, n);
        show_sort_menu();
        break;
    case 3:
        clrscr();
        sort_timp(CLIENT, n);
        afisare(CLIENT, n);
        show_sort_menu();
        break;
    case 4:
        clrscr();
        show_main_menu();
        break;
    }
}

// Meniu pentru accesarea functiile editare_nume, editare_varsta, si show_editcarte.
void show_edit_menu()
{
    int choice_submenu;
    cout << "========== Editare Client ========== \n";
    cout << "#                                  # \n";
    cout << "#   [1] Editare Nume               # \n";
    cout << "#   [2] Editare Varsta             # \n";
    cout << "#   [3] Editare Carte              # \n";
    cout << "#   [4] Editare Cod                # \n";
    cout << "#   [5] Back                       # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "==================================== \n \n";
    cin >> choice_submenu;
    switch (choice_submenu)
    {
    case 1:
        clrscr();
        editare_nume(CLIENT, n);
        clrscr();
        show_edit_menu();
        break;
    case 2:
        clrscr();
        editare_varsta(CLIENT, n);
        clrscr();
        show_edit_menu();
        break;
    case 3:
        clrscr();
        show_editcarte_menu();
        clrscr();
        show_edit_menu();
        break;
    case 5:
        clrscr();
        gestionare_show_menu();
        break;
    case 4:
        clrscr();
        editare_cod(CLIENT, n);
        clrscr();
        show_edit_menu();
        break;
    }
}

// Meniu pentru accesare functiilor editare_titlu, editare_tip, editare_autor, editare_timp.
void show_editcarte_menu()
{
    int choice_submenu;
    cout << "========== Editare  Carte ========== \n";
    cout << "#                                  # \n";
    cout << "#   [1] Editare Titlu              # \n";
    cout << "#   [2] Editare Autor              # \n";
    cout << "#   [3] Editare Tip                # \n";
    cout << "#   [4] Editare Timp Ramas         # \n";
    cout << "#   [5] Back                       # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "==================================== \n \n";
    cin >> choice_submenu;
    switch (choice_submenu)
    {
    case 1:
        clrscr();
        editare_titlu(CLIENT, n);
        clrscr();
        show_editcarte_menu();
        break;
    case 2:
        clrscr();
        editare_autor(CLIENT, n);
        clrscr();
        show_editcarte_menu();
        break;
    case 3:
        clrscr();
        editare_tip(CLIENT, n);
        clrscr();
        show_editcarte_menu();
        break;
    case 4:
        clrscr();
        editare_timp(CLIENT, n);
        clrscr();
        show_editcarte_menu();
        break;
    case 5:
        clrscr();
        show_edit_menu();
        break;
    }
}

// Meniu pentru accesarea functiilor search_client si search_carte.
void show_search_menu()
{
    int choice_submenu;
    cout << "============== Search ============== \n";
    cout << "#                                  # \n";
    cout << "#   [1] Search Client              # \n";
    cout << "#   [2] Search Carte               # \n";
    cout << "#   [3] Back                       # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "==================================== \n \n";
    cin >> choice_submenu;
    switch (choice_submenu)
    {
    case 1:
        clrscr();
        search_client(CLIENT, n);
        clrscr();
        show_search_menu();
        break;
    case 2:
        clrscr();
        search_carte(CLIENT, n);
        clrscr();
        show_search_menu();
        break;
    case 3:
        clrscr();
        show_main_menu();
        break;
    }
}

void show_secret_menu()
{
    int choice_submenu;
    cout << "=============== Extra ============== \n";
    cout << "#                                  # \n";
    cout << "#   [1] Clear All Data             # \n";
    cout << "#   [2] Calculator                 # \n";
    cout << "#   [3] Spinning Donut             # \n";
    cout << "#   [4] Augustus's Code            # \n";
    cout << "#   [5] Back                       # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "==================================== \n \n";
    cin >> choice_submenu;
    switch (choice_submenu)
    {
    case 1:
        clrscr();
        clear_data(CLIENT, n);
        clrscr();
        show_secret_menu();
        break;
    case 2:
        clrscr();
        calcloadingscreen();
        clrscr();
        calcmenu();
        clrscr();
        show_secret_menu();
        break;
    case 3:
        clrscr();
        spinning_donut();
        system("Pause");
        clrscr();
        show_secret_menu();
        break;
    case 4:
        clrscr();
        show_code_menu();
        clrscr();
        show_secret_menu();
        break;
    case 5:
        clrscr();
        show_main_menu();
    }
}

void show_code_menu()
{
    int choice_submenu;
    cout << "============== Search ============== \n";
    cout << "#                                  # \n";
    cout << "#   [1] Encrypt                    # \n";
    cout << "#   [2] Decrypt                    # \n";
    cout << "#   [3] Back                       # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "==================================== \n \n";
    cin >> choice_submenu;
    switch (choice_submenu)
    {
    case 1:
        clrscr();
        encrypt();
        clrscr();
        show_code_menu();
        break;
    case 2:
        clrscr();
        decrypt();
        clrscr();
        show_code_menu();
        break;
    case 3:
        clrscr();
        show_secret_menu();
        break;
    }
}

void show_statistic_menu()
{
    int choice_submenu;
    cout << "============ Statistic ============= \n";
    cout << "#                                  # \n";
    cout << "#   [1] Varsta                     # \n";
    cout << "#   [2] Carte                      # \n";
    cout << "#   [3] Autor                      # \n";
    cout << "#   [4] Tip                        # \n";
    cout << "#   [5] Back                       # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "#                                  # \n";
    cout << "==================================== \n \n";
    cin >> choice_submenu;
    switch (choice_submenu)
    {
    case 1:
        clrscr();
        statistic_varsta(CLIENT, n);
        clrscr();
        show_statistic_menu();
        break;
    case 2:
        clrscr();
        statistic_titlu(CLIENT, n);
        clrscr();
        show_statistic_menu();
        break;
    case 3:
        clrscr();
        statistic_autor(CLIENT, n);
        clrscr();
        show_statistic_menu();
        break;
    case 4:
        clrscr();
        statistic_tip(CLIENT, n);
        clrscr();
        show_statistic_menu();
        break;
    case 5:
        clrscr();
        show_main_menu();
        break;
    }
}

// Loading screen animation. Self-explanatory. (Fluctuatile in viteza progress barurului sunt intentionate)
void loading_screen()
{
    int i, y;
    cout << endl;
    cout << R"($$\                                $$\ $$\
$$ |                               $$ |\__|
$$ |      $$$$$$\   $$$$$$\   $$$$$$$ |$$\ $$$$$$$\   $$$$$$\
$$ |     $$  __$$\  \____$$\ $$  __$$ |$$ |$$  __$$\ $$  __$$\
$$ |     $$ /  $$ | $$$$$$$ |$$ /  $$ |$$ |$$ |  $$ |$$ /  $$ |
$$ |     $$ |  $$ |$$  __$$ |$$ |  $$ |$$ |$$ |  $$ |$$ |  $$ |
$$$$$$$$\\$$$$$$  |\$$$$$$$ |\$$$$$$$ |$$ |$$ |  $$ |\$$$$$$$ |$$\ $$\ $$\
\________|\______/  \_______| \_______|\__|\__|  \__| \____$$ |\__|\__|\__|
                                                     $$\   $$ |
                                                     \$$$$$$  |
                                                      \______/

)";
    for (i = 0; i < 74; i++)
    {
        y = 1 + (rand() % 130);
        cout << "=";
        Sleep(y);
    }
    cout << " \n \n Succes! \n \n";
    system("Pause");
}
