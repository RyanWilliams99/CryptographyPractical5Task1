#include "sha1.h";

#include <ctype.h>      
#include <iostream>     
#include <string>       
#include <vector>    
#include <math.h> 
#include <random>

using namespace std;


std::string random_string()
{
    std::string str("0123456789abcdefghijklmnopqrstuvwxyz");

    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(str.begin(), str.end(), generator);

    return str.substr(0, 6);    // assumes 32 < number of characters in str         
}


string GetNextAttempt(int digitAttemp, int charAttempt)
{

    string tmp_s;

    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";


    tmp_s += alphanum[charAttempt-1];


    return tmp_s;
}

int main()
{
    string str = random_string();
    string str1 = random_string();
    string str2 = random_string();
    string str3 = random_string();
    string str4 = random_string();
    string str5 = random_string();


    string input = "";

    cout << "Enter String: ";
    getline(cin, input);



    SHA1 checksum;
    checksum.update(input);
    const string hash = checksum.final();

    cout << "The SHA-1 of \"" << input << "\" is: " << hash << endl;

    string attempt;
    long digitOne = 32;
    long digitTwo = 32;



    for (size_t i = 32; i < 128; i++)
    {
        for (size_t j = 32; j < 128; j++)
        {

        }
    }


    while (checksum.final() != hash)
    {
        
        cout << "\" Failed " << endl;

        //Generate next char
        attempt = digitOne;

        checksum.update(attempt);

        digitOne += 1;



        cout << "Trying password \"" << attempt;
    }


    cout << "\" Brute forced password after \"" << attempt << "\" attempts." << endl;

    return 0;
}
