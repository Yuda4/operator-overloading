#include "CircularInt.hpp"

//constractor
    CircularInt::CircularInt( int minimum, int maximum){
      this->min = minimum;
      this->max = maximum;
      this->current = minimum;
    }
//constractor copy
    CircularInt::CircularInt(const CircularInt& other){
      int min = other.min;
      int max = other.max;
      int current =other.current;
      this->min = min;
      this->max = max;
      this->current = current;
    }

//fix the circular
    CircularInt& CircularInt :: check(int fix){
        //check if greather then max
        if(fix > this-> max){
          do{
             fix %= this-> max;
             //check if modolu is zero
             if(fix == 0) fix = this-> max;
             //check if smaller then min
             if(fix < min) fix += min;
          }while(fix > this-> max);
          this-> current = fix;
          return *this;
        }
        //check if negative
        if(fix < 0){
          do{
            fix *= -1;
            fix %= this-> max;
            fix = this-> max - fix;
          }while(fix < 0);
          this-> current = fix;
          return *this;
        }
        //check if smaller then min
        if(fix < min){
          fix += min;
          while(fix > this-> max){
               fix %= this-> max;
               //check if modolu is zero
               if(fix == 0) fix = this-> max;
               //check if smaller then min
               if(fix < min) fix += min;
          }
        } 
        this-> current = fix;
        return *this;
    }

// define overloaded = (equ-) operator\
//copy
    CircularInt CircularInt::operator= (const CircularInt& other){
      current = other.current;
      max = other.max;
      min = other.min;
      return *this;
    }
    CircularInt CircularInt::operator=(const int& num){
         this-> current = num;
         check(this-> current);
         return *this;
     }

// defie overloaded + (plus) operator
    CircularInt CircularInt::operator+ (int num)const{
      CircularInt result(*this);
      result.current += num;
      result.check(result.current);
      return result;
    }
    
    CircularInt CircularInt::operator+ (CircularInt& other)const{
      CircularInt result(*this);
      result.current += other.current;
      result.check(result.current);
      return result;
    }
    
    CircularInt& CircularInt::operator+=(int num){
      this-> current += num;
      check(this-> current);
      return *this;
    }
    
    CircularInt& CircularInt::operator+=(CircularInt& other){
      this-> current += other.current;
      check(this-> current);
      return *this;
    }
    
    CircularInt operator+ (int nMember, CircularInt& member){
        CircularInt result(member);
        return result.check(nMember + member.current);;
    }
    
    CircularInt& CircularInt::operator++(void){ //A++
         ++(this-> current);
         return *this;
    }
    
    CircularInt CircularInt::operator++(const int){ //++A
         CircularInt post (*this);
         ++(this-> current);
         return post;
    }
    
// defie overloaded - (minus) operator
    CircularInt CircularInt::operator- (void)const{
      CircularInt result(*this);
      result.check(-(this-> current));
      return result;
    }
    
    CircularInt CircularInt::operator- (int num)const{
      CircularInt result(*this);
      result.current -= num;
      result.check(result.current);
      return result;
    }
    
    CircularInt CircularInt::operator- (CircularInt& other)const{
      CircularInt result(*this);
      result.current -= other.current;
      result.check(result.current);
      return result;
    }
    
    CircularInt operator- (int nMember, CircularInt& member){
        CircularInt result(member);
        result.check(nMember - member.current);
        return result;
    }

    CircularInt& CircularInt::operator-=(int num){
      this-> current -= num;
      check(this-> current);
      return *this;
    }
    
    CircularInt& CircularInt::operator-=(CircularInt& other){
      this-> current -= other.current;
      check(this-> current);
      return *this;
    }
    
    CircularInt& CircularInt::operator--(void){ //A--
         --(this-> current);
         return *this;
    }
    
    CircularInt CircularInt::operator--(const int){ //--A
          CircularInt post(*this);
         --(this-> current);
         return post;
    }

// defie overloaded * (multi-) operator
    CircularInt CircularInt::operator* (int num)const{
      CircularInt result(*this);
      result.current *= num;
      result.check(result.current);
      return result;
    }
    
    CircularInt CircularInt::operator* (CircularInt& other)const{
      CircularInt result(*this);
      result.current *= other.current;
      result.check(result.current);
      return result;
    }
    
    CircularInt& CircularInt::operator*=(int num){
      this-> current *= num;
      check(this-> current);
      return *this;
    }
    
    CircularInt& CircularInt::operator*=(CircularInt& other){
      this-> current *= other.current;
      check(this-> current);
      return *this;
    }
    
    CircularInt operator*(int nMember, CircularInt& member){
        CircularInt result(member);
        return result.check(nMember * member.current);;
    }

// defie overloaded / (div-) operator
     CircularInt CircularInt::operator/ (int num)const{
      try{
        if(num == 0) {
          throw "Division by zero is forbidden!";
        }
        if(current%num != 0) {
          double divi = (current*1.0)/num;
          ostringstream oss;
          oss << "There is no number " << divi << " in {" << min << "," << max << "} such that " << divi << "*" << num << "=" << current; 
          string msg = oss.str();
          throw msg;
        }
        CircularInt result(*this);
        result.current /= num;
        result.check(result.current);
        return result;
      }catch (const char* msg) {
        cerr << msg << endl;
      }
      return *this;
    }
    
    CircularInt CircularInt::operator/ (CircularInt& other)const{
      try{
        if(other.current == 0) {
          throw "Division by zero is forbidden!";
        }
        if(current%other.current != 0) {
          double divi = (current*1.0)/other.current;
          ostringstream oss;
          oss << "There is no number " << divi << " in {" << min << "," << max << "} such that " << divi << "*" << other.current << "=" << current; 
          string msg = oss.str();
          throw msg;
        }
        CircularInt result(*this);
        result.current /= other.current;
        result.check(result.current);
        return result;
      }catch (const char* msg) {
        cerr << msg << endl;
      }
      return *this;
    }
    
     CircularInt& CircularInt::operator/=(int num){
               try{
        if(num == 0) {
          throw "Division by zero is forbidden!";
        }
        if(current%num != 0) {
          double divi = (current*1.0)/num;
          ostringstream oss;
          oss << "There is no number " << divi << " in {" << min << "," << max << "} such that " << divi << "*" << num << "=" << current; 
          string msg = oss.str();
          throw msg;
        }
        this-> current /= num;
        check(this-> current);
        return *this;
      }catch (const char* msg) {
        cerr << msg << endl;
      }
      return *this;
    }
    
    CircularInt& CircularInt::operator/=(CircularInt& other){
               try{
        if(other.current == 0) {
          throw "Division by zero is forbidden!";
        }
        if(current%other.current != 0) {
          double divi = (current*1.0)/other.current;
          ostringstream oss;
          oss << "There is no number " << divi << " in {" << min << "," << max << "} such that " << divi << "*" << other.current << "=" << current; 
          string msg = oss.str();
          throw msg;
        }
        this-> current /= other.current;
        check(this-> current);
        return *this;
      }catch (const char* msg) {
        cerr << msg << endl;
      }
      return *this;
    }
    
    CircularInt operator/ (int nMember, CircularInt& member){
         try{
        if(member.current == 0) {
          throw "Division by zero is forbidden!";
        }
        if(nMember%member.current != 0) {
          double divi = (nMember*1.0)/member.current;
          ostringstream oss;
          oss << "There is no number " << divi << " in {" << member.min << "," << member.max << "} such that " << divi << "*" << member.current << "=" << nMember; 
          string msg = oss.str();
          throw msg;
        }
        CircularInt result(member);
        return result.check(nMember / member.current);;
      }catch (const char* msg) {
        cerr << msg << endl;
      }
      return member;
    }
    
    //comperator
    //CircularInt - CircularInt
    bool CircularInt::operator< (const CircularInt& other) const{ return this-> current < other.current; }
    bool CircularInt::operator> (const CircularInt& other) const{ return this-> current > other.current; }
    bool CircularInt::operator<=(const CircularInt& other) const{ return this-> current <= other.current; }
    bool CircularInt::operator>=(const CircularInt& other) const{ return this-> current >= other.current; }
    bool CircularInt::operator==(const CircularInt& other) const{ return this-> current == other.current; }
    bool CircularInt::operator!=(const CircularInt& other) const{ return this-> current != other.current; }
    
    //CircularInt - int
    bool CircularInt::operator< (const int other) const{ return this-> current < other; }
    bool CircularInt::operator> (const int other) const{ return this-> current > other; }
    bool CircularInt::operator<=(const int other) const{ return this-> current <= other; }
    bool CircularInt::operator>=(const int other) const{ return this-> current >= other; }
    bool CircularInt::operator==(const int other) const{ return this-> current == other; }
    bool CircularInt::operator!=(const int other) const{ return this-> current != other; }
    
  /*  
     //comperator
     int CircularInt::checkBool(int fix){
        int mod = CircularInt::max - CircularInt::min + 1;
        //check if greather then max
        if(fix >max){
             fix = fix % mod;
             //check if modolu is zero
             if(fix == 0) fix = max;
             //check if smaller then min
             if(fix < min) fix += min;
             return fix;
        }
        //check if negative
        if(fix < 0){
            fix *= -1;
            fix %= mod;
            fix = max - fix;
            return fix;
        }
        //check if smaller then min
        if(fix < min) fix += min;
        return fix;
    }
    */
