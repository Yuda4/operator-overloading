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

    CircularInt& check(int); //checking the modulo
    
    CircularInt operator= (const CircularInt& other); // copy assignment
    CircularInt operator= (const int& num);
    
   //operator add
    CircularInt operator+ (int num)const;
    CircularInt operator+ (CircularInt& other)const;
    friend CircularInt operator+ (int nMember, CircularInt& member);
    CircularInt& operator+=(int num);
    CircularInt& operator+=(CircularInt& other);
    CircularInt& operator++(void);
    CircularInt operator++(const int);
    
    //operator minus
    CircularInt operator- (void)const;
    CircularInt operator- (int num)const;
    CircularInt operator- (CircularInt& other)const;
    friend CircularInt operator- (int nMember, CircularInt& member);
    CircularInt& operator-=(int num);
    CircularInt& operator-=(CircularInt& other);
    CircularInt& operator--(void);
    CircularInt operator--(const int);
    
    // operator multiplication
    CircularInt operator* (int num)const;
    CircularInt operator* (CircularInt& other)const;
    CircularInt& operator*=(int num);
    CircularInt& operator*=(CircularInt& other);
    friend CircularInt operator*(int nMember, CircularInt& member);
    
    //operator division
    CircularInt operator/ (int num)const;
    CircularInt operator/ (CircularInt& other)const;
    CircularInt& operator/=(int num);
    CircularInt& operator/=(CircularInt& other);
    friend CircularInt operator/(int nMember, CircularInt& member);
    
    //comperator
    //CircularInt - CircularInt
    bool operator< (const CircularInt& other) const;
    bool operator> (const CircularInt& other) const;
    bool operator<=(const CircularInt& other) const;
    bool operator>=(const CircularInt& other) const;
    bool operator==(const CircularInt& other) const;
    bool operator!=(const CircularInt& other) const;
    //CircularInt - int
    bool operator< (const int other) const;
    bool operator> (const int other) const;
    bool operator<=(const int other) const;
    bool operator>=(const int other) const;
    bool operator==(const int other) const;
    bool operator!=(const int other) const;

    //output stream
    friend ostream& operator<<(ostream& os, const CircularInt& cirInt);
    //input stream
    friend istream& operator>> (istream& is, const CircularInt& cirInt);
};

//output stream
    inline ostream& operator<<(ostream& os, const CircularInt& cirInt){
        os << cirInt.current;
        return os;
    }
    //input stream
    inline istream& operator>> (istream& is, const CircularInt& cirInt) {
        int current;
        is>>current;
	 this-> current =current;
        check(this->current);
        return is;  
    }  
    
    //int - CircularInt
    inline bool operator==(const int& nMember, const CircularInt& member){ return nMember == member.current; }
    inline bool operator!=(const int& nMember, const CircularInt& member){ return nMember != member.current;}
    inline bool operator< (const int& nMember, const CircularInt& member){ return nMember < member.current; }
    inline bool operator> (const int& nMember, const CircularInt& member){ return  nMember > member.current;}
    inline bool operator<=(const int& nMember, const CircularInt& member){ return nMember <= member.current;}
    inline bool operator>=(const int& nMember, const CircularInt& member){ return nMember >= member.current;}
