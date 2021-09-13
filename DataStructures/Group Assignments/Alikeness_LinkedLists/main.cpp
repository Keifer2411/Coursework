#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "ArgumentManager.h"
#include "list.h"

//Joseph G 
//Henry O
//Thuynhi P
//Joshua M

//used https://stackoverflow.com/questions/6911700/how-can-you-strip-non-ascii-characters-from-a-string-in-c for this part
void remove_nonprinting (string& line)
{
    line.erase (remove_if (line.begin(), line.end(),[](unsigned char c){return!std::isprint(c);}),line.end());

}

void compareArrays(vector<string> arr1, vector<string> arr2, int size1, int size2, string fileName)
{
  //cout << "Compare Arrays" <<  endl;
  vector<string> result;
  int count = 0;

  ofstream outFS(fileName);

  for (int i =0; i < arr1.size(); i++){
    for (int j = 0; j < arr2.size(); j++)
    {  
      remove_nonprinting (arr1[i]);
      remove_nonprinting (arr2[j]);
      if (arr1[i] == arr2[j]) {
      result.push_back(arr1[i]);
      count++;
      break;
      }
    }
  }

  //sort(result.begin(), result.end());
  for(int i = 0; i < result.size(); i++){
    for(int j = i+1; j < result.size(); j++){
        if(result[i] > result[j]){
                string swap = result[i];
                result[i] = result[j];
                result[j] = swap;
            }
    }
  }
  outFS<<"Alikeness is "<<result.size()<<" out of "<< size1 <<":\n";
  for (int i = 0; i< result.size(); i++)
  {outFS << i+1 << ". " << result[i] << endl;}
  
}

//int main(){  
int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    string input1 = am.get("haru_miya");
    string input2 = am.get("jitu_miya");
    string output= am.get("output");

    
    list myListA(input1);
    list myListB(input2);
    
    //compareArrays(myListA, myListB, myListA.getSize(), myListB.getSize());
    compareArrays(myListA.createArray(), myListB.createArray(), myListA.getSize(), myListB.getSize(), output);

     
    
    return 0;   
}