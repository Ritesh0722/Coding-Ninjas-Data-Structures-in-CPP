#include<bits/stdc++.h>
using namespace std;

class Fraction {
	private :

		int numerator;
		int denominator;

	public :

		Fraction() {
			
		}

		Fraction(int numerator, int denominator) {
			this -> numerator = numerator;
			this -> denominator = denominator;
		}

		int getNumerator() const {
			return numerator;
		}
		
		int getDenominator() const {
			return denominator;
		}

		void setNumerator(int n) {
			numerator = n;
		}

		void setDenominator(int d) {
			denominator = d;
		}

		void print() const {
			cout << this -> numerator << " / " << denominator << endl;
		}

		void simplify() {
			int gcd = 1;
			int j = min(this -> numerator, this -> denominator);
			for(int i = 1; i <= j; i++) {
				if(this -> numerator % i == 0 && this -> denominator % i == 0) {
					gcd = i;
				}
			}
			this -> numerator = this -> numerator / gcd;
			this -> denominator = this -> denominator / gcd;
		}

		Fraction add(Fraction const &f2) {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			// numerator = num;
			// denominator = lcm;
            Fraction fNew(num, lcm);
            fNew.simplify();
			return fNew;
		}

        //Overloading '+' operator
		Fraction operator+(Fraction const &f2) const {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			Fraction fNew(num, lcm);
            fNew.simplify();
			return fNew;
		}

		Fraction multiply(Fraction const &f2) {
			int n = numerator * f2.numerator;
			int d = denominator * f2.denominator;
			Fraction fNew(n, d);
			fNew.simplify();
            return fNew;
		}

        //Overloading '*' operator
		Fraction operator*(Fraction const &f2) const {
			int n = numerator * f2.numerator;
			int d = denominator * f2.denominator;
			Fraction fNew(n, d);
			fNew.simplify();
            return fNew;
		}

        //Overloading '==' operator
        bool operator==(Fraction &f2) {
            simplify();
            f2.simplify();
            return (numerator == f2.numerator && denominator == f2.denominator);
        }

        //Overloading '++' (pre-increment) operator
        Fraction& operator++() {                                //Returning by reference
            numerator = numerator + denominator;
            simplify();

            return *this;
        }

        //Overloading '++' (pre-increment) operator
        Fraction operator++(int) {                                //Returning by reference
            Fraction fNew(numerator, denominator);
            numerator = numerator + denominator;
            simplify();
            fNew.simplify();
            return fNew;
        }

        //Overloading '+=' operator
		Fraction& operator+=(Fraction const &f2) {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

            numerator = num;
            denominator = lcm;
			simplify();
            return *this;
		}
};

int main() {
    Fraction f1(10, 2);
	Fraction f2(15, 4);

    // f1.print();
    // f1 += f2;
    f1.print();
    (f1 += f2) += f2;
    f1.print();

    /*
	Fraction f1(10, 2);
	Fraction f2(15, 4);
    f1.print();
    f2.print();
    
    Fraction f3 = f1.add(f2);
    f3.print();
    Fraction f4 = f1 + f2;
    f4.print();
    
    Fraction f5 = f1.multiply(f2);
    f5.print();
	Fraction f6 = f1 * f2;
    f6.print();

    cout<< ((f1 == f2)? "Equal" : "Not Equal");
    */

    /*
    f1.print();
    // f1++;
    Fraction f7 = ++f1;
    Fraction f8 = ++(++f1);
    f1.print();
    f7.print();
    f8.print();
    */

    // f1.print();
    // Fraction f9 = f1++;
    // f9.print();
}