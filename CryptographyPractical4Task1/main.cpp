#include "sha1.h";

#include <ctype.h>      
#include <iostream>     
#include <string>       
#include <vector>    
#include <math.h> 

using namespace std;



int main()
{
    string input = "";

    cout << "Enter String: ";
    getline(cin, input);

    

    SHA1 checksum;
    checksum.update(input);
    const string hash = checksum.final();

    cout << "The SHA-1 of \"" << input << "\" is: " << hash << endl;


    string attemp;
    char c;
    long attemptNumber = 32;

    while (checksum.final() != hash)
    {
        //Generate next char
        c = attemptNumber;

        s.push_back(ch);

        checksum.update(attemp);

        


        attemptNumber += 1;

        if (attemptNumber 
    }

    cout << "Brute forced password after \"" << attemptNumber << "\" attempts. Password is: " << attemp << endl;

    return 0;
}
