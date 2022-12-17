#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

float result;

void calcloadingscreen()
{
    cout << R"(

                       .,,uod8B8bou,,.
              ..,uod8BBBBBBBBBBBBBBBBRPFT?l!i:.
         ,=m8BBBBBBBBBBBBBBBRPFT?!||||||||||||||
         !...:!TVBBBRPFT||||||||||!!^^""'   ||||
         !.......:!?|||||!!^^""'            ||||
         !.........||||                     ||||
         !.........||||  ##                 ||||
         !.........||||                     ||||
         !.........||||                     ||||
         !.........||||                     ||||
         !.........||||                     ||||
         `.........||||                    ,||||
          .;.......||||               _.-!!|||||
   .,uodWBBBBb.....||||       _.-!!|||||||||!:'
!YBBBBBBBBBBBBBBb..!|||:..-!!|||||||!iof68BBBBBb....
!..YBBBBBBBBBBBBBBb!!||||||||!iof68BBBBBBRPFT?!::   `.
!....YBBBBBBBBBBBBBBbaaitf68BBBBBBRPFT?!:::::::::     `.
!......YBBBBBBBBBBBBBBBBBBBRPFT?!::::::;:!^"`;:::       `.
!........YBBBBBBBBBBRPFT?!::::::::::^''...::::::;         iBBbo.
`..........YBRPFT?!::::::::::::::::::::::::;iof68bo.      WBBBBbo.
  `..........:::::::::::::::::::::::;iof688888888888b.     `YBBBP^'
    `........::::::::::::::::;iof688888888888888888888b.     `
      `......:::::::::;iof688888888888888888888888888888b.
        `....:::;iof688888888888888888888888888888888899fT!
          `..::!8888888888888888888888888888888899fT|!^"'
            `' !!988888888888888888888888899fT|!^"'
                `!!8888888888888888899fT|!^"'
                  `!988888888899fT|!^"'
                    `!9899fT|!^"'
                      `!^"'

                                All rights reserved HappySoft Tech.
)" << endl << endl;
    cout << "Loading";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << "Done!" << endl << endl;
    system("Pause");
}

float addition()
{
    float x, y;
    cout << "x = ";
    cin >> x;
    cout << endl;
    cout << "y = ";
    cin >> y;
    cout << endl;
    result = x + y;
    return result;
}

float subtraction()
{
    float x, y;
    cout << "x = ";
    cin >> x;
    cout << endl;
    cout << "y = ";
    cin >> y;
    cout << endl;
    result = x - y;
    return result;
}

float multiplication()
{
    float x, y;
    cout << "x = ";
    cin >> x;
    cout << endl;
    cout << "y = ";
    cin >> y;
    cout << endl;
    result = x * y;
    return result;
}

float division()
{
    float x, y;
    cout << "x = ";
    cin >> x;
    cout << endl;
    cout << "y = ";
    cin >> y;
    cout << endl;
    result = x / y;
    return result;
}

float loge()
{
    float x;
    cout << "x = ";
    cin >> x;
    result = log(x);
    return result;
}

float lg()
{
    float x;
    cout << "x = ";
    cin >> x;
    result = log10(x);
    return result;
}

float sinus()
{
    float x;
    cout << "x = ";
    cin >> x;
    result = sin(x*PI/180);
    return result;
}

float cosinus()
{
    float x;
    cout << "x = ";
    cin >> x;
    result = cos(x*PI/180);
    return result;
}

float tangent()
{
    float x;
    cout << "x = ";
    cin >> x;
    result = tan(x*PI/180);
    return result;
}

float arcsin()
{
    float x;
    cout << "x = ";
    cin >> x;
    result = asin(x*PI/180);
    return result;
}

float arccos()
{
    float x;
    cout << "x = ";
    cin >> x;
    result = acos(x*PI/180);
    return result;
}

float arctan()
{
    float x;
    cout << "x = ";
    cin >> x;
    result = atan(x*PI/180);
    return result;
}

float radical()
{
    float x;
    cout << "x = ";
    cin >> x;
    result = sqrt(x);
    return result;
}

float radicalcub()
{
    float x;
    cout << "x = ";
    cin >> x;
    result = cbrt(x);
    return result;
}

float power()
{
    float result,x, y;
    cout << "x = ";
    cin >> x;
    cout << endl;
    cout << "y = ";
    cin >> y;
    result = pow(x,y);
    return result;
}

void calcmenu()
{
    int choice_submenu;
    cout << R"(.-----------------------------.
| # Texax Instruments   TI-82 |
| .-------------------------. |
| |            ./           | |
| |            +            | |
| |. . . . . ./. . . . . . .| |
| |          / .            | |
| | X=5.2   /  .   Y=0      | |
| '-------------------------' |
| [Y=][WIN][ZOOM][TRACE][GRH] |
|                  _ [ ^ ] _  |
| [2nd][MODE][DEL]|_|     |_| |
| [ALP][XTO][STAT]   [ V ]    |
| [MATH][MAT][PGM][VARS][CLR] |
| [x-1] [SIN] [COS] [TAN] [^] |
|  [x2][ , ][ ( ][ ) ][ / ]   |
| [LOG][ 7 ][ 8 ][ 9 ] [ X ]  |
| [LN ][ 4 ][ 5 ][ 6 ] [ - ]  |
| [STO>][ 1 ][ 2 ][ 3 ][ + ]  |
| [ON][ 0 ][ . ][ (-) ][ENTR] |
| ----                        |
'-----------------------------')" << endl << endl;
    cout << "Available functions: " << endl;
    cout << "(1) Addition " << endl;
    cout << "(2) Subtraction " << endl;
    cout << "(3) Multiplication " << endl;
    cout << "(4) Division " << endl;
    cout << "(5) Log e" << endl;
    cout << "(6) Log 10" << endl;
    cout << "(7) sin" << endl;
    cout << "(8) cos" << endl;
    cout << "(9) tan" << endl;
    cout << "(10) arcsin" << endl;
    cout << "(11) arccos" << endl;
    cout << "(12) arctan" << endl;
    cout << "(13) Square Root" << endl;
    cout << "(14) Cube Root" << endl;
    cout << "(15) Raise to power" << endl;
    cout << endl;
    cout << "[0] Exit" << endl << endl;
    cin >> choice_submenu;
    switch (choice_submenu)
    {
    case 1:
    system("@cls||clear");
    addition();
    cout << "REZULTAT = " << result << endl;
    system("Pause");
    system("@cls||clear");
    calcmenu();
    break;
    case 2:
    system("@cls||clear");
    subtraction();
    cout << "REZULTAT = " << result << endl;
    system("Pause");
    system("@cls||clear");
    calcmenu();
    break;
    case 3:
    system("@cls||clear");
    multiplication();
    cout << "REZULTAT = " << result << endl;
    system("Pause");
    system("@cls||clear");
    calcmenu();
    break;
    case 4:
    system("@cls||clear");
    division();
    cout << "REZULTAT = " << result << endl;
    system("Pause");
    system("@cls||clear");
    calcmenu();
    break;
    case 5:
    system("@cls||clear");
    loge();
    cout << "REZULTAT = " << result << endl;
    system("Pause");
    system("@cls||clear");
    calcmenu();
    break;
    case 6:
    system("@cls||clear");
    lg();
    cout << "REZULTAT = " << result << endl;
    system("Pause");
    system("@cls||clear");
    calcmenu();
    break;
    case 7:
    system("@cls||clear");
    sinus();
    cout << "REZULTAT = " << result << endl;
    system("Pause");
    system("@cls||clear");
    calcmenu();
    break;
    case 8:
    system("@cls||clear");
    cosinus();
    cout << "REZULTAT = " << result << endl;
    system("Pause");
    system("@cls||clear");
    calcmenu();
    break;
    case 9:
    system("@cls||clear");
    tangent();
    cout << "REZULTAT = " << result << endl;
    system("Pause");
    system("@cls||clear");
    calcmenu();
    break;
    case 10:
    system("@cls||clear");
    arcsin();
    cout << "REZULTAT = " << result << endl;
    system("Pause");
    system("@cls||clear");
    calcmenu();
    break;
    case 11:
    system("@cls||clear");
    arccos();
    cout << "REZULTAT = " << result << endl;
    system("Pause");
    system("@cls||clear");
    calcmenu();
    break;
    case 12:
    system("@cls||clear");
    arctan();
    cout << "REZULTAT = " << result << endl;
    system("Pause");
    system("@cls||clear");
    calcmenu();
    break;
    case 13:
    system("@cls||clear");
    radical();
    cout << "REZULTAT = " << result << endl;
    system("Pause");
    system("@cls||clear");
    calcmenu();
    break;
    case 14:
    system("@cls||clear");
    radicalcub();
    cout << "REZULTAT = " << result << endl;
    system("Pause");
    system("@cls||clear");
    calcmenu();
    break;
    case 15:
    system("@cls||clear");
    power();
    cout << "REZULTAT = " << result << endl;
    system("Pause");
    system("@cls||clear");
    calcmenu();
    break;
    }
}


