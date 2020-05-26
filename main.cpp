/* Zubair Matani
Hw6-1 Parser.cpp 
Done in class with the help of Dr.T and collaborated with other classmates */

	
#include <iostream>

#include "Parser.h"

using namespace std;

int main(){

  string input;
  Parser p;

  cout << ">";
  getline(cin, input);
  while(input != "exit"){
    if(p.parse(input)){
      cout << "Accepted!" << endl;
      cout << "Count: " << p.nodeCount() << endl;
      cout << "Eval: " << p.eval() << endl;
			p.varDump();
    }else{
      cout << "Not Accepted" << endl;
    }
    cout << ">";
    getline(cin, input);
  }
  cout << "Exiting!" << endl;
}
  // Create Value and Plus nodes, put them together, and see if the correct eval
  // functions are called.
  //Base* b = new parser(5);

  //delete h; // TODO verify this cleans up memory
