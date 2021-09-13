#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Arrays
{
public:
    int ROWS, COLS;
    vector<vector<char>> matr;
    
    Arrays(){}
    ~Arrays()
    {
        for (int i = 0; i < matr.size(); i++)
        {
            matr[i].clear();
        }
        matr.clear();
    }
    Arrays(ifstream& input, ofstream& output, string word)
    {
        char letter, ignore, r, c;
        string line;
        while (getline (input, line))
        {
            stringstream tempstream(line);
            string temp;
            tempstream >> temp;
            if(temp == word)
            {
                getline(input, line);
                //cout << line << endl;
                stringstream dimen(line);
                dimen >> r >> ignore >> c;
                ROWS = r - '0';
                COLS = c - '0';
                for (int i = 0; i < ROWS; i++)
                {
                    getline(input,line);
                    line.erase(remove(line.begin(), line.end(), ' '), line.end()); //taken from https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c
                    stringstream iss(line);
                    matr.push_back(vector<char>()); //creating first empty vector of # of ROWS

                    for (int j = 0; j < COLS; j++)
                    {
                        iss >> letter;
                        matr[i].push_back(letter);
                    }
                }
                input.clear();
                input.seekg(0, ios::beg);
                break;
                /*
                for (int i = 0; i < matr.size(); i++)
                {
                    cout << endl;
                    for (int j = 0; j < matr[i].size(); j++)
                    {
                        cout << matr[i][j];
                    }
                }*/
            }
        }
    }

    string decode()
    {        
        string result = "";
        int total = ROWS * COLS;
        int top = 0;
        int bottom = ROWS - 1;
        int left = 0;
        int right = COLS - 1;
        int count = 0;
        //cout << matr.size() << endl;

        while (count < total)
        {
            for (int i = left; i <= right; i++)
            {
                result += matr[top][i];
                count++;
                if (count >= total) {return result;}
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                result += matr[i][right];
                count++;
                if (count >= total) {return result;}
            }
            right--;
            for (int i = right; i >= left; i--)
            {
                result += matr[bottom][i];
                count++;
                if (count >= total) {return result;}
            }
            bottom--;
            for (int i = bottom; i >= top; i--)
            {
                result += matr[i][left];
                count++;
                if (count >= total) {return result;}
            }
            left++;
            cout << left << ", " << right << ", " << bottom << ", " << top << endl;
        }
        return result;
    }

};
#endif