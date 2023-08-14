#include<iostream>
#include "../lab-1/SLL.cpp"
using namespace std;

template<class T> class Queue {
public:
    int n = 0;
    SLL<T> newSLL;
    void enqueue(T val){
        newSLL.push_front(val);
        n++;
    }
    void dequeue(){
        newSLL.remove_back();
        n--;
    }
    void peek(){
        cout<<newSLL.access(n)<<endl;
    }
    void printq(){
        newSLL.print();
    }
};

int main(){
    Queue<char> newQueue;
    newQueue.enqueue('a');
    newQueue.enqueue('b');
    newQueue.enqueue('c');
    newQueue.enqueue('d');
    newQueue.printq();
    newQueue.peek();
    newQueue.dequeue();
    newQueue.peek();
    newQueue.printq();
    

    return 0;
}