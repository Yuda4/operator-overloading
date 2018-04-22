#include <iostream>
using namespace std;
#include <string>
#include <sstream>

class CircularInt {
    public:
    int min, max;
    int current;
	
	
    CircularInt(int minimum, int maximum); // c'tor
    CircularInt(const CircularInt& other); // copy c'tor
    
    CircularInt& check(int fix); //checking the modulo
    
    CircularInt operator=(const CircularInt& other); // copy assignment
    
   //operator add
    CircularInt operator+(int num);
    CircularInt operator+(CircularInt& other);
    friend CircularInt operator+(int nMember, CircularInt& member);
    CircularInt& operator+=(int num);
    CircularInt& operator++(void);
    CircularInt operator++(int unused);
    
    //operator minus
    CircularInt operator-(void);
    CircularInt operator-(int num);
    CircularInt operator-(CircularInt& other);
    friend CircularInt operator-(int nMember, CircularInt& member);
    CircularInt& operator-=(int num);
    CircularInt& operator--(void);
    CircularInt operator--(int unused);
    
    // operator multiplication
    CircularInt operator*(int num);
    CircularInt& operator*=(int num);
    friend CircularInt operator*(int nMember, CircularInt& member);
    
    //operator division
    CircularInt operator/(int num);
    CircularInt& operator/=(int num);
    friend CircularInt operator/(int nMember, CircularInt& member);
    
    //comperator
    bool operator< (const CircularInt& other) const;
    bool operator> (const CircularInt& other) const;
    bool operator<=(const CircularInt& other) const;
    bool operator>=(const CircularInt& other) const;
    bool operator==(const CircularInt& other) const;
    bool operator!=(const CircularInt& other) const;

};
