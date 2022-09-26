#include <iostream>
#ifdef _WIN32
#include <windows.h>
#define TERM_INIT int __orgCP = GetConsoleCP();  int __orgOutputCP = GetConsoleOutputCP(); \
    SetConsoleCP(1252); SetConsoleOutputCP(1252);
#define TERM_RESET SetConsoleCP(__orgCP); SetConsoleOutputCP(__orgOutputCP);
#else
#define TERM_INIT ""
#define TERM_RESET ""
#endif

int main03()
{
    TERM_INIT;

    std::cout << "===============================================" << std::endl;
    std::cout << "Codage du symbole euros, du e accent aigu, etc." << std::endl;
    std::cout << "===============================================" << std::endl << std::endl;
    
    std::cout << "Solution 1 : utiliser UTF-8 et Unicode" << std::endl;
    std::cout << "==========" << std::endl;
    std::cout << "    Inconvenients " << std::endl;
    std::cout << "        * il faut ajuster la configuration de Visual Studio pour chaque projet" << std::endl;
    std::cout << "        * il faut uniliser des fonctionnalités spécifiques sous Windows" << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "Solution 2 : utiliser Windows-1252" << std::endl;
    std::cout << "==========" << std::endl;
    std::cout << std::endl;
    std::cout << "Aujouter quelques lignes de code " << std::endl;
    std::cout << std::endl;
   
    std::cout << "==============================================================================================" << std::endl;
    std::cout << 
R"END(#include <windows.h>
#define TERM_INIT int __orgCP = GetConsoleCP();  int __orgOutputCP = GetConsoleOutputCP(); \
    SetconsoleCp(1252); SetConsoleOutputCP(1252);
#define TERM_RESET SetConsoleCP(__orgCP); SetConsoleOutputCP(__orgOutputCP);
#else
#define TERM_INIT ""
#define TERM_RESET ""
#endif
)END";

    std::cout << R"END(
==============================================================================================
Caractères utilisables en ISO 8859-15 et en Windows 1252 (et aussi en Unicode !!!)
============================================================================================== 
Monnaies    : € ¢ £ ¥
Accents     : ß äëïöüÿ ÄËÏÖÜŸ âêôiôû ÂÊÎÔÛ àèìòù ÀÈÌÒÙ æÆ œŒ çÇ  
Maths       : × ÷ ± ² ³ µ ¼ ½ ¾ °C
Ponctuation : « » § Nº … [… pas en ISO 8859-15]

)END";
    std::cout << "Espace insécable 160 A0 : _#\xA0#_" << std::endl;
    std::cout << "Tiret timide     173 AD : _#\xAD#_" << std::endl;
    std::cout << 
R"END(==============================================================================================

)END";

    TERM_RESET;
    return 0;
}
