#include "sha1.h";

#include <ctype.h>      
#include <iostream>     
#include <string>       
#include <vector>    
#include <math.h> 

using namespace std;

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
