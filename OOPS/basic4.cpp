/*
https://www.codingninjas.com/studio/guided-paths/basics-of-c/content/118817/offering/1381815?leftPanelTab=0&leftPanelTabValue=PROBLEM
*/
#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

class Polynomial {
    public:
    int * degCoeff; // Name of your array (Don't change this)
    int totalSize;
   
    Polynomial(){
        degCoeff = new int[5];
        for(int i=0;i<5;i++){
            degCoeff[i] = 0;
        }
        this->totalSize = 5;
    }

    Polynomial(Polynomial const & temp){

        degCoeff = new int[temp.totalSize];
        for(int i=0;i<temp.totalSize;i++){
            degCoeff[i] = temp.degCoeff[i];
        }
        this->totalSize = temp.totalSize;
    }
    void operator = (Polynomial
        const & p) {
        delete[] degCoeff;
        degCoeff = new int[p.totalSize];
        for (int i = 0; i < p.totalSize; i++) {
            degCoeff[i] = p.degCoeff[i];
        }
        totalSize = p.totalSize;
    }
    void setCoefficient(int degree, int coeff){
        if(degree>this->totalSize){
            int size = 2 * this->totalSize;
            while(size<=degree){
                size=size*2;
            }

            int *newdegcoeff = new int[size];

            for(int i=0;i<size;i++){
                newdegcoeff[i] = 0;
            }
            for(int i=0;i<this->totalSize;i++){
                newdegcoeff[i] = this->degCoeff[i];
            }
            this->totalSize = size;
            delete[] this->degCoeff;
            this->degCoeff = newdegcoeff;
        }
        this->degCoeff[degree] = coeff;
    }

    Polynomial operator+ (Polynomial &p){
        Polynomial pNew;
        int i = 0;
        int j = 0;

        while(i<=this->totalSize && j<=p.totalSize){
            int deg = i;
            int coeff = this->degCoeff[i] + p.degCoeff[j];
            pNew.setCoefficient(deg,coeff);
            i++;
            j++;
        }
        while(i<=this->totalSize){
            pNew.setCoefficient(i,this->degCoeff[i]);
            i++;
        }
        while(j<=p.totalSize){
            pNew.setCoefficient(j,p.degCoeff[j]);
            j++;
        }
        return pNew;
    }

    Polynomial operator- (Polynomial &p){
        Polynomial pNew;
        int i = 0;
        int j = 0;

        while(i<=this->totalSize && j<=p.totalSize){
            int deg = i;
            int coeff = this->degCoeff[i] - p.degCoeff[j];
            pNew.setCoefficient(deg,coeff);
            i++;
            j++;
        }
        while(i<=this->totalSize){
            pNew.setCoefficient(i,this->degCoeff[i]);
            i++;
        }
        while(j<=p.totalSize){
            pNew.setCoefficient(j,p.degCoeff[j]);
            j++;
        }
        return pNew;
    }
    Polynomial operator* (Polynomial& p){
        Polynomial pNew;

        for(int i=0;i<this->totalSize;i++){
            for(int j=0;j<p.totalSize;j++){
                int deg = i+j;
                int coeff = pNew.degCoeff[deg] + (this->degCoeff[i]*p.degCoeff[j]);
                pNew.setCoefficient(deg,coeff);
            }
        }
        return pNew;
    }
    void print(){
        for(int i=0;i<this->totalSize;i++){
            if(degCoeff[i]!=0){
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
    }    
};

int main() {
    int count1, count2, choice;
    cin >> count1;

    int * degree1 = new int[count1];
    int * coeff1 = new int[count1];

    for (int i = 0; i < count1; i++) {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++) {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int * degree2 = new int[count2];
    int * coeff2 = new int[count2];

    for (int i = 0; i < count2; i++) {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++) {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch (choice) {
        // Add
    case 1:
        result = first + second;
        result.print();
        break;
        // Subtract
    case 2:
        result = first - second;
        result.print();
        break;
        // Multiply
    case 3:
        result = first * second;
        result.print();
        break;

    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        break;
    }

    }

    return 0;
}