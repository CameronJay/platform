/*
Platform
Cameron Dempsey
James Tubbs
*/

#include <iostream>

static const std::string close = "CLOSE";

int main()
{
    std::string input = "";
    do
    {
        std::cin >> input;
    } 
    while (input != close);
}