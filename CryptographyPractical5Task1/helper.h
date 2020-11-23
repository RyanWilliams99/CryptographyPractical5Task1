#pragma once
#include <string>
#include <iostream>


class Helper
{
public: Helper() {};

public: std::string currentTime() {
        time_t now = time(NULL);
        struct tm tstruct;
        char buf[40];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%X", &tstruct);
        return buf;
    }

public: void logstr(std::string str, bool prefixWithTime, bool newline)
    {

        std::ofstream myfile;

        myfile.open("output.txt", std::ios::out | std::ios::ios_base::app);

        if (myfile.is_open())
        {
            if (prefixWithTime)
            {
                myfile << currentTime() + " - ";
                std::cout << currentTime() + " - ";
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
            std::cerr << "cant write" << std::endl;
        }

    }

};
