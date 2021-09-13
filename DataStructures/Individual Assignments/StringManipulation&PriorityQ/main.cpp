#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <queue>
#include "ArgumentManager.h"
using namespace std;

//example from https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/

struct Command
{
    string instruction;
    string letters;
    int priority;
    int sequence;
};

struct comparePriority
{
    bool operator()(Command const &c1, Command const &c2)
    {
        if (c1.priority == c2.priority)
        {
            return c1.sequence > c2.sequence;
        }
        return c1.priority > c2.priority; //change this based on the order you want
    }
};

void add(string &s, string letters)
{
    letters.erase(remove(letters.begin(), letters.end(), ','), letters.end());
    char l1 = letters[0];
    char l2 = letters[1];
    //cout << l1 << " " << l2 << endl;
    for (int i =0; i < s.length(); i++)
    {
        if (s[i] == l1){
            s.insert(i+1, 1, l2);
            i++;
        }
    }
    //cout << s;
}
void remove(string &s, string letters)
{
    //cout << s;
    s.erase(remove(s.begin(), s.end(), letters[0]), s.end());
    //cout << s << endl;
}
void replace(string &s, string letters)
{
    //cout <<letters << " ";
    letters.erase(remove(letters.begin(), letters.end(), ','), letters.end());
    //cout << letters[0] << letters[1] << endl;
    replace(s.begin(), s.end(), letters[0], letters[1]);
    //cout << s << endl;
}

void swap(string &s, string letters)
{
    //cout << s << endl;
    letters.erase(remove(letters.begin(), letters.end(), ','), letters.end());
    //cout << letters[0] << letters[1];
    for (int i = 0; i < s.length();i++)
    {
        if (s[i] == letters[0]) {s[i] = letters[1];}
        else if (s[i] == letters[1]) {s[i] = letters[0];}
    }
    //cout << s;
}

void print(queue<string> &message, ofstream &out)
{
    if (!message.empty())
    {
        out << message.front() << endl;
        message.pop();
    }
}

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output= am.get("output");

    ifstream infile;
    ofstream outfile;
    infile.open(input);
    outfile.open(output);
    priority_queue<Command, vector<Command>, comparePriority> pQ;
    queue<string> message;

    int seq = 0;
    string str;

    while (getline(infile, str))
    {
        if(str.empty())
        {
            continue;
        }
        Command c;
        c.instruction = str.substr(0, str.find(":"));
        if (str.find('[') != string::npos) {c.letters = str.substr(str.find("[")+1, str.find("]")-str.find("[")-1);}
        c.priority = stoi(str.substr(str.find("(")+1, str.find(")")-str.find("(")-1));
        c.sequence = seq;
        pQ.push(c);
        seq++;
    }

    //remove instructions if before a decode
    while (pQ.top().instruction != "DECODE")
    {
        pQ.pop();
    }
/*
    while (!pQ.empty())
    {
        Command temp3 = pQ.top();
        pQ.pop();
        cout << temp3.instruction << " " << temp3.letters << " " << temp3.priority << endl;
        //cout << temp3.instruction << temp3.priority << endl;
    }
*/
    while (!pQ.empty())
    {
        Command temp2 = pQ.top();
        pQ.pop();
        //cout << temp2.instruction << " " << temp2.letters << " " << temp2.priority << " " << temp2.sequence<< endl;
        if (temp2.instruction == "DECODE")
        {
            message.push(temp2.letters);
            continue;
        }
        else if (temp2.instruction == "ADD")
        {
            add(message.front(), temp2.letters);
            //cout << message.front() << endl;
        }
        else if (temp2.instruction == "REMOVE")
        {
            remove(message.front(), temp2.letters);
            //cout << message.front() << endl;
        }
        else if (temp2.instruction == "REPLACE")
        {
            replace(message.front(), temp2.letters);
            //cout << message.front() << endl;
        }
        else if (temp2.instruction == "SWAP")
        {
            swap(message.front(), temp2.letters);
            //cout << message.front() << endl;
        }
        else if (temp2.instruction == "PRINT")
        {
            print(message, outfile);
            continue;
            //cout << message.front() << endl;
        }
        else 
        {
            //cout << "Not meeting criteria" << endl;
            //cout << temp2.instruction << endl;
        }
        if (!message.empty())
        {
            string mtemp = message.front();
            message.pop();
            message.push(mtemp);
        }
    }

    infile.close();
    outfile.close();
    return 0;

}