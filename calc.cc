/*
 * =====================================================================================
 *
 *       Filename:  calc.cc
 *
 *    Description:  A series of calculator functions 
 *
 *         Author:  Jeff Dyck
 *
 * =====================================================================================
 */

#include "calc.h"

// Constructor
Calc::Calc () {
   this->error = false;
   this->display = 0;
   this->oper = '0';
   this->result = 0;
   this->memory = 0;
}

// Copy constructor
Calc::Calc (const Calc &other) { 
   this->error = other.error;
   this->display = other.display;
   this->oper = other.oper;
   this->result = other.result;
   this->memory = other.memory;
}

/*
 * Adds the given digit to the display
 */
void Calc::digit(int digit){
   if (! this->error) {
      this->display = this->display * 10 + digit;
      return;
   }
}

/*
 * Sets the operator field. 
 * If operator was previously set, combines display and result with that operator
 * Otherwise display is copied to result.
 * Clears display afterwards
 */
void Calc::op(char oper){
   if (this->oper == '0') {
      this->oper = oper;
      this->result = this->display;
   } else if (! this->error) {
      switch(this->oper) {
         case '+':   this->result += this->display; break;
         case '-':   this->result -= this->display; break;
         case '*':   this->result *= this->display; break;
         case '/':   if (this->display == 0){
                        this->error = true;
                        this->result = 0;
                     } else {
                        this->result /=  this->display;
                     }
                     break;
      } // switch

      this->oper = oper;
   }

   this->display = 0;
   return;
}

/*
 * Combines result and display using the operator, and stores the result in 
 * result and display
 * Clears the operator field
 */
void Calc::equals(){
   if (! this->error) {
      switch(this->oper) {
         case '+':   this->result = this->display = this->result + this->display; break;
         case '-':   this->result = this->display = this->result - this->display; break;
         case '*':   this->result = this->display = this->result * this->display; break;
         case '/':   if (this->display == 0) {
                        this->error = true;
                        this->result = 0;
                        break;
                     } else {
                        this->result = this->display = this->result / this->display; break;
                     }
      } // switch
   } // if

   this->oper = '0';
   return;
}



/*
 * Adds the displayed value to the contents of memory and stores it in memory
 */
void Calc::memPlus(){
   if (! this->error) {
      this->memory += this->display;
   }
}

/*
 * Clears the calculator's memory
 */
void Calc::memClear(){
   if (! this->error) {
      this->memory = 0;
   }

   return;
}

/*
 * Brings the calculator's memory value to the display
 */
void Calc::memRecall(){
   if (! this->error) {
      this->display = this->memory;
   }
   return;
}

/*
 * Returns the calculator's memory flag
 */
bool Calc::isError() const{
   return this->error;
}

/*
 * Clears all of the calculator's stored values
 */
void Calc::allClear(){
   this->display = 0;
   this->result = 0;
   this->memory = 0;
   this->error = false;
   this->oper = '0';
   return;
}

/*
 * Overloads the << operator
 * Prints the calculator's result field
 * Also prints the memory value and error indicator if applicable
 */
std::ostream &operator<<(std::ostream &out, const Calc &c) {
   out << c.result;

   if (c.memory != 0) {
      out << " M: " << c.memory;
   }

   if (c.error) { 
      out << " E";
   }

   return out;
}


