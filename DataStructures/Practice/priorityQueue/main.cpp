//priorityQ
#include <iostream>
#include <queue>
using namespace std;

//example from https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/

struct Person
{
    int age;
    float height;
    Person(int age, float height): age(age), height(height){}
};

struct compareAge
{
    bool operator()(Person const &p1, Person const &p2)
    {
        return p1.age > p2.age; //change this based on the order you want
    }
};

int main()
{

    priority_queue<Person, vector<Person>, compareAge> Qu;

    Person p1(25, 5.5);
    Qu.push(p1);
    Person p2(65, 5.2);
    Qu.push(p2);
    Person p3(34, 6.2);
    Qu.push(p3);
    Person p4(42, 5.8);
    Qu.push(p4);
    Person p5(81, 6.3);
    Qu.push(p5);
    
    while (!Qu.empty())
    {
        Person p = Qu.top();
        Qu.pop();
        cout << p.age << " " << p.height << endl;
    }

    return 0;
}