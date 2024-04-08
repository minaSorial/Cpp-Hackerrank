//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box
class Box {

private:
    int l, b, h;

public:
    Box() :l{ 0 }, b{ 0 }, h{ 0 } {}

    Box(int a, int b1, int c) :l{ a }, b{ b1 }, h{ c } {
    }

    int getLength() {
        return l;
    }; // Return box's length



    int getBreadth() {
        return b;
    } // Return box's breadth


    int getHeight() {
        return h;
    }

    Box(const Box& A) {
        this->l = A.l;
        this->b = A.b;
        this->h = A.h;
    }


    long long CalculateVolume() {

        return (long long)l * b * h;
    }

    bool operator<(Box& b) {

        if (this->l < b.getLength()) {
            return true;
        }
        else if (this->b < b.getBreadth() && this->l == b.getLength()) {
            return true;

        }
        else if (this->h < b.getHeight() && this->b == b.getBreadth() && this->l == b.getLength())
        {
            return true;

        }
        else {
            return false;
        }



    }


    friend ostream& operator<<(ostream& out, Box& B);
};

ostream& operator<<(ostream& out, Box& B) {

    return out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
}


void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0;i < n;i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }

    }
}

int main()
{
    check2();
}