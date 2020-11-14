#include "sha1.h";

#include <ctype.h>      
#include <iostream>     
#include <string>       
#include <vector>    
#include <math.h> 
#include <random>
#include <algorithm>
#include <cctype>
#include <chrono>


using namespace std;

string password;

bool IsCorrectPassword(string guess, string actualPassword)
{
    SHA1 checksum;
    checksum.update(guess);
    string hash = checksum.final();

    return hash.compare(actualPassword) == 0;
}

int Generate(unsigned int length, std::string s)
{
    std::string str("0123456789abcdefghijklmnopqrstuvwxyz");

    if (length == 0) // when length has been reached
    {
        //std::cout << "Trying Password " << s;
        if (IsCorrectPassword(s, password))
        {
            std::cout << "\nFound Correct Password \"" << s;
            return 1;
        }

        //cout << "\n";
        return 0;
    }

    for (unsigned int i = 0; i < 36; i++) // iterate through 
    {
        // Create new string with next character
        std::string appended = s + str[i];
        if (Generate(length - 1, appended) == 1) return 1;
    }
}



void CrackHash(int passwordLength, string hashToCrack)
{
    cout << "\n" << "Attempting to crack " << hashToCrack <<"...\n";
    auto start = std::chrono::high_resolution_clock::now();

    password = hashToCrack;

    //std::transform(password.begin(), password.end(), password.begin(), [](unsigned char c) { return std::toupper(c); });

    int result = 0;

    for (size_t i = 1; i < passwordLength + 1; i++)
    {
        cout << "Trying all possible " << i << " length Passwords...";
        result = Generate(i, "");
        if (result == 1)
        {
            result = 0;
            auto finish = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> elapsed = finish - start;

            cout << "\" after " << elapsed.count() << " seconds (" << elapsed.count() / 60 << " Minutes)" << "\n";
            return;
        }
        cout << "\n";
    }

    cout << "Failed to crack hash\n";
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
        //CrackHash(6, "a9993e364706816aba3e25717850c26c9cd0d89d"); //Mine that are quick
        //CrackHash(6, "589c22335a381f122d129225f5c0ba3056ed5811"); //Mine that are quick
        //CrackHash(6, "d8b1c3e59ae165abbbb80c3a017ce77d5e281b18"); //Mine that are quick


        CrackHash(6, "c2543fff3bfa6f144c2f06a7de6cd10c0b650cae"); //From worksheet
        CrackHash(6, "b47f363e2b430c0647f14deea3eced9b0ef300ce"); //From worksheet
        CrackHash(6, "e74295bfc2ed0b52d40073e8ebad555100df1380"); //From worksheet
        CrackHash(6, "0f7d0d088b6ea936fb25b477722d734706fe8b40"); //From worksheet
        CrackHash(6, "77cfc481d3e76b543daf39e7f9bf86be2e664959"); //From worksheet
        CrackHash(6, "5cc48a1da13ad8cef1f5fad70ead8362aabc68a1"); //From worksheet
        CrackHash(6, "4bcc3a95bdd9a11b28883290b03086e82af90212"); //From worksheet
        CrackHash(6, "7302ba343c5ef19004df7489794a0adaee68d285"); //From worksheet
        CrackHash(6, "21e7133508c40bbdf2be8a7bdc35b7de0b618ae4"); //From worksheet
        CrackHash(6, "6ef80072f39071d4118a6e7890e209d4dd07e504"); //From worksheet
        CrackHash(6, "02285af8f969dc5c7b12be72fbce858997afe80a"); //From worksheet
        CrackHash(6, "57864da96344366865dd7cade69467d811a7961b"); //From worksheet
    }
    
}