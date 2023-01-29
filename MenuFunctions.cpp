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
    cout << "=============== MENU ===============" << endl;
    cout << "#                                  #" << endl;
    cout << "#  [1] Sortare                     #" << endl;
    cout << "#  [2] Afisare Clienti             #" << endl;
    cout << "#  [3] Gestionare Clienti          #" << endl;
    cout << "#  [4] Cautare                     #" << endl;
    cout << "#  [5] Statistics                  #" << endl;
    cout << "#  [6] Exit                        #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#                                  #" << endl;
    cout << "#  [0] Extra                       #" << endl;
    cout << "#                                  #" << endl;
    cout << "====================================" << endl;
    cout << endl;
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
    cout << "========== Editare Client ==========" << endl;
    cout << "#                                  #" << endl;
    cout << "#   [1] Editare Nume               #" << endl;
    cout << "#   [2] Editare Varsta             #" << endl;
    cout << "#   [3] Editare Carte              #" << endl;
    cout << "#   [4] Editare Cod                #" << endl;
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
    cout << "=============== Extra ==============" << endl;
    cout << "#                                  #" << endl;
    cout << "#   [1] Clear All Data             #" << endl;
    cout << "#   [2] Calculator                 #" << endl;
    cout << "#   [3] Spinning Donut             #" << endl;
    cout << "#   [4] Augustus's Code            #" << endl;
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
    cout << "============== Search ==============" << endl;
    cout << "#                                  #" << endl;
    cout << "#   [1] Encrypt                    #" << endl;
    cout << "#   [2] Decrypt                    #" << endl;
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
    cout << "============ Statistic =============" << endl;
    cout << "#                                  #" << endl;
    cout << "#   [1] Varsta                     #" << endl;
    cout << "#   [2] Carte                      #" << endl;
    cout << "#   [3] Autor                      #" << endl;
    cout << "#   [4] Tip                        #" << endl;
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
    cout << endl << endl << "Succes!" << endl << endl;
    system("Pause");
}
