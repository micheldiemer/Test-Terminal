#include <iostream>

int main02()
{
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Test des 95 caracteres ASCII Imprimables" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" << std::endl;
    std::cout << "0123456789" << std::endl;
    std::cout << "  . : ? ! , ; & | ' ` ~ < > = + % * - $ { } [ ] ( ) / @ # _ ˆ" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Pour afficher un \\ on utilise \\\\" << std::endl;
    std::cout << "Pour afficher un \" on utilise \\\"" << std::endl;
    std::cout << std::endl;

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Teste de quelques caracteres ASCII speciaux" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "                    0123456789 123456789" << std::endl;
    std::cout << " SP Espace        : debut_# #_fin" << std::endl;
    std::cout << "BEL Alarme     \\a : debut_#\a#_fin" << std::endl;
    std::cout << " BS Backspace  \\b : debut_#\b#_fin" << std::endl;
    std::cout << " HT Tabulation \\t : debut_#\t#_fin" << std::endl;
    std::cout << " VT Tab V      \\v : debut_#\v#_fin" << std::endl;
    std::cout << " FF Form Feed  \\f : debut_#\f#_fin" << std::endl;
    std::cout << " CR Carriage R \\r : debut_#\r#_fin" << std::endl;
    std::cout << " LF Line Feed  \\n : debut_#\n#_fin" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "NOTER :" << std::endl;
    std::cout << "\t* BEL, CR, VT et FF fonctionnent en fonction de la console utilisée" << std::endl;
    std::cout << "\t* BEL produit un son " << std::endl;
    std::cout << "\t*  CR revient en position 0 " << std::endl;
    std::cout << "\t*  VT et FF ajoutent une ligne ; rarement utilisé " << std::endl;
    std::cout << "IMPORTANT :" << std::endl;
    std::cout << "\t* On utilisera LF<0A> (Linux) ou bien CRLF<0D0A> (Windows)\n";
    std::cout << "\t  pour les sauts de ligne";
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}
