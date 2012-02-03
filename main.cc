#include <iostream>
#include "calc.h"

using namespace std;

int main() {
  Calc c;
  char ch;
  bool memOp = false;
  bool ac = false;
  while (cin >> ch) {
    switch(ch) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
         c.digit(ch - '0');
         break;
      case 'M': memOp = true; break;
      case 'R': if (memOp) c.memRecall(); memOp = false; break;
      case 'C': if (memOp) { c.memClear(); memOp = false; }
                if (ac) { c.allClear(); ac = false; } break;
      case '+': if (memOp) c.memPlus();
                else c.op('+');
                memOp = false; break;
      case '-': case '*': case '/': c.op(ch); break;
      case 'A': ac = true; break; 
      case '=': c.equals(); cout << c << endl; break;
    }
  }  
}

