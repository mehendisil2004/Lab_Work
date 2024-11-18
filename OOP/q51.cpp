#include<iostream>
using namespace std;
#define maxi  1000

template <class T>
void Swap(T &a, T &b){
  T temp = a ;
  a = b;
  b = temp;
}


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
class Stack{
  int top;
  int data[maxi];
  public:
  Stack(){
    top = -1;
  }
  void push(int a){
    if(top == maxi-1) throw Overflow();
    data[++top]=a;
  };
  int pop(){
    if(top <= -1) throw Underflow();
    return data[top--];
  };
  bool isEmpty(){return top == -1 ? 1 : 0;}
  int show_top(){
    return data[top];
  }
};

#include<string.h>
template<>
void Swap(Stack &a, Stack &b){
  Stack sa,sb;
  while(!a.isEmpty()){
    sa.push(a.pop());
  }
  while(!b.isEmpty()){
    sb.push(b.pop());
  }
  while(!sa.isEmpty()){
    b.push(sa.pop());
  }
  while(!sb.isEmpty()){
    a.push(sb.pop());
  }
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
  Stack s1,s2;
  s1.push(3);
  s1.push(2);
  s1.push(1);

  s2.push(6);
  s2.push(5);
  s2.push(4);

  Swap(s1,s2);
  while(!s1.isEmpty()){
    cout<<s1.pop()<<" ";
  }cout<<endl;
  while(!s2.isEmpty()){
    cout<<s2.pop()<<" ";
  }cout<<endl;
}