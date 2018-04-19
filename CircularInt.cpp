#include <iostream>
using namespace std;


class CircularInt {
    public:
    int min, max;
    int current;
	
	
    CircularInt(int minimum, int maximum);
    CircularInt(const CircularInt& other);
    
    CircularInt& check(int fix);
     
     CircularInt& operator+(int num);
     CircularInt& operator+=(int num);
     CircularInt& operator-(void);
     CircularInt& operator-(int num);
     friend CircularInt& operator -(int nMember, CircularInt& member);
     CircularInt& operator-=(int num);
     CircularInt& operator++(void);
     CircularInt& operator++(int unused);
     CircularInt& operator--(void);
     CircularInt& operator--(int unused);
	
};
    CircularInt::CircularInt( int minimum, int maximum){
      this->min = minimum;
      this->max = maximum;
      this->current = minimum;
    }
    
    CircularInt::CircularInt(const CircularInt& other){
      this->min = other.min;
      this->max = other.max;
      this->current = other.current;
    }
    
   CircularInt& CircularInt :: check(int fix){
        int mod = this-> max - this-> min + 1;
        if(fix > this-> max){
             this-> current = fix % mod;
             return *this;
        }
        if(fix < 0){
            fix *= -1;
            fix %= mod;
            this-> current = this-> max - fix;
            return *this;
        }
        this-> current = fix;
        return *this;
    }

// defie overloaded + (plus) operator
    CircularInt& CircularInt::operator+(int num){
      this-> current += num;
      this-> current = check(this->current).current;
      return *this;
    }
    
    CircularInt& CircularInt::operator+=(int num){
      operator+(num);
      return *this;
    }
    
     CircularInt& CircularInt::operator-(void){
      (this-> current) *= -1;
      return check(this-> current);
    }
    
    CircularInt& CircularInt::operator-(int num){
      this-> current -= num;
      this-> current = check(this->current).current;
      return *this;
    }
    
    CircularInt& operator -(int nMember, CircularInt& member){
        CircularInt rst(member);
        return rst.check(nMember - member.current);;
    }
    
    CircularInt& CircularInt::operator-=(int num){
      operator-(num);
      return *this;
    }
    
    ostream& operator<<(ostream& os, const CircularInt& cirInt) {
    return os << cirInt.current;
    }

    
    CircularInt& CircularInt::operator++(void){ //A++
         ++(this-> current);
         return *this;
    }
    
     CircularInt& CircularInt::operator++(int unused){ //++A
         CircularInt post (*this);
         ++(this-> current);
         return post;
    }
    
    CircularInt& CircularInt::operator--(void){ //A--
         --(this-> current);
         return *this;
    }
    
     CircularInt& CircularInt::operator--(int unused){ //--A
         CircularInt post (*this);
         --(this-> current);
         return post;
    }
    
    
// int main () {
//     CircularInt test { 1, 5 };
//     cout << test << " " << test << " " << endl;
    
//     return 0;
    
// }
