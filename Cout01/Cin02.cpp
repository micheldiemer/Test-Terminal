#include <string>
#include <iostream>
#include <sstream>


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

int main12()
{

    TERM_INIT;

    std::cout << "M?me programme qu'avant\n";
    std::cout << " mais on va vider le buffer avec cin_flush() ? chaque fois \n";
    std::cout << "-----------------------------------------------------------\n";

    std::string saisie;
    std::cout << "Un mot ASCII sans accents ni caract?res sp?ciaux svp :\n";
    std::cin >> saisie;
    std::cout << "vous avez saisi le mot : " << saisie << "\n";
    std::cout << std::endl << std::endl;
    cin_flush();

    std::cout << "Deux mots ASCII sans accents ni caract?res sp?ciaux svp :\n";
    std::cin >> saisie;
    std::cout << "Premier mot : " << saisie << "\n";
    std::cin >> saisie;
    std::cout << " Second mot : " << saisie << "\n";
    std::cout << std::endl << std::endl;
    cin_flush();

    std::cout << "Une phrase compl?te, svp :\n";
    std::cout << "---------------------------------------------------------\n";
    std::cout << "La fonction getline() pemet de saisir une phrase compl?te\n";
    std::cout << "---------------------------------------------------------\n";
    std::getline(std::cin, saisie);
    std::cout << "Votre phrase : " << saisie << "\n";
    std::cout << std::endl << std::endl;
    cin_flush();

    std::cout << std::endl << std::endl;

    TERM_RESET;

    return 0;
}
