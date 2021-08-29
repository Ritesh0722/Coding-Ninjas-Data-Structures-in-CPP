#include<bits/stdc++.h>
using namespace std;

// Declaring a template (Generic template)
template <typename T, typename V>

// Multiple datatypes in a template
class Pair {
    T x;
    V y;

    public:
    void setX(T x) {
        this -> x = x;
    }

    T getX(){
        return x;
    }
    
    void setY(V y) {
        this -> y = y;
    }

    V getY(){
        return y;
    }
};

/*
template <typename T>

class Pair {
    T x;
    T y;

    public:
    void setX(T x) {
        this -> x = x;
    }

    T getX(){
        return x;
    }
    
    void setY(T y) {
        this -> y = y;
    }

    T getY(){
        return y;
    }
};
*/

int main(){

    Pair<Pair<int, int>, int> p4;   //Taking a datatype as Pair to have three values 
    Pair<int, int> p5;

    p5.setX(10);
    p5.setY(20);

    p4.setX(p5); //passing a pair or int, int in X 
    p4.setY(30);

    cout<< p4.getX().getX() << " " << p4.getX().getY() << " " << p4.getY() << endl;

    /*
    Pair<int, double> p3;
    p3.setX(100);
    p3.setY(50.23);

    cout<< p3.getX() << " " << p3.getY() << endl;
    */

    /*
    Pair<int> p1;    //the data type is being stated in the angular brackets as to set the template for that particular object
    p1.setX(10);
    p1.setY(20);

    cout<< p1.getX() << " " << p1.getY() << endl;

    Pair<double> p2;
    p2.setX(100.23);
    p2.setY(50.23);

    cout<< p2.getX() << " " << p2.getY() << endl;
    */
}