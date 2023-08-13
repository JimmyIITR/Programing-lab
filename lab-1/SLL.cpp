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
    void push_back(T val){
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
    bool insertAfterNode(T curr, T val){
        struct Node<T> *newNode = new Node<T>;
        struct Node<T> *ptr = head, *temp;
        newNode->val = val;
        newNode->next = NULL;
        while(ptr != NULL){
            if(ptr->val == curr){
                temp = ptr->next;
                ptr->next = newNode;
                ptr->next = temp;
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }
    void removebyValue(T val){
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
    void remove_back(){
        struct Node<T> *curr = head, pre = NULL;
        while(curr != NULL){
            if(curr->next == NULL){
                pre->next = NULL;
                return;
            }
            pre = curr;
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
    int size(){
        struct Node<T> *ptr = head;
        int size = 0;
        while(ptr != NULL){
            ptr = ptr->next;
            size++;
        }
        return size;
    }
    bool find(T val){
        struct Node<T> *ptr = head;
        while(ptr !=NULL){
            if(ptr->val == val)
                return true;
            ptr = ptr->next;
        }
        return false;
    }
};

// int main(){
//     SLL<char> newSLL;
//     newSLL.insert('a');
//     newSLL.insert('b');
//     newSLL.insert('c');
//     newSLL.insert('d');
//     newSLL.print();
//     newSLL.remove('b');
//     newSLL.remove('a');
//     newSLL.print();
//     newSLL.remove('d');
//     newSLL.print();
//     return 0;
// }
