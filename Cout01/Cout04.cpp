#include <iostream>
#include <iomanip>
#include <string>

#ifdef _WIN32
#include <windows.h>
#define TERM_INIT int __orgCP = GetConsoleCP();  int __orgOutputCP = GetConsoleOutputCP(); \
    SetConsoleCP(1252); SetConsoleOutputCP(1252);
#define TERM_RESET SetConsoleCP(__orgCP); SetConsoleOutputCP(__orgOutputCP);
#else
#define TERM_INIT ""
#define TERM_RESET ""
#endif

int main04()
{

    TERM_INIT; 
    
    std::string s1 = "|_#  Bonjour   #_|";
    std::string s2 = "|_# Au revoir  #_|";

    std::cout << "Afffichage par défaut" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 " << std::endl;
    std::cout << s1 << s2 << std::endl;
    std::cout << std::endl;

    std::cout << "Occuper une certaine largeur avec setw" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 " << std::endl;
    std::cout << std::setw(20) << s1 << std::setw(30) << s2 << std::endl;
    std::cout << std::endl;

    std::cout << "Utiliser une certaine largeur et aligner à gauche ou à droite" << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 " << std::endl;
    std::cout << std::setw(40) << std::left << s1;
    std::cout << std::setw(40) << std::right << s2 << std::endl;
    std::cout << std::endl;

    std::cout << "Et remplir avec setfill" << std::endl;
    std::cout << std::setw(80) << std::setfill('-') << '-' << std::endl;
    std::cout << "123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 " << std::endl;
    std::cout << std::setw(40) << std::setfill('/') << std::left << s1;
    std::cout << std::setw(40) << std::setfill('\\') << std::left << s2 << std::endl;
    std::cout << std::setw(40) << std::setfill('/') << std::right << s1;
    std::cout << std::setw(40) << std::setfill('\\') << std::right << s2 << std::endl;
    std::cout << std::setw(40) << std::setfill('/') << std::right << s1;
    std::cout << std::setw(40) << std::setfill('\\') << std::left << s2 << std::endl;
    std::cout << std::setw(40) << std::setfill('/') << std::left << s1;
    std::cout << std::setw(40) << std::setfill('\\') << std::right << s2 << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    

    TERM_RESET;

    return 0;
}