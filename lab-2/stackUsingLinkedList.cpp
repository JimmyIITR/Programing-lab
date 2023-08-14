#include<iostream>
#include "../lab-1/SLL.cpp"
using namespace std;

template<class T> class Stack {
public:
    int n = 0;
    SLL<T> newSLL;
    void push(T val){
        newSLL.push_back(val);
        n++;
    }
    void pop(){
        newSLL.remove_back();
        n--;
    }
    void peek(){
        cout<<newSLL.access(n)<<endl;
    }
};

int main(){
    Stack<char> newStack;
    newStack.push('a');
    newStack.push('b');
    newStack.peek();
    newStack.pop();
    newStack.peek();
    

    return 0;
}