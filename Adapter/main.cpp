#include <iostream>
using namespace std;



class AbstractT800 {
public:
  virtual void moveSlow() = 0;
  virtual void moveFast() = 0;
  virtual void transform() = 0;
  virtual void block() = 0;
  virtual void strike() = 0;
};


class T800 : public AbstractT800 {

public:

  void moveSlow() {
      cout << "is moving slow" << endl;
  }
  void moveFast() {
      cout << "is moving fast" << endl;
  }
  void transform(){
      cout << "is transforming" << endl;
  }
  void block(){
      cout << "is blocking attack" << endl;
  }
  void strike(){
      cout << "is striking oponent" << endl;
  }
};


class AbstractT1000 {

public:
  virtual void walk() = 0;
  virtual void sprint() = 0;
  virtual void adapt() = 0;
  virtual void parry() = 0;
  virtual void  attack() = 0;

};


class T1000 : public AbstractT1000 {

public:

  void walk() {
      cout << "is walking" << endl;
  }
  void sprint() {
      cout << "is sprinting" << endl;
  }
  void adapt(){
      cout << "is adapting to its environment" << endl;
  }
  void parry(){
      cout << "is parrying incoming attack" << endl;
  }
  void attack(){
      cout << "is attacking its oponent" << endl;
  }

};


class T1000toT800Adapter : public T800 {

public:
    AbstractT1000 *T1000;

    T1000toT800Adapter(AbstractT1000 *T1000) {
        this -> T1000 = T1000;
    }

    void moveSlow() {
        T1000 -> walk();
    }
    void moveFast() {
        T1000 -> sprint();
    }
    void transform(){
        T1000 -> adapt();
    }
    void block(){
        T1000 -> parry();
    }
    void strike(){
        T1000 -> attack();
    }

};

class T800toT1000Adapter : public T1000 {

public:
    AbstractT800 *T800;

    T800toT1000Adapter(AbstractT800 *T800) {
        this -> T800 = T800;
    }

    void walk(){
        T800 -> moveSlow();
    }

    void sprint(){
        T800 -> moveFast();
    }

    void adapt(){
        T800 -> transform();
    }

    void parry(){
        T800 -> block();
    }

    void attack(){
        T800 -> strike();
    }

};

int main()
{

  T800 *myT800 = new T800;

  T1000 *myT1000 = new T1000;
  //el T1000 se adapta para utilizar los metodos del T800
  //Objetivo = Adaptador(Adaptado)
  T800 *adaptedT1000 = new T1000toT800Adapter(myT1000);

  cout << "T1000 ";
  myT1000 -> walk();
  cout << "T800 ";
  myT800 -> moveSlow();
  cout << "Adapted T1000 ";
  adaptedT1000 -> moveSlow();

  delete myT800;
  delete myT1000;
  delete adaptedT1000;


  return 0;
}