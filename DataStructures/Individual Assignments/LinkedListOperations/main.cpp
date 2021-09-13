#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "classes.h"
#include "ArgumentManager.h"

using namespace std;

//used https://iq.opengenus.org/sort-2d-vector-in-cpp/ as basis for the following functions
bool sortbycol1(const vector<string> &vect1, const vector<string> &vect2) //sort by id
{return vect1[1] < vect2[1];}

bool sortbycol2(const vector<string> &vect1, const vector<string> &vect2) //sort by name
{return vect1[2] < vect2[2];}

bool sortbycol3(const vector<string> &vect1, const vector<string> &vect2) //sort by difficults
{return vect1[3] < vect2[3];}

//Decreasing sorts
bool sortbycol1_decr(const vector<string> &vect1, const vector<string> &vect2) //sort by id
{return vect1[1] > vect2[1];}

bool sortbycol2_decr(const vector<string> &vect1, const vector<string> &vect2) //sort by name
{return vect1[2] > vect2[2];}

bool sortbycol3_decr(const vector<string> &vect1, const vector<string> &vect2) //sort by difficults
{return vect1[3] > vect2[3];}

difficulty converttoEnum(string str)
{
    if (str == "Easy") {return easy;}
    if (str == "Medium") {return medium;}
    if (str == "Hard") {return hard;}
}

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    string input1 = am.get("input");
    string input2 = am.get("command");
    string output= am.get("output");
    ifstream infile, commands;
    ofstream outfile;

    infile.open(input1);
    commands.open(input2);
    outfile.open(output);

    vector <vector<string>> info;
    string str, temp, temp2;

    while (getline(infile, str))
    {
        if(str.empty())
        {
            continue;
        }
        istringstream ss(str);
        vector <string> row;
        row.push_back(str);
        while (getline(ss, temp, ','))
        {
            size_t pos= temp.find(":");
            temp2 = temp.substr(pos+1);
            row.push_back(temp2);
        }
        info.push_back(row);
        //cout << "-----------------" << endl;
    }

    string str2;
    while (getline(commands, str2))
    {
        //cout << str2 << endl;
        if(str2.substr(0,3) == "add")
        {
            //cout << str2 << endl;
            size_t posi2 = str2.find("problem");
            string tem = str2.substr(8, posi2-9);
            int num = stoi(tem);
            //cout << "add pos: " <<num << endl;
            size_t pos2 = str2.find("problem_id");
            str2.erase(0,pos2);
            vector <string> row;
            row.push_back(str2);
            bool dupe = 0;
            for (int i =0; i < info.size(); i++)
            {
                size_t position = str2.find(":");
                size_t position2 = str2.find(",");
                string tempor = str2.substr(position+1, position2-position-1);
                //cout << tempor <<endl;
                if(tempor == info[i][1])
                {
                    dupe = 1;
                    //cout << "Dupe: " << info[i][1] << endl; 
                    break;
                }
            }
            if(dupe){continue;}
            istringstream ss(str2);
            while (getline(ss, temp, ','))
            {
                    size_t pos= temp.find(":");
                    temp2 = temp.substr(pos+1);
                    row.push_back(temp2); 
            }
            if (num >= info.size())
            {
                    info.push_back(row);
            }
            else
            {
                info.insert(info.begin()+num, row);
            }
        }
        if (str2.substr(0, 6)== "remove")
        {
            if (str2.substr(7,10) == "problem_id")
            {
                size_t pos= str2.find(":");
                temp = str2.substr(pos+1);
                for (int i =0; i < info.size(); i++)
                {
                    if(temp == info[i][1])
                    {
                        //cout << "RemoveById: " << info[i][1] << endl; 
                        info.erase(info.begin()+i);
                        continue;
                    }
                }
            }
            if (str2.substr(7,12) == "problem_name")
            {
                size_t pos= str2.find(":");
                temp = str2.substr(pos+1);
                for (int i =0; i < info.size(); i++)
                {
                    if(temp == info[i][2])
                    {
                        //cout << "RemoveByName: " << info[i][2] << endl;
                        info.erase(info.begin()+i);
                        continue;
                    }
                }
            }
            if (str2.substr(7,10) == "difficulty")
            {
                size_t pos= str2.find(":");
                temp = str2.substr(pos+1);
                for (int i =0; i < info.size(); i++)
                {
                    if(temp == info[i][3])
                    {
                        //cout << "RemoveByDiff: " << info[i][3] << endl;
                        info.erase(info.begin()+i);
                        continue;
                    }
                }
            }
            if (str2.substr(7,3) == "pos")
            {
                size_t posi = str2.find(":");
                string tem = str2.substr(posi+1);
                int num = stoi(tem);
                //cout << "remove at pos: " << num << endl;
                if (num >= info.size())
                {
                    continue;
                }
                info.erase(info.begin()+num);
            }
        }
        if (str2.substr(0, 4)== "sort")
        {
            if (str2.substr(5, 10)== "problem_id")
            {
                if (str2.substr(16, 10)== "increasing")
                {
                    //cout << "sort id increasing" << endl;
                    sort(info.begin(),info.end(),sortbycol1);
                }
                else
                {
                    //cout << "sort id decr" << endl;
                    sort(info.begin(),info.end(),sortbycol1_decr);
                }
            }
            if (str2.substr(5, 12)== "problem_name")
            {
                if (str2.substr(18, 10)== "increasing")
                {
                    //cout << "sort name increasing" << endl;
                    sort(info.begin(),info.end(),sortbycol2);

                }
                else
                {
                    //cout << "sort name decr" << endl;
                    sort(info.begin(),info.end(),sortbycol2_decr);
                }
            }
            if (str2.substr(5, 10)== "difficulty")
            {
                if (str2.substr(16, 10)== "increasing")
                {
                    //cout << "sort dif increasing" << endl;
                    sort(info.begin(),info.end(),sortbycol3);
                }
                else
                {
                    //cout << "sort diff decr" << endl;
                    sort(info.begin(),info.end(),sortbycol3_decr);
                }
            }
        }
    }
/*
    for (int i =0; i < info.size(); i++)
    {
        for (int j =1; j < info[i].size(); j++)
        {
            cout << info[i][j] << " | ";
        }
        cout << endl;
    }
*/
    LinkedList leet;
    for (int i =0; i < info.size(); i++)
    {
        Problem entry;
        entry.whole = info[i][0];
        entry.id = stoi(info[i][1]);
        entry.name = info[i][2];
        entry.diff = converttoEnum(info[i][3]);
        leet.addtoEnd(entry);
    }

    leet.print(outfile);


    infile.close();
    commands.close();
    outfile.close();

    return 0;
}
