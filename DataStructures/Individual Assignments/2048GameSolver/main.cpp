#include <iostream>
#include <stack> 
#include <algorithm>
#include <fstream>
#include <vector>
#include <stack>
#include "ArgumentManager.h"
using namespace std;

class Coord
{
    public:
        int x, y;
        Coord(int le, int r)
        {
            x= le;
            y =r;
        }
};

void merge(vector<vector<int>> &vect, int i, int j, int m, int n, int num1, int num2)
{
    vect[i][j] = num1 + num2;
    vect[m][n] = 0;
}

void moveL(vector<vector<int>> &vect)
{
    vector<Coord> checkMerge;
    for (int i = 0 ; i < vect.size(); i++)
    {
        //int start = 0;
        for(int j = 0; j < vect[i].size(); j++)
        {
            if(vect[i][j] != 0)
            {
                int k = j;
                while (k !=0 && vect[i][k-1] == 0)
                {
                    swap(vect[i][k], vect[i][k-1]); 
                    k--;
                }
                if (vect[i][k-1] == vect[i][k])
                {
                    bool flag = 0;
                    Coord mer(i, k-1);
                    for (int a = 0; a < checkMerge.size(); a++)
                    {
                        if (checkMerge[a].x == i && checkMerge[a].y == k-1)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1){continue;}
                    merge(vect, i, k-1, i, k, vect[i][k-1], vect[i][k]);
                    checkMerge.push_back(mer);
                }
            }
        }
    }
}

void moveR(vector<vector<int>> &vect)
{
    vector<Coord> checkMerge;
    for (int i = 0 ; i < vect.size(); i++)
    {
        //int start = 0;
        for(int j = vect[i].size()-1; j >= 0; j--)
        {
            if(vect[i][j] != 0)
            {
                int k = j;
                while (k !=vect[i].size()-1 && vect[i][k+1] == 0)
                {
                  swap(vect[i][k], vect[i][k+1]); 
                  k++;
                }
                if (vect[i][k] == vect[i][k+1])
                {
                    bool flag = 0;
                    Coord mer(i, k+1);
                    for (int a = 0; a < checkMerge.size(); a++)
                    {
                        if (checkMerge[a].x == i && checkMerge[a].y == k+1)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1){continue;}
                    merge(vect, i, k+1, i, k, vect[i][k+1], vect[i][k]);

                }
            }
        }
    }
}

void moveU(vector<vector<int>> &vect)
{
    vector<Coord> checkMerge;
    for (int j = 0 ; j < vect[0].size(); j++)
    {
        for(int i = 0; i < vect.size(); i++)
        {
            //cout << vect[i][j] << " ";
            if(vect[i][j] != 0 && i != 0)
            {
               int k = i;
               while (k != 0 && vect[k-1][j] == 0)
                {
                  swap(vect[k][j], vect[k-1][j]); 
                  k--;
                }
                if (k > 0 && vect[k][j] == vect[k-1][j])
                {
                    bool flag = 0;
                    Coord mer(k-1, j);
                    for (int a = 0; a < checkMerge.size();a++)
                    {
                        if (checkMerge[a].x == k-1 && checkMerge[a].y == j)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1){continue;}
                    merge(vect, k-1, j, k, j, vect[k-1][j], vect[k][j]);
                    checkMerge.push_back(mer);
                }
            }
        }
    }
}

void moveD(vector<vector<int>> &vect)
{
    vector<Coord> checkMerge;
    for (int j = 0 ; j < vect[0].size(); j++)
    {
        for(int i = vect.size()-1; i >= 0; i--)
        {
            //cout << vect[i][j] << " ";
            if(vect[i][j] != 0)
            {
                int k = i;
                while (k != vect.size()-1 && vect[k+1][j] == 0)
                {
                  swap(vect[k][j], vect[k+1][j]); 
                  k++;
                }

                if (k < vect.size()-1 && vect[k+1][j] == vect[k][j])
                {
                    bool flag = 0;
                    Coord mer(k+1, j);
                    for (int a = 0; a < checkMerge.size();a++)
                    {
                        if (checkMerge[a].x == k+1 && checkMerge[a].y == j)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1){continue;}
                    merge(vect, k+1, j, k, j, vect[k+1][j], vect[k][j]);
                    checkMerge.push_back(mer);
                }
            }
        }
    }
}

void printMatrix (vector<vector<int>> vect)
{
    for(int i =0; i < vect.size(); i++)
    {
        for(int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j];
        }
        cout << endl;
    }
}

