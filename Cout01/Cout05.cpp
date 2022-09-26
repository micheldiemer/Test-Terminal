#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "CP1252_to_UTF8.hpp"

#ifdef _WIN32
#include <windows.h>
#define TERM_INIT int __orgCP = GetConsoleCP();  int __orgOutputCP = GetConsoleOutputCP(); \
    SetConsoleCP(1252); SetConsoleOutputCP(1252);
#define TERM_RESET SetConsoleCP(__orgCP); SetConsoleOutputCP(__orgOutputCP);
#else
#define TERM_INIT ""
#define TERM_RESET ""
#endif

int __nbOctets;

static std::string string_to_hex(const std::string s1, int* nbOctets = &__nbOctets, const std::string between = " ")
{
    std::stringstream ss;
    *nbOctets = 0;
    for (const unsigned char& item : s1)
    {
        ss << std::setw(2) << std::setfill('0') << std::hex << std::uppercase << (int)item << between;
        (*nbOctets)++;
    }
    *nbOctets *= sizeof(unsigned char);
    return ss.str();
}

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
}
    return str;
}

int main()
{
#ifndef _WIN32
    std::cout << "Programme testé sous Windows uniquement" << endl;
    return 0;
#endif

    TERM_INIT;

    std::string ascii_c0, iso_c1, ascii_printable, ascii_extended, test_special;
    for (int i = 0; i < 32; i++)
    {
        if (i > 0 && i != 0X1B && (i<0X07 || i>0X0F)) ascii_c0 += static_cast<char>(i);
        iso_c1 += static_cast<char>(i+128);
    }
    ascii_c0 += "  (non affichés : 00 07 08 09 0A 0B 0C 0D 0F 1F 7F)";


    for (int i = 32; i < 128; i++)
    {
        ascii_printable += static_cast<char>(i);
        ascii_extended += static_cast<char>(i + 128);
    }
    std::string iso_c1_1252 = iso_c1;
    iso_c1_1252[01] = '?'; //Ox81
    iso_c1_1252[13] = '?'; //Ox8D
    iso_c1_1252[15] = '?'; //Ox8F
    iso_c1_1252[16] = '?'; //Ox90
    iso_c1_1252[29] = '?'; //Ox9D

    test_special = " €  é  è  ê  ç  Ç  É  È  Ê     à  À  ô  ï  ù  Ÿ  ÿ";

    std::cout << std::endl;
    std::cout << std::endl;
    
    SetConsoleOutputCP(437);
    std::cout << std::setw(30) << "ASCII printable : ";
    std::cout << ascii_printable << std::endl;

    SetConsoleOutputCP(65001);
    std::cout << std::setw(30) << "ASCII printable UTF-8 : ";
    std::cout << ascii_printable << std::endl;

    std::cout << std::endl;
    

    SetConsoleOutputCP(437);
    std::cout << std::setw(30) << "chcp 437 IBM 437 C0 : ";
    std::cout << ascii_c0 << std::endl;

    SetConsoleOutputCP(850);
    std::cout << std::setw(30) << "chcp 850 IBM 850 C0 : ";
    std::cout << ascii_c0 << std::endl;
    
    SetConsoleOutputCP(10000);
    std::cout << std::setw(30) << "chcp 10000 macRoman C0 : ";
    std::cout << ascii_c0 << std::endl;
    
    SetConsoleOutputCP(1252);
    std::cout << std::setw(30) << "chcp 1252 windows1252 C0 : ";
    std::cout << ascii_c0 << std::endl;
    
    std::cout << std::endl;
    

    SetConsoleOutputCP(437);
    std::cout << std::setw(30) << "chcp 437 IBM 437 C1 : ";
    std::cout << iso_c1 << std::endl;

    SetConsoleOutputCP(850);
    std::cout << std::setw(30) << "chcp 850 IBM 850 C1 : ";
    std::cout << iso_c1 << std::endl;

    SetConsoleOutputCP(10000);
    std::cout << std::setw(30) << "chcp 10000 macRoman C1 : ";
    std::cout << iso_c1 << std::endl;

    SetConsoleOutputCP(1252);
    std::cout << std::setw(30) << "chcp 1252 windows1252 C1 : ";
    std::cout << iso_c1_1252 << std::endl;

    std::cout << std::endl;


    SetConsoleOutputCP(437);
    std::cout << std::setw(30) << "chcp 437 IBM 437 EXT. : ";
    std::cout << ascii_extended << std::endl;

    SetConsoleOutputCP(850);
    std::cout << std::setw(30) << "chcp 850 IBM 850 EXT. : ";
    std::cout << ascii_extended << std::endl;

    SetConsoleOutputCP(10000);
    std::cout << std::setw(30) << "chcp 10000 macRoman EXT. : ";
    std::cout << ascii_extended << std::endl;

    SetConsoleOutputCP(1252);
    std::cout << std::setw(30) << "chcp 1252 windows1252 EXT. : ";
    std::cout << ascii_extended << std::endl;

    SetConsoleOutputCP(65001);
    std::cout << std::setw(30) << "chcp 1252 windows1252 EXT. : ";
    std::cout << ascii_extended << std::endl;

    std::cout << std::endl;


    SetConsoleOutputCP(1252);
    std::cout << std::setw(30) << "chcp 1252 windows1252 : ";
    std::cout << test_special << std::endl;

    SetConsoleOutputCP(437);
    std::cout << std::setw(30) << "chcp 437 IBM 437 : ";
    std::cout << test_special << std::endl;

    SetConsoleOutputCP(850);
    std::cout << std::setw(30) << "chcp 850 IBM 850 : ";
    std::cout << test_special << std::endl;

    SetConsoleOutputCP(10000);
    std::cout << std::setw(30) << "chcp 10000 macRoman : ";
    std::cout << test_special << std::endl;


    SetConsoleOutputCP(65001);
    std::cout << std::setw(30) << "chcp 65001 utf-8 : ";
    std::cout << test_special << std::endl;

    SetConsoleOutputCP(1252);
    std::cout << std::setw(30) << "HEXA : ";
    std::string test_special_no_space = ReplaceAll(test_special, " ", "");
    std::cout << string_to_hex(test_special_no_space) << std::endl;

    std::cout << std::endl;

    
    
    size_t loop = test_special_no_space.size();
    std::string utf8_test_special_char ="", utf8string="", utf8_1252="", utf8_hexa="";
    SetConsoleOutputCP(1252);
    for (size_t j = 0; j < loop; j++)
    {
        utf8_test_special_char = CP1252_to_UTF8(test_special_no_space.substr(j, 1));
        utf8_hexa += string_to_hex(utf8_test_special_char, &__nbOctets, "") + " ";
        __nbOctets = 2 * __nbOctets -1;
        while (--__nbOctets)
        {
            utf8string += CP1252_to_UTF8(" ");
        }
        utf8string += utf8_test_special_char + "  ";
        utf8_1252 += "   " + utf8_test_special_char;
    }
    SetConsoleOutputCP(65001);
    std::cout << std::setw(30) << "chcp 65001 utf-8 : " << utf8string << std::endl;
    SetConsoleOutputCP(1252);
    std::cout << std::setw(30) << "chcp 1252 windows1252 : " << utf8_1252 << std::endl;
    std::cout << std::setw(30) << "utf8-hexa : " << utf8_hexa << std::endl;
    
    std::cout << std::endl;    
    std::cout << "chcp 1200 UTF-16 UTF-16LEle\n";
    std::cout << "chcp 1201 unicodeFFFE UTF-16be\n";
    std::cout << "chcp 12000 UTF-32\n";
    std::cout << "chcp 12001 UTF-32BE\n";

    TERM_RESET;
}
