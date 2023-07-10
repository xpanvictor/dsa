#include <iostream>
class Num {
  public:
    Num();
    Num(int a) {
      setNum(a);
    }
    int setNum(int num) {
      _num = num;
      return _num;
    }
    int getNum() {
      return _num;
    }

    Num operator=(int num) {
      Num temp(num);
      return temp;
    }

    Num operator=(Num &num) {
      Num temp(num.getNum());
      return temp;
    }

    Num operator+(Num &b) {
      Num temp;
      temp = this->getNum() * b.getNum();
      return temp;
    }
    
  private:
    int _num;
};

int main() {
  // Num v1 = 4, v2 = 6;
  // Num v3 = v1 + v2;
  std::cout << 3;

  return 0;
}
