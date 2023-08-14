#include<iostream>
#include "../lab-1/Array.cpp"
using namespace std;

template<class T> class Queue {
public:
    int n = 0;
    Array<T> newArr;
    void enqueue(T val){
        newArr.push_front(val);
        n++;
    }
    void dequeue(){
        newArr.removebyIndex(n--);
    }
    void peek(){
        cout<<newArr.access(n-1)<<endl;
    }
};

int main(){
    Queue<char> newQ;
    newQ.enqueue('a');
    newQ.enqueue('b');
    newQ.peek();
    newQ.dequeue();
    newQ.peek();
    

    return 0;
}