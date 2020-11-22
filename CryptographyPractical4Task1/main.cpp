#pragma warning(disable : 4996);

#include "sha1.h";
#include "tinysha1.h";

#include <ctype.h>      
#include <iostream>     
#include <fstream>
#include <string>       
#include <vector>    
#include <math.h> 
#include <random>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <unordered_map>

std::string password;
SHA1 checksum;

char currentGuess[40] = "";
char actualHash[40] = "";

const int SizeOfPasswordSpace = 2176782336;

std::string charSet("abcdefghijklmnopqrstuvwxyz0123456789");



void logstr(std::string str, bool newline, bool prefixWithTime)
{
    
    std::ofstream myfile;

    myfile.open("output.txt", std::ios::out | std::ios::ios_base::app);

    if (myfile.is_open())
    {
        if (prefixWithTime)
        {
            myfile << currentTime();
            std::cout << str;
        }
        myfile << str;
        std::cout << str;
        if (newline)
        {
            myfile << "\n";
            std::cout << "\n";
        }
            
        myfile.close();
    }
    else
    {
        std::cerr << "didn't write" << std::endl;
    }

}


//std::unordered_map<std::string, std::string> umap;


//To crack a sha1
//generate a possible password
//


std::string hashToCrack;

std::string Hash(std::string input)
{
    checksum.update(input);
    return checksum.final();
}

void testSHA1(const std::string& val) {
    sha1::SHA1 s;
    s.processBytes(val.c_str(), val.size());
    uint32_t digest[5];
    s.getDigest(digest);
    char tmp[48];
    snprintf(tmp, 45, "%08x %08x %08x %08x %08x", digest[0], digest[1], digest[2], digest[3], digest[4]);
    logstr("Calculated : (\"" + val + "\") = " + tmp, true);
}

//std::string newHash(std::string input)
//{
//    testSHA1("The quick brown fox jumps over the lazy dog");
//    testSHA1("The quick brown fox jumps over the lazy cog");
//    testSHA1("");
//
//}


bool IsCorrectPassword(std::string nextHash)
{
    std::string hash = Hash(nextHash);
    int result = hash.compare(hashToCrack);
    return result == 0;
}

int Generate(unsigned int length, std::string s)
{
    

    if (length == 0) // when length has been reached
    {
        //std::cout << "Trying Password " << s;
        if (IsCorrectPassword(s))
        {
            logstr("\nFound Correct Password \"" + s, false);
            return 1;
        }

        //std::cout << "\n";
        return 0;
    }

    for (unsigned int i = 0; i < 36; i++) // iterate through 
    {
        std::string appended = s + charSet[i];
        if (Generate(length - 1, appended) == 1)
        {
            return 1;
        }

    }
}

std::string currentTime() {
    time_t now = time(NULL);
    struct tm tstruct;
    char buf[40];
    tstruct = *localtime(&now);
    //format: HH:mm:ss
    strftime(buf, sizeof(buf), "%X", &tstruct);
    return buf;
}

void CrackHash(std::string inputHash, int passwordLength)
{
    //First check to see if its already in hash table

    //if (umap[])

    logstr("\nStarting to brute force " + inputHash + "...", true);
    //std::cout << "\n" << "Starting to brute force " << inputHash <<"...\n";
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed;

    //std::cout << hashToCrack << std::endl;

    //std::cout << actualHash << std::endl;


    //strcpy(actualHash, inputHash.c_str());

    hashToCrack = inputHash;

    //std::cout << hashToCrack << std::endl;
    //
    //std::cout << actualHash << std::endl;

    for (size_t i = 1; i < passwordLength + 1; i++)
    {

        std::time_t end_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        

        logstr( + "Trying all possible " + std::to_string(i) + " length Passwords...", false);

        if (Generate(i, "") == 1)
        {
            elapsed = std::chrono::high_resolution_clock::now() - start;

            logstr("\" after " + std::to_string(elapsed.count()) + " seconds (" + std::to_string(elapsed.count() / 60) + " Minutes)", true);
            return;
        }
        std::cout << "\n";
    }

    std::cout << "Failed to crack hash\n";

}



int main()
{

    std::string intput;
    std::cout << "Enter sha1 hash or type test: ";
    getline(std::cin, intput);
    if (intput == "test")
    {
        CrackHash("0ade7c2cf97f75d009975f4d720d1fa6c19f4897", 6); //Mine that are quick
        CrackHash("a9993e364706816aba3e25717850c26c9cd0d89d", 6); //Mine that are quick
        CrackHash("589c22335a381f122d129225f5c0ba3056ed5811", 6); //Mine that are quick
        CrackHash("d8b1c3e59ae165abbbb80c3a017ce77d5e281b18", 6); //Mine that are quick

        //CrackHash("c2543fff3bfa6f144c2f06a7de6cd10c0b650cae", 6); //From worksheet
        //CrackHash("b47f363e2b430c0647f14deea3eced9b0ef300ce", 6); //From worksheet
        //CrackHash("e74295bfc2ed0b52d40073e8ebad555100df1380", 6); //From worksheet
        //CrackHash("0f7d0d088b6ea936fb25b477722d734706fe8b40", 6); //From worksheet
        //CrackHash("77cfc481d3e76b543daf39e7f9bf86be2e664959", 6); //From worksheet
        //CrackHash("5cc48a1da13ad8cef1f5fad70ead8362aabc68a1", 6); //From worksheet
        //CrackHash("4bcc3a95bdd9a11b28883290b03086e82af90212", 6); //From worksheet
        //CrackHash("7302ba343c5ef19004df7489794a0adaee68d285", 6); //From worksheet
        //CrackHash("21e7133508c40bbdf2be8a7bdc35b7de0b618ae4", 6); //From worksheet
        //CrackHash("6ef80072f39071d4118a6e7890e209d4dd07e504", 6); //From worksheet
        //CrackHash("02285af8f969dc5c7b12be72fbce858997afe80a", 6); //From worksheet
        //CrackHash("57864da96344366865dd7cade69467d811a7961b", 6); //From worksheet
    }
    else
    {
        CrackHash(intput, 6);
    }

}