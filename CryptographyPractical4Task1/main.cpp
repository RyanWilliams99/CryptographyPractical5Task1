#include "sha1.h";

#include <ctype.h>      
#include <iostream>     
#include <string>       
#include <vector>    
#include <math.h> 
#include <random>

using namespace std;

string password;

bool IsCorrectPassword(string guess, string actualPassword)
{
    return guess.compare(actualPassword) == 0;
}

void Generate(unsigned int length, std::string s)
{
    std::string str("0123456789abcdefghijklmnopqrstuvwxyz");

    if (length == 0) // when length has been reached
    {
        std::cout << "Trying Password " << s;
        if (IsCorrectPassword(s, password))
        {
            std::cout << " Correct Password " << "\n";
            exit(0);
        }

        cout << "\n";
        
        return;
    }

    for (unsigned int i = 0; i < 36; i++) // iterate through 
    {
        // Create new string with next character
        std::string appended = s + str[i];
        Generate(length - 1, appended);
    }
}


int main()
{

    cout << "Enter password: ";
    getline(cin, password);

    for (size_t i = 1; i < 7; i++)
    {
        Generate(i, "");
    }
    


    //string input = "";

    //cout << "Enter String: ";
    //getline(cin, input);



    //SHA1 checksum;
    //checksum.update(input);
    //const string hash = checksum.final();

    //cout << "The SHA-1 of \"" << input << "\" is: " << hash << endl;

    //string attempt;
    //long digitOne = 32;
    //long digitTwo = 32;



    //for (size_t i = 32; i < 128; i++)
    //{
    //    for (size_t j = 32; j < 128; j++)
    //    {

    //    }
    //}


    //while (checksum.final() != hash)
    //{
    //    
    //    cout << "\" Failed " << endl;

    //    //Generate next char
    //    attempt = digitOne;

    //    checksum.update(attempt);

    //    digitOne += 1;



    //    cout << "Trying password \"" << attempt;
    //}


    //cout << "\" Brute forced password after \"" << attempt << "\" attempts." << endl;

    //return 0;
}
