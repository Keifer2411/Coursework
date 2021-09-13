#include <iostream>
#include <fstream>
#include "class.h"

using namespace std;

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output= am.get("output");
    Arrays textfile(input);
    textfile.processing();
    textfile.print(output);
    return 0;
}