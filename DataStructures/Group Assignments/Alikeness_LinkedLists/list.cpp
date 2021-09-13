#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "list.h"

using namespace std;

list::list(){
    head->data = "empty";
    head->next = nullptr;
}

list::list(string fileName){
    ifstream inputFile(fileName);
    string line;
    node * curr = head;

    while(!inputFile.eof()){
        getline(inputFile, line);
        if(line.empty()){
            break;
        }
        curr->data = line;
        curr->next = new node;
        curr = curr->next;
        size++;
        
    }  

    curr->next = nullptr;
};
    
void list::printList(){
    node * curr = head;
    int i = 1;
    
    while(curr->next!=nullptr){
        
        cout << curr->data << endl;
        curr = curr->next;
    } 
    cout << size << endl;
}
/*
string* list::createArray(){
    array = new string[size];
    node * curr = head;

    for(int i = 0; i < size; i++){
        array[i] = curr->data;

        curr = curr->next;
    }

    

    return array;
}
*/

vector<string> list::createArray(){
    //array = new string[size];
    node * curr = head;
    vector<string> vect;

    for(int i = 0; i < size; i++){
        vect.push_back(curr->data);
        curr = curr->next;
    }
    return vect;
}

string list::at(int pos){
  stringstream ss;
  
  node * curr = new node;
  curr = head;

  if(pos == 0 ){
    ss << head->data;
  }

  else{
    for(int i = 0; i < pos; i++ ){
      curr = curr -> next;
    }

    ss << curr->data;   


  }


  
  

  return ss.str();
};