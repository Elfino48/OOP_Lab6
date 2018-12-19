/* Кенгерли Эльмар, ИП-72 Вариант 13, уровень Б

Лабораторная работа №6
Спроектувати клас «Fraction», який містить: дріб в форматі «±m/n», правильну чи неправильну. 
Для нього визначити: операцію присвоєння «=», операції «==» та «!=». Продемонструвати кожну операцію.
Додати виключення.

*/
#include "stdafx.h"
#include "string"
#include "iostream"
using namespace std;

class Error {

  public:

    Error(string ms) {

      report(ms);

    }

  void report(string ms) {

    cout << ms << ": division by zero!" << endl;

  }

};

class Fraction {

  public:

    string secTr = "",
    firsTr = "";
  double value;

  Fraction(string ms) throw (Error) {

    frac = ms;

    int pos = frac.find("/");
    secTr = frac.substr(pos + 1);
    firsTr = frac.substr(0, pos);

    if (secTr == "0") throw Error(ms);

    try {
      value = (stod(firsTr) / stod(secTr));
    } catch (invalid_argument e) {
      cout << ms << ": Cannot convert letters to numbers\n";
    }

  }

  Fraction operator = (string a) {
    return Fraction(a);
  }

  string frac = "";

  double getDouble() {

    return value;
  }

  const bool operator == (Fraction & newFr) {

    if (this - > getDouble() == newFr.getDouble()) {

      return true;

    } else {
      return false;
    }

  }

  const bool operator != (Fraction & newFr) {

    if (this - > getDouble() == newFr.getDouble()) {

      return false;

    } else {
      return true;
    }

  }

};

int main() {
  Fraction * fr = new Fraction("-a/5");
  Fraction * fr1 = new Fraction("4.5/5");
  Fraction * fr2 = new Fraction("-4.5/5");

  try {

    Fraction * errFr = new Fraction("4/0");

  } catch (Error e) {}

  if ( * fr == * fr2)
    cout << "fr (-4.5/5) == fr2 (-4.5/5)\n";
  if ( * fr != * fr1)
    cout << "fr (-4.5/5) != fr1 (4.5/5)\n";
  system("pause");
  return 0;
}
