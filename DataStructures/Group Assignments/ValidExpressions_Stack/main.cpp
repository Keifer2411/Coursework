#include <algorithm>
#include <ctype.h>
#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <cstdio>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

#include "ArgumentManager.h"

// Joseph G
// Henry O
// Thuynhi P
// Joshua M

/*
bool isOper(char ch)//is the character an operator
{
  switch(ch)
  {
	case '+':
	case '-':
	  return true;
	case '(':
	case '[':
	case '{':
	  return true;
	default:
	  return false;
  }
}

int operationPriority(char ch)
{
  switch (ch)
  {
	case '+':
	case '-':
	  return 0;
	case '(':
	case '[':
	case '{':
	  return 1;
	default:
	  return -1;
  }
}
*/
void removeOperAtBeginEnd(string &str) {
	while (str[0] == '+' || str[0] == '-') {
		str.erase(str.begin());
	}
	while (str[str.length()] == '+' || str[str.length()] == '-') {
		str.erase(str.end());
	}
}

/*int prec(char c) {
	if(c == '^') //^, /, and * will not be in the strings
		return 3;
	else if(c == '/')
		return 2;
	else if(c=='*')
		 return 1;
	if(c == '+' || c == '-')
		return -1;
	else
		return -2;
}*/

bool matching(string s) {
	stack<char> brackets;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (c == '(' || c == '[' || c == '{') {
			brackets.push(c);
		} else if (c == ')') {
			if (brackets.top() != '(') {
				return false;
			}
			brackets.pop();
		} else if (c == ']') {
			if (brackets.top() != '[') {
				return false;
			}
			brackets.pop();
		} else if (c == '}') {
			if (brackets.top() != '{') {
				return false;
			}
			brackets.pop();
		}
	}
	if (!brackets.empty()) {
		return false;
	}
	return true;
}

void checkForNeg(string &str) {
	for (int i = 0; i < str.length(); i++) {
		size_t found1 = str.find("-(-");
		// auto it1 = str.begin() + found1;
		size_t found2 = str.find("-[-");
		// auto it2 = str.begin() + found2;
		size_t found3 = str.find("-{-");
		// auto it3 = str.begin() + found3;
		size_t foundEnd;

		if (found1 !=
			std::string::
				npos) // ref:http://www.cplusplus.com/reference/string/string/find/
		{
			// cout << "###########" << str[found1+2] << " " <<"###########" <<
			// endl;
			str.erase(str.begin() + found1 + 2);
			for (int j = int(found1); str[j] != ')'; j++) {
				if (str[j] == '-') {
					str[j] = '+';
				}
			}
		} else if (
			found2 !=
			std::string::
				npos) // ref:http://www.cplusplus.com/reference/string/string/find/
		{
			for (int j = int(found2); str[j] != ')'; j++) {
				if (str[j] == '-') {
					str[j] = '+';
				}
			}
		} else if (
			found3 !=
			std::string::
				npos) // ref:http://www.cplusplus.com/reference/string/string/find/
		{
			for (int j = int(found3); str[j] != ')'; j++) {
				if (str[j] == '-') {
					str[j] = '+';
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
	ArgumentManager am(argc, argv);
	const string input = am.get("input");
	const string output = am.get("output");
	

	ifstream infile;
	ofstream outfile;
	infile.open(input);
	outfile.open(output);
  outfile<<"";
	string line;
	stack<char> oper; // stack of operators
	int count = 0;
	stack<int> stack;
	int i = 0;
	bool errorFlag = 0;
	vector<int> value;

	while (getline(infile, line)) {
		string postfix = "";
		if (line.empty()) {
			continue;
		}
		count++;

		if (!matching(line)) {
			errorFlag = 1;
			outfile << "Error at: " << count << endl;
			continue;
		}
		removeOperAtBeginEnd(line);
		checkForNeg(line);
		for (int i = 0; i < line.length(); i++) {
			char ch = line[i];

			if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') ||
				(ch >= '0' && ch <= '9')) {
				postfix += ch;
			}

			else if (ch == '(' || ch == '[' || ch == '{') {
				oper.push(ch);
			}

			else if (ch == ')' || ch == ']' || ch == '}') { // operator to
															// compare
				while (oper.top() != '(' && oper.top() != '[' &&
					   oper.top() != '{') {
					postfix += oper.top();
					oper.pop();
				}
				if (oper.top() == '(' || oper.top() == '[' ||
					oper.top() == '{') {
					oper.pop();
				}
			}

			else {
				while (!oper.empty() &&
					   (oper.top() == '+' || oper.top() == '-')) {
					postfix += oper.top();
					oper.pop();
				}
				oper.push(ch); // push operator onto stack
							   // cout << "pushed: " << oper.top() << endl;
			}
			// empty stack
		}
		while (!oper.empty()) {
			postfix += oper.top();
			oper.pop();
		}
		//cout << postfix << endl;

		// math for answer to expressions
		for (i = 0; i < postfix.length(); i++) {
			if (isalpha(postfix[i]) || isdigit(postfix[i])) {
				int ascii = (int)postfix[i];
				stack.push(postfix[i] - '0');
				//cout << ascii << " ";

			} else {
				int x = stack.top();
				stack.pop();

				int y = stack.top();
				stack.pop();

				if (postfix[i] == '+') {
					stack.push(y + x);
				} else if (postfix[i] == '-') {
					stack.push(y - x);
				}
			}
		}

		cout << "answer:" << stack.top() << endl;
		value.push_back(stack.top());
	}

	// checks if values are the same between all

	//vector<int> duplicate;
  int duplicates = 0;
	int val = value[0];
	sort(value.begin(), value.end());

/*
	for (auto it = cbegin(value); it != value.end();) {
		int dups = std::count(it, value.end(), *it);
		if (dups > 1) {
			cout << *it << " is a duplicated number, times: " << dups << endl;
			duplicate.push_back(dups);
		} else {
			duplicate.push_back(0);

		}
		for (auto last = *it; *++it == last;);
	}
  */
  for(auto it = value.begin(); it != value.end(); ) {  

    int dups = std::count(it, value.end(), *it);
    if ( dups > 1 ) {
        //cout << *it << " is a duplicated number, times: " << dups << endl;
        } else if (dups==0) {
          //cout<< "no dupes";          
        }
    duplicates = dups;
    for(auto last = *it;*++it == last;);
    
  }

  if (errorFlag == 0) {
    if ( duplicates >= int(value.size())) {
      outfile<<"Yes"<<endl;
      cout<<"Because "<< duplicates <<" is equal "<<value.size()<<endl;
    } 
    else{
      outfile<<"No"<<endl;
      cout<<"Because "<< duplicates <<" does not equal "<<value.size()<<endl;
    }
  }
/*
	if (errorFlag == 0) {
		if (duplicate.at(0) == value.size() ||
			duplicate.empty() == value.size()) {
			outfile << "Yes" << endl;
			cout<<"Because "<<duplicate[0]<<" is equal "<<value.size()<<endl;
		} else if (duplicate.empty() || duplicate.at(0) < value.size()) {
			outfile << "No" << endl;
			 cout<<"Because "<<duplicate[0]<<" does not equal"<<value.size()<<endl;
		}
	}
  */

  infile.close();
  outfile.close();
  

	return 0;
}