bool checkIfDone(vector<vector<int>> vect)
{
    int count= 0;
    for(int i =0; i < vect.size(); i++)
    {
        for(int j = 0; j < vect[i].size(); j++)
        {
            if(vect[i][j] != 0){count++;}
        }
    }
    if (count == 1) {return true;}
    else {return false;}
}
/*
void gatherSolutions(vector<vector<int>> matr, vector<vector<int>> copy, vector<string> &moves, string str, int moveCount, int totalMoveCount)
{
    moveCount++;
    totalMoveCount++;
    if (checkIfDone(copy))
    {
        moves.push_back(str);
        str = "";
        copy = matr;
    }
    if (moveCount >= 3)
    {
        cout << str;
        moves.push_back("Impossible");
        str = "";
        copy = matr;
    }
    if (totalMoveCount >= 12)
    {
        return;
    }
    moveU(copy);
    str += "1";
    gatherSolutions(matr, copy, moves, "", 0, 0);
    moveD(copy);
    moveR(copy);
    str += "2";
    gatherSolutions(matr, copy, moves, "", 0, 0);
    moveL(copy);
    moveD(copy);
    str += "3";
    gatherSolutions(matr, copy, moves, "", 0, 0);
    moveU(copy);
    moveL(copy);
    str += "4";
    gatherSolutions(matr, copy, moves, "", 0, 0);
    moveR(copy);
}
*/

//taken from https://stackoverflow.com/questions/16446374/generating-all-permutations-with-repetition/42403049
template <class Iter>
bool next_variation(Iter first, Iter last, const typename std::iterator_traits<Iter>::value_type max)
{
    if(first == last) return false; // empty sequence (n==0)

    Iter i(last); --i; // Point to the rightmost element
    // Check if I can just increase it
    if(*i < max) { ++(*i); return true; } // Increase this element and return

    // Find the rightmost element to increase
    while( i != first )
       {
        *i = 0; // reset the right-hand element
        --i; // point to the left adjacent
        if(*i < max) { ++(*i); return true; } // Increase this element and return
       }

    // If here all elements are the maximum symbol (max=k-1), so there are no more variations
    //for(i=first; i!=last; ++i) *i = 0; // Should reset to the lowest sequence (0)?
    return false;
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
    int dimen;
    
    infile >>dimen;

    vector<vector<int>> matrix;
    vector<vector<int>> copy;
    vector<int> moves(3,0);
    vector<int> successes;
    vector<string> possibilities;
    stack<string> answer;

    matrix.resize(dimen, vector<int>(dimen));

    for(int i =0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            infile >> matrix[i][j];
            if (matrix[i][j] == 2048){matrix[i][j] = 0;}
        }
    }
    //printMatrix(matrix);


    //cout << "___________" << endl;
    string number = "";
    //gatherSolutions(matrix, copy, moves, "", 0, 0);


    //taken from https://stackoverflow.com/questions/16446374/generating-all-permutations-with-repetition/42403049
    do{
        for(std::vector<int>::const_iterator it=moves.begin(); it!=moves.end(); ++it)
        {
            number += to_string(*it);
        }
        possibilities.push_back(number); //add all posibilities to stack
        number = "";
    }while( next_variation(moves.begin(), moves.end(), 4) ); //assuming max of 3 moves based on test cases

    bool found = 0;

    for (int i =0; i < possibilities.size(); i++)
    {
        copy = matrix;
        number = possibilities[i];
        for (int c = 0; c < 3; c++)
        {
            //cout << number[c];
            if(number[c] == '0'){continue;} //do nothing
            if(number[c] == '1'){moveU(copy);}
            if(number[c] == '2'){moveR(copy);}
            if(number[c] == '3'){moveD(copy);}
            if(number[c] == '4'){moveL(copy);}
            //printMatrix(copy);
            //cout <<"__________" << endl;
            if(checkIfDone(copy))
            {
                answer.push(number);
                found = 1;
            }
        }
        //cout << number << endl;
        if (found==1)
        {
            outfile << answer.top();
            answer.pop();
            break;
        }
    }

    if (found == 0) {outfile << "Impossible";}

    //printMatrix(matrix);  
    //moveR(matrix);
    //moveU(matrix);
    //moveL(matrix);
    //moveD(matrix);
    //moveR(matrix);
    //printMatrix(matrix);

    return 0;

}