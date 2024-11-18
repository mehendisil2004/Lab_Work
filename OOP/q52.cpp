#include<iostream>
using namespace std;
#define maxi  1000

class Overflow{
  const char * msg;
  public:
  Overflow():msg("overflowed"){};
    void showMsg(){
        cout<<"===ERROR==="<<endl;
        cout<<msg<<endl;
        cout<<"===END==="<<endl;
    }
};
class Underflow{
  const char * msg;
  public:
  Underflow():msg("underflowed"){};
    void showMsg(){
        cout<<"===ERROR==="<<endl;
        cout<<msg<<endl;
        cout<<"===END==="<<endl;
    }
};

template <class T>
class Stack{
  int top;
  T data[maxi];
  public:
  Stack(){
    top = -1;
  }
  void push(T a){
    if(top == maxi-1) throw Overflow();
    data[++top]=a;
  };
  T pop(){
    if(top <= -1) throw Underflow();
    return data[top--];
  };
  bool isEmpty(){return top == -1 ? 1 : 0;}
  T show_top(){
    return data[top];
  }
};

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
    cout<<"re "<<re<<" "<<"img " <<img<<endl;
  }
};


int main(){
  Stack<Complex> st;
  st.push(Complex(1,5));
  st.push(Complex(2,4));
  st.push(Complex(3,3));
  st.push(Complex(4,2));
  st.push(Complex(5,1));
  st.pop().show();
  st.pop().show();
  st.pop().show();
  st.pop().show();
}