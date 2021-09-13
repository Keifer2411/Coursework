#ifndef CLASS_H
#define CLASS_H //same as pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include "ArgumentManager.h"

class Arrays
{
    private:
        ifstream infile;
        ofstream outfile;
        
    public:
        int size;
        double percent;
        Arrays();
        Arrays(string inFilename)
        {
            int dimension = 0;
            infile.open(inFilename);
            infile >> dimension;
            //cout << dimension;
            size = dimension * dimension; 
        }
        void processing()
        {
            //cout << size;
            char condition;
            int value = 0;
            int count = 0;
            int* arr = new int[size];
            for (int i = 0; i < size; i++)
            {
                infile >> arr[i];
            }
            infile >> condition;
            //cout << condition;
            switch (condition)
            {
            case 'e':
                for (int i = 0; i < size; i++)
                {
                    if (arr[i] % 2 == 0)
                    {
                        count++;
                    }
                }
                break;
            case 'o':
                for (int i = 0; i < size; i++)
                {
                    if (arr[i] % 2 != 0)
                    {
                        count++;
                    }
                }
                break;
            case '=':
                infile >> value;
                for (int i = 0; i < size; i++)
                {
                    if (arr[i] == value)
                    {
                        count++;
                    }
                }
                break;
            case '>':
                infile >> value;
                cout << value;
                for (int i = 0; i < size; i++)
                {
                    if (arr[i] > value)
                    {
                        count++;
                    }
                }
                break;
            case '<':
                infile >> value;
                for (int i = 0; i < size; i++)
                {
                    if (arr[i] < value)
                    {
                        count++;
                    }
                }
                break;
            default:
                break;
            }
            percent = double(count)/ double(size);
            delete [] arr;
            return;
        }
        void print(string outFilename)
        {
            outfile.open(outFilename);
            outfile << fixed << setprecision(2) << percent;
            //cout << fixed << setprecision(2) << percent;
            return;
        }
};
#endif