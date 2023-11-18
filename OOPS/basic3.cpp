#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

class ComplexNumbers {
    int real,imag;

    public:
    ComplexNumbers(int real,int imag){
        this->real = real;
        this->imag = imag;
    }

    void plus(ComplexNumbers& temp){
        this->real+=temp.real;
        this->imag+=temp.imag;
    }

    void multiply(ComplexNumbers& temp){
        int r1 = this->real;
        int r2 = this->imag;
        this->real = (r1*temp.real - (r2*temp.imag));
        this->imag = ((r1*temp.imag) + (r2*temp.real));

    }
    void print(){
        cout<<this->real<<" + "<<"i"<<this->imag<<endl;
    }



};

int main() {
    int real1, imaginary1, real2, imaginary2;

    // cin >> real1 >> imaginary1;
    // cin >> real2 >> imaginary2;

    ComplexNumbers c1(3,6);
    ComplexNumbers c2(7,9);

    int choice=2;
    // cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }

}