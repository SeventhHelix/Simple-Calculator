#ifndef __CALC_H__
#define __CALC_H__
#include <iostream>

struct Calc {
  Calc();
  Calc(const Calc &other);

  bool error;
  int display;
  char oper;
  int result;
  int memory;

  void digit(int digit);
  void op(char oper);
  void equals();

  void memPlus();
  void memClear();
  void memRecall();

  bool isError() const;

  void allClear();
};

std::ostream &operator<<(std::ostream &out, const Calc &c);

#endif

