#include<iostream>
using namespace std;


template<typename S> struct Node{
    S val;
    struct Node* next;
};

template<class T> class SLL{
    public:
    struct Node<T> *head,*curr;
    SLL(){
        head = NULL;
    }
    void insert(int val){
        struct Node<T> *newNode = new Node<T>;
        newNode->val = val;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
            curr= head;
        }
        else {
            curr->next= newNode;
            curr = curr->next;
        }
        return;
    }
    void print(){
        struct Node<T> *ptr = head;
        while(ptr != NULL){
            cout<<ptr->val<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
        return;
    }
    //must be unique if not then first will get deleted
    void remove(int val){
        struct Node<T> *ptr = head,*sptr = head->next;
        if(ptr->val == val){
            head = head->next;
        }
        while(sptr != NULL){
            if(sptr->val == val){
                ptr->next = sptr->next;
                return;
            }
            sptr = sptr->next;
            ptr = ptr->next;
        }
        return;
    }
};

int main(){
    SLL<char> newSLL;
    newSLL.insert('a');
    newSLL.insert('b');
    newSLL.insert('c');
    newSLL.insert('d');
    newSLL.print();
    newSLL.remove('b');
    newSLL.remove('a');
    newSLL.print();
    newSLL.remove('d');
    newSLL.print();
    return 0;
}