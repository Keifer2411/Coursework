#include <iostream>
#include <fstream>
#include "classes.h"
#include "ArgumentManager.h"
 
 void recursivePrint(ifstream&, ofstream&, string);

 using namespace std;

 int main (int argc, char* argv[])
 {
    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output= am.get("output");
/*
    if (argc < 3){
        cout << "too few arguments" << endl;
        exit(1);
    }
    for (int i =0; i < argc; i++)
    {
        cout << "arg" << i << ": " << argv[i] << endl;
    }
*/
    ifstream infile;
    ofstream outfile;

    infile.open(input);
    outfile.open(output);
    recursivePrint(infile, outfile, "start");
    infile.close();
    outfile.close();

    return 0;
 }

 void recursivePrint(ifstream &in, ofstream &out, string toSearch)
 {
     if (toSearch == "finish")
     {
         return;
     }

    Arrays arr(in, out, toSearch);
    recursivePrint(in, out, arr.decode());
    //cout << toSearch << endl;
    out << toSearch << endl;
 }
