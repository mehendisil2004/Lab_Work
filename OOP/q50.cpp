#include<iostream>
using namespace std;


template <class T>
T Max(T a, T b){
  return a > b ? a: b;
}

#include<string.h>
template<>
const char * Max(const char *a, const char * b){
  return strlen(a) > strlen(b) ? a : b;
}

class Complex{
  int re, img;
  public:
  Complex(int re = 0, int img = 0){
    this-> re  = re;
    this-> img  = img;
  }
  
  bool operator > (const Complex & obj){
    if(this->re > obj.re)  return 1;
    if(this->img > obj.img) return 1;
    return 0;
  }
  void show(){
    cout<<"re "<<re<<" "<<"img " <<img;
  }
};


int main(){
  Complex c1(2,1), c2(5,2);
  Complex a = Max(c1,c2);
  a.show();
  cout<<Max("1234","12345")<<endl;
}