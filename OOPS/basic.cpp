/*
    BASIC OOP CONCEPTS
*/

#include <iostream>
using namespace std;

// class
class Hero{
    // access modifiers
    private:
    int health;

    public:
    int level;
    char *name;

    // default Constructor
    Hero(){
        cout<<"Default Constructor"<<endl;
    }
    // parametrized constructor
    Hero(int health, int level){
        cout<<"Parametrized Constructor called"<<endl;
        this->health = health;
        this->level = level;
    }
    // copy constructor
    Hero(Hero& temp){
        cout<<"Copy Constructor called"<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    // Setter and getter methods
    void setDetails(int health, int level){
        cout<<"Address of this:"<<this<<endl;
        this->health = health;
        this->level = level;
    }
    void getDetails(){
        cout<<"Health: "<<this->health<<endl;
        cout<<"Level: "<<this->level<<endl;
        
    }

};

int main(){
    // Static Object 
    Hero h1;
    cout<<"Address of h1:"<<&h1<<endl;
    h1.setDetails(40, 1);
    h1.getDetails();

    // Dynamic Object
    Hero *h2 = new Hero();
    cout<<"Address of h2:"<<h2<<endl;
    (*h2).setDetails(22,2); 
    h2->getDetails();

    return 0;
}