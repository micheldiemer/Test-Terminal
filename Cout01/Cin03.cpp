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

static std::string string_to_hex(const std::string s1, int *nbOctets)
{
    std::stringstream ss;
    *nbOctets = 0;
    for (const unsigned char&item : s1)
    {
        ss << std::setw(2) << std::setfill('0') << std::hex << std::uppercase << (int)item << " ";
        (*nbOctets)++;
    }
    *nbOctets *= sizeof(unsigned char);
    return ss.str() + "\n";
}

int main13()
{
    TERM_INIT;

    std::string saisie;
    int nbOctets = -1;

    std::cout << "==============================================================\n";
    std::cout << "| Je suis un perroquet. Je r�p�te tout ce que vous me dites. |\n";
    std::cout << "|                           ---                              |\n";
    std::cout << "|                       TEST UNICODE                         |\n";
    std::cout << "|                                                            |\n";
    std::cout << "|   Sous Windows :                                           |\n";
    std::cout << "|      - pour l'affichage de caract�res Unicode              |\n";
    std::cout << "|             1) activer l'UTF-8 pour le projet              |\n";
    std::cout << "|             2) r�enregistrer le fichier                    |\n";
    std::cout << "|             3) chcp(65001) au lieu de chcp(1252)           |\n";
    std::cout << "|             4) mettre u8 partout pour les cha�nes          |\n";
    std::cout << "|                                                            |\n";
    std::cout << "|      - pour la saisie                                      |\n";
    std::cout << "|             il faut plusieurs r�glages non-triviaux        |\n";
    std::cout << "|                                                            |\n";
    std::cout << "|   Sous MacOS/Linux:                                        |\n";
    std::cout << "|      � tester selon le terminal                            |\n";
    std::cout << "|                                                            |\n";
    std::cout << "==============================================================\n";
    std::cout << "\n\n";

    std::cout << "Je suis un perroquet. Je r�p�te tout ce que vous me dites.\n";
    std::cout << "      * Je re�ois des donn�es binaires que je transforme en caract�res\n";
    std::cout << "      * J'essaye de r�p�ter dans votre langue\n";
    std::cout << "      * Parfois je n'y arrive pas trop\n";
    std::cout << "          donc je vous donne aussi les donn�es dans ma langue, en hexad�cimal\n";
    std::cout << "          pour vous aider � comprendre pourquoi je n'ai pas compris\n";
    std::cout << "\n";
    std::cout << "Je suis un perroquet. Je r�p�te tout ce que vous me dites.\n";
    std::cout << "Suis-je un perroquet fid�le :\n";
    std::cout << "    * pour les accents ISO-8859-15/windows 1252 ��� No�l c�ur ?\n";
    std::cout << "    * pour les caract�res Unicode BMP <U+0000-U+D7FF U+E000-U+FFFD> ?\n";
    std::cout << "    * pour les autres caract�res Unicode, dont les emoji ?\n";
    std::cout << "\n\n";
    std::cout << "Une phrase avec des caract�res accentu�s svp :\n";
    std::getline(std::cin, saisie);
    std::cout << "\n";
    std::cout << "           je r�p�te : " << saisie << "\n";
    std::cout << "          majuscules : " << std::uppercase << saisie << "\n";
    std::cout << "          minuscules : " << std::tolower << saisie << "\n";
    std::cout << " quantit� de donn�es : " << saisie.size() << "\n";
    std::cout << "             en hexa : " << string_to_hex(saisie, &nbOctets) << "\n";
    std::cout << "              octets : " << nbOctets << "\n";
    std::cout << "\n";

    std::cout << "Une autre avec des caract�res Unicode comme <= U+2264 :\n";
    std::getline(std::cin, saisie);
    std::cout << "\n";
    std::cout << "           je r�p�te : " << saisie << "\n";
    std::cout << " quantit� de donn�es : " << saisie.size() << "\n";
    std::cout << "             en hexa : " << string_to_hex(saisie, &nbOctets) << "\n";
    std::cout << "              octets : " << nbOctets << "\n";
    std::cout << "\n";

    std::cout << "Une autre avec un emoji, par exemple lol U+1F602 :\n";
    std::getline(std::cin, saisie);
    std::cout << "\n";
    std::cout << "           je r�p�te : " << saisie << "\n";
    std::cout << " quantit� de donn�es : " << saisie.size() << "\n";
    std::cout << "             en hexa : " << string_to_hex(saisie, &nbOctets) << "\n";
    std::cout << "              octets : " << nbOctets << "\n";
    std::cout << "\n";

    std::cout << "Une autre avec un drapeau par exemple FR = U+1F1EB U+1F1F7 :\n";
    std::getline(std::cin, saisie);
    std::cout << "\n";
    std::cout << "           je r�p�te : " << saisie << "\n";
    std::cout << " quantit� de donn�es : " << saisie.size() << "\n";
    std::cout << "             en hexa : " << string_to_hex(saisie, &nbOctets) << "\n";
    std::cout << "              octets : " << nbOctets << "\n";
    std::cout << "\n";

    TERM_RESET;

    return 0;
}