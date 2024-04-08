#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person
{
public:


    Person() {

    };
    ~Person() {

    };
    virtual void getdata(void) = 0;
    virtual void putdata(void) = 0;

protected:
    string name;
    int age;
    //static int id;
};



class Professor :public Person
{
public:
    Professor() {
        cur_id = count;
        count++;
    }
    ~Professor() {
        count--;
    }

    void getdata(void) override {
        cin >> name;
        cin >> age;
        cin >> publication;
    }

    void putdata(void) override {

        std::cout << name << " " << age << " " << publication << " " << cur_id << endl;
    }

private:
    int cur_id;
    int publication;
    static int count;

};

int Professor::count = 1;




class Student :public Person
{
public:
    Student() {
        cur_id = count;
        count++;
    }
    ~Student() {
        count--;
    }

    void getdata(void) override {
        cin >> name;
        cin >> age;
        for (size_t i = 0; i < 6; i++)
        {
            cin >> marks[i];
        }

    }

    int marks_sum() {
        int sum = 0;
        for (size_t i = 0; i < 6; i++)
        {
            sum += marks[i];
        }
        return sum;
    }
    void putdata(void) override {

        std::cout << name << " " << age << " " << marks_sum() << " " << cur_id << endl;
    }

private:
    int cur_id;
    int marks[6];
    static int count;

};

int Student::count = 1;
int main() {

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person* per[n];

    for (int i = 0;i < n;i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0;i < n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
