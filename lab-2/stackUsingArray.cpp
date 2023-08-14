#include<iostream>
#include "../lab-1/Array.cpp"
using namespace std;

template<class T> class Stack {
public:
    int n = 0;
    Array<T> newArr;
    void push(T val){
        newArr.push_back(val);
        n++;
    }
    void pop(){
        newArr.removebyIndex(n--);
    }
    void peek(){
        cout<<newArr.access(n-1)<<endl;
    }
};

int main(){
    Stack<char> newQ;
    newQ.push('a');
    newQ.push('b');
    newQ.peek();
    newQ.pop();
    newQ.peek();
    

    return 0;
}