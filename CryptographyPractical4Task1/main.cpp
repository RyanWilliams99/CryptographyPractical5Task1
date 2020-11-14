#include "sha1.h";

#include <ctype.h>      
#include <iostream>     
#include <string>       
#include <vector>    
#include <math.h> 
#include <random>
#include <algorithm>
#include <cctype>

using namespace std;

string password;

bool IsCorrectPassword(string guess, string actualPassword)
{
    SHA1 checksum;
    checksum.update(guess);
    string hash = checksum.final();

    

    return hash.compare(actualPassword) == 0;
}

void Generate(unsigned int length, std::string s)
{
    std::string str("0123456789abcdefghijklmnopqrstuvwxyz");

    if (length == 0) // when length has been reached
    {
        //std::cout << "Trying Password " << s;
        if (IsCorrectPassword(s, password))
        {
            std::cout << "\nFound Correct Password: " << s << "\n";
            exit(0);
        }

        //cout << "\n";
        
        return;
    }

    for (unsigned int i = 0; i < 36; i++) // iterate through 
    {
        // Create new string with next character
        std::string appended = s + str[i];
        Generate(length - 1, appended);
    }
}



void CrackHash(int passwordLength, string hashToCrack)
{
    password = hashToCrack;

    std::transform(password.begin(), password.end(), password.begin(), [](unsigned char c) { return std::toupper(c); });

    for (size_t i = 1; i < passwordLength + 1; i++)
    {
        cout << "Trying all possible " << i << " length Passwords..." << "\n";
        Generate(i, "");
    }
}


int main()
{

    string intput;
    cout << "Enter sha1 hash or type test: ";
    getline(cin, intput);
    if (intput != "test")
    {
        CrackHash(6, intput);
    }
    else
    {
        CrackHash(6, "c2543fff3bfa6f144c2f06a7de6cd10c0b650cae");
        CrackHash(6, "b47f363e2b430c0647f14deea3eced9b0ef300ce");
        CrackHash(6, "e74295bfc2ed0b52d40073e8ebad555100df1380");
        CrackHash(6, "0f7d0d088b6ea936fb25b477722d734706fe8b40");
        CrackHash(6, "77cfc481d3e76b543daf39e7f9bf86be2e664959");
        CrackHash(6, "5cc48a1da13ad8cef1f5fad70ead8362aabc68a1");
        CrackHash(6, "4bcc3a95bdd9a11b28883290b03086e82af90212");
        CrackHash(6, "7302ba343c5ef19004df7489794a0adaee68d285");
        CrackHash(6, "21e7133508c40bbdf2be8a7bdc35b7de0b618ae4");
        CrackHash(6, "6ef80072f39071d4118a6e7890e209d4dd07e504");
        CrackHash(6, "02285af8f969dc5c7b12be72fbce858997afe80a");
        CrackHash(6, "57864da96344366865dd7cade69467d811a7961b");
    }
    
}