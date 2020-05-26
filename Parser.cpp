/* Zubair Matani
Hw8-2 Parser.cpp 
Due November 11th, 2019
*/

#include <iostream>
#include <string>
#include <stdlib.h>

#include "Parser.h"

using namespace std;


Parser::Parser(){
}

bool Parser::parse(string s){
	root = Variable(s);
	return root != NULL;
	
}

/*Base* Expression(string s){
	for(int i = 0; i < s.length(); i++){
		if((s[i] == '+') || (s[i] == '-')){
			if((Expression(s.substr(0,i)) && Expression(s.substr(i+1))) && (s.length()!=0) == true)return true;
        }
       }
			 if((s[0] == '(') && (s[s.length() -1] == ')') && (Expression(s.substr(1, s.length()-2)))) return true;
        return new Digit(s);
} */
Base* Parser::Variable(string s){
	for(int i = 0; i < s.length(); i++){
		s.erase(remove(s.begin(), s.end(), ' '), s.end());
		if(s[i] == '='){
			if((Char(s.substr(0,i)) && Digit(s.substr(i+1))) && (s.length()!=0) == true){
					Base* a = Char(s.substr(0,i));
					Base* b = Digit(s.substr(i+1));
				//mymap a = b;
					return new Assignment(a,b, &mymap);
					
			}
			else if(s[i] == '='){
				if((Char(s.substr(0,i)) && Expression(s.substr(i+1))) && (s.length()!=0) == true){
						Base* a = Char(s.substr(0,i));
						Base* b = Expression(s.substr(i+1));
					//mymap a = b;
						return new Assignment(a,b, &mymap);
					
			}
		}
			
			
	}
}


	return Expression(s);
}



Base* Parser::Expression(string s){
	for(int i = 0; i < s.length(); i++){
		s.erase(remove(s.begin(), s.end(), ' '), s.end());
		if(s[i] == '+'){
			if((Expression(s.substr(0,i)) && Term(s.substr(i+1))) && (s.length()!=0) == true){
				Base* a = Expression(s.substr(0,i));
				Base* b = Term(s.substr(i+1));
				return new Plus(a,b);
			}
		}
		else if(s[i] == '-'){
			if((Expression(s.substr(0,i)) && Term(s.substr(i+1))) && (s.length()!=0) == true){
				Base* a = Expression(s.substr(0,i));
				Base* b = Term(s.substr(i+1));
				return new Minus(a,b);
			}
		}
	}

	
	/*if((s[0] == '(') && (s[s.length() -1] == ')') && (Expression(s.substr(1, s.length()-2)))){
		Base* a = (Expression(s.substr(1, s.length()-2)));
		return a;
	} */
			 return Term(s);
} 

Base* Parser::Term(string s){
	for(int i = 0; i < s.length(); i++){
		s.erase(remove(s.begin(), s.end(), ' '), s.end());
		if(s[i] == '*'){
			if((Term(s.substr(0,i)) && Term2(s.substr(i+1))) && (s.length()!=0) == true){
				Base* a = Term(s.substr(0,i));
				Base* b = Term2(s.substr(i+1));
				return new Multiply(a,b);
			}
		}
		else if(s[i] == '/'){
			if((Term(s.substr(0,i)) && Term2(s.substr(i+1))) && (s.length()!=0) == true){
				Base* a = Term(s.substr(0,i));
				Base* b = Term2(s.substr(i+1));
				return new Divide(a,b);
			}
		}
	}
	return Term2(s);
}

Base* Parser::Term2(string s){
	for(int i = 0; i < s.length(); i++){
		s.erase(remove(s.begin(), s.end(), ' '), s.end());
		if(s[i] == '%'){
			if((Term2(s.substr(0,i)) && Factor(s.substr(i+1))) && (s.length()!=0) == true){
				Base* a = Term2(s.substr(0,i));
				Base* b = Factor(s.substr(i+1));
				return new Modulo(a,b);
			}
		}
		else if(s[i] == '^'){
			if((Term2(s.substr(0,i)) && Factor(s.substr(i+1))) && (s.length()!=0) == true){
				Base* a = Term2(s.substr(0,i));
				Base* b = Factor(s.substr(i+1));
				return new Power(a,b);
			}
		}
	}
	return Factor(s);
}

Base* Parser::Factor(string s){
	/*for(int i = 0; i < s.length(); i++){
		s.erase(remove(s.begin(), s.end(), ' '), s.end());
		if(s[i] == '^'){
			if((Expression(s.substr(0,i)) && Term(s.substr(i+1))) && (s.length()!=0) == true){
				Base* a = Factor(s.substr(0,i));
				Base* b = Factor(s.substr(i+1));
				return new Power(a,b);
			}
		}
	} */
		/*else if(s[i] == '-'){
			if((Expression(s.substr(0,i)) && Term(s.substr(i+1))) && (s.length()!=0) == true){
				Base* a = Expression(s.substr(0,i));
				Base* b = Term(s.substr(i+1));
				return new Minus(a,b);
			}
		}
	} */
	
	if((s[0] == '(') && (s[s.length() -1] == ')') && (Variable(s.substr(1, s.length()-2)))){
		Base* a = (Variable(s.substr(1, s.length()-2)));
		return a;
	} 
	if(Digit(s)){
		return Digit(s);
	}
	return Char(s);
} 




Base* Parser::Digit(string s){
	if(s.length() == 0) return NULL;
    for(int i = 0; i < s.length(); i++){
        if(s[i]<'0' || s[i]>'9')return NULL;
    }
    return new Val(atoi(s.c_str()));
}
	
Base* Parser::Char(string s){
	if(s.length() == 0) return NULL;
    for(int i = 0; i < s.length(); i++){
        if(s[i]<'a' || s[i]>'z')return NULL;
    }
    return new Alphabet(s, &mymap);	
}

int Parser::nodeCount(){
	return root->nodeCount();
}
int Parser::eval(){
	return root->eval();
}

int Parser::eval(string s){
	root = Variable(s);
	if(root) return root->eval();
	return -1;
}

void Parser::varDump(){
	//cout << "mymap contains:\n";
  for (map<string, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it){
    //std::cout << it->first << " => " << it->second << '\n';
	}
	
	
}
void Parser::varClear(){
	mymap.clear();
}




                      




