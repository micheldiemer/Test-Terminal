#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>


#ifdef _WIN32
#include <windows.h>
#define TERM_INIT int __orgCP = GetConsoleCP();  int __orgOutputCP = GetConsoleOutputCP(); \
    SetConsoleCP(1252); SetConsoleOutputCP(1252);
#define TERM_RESET SetConsoleCP(__orgCP); SetConsoleOutputCP(__orgOutputCP);
#else
#define TERM_INIT ""
#define TERM_RESET ""
#endif

static void cin_flush()
{
    std::string temp;
    std::getline(std::cin, temp);
    /*
    #include <limits>
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    */
}

enum TOUCHE_GENERIQUE
{
    DEFAUT, HAUT, GAUCHE, BAS, DROITE, SPECIAL, FONCTION, CARACTERE, 
    ASCII_CONTROL, BEL, BS, HT, LF, VT, FF, CR, DEL, CTRL_C, CONTROL_KEY
};

typedef struct TOUCHE
{
    TOUCHE_GENERIQUE touche = DEFAUT;
    int caractere = 0;
};

#ifdef _WIN32
#include <conio.h>
#define GETCH _getch
#else
#include <curses.h>
#define GETCH getch
#endif

static TOUCHE term_getKey(bool show)
{
    TOUCHE touche;
    touche.touche = DEFAUT;
    touche.caractere = 0;

    int getch_return = 0;
    std::cout << std::endl << "\x1b[32;40mAppuyez sur une touche pour continuer...\x1b[0m" << std::endl;
    getch_return = GETCH();
    int i = getch_return;

#ifdef _WIN32
    //https://learn.microsoft.com/en-us/previous-versions/visualstudio/visual-studio-2012/078sfkak(v=vs.110)?redirectedfrom=MSDN
    if (getch_return == 0 || getch_return == 0xE0)
    {
        // caractère spécial
        while (getch_return == 0 || getch_return == 0xE0)
            getch_return = GETCH();
        int i = getch_return;
        
        std::string strClavier;

        if(show) std::cout << "Code saisi : 0xE0 " << i << " " << (unsigned int)i << std::endl;
        if (i >= 59 && i <= 69)
        {
            touche.touche = FONCTION;
            strClavier = "F" + (i - 58);
        }
        else
        {
            switch (i)
            {
            case 72:
                touche.touche = HAUT;
                strClavier = "HAUT";
                break;
            case 75:
                touche.touche = GAUCHE;
                strClavier = "GAUCHE";
                break;
            case 77:
                touche.touche = DROITE;
                strClavier = "DROITE";
                break;
            case 80:
                touche.touche = BAS;
                strClavier = "BAS";
                break;
            default:
                touche.touche = SPECIAL;
                strClavier = "SPECIAL";
            }
            
            if(show) std::cout << "Touche          : " << strClavier << std::endl;
            show = false;
        }
        
    }
#endif
    
    
    if(show) std::cout << "Code saisi    : " << i << " " << (unsigned int)i << std::endl;
    if (i < 32)
    {
        touche.touche = CONTROL_KEY;
        if (i == 0x07)
        {
            touche.touche = BEL;
        }
        if (i == 0x03) touche.touche = CTRL_C;
        if (i == 0x08) touche.touche = BS;
        if (i == 0x09) touche.touche = HT;
        if (i == 0x10) touche.touche = LF;
        if (i == 0x0A) touche.touche = VT;
        if (i == 0x0B) touche.touche = FF;
        if (i == 0x0D) touche.touche = CR;
        if (i == 0x7F) touche.touche = DEL;
        if (show)  std::cout << "ASCII_CONTROL : " << std::setw(2) << std::setfill('0') << std::hex << std::uppercase << i << ' ' << std::dec  << i << std::endl;

    }
    else
    {
        touche.touche = CARACTERE;
        touche.caractere = i;
        if (show)  std::cout << "Caractère saisi : " << static_cast<char>(i) << std::endl;
    }
    
    
    return touche;
}


static int term_getch(bool show)
{
    TOUCHE touche;
    do
    {
        touche = term_getKey(show);
    } while (touche.caractere == 0);

    return touche.caractere;
}

void q_pour_quitter()
{
    std::cout << "Taper q pour quitter" << std::endl;

    TOUCHE touche = term_getKey(false);
    while (touche.caractere != 'q')
    {
        if (touche.caractere == 0) std::cout << "C'était un caractère spécial !!!" << std::endl;
        if (touche.caractere > 0) std::cout << "j'ai eu " << touche.caractere << " on continue." << std::endl;
        std::cout << "Taper q pour quitter" << std::endl;
        touche = term_getKey(touche.caractere == 0);
    }
}

bool oui_ou_non_une_seule_touche()
{
    std::cout << "o ou O ou ENTREE c'est OUI sinon c'est non" << std::endl;
    TOUCHE t = term_getKey(false);
    return t.caractere == 'o' || t.caractere == 'O' || t.touche == CR || t.touche == LF;
}

int main14()
{
    TERM_INIT;

    std::cout << "Saisie d'un seul caractère au clavier" << std::endl;
    std::cout << "Sans besoin d'appuyer sur entrée" << std::endl;
    std::cout << std::endl;

    term_getKey(true);
    term_getKey(true);
    term_getKey(true);
    term_getKey(true);
    term_getKey(true);


    std::cout << "éviter q_pour_quitter ?" << std::endl;
    if (!oui_ou_non_une_seule_touche()) q_pour_quitter();

    std::cout << "¯¯¯" << std::endl;
    std::cout << "FIN" << std::endl;
    std::cout << "¯¯¯" << std::endl << std::endl;
    

    TERM_RESET;

    return 0;
}