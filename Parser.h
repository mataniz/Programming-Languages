/* Zubair Matani
Hw8-2 Parser.cpp 
Due November 11th, 2019
*/


#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <iterator>

using namespace std;

class Base{
public:
  virtual ~Base(){};         
	
  virtual int eval() = 0;
	virtual int nodeCount() = 0;
	virtual string getValue(){
		return "";
	}; 
	  
};



class Val: public Base{
public:
  Val(int value){
    this->value = value;
		this->x = 1;
  }
  int eval(){
    return value;
  }
	
	int nodeCount(){
		return 1;
	}
private:
  int value;
	int x;
};

class Alphabet: public Base{
public:
  Alphabet(string value, map<string, int>* map){
    this->value = value;
		this->x = 1;
		this->map = map;
		//this->mymap = mymap;
  }
  int eval(){
		if(map->count(value) == 0){
			//cout << "not found " << value << endl;
			
 			return -1;
		}
		
		// TODO print if value is not a key in mymap
		return map->find(value)->second;
    //return value;
		//return -1;
  }
	string getValue(){
		return value;
	}
	
	int nodeCount(){
		return 1;
	}
private:
  string value;
	int x;
	map<string,int>* map;
};

class Assignment: public Base{
public:
  Assignment(Base* a, Base* b, map<string,int>* map){
    left = a;
    right = b;
		this->map = map;
  }

  ~Assignment(){
    cout << "Assignment destruct " << endl;
    delete left;
    delete right;
    left = NULL;
    right = NULL;
  }

  int eval(){
		//cout << "Left" << left->getValue() << endl;
		int ret = right->eval();
		map->erase(left->getValue());
    map->insert(pair<string, int>(left->getValue(), ret));
		return ret;
  }
	
	int nodeCount(){
		return 1 + left->nodeCount() + right->nodeCount();
	}
private:
  Base* left;
  Base* right;
	map<string,int>* map;
};

class Plus: public Base{
public:
  Plus(Base* a, Base* b){
    left = a;
    right = b;
  }

  ~Plus(){
    cout << "plus destruct " << endl;
    delete left;
    delete right;
    left = NULL;
    right = NULL;
  }

  int eval(){
    return left->eval() + right->eval();
  }
	
	int nodeCount(){
		return 1 + left->nodeCount() + right->nodeCount();
	}
private:
  Base* left;
  Base* right;
};
	class Minus: public Base{
	public:
	  Minus(Base* a, Base* b){
	    left = a;
	    right = b;
	  }

	  ~Minus(){
	    cout << "minus destruct " << endl;
	    delete left;
	    delete right;
	    left = NULL;
	    right = NULL;
	  }

	  int eval(){
	    return left->eval() - right->eval();
	  }
	
		int nodeCount(){
			return 1 + left->nodeCount() + right->nodeCount();
		}
private:
  Base* left;
  Base* right;
};
class Multiply: public Base{
public:
  Multiply(Base* a, Base* b){
    left = a;
    right = b;
  }

  ~Multiply(){
    cout << "Multiply destruct " << endl;
    delete left;
    delete right;
    left = NULL;
    right = NULL;
  }

  int eval(){
    return left->eval() * right->eval();
  }
	
	int nodeCount(){
		return 1 + left->nodeCount() + right->nodeCount();
	}
private:
  Base* left;
  Base* right;
};


class Divide: public Base{
public:
  Divide(Base* a, Base* b){
    left = a;
    right = b;
  }

  ~Divide(){
    cout << "Divide destruct " << endl;
    delete left;
    delete right;
    left = NULL;
    right = NULL;
  }

  int eval(){
    return left->eval() / right->eval();
  }
	
	int nodeCount(){
		return 1 + left->nodeCount() + right->nodeCount();
	}
private:
  Base* left;
  Base* right;
};

class Modulo: public Base{
public:
  Modulo(Base* a, Base* b){
    left = a;
    right = b;
  }

  ~Modulo(){
    cout << "Modulo destruct " << endl;
    delete left;
    delete right;
    left = NULL;
    right = NULL;
  }

  int eval(){
    return left->eval() % right->eval();
  }
	
	int nodeCount(){
		return 1 + left->nodeCount() + right->nodeCount();
	}
private:
  Base* left;
  Base* right;
};

class Power: public Base{
public:
  Power(Base* a, Base* b){
    left = a;
    right = b;
  }

  ~Power(){
    cout << "Power destruct " << endl;
    delete left;
    delete right;
    left = NULL;
    right = NULL;
  }

  int eval(){
    return pow(left->eval(),(right->eval()));
  }
	
	int nodeCount(){
		return 1 + left->nodeCount() + right->nodeCount();
	}
private:
  Base* left;
  Base* right;
};


class Parser{
public:
Parser();

bool parse(string s);

Base* Expression(string s);

Base* Digit(string s);

Base* Variable(string s);

Base* Term(string s);

Base* Term2(string s);

Base* Factor(string s);

Base* Char(string s);

void varDump();

void varClear();

int nodeCount();

int eval();

int eval(string s);

private:
  Base* root;
	map<string, int> mymap;
}; 



#endif