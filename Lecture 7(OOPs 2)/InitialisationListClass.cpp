#include <iostream>
using namespace std;

class Student {
	public :
	
		int age;
		const int rollNumber;
		int &x;		// age reference variable

		//initialisation list used for setting values at the time of memory allocation
		Student(int r, int age) : rollNumber(r), age(age), x(this -> age) {
			//rollNumber = r;
			
		}
};

int main() {
	Student s1(101, 20);
	s1.age = 20;
	//s1.rollNumber = 101;
}