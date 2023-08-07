#include<iostream>
using namespace std;


template<typename S> struct Node{
    S val;
    struct Node* next;
};

template<class T> class CLL{
    public:
    struct Node<T> *head,*end;
    CLL(){
        head = NULL;
    }
    void insert(int val){
        struct Node<T> *newNode = new Node<T>;
        newNode->val = val;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
            end= head;
            end->next = head;
        }
        else {
            end->next= newNode;
            end = end->next;
            end->next = head;
        }
        return;
    }
    void print(){
        struct Node<T> *ptr = head;
        do{ 
            cout<<ptr->val<<" ";
            ptr = ptr->next;
        }while(ptr != head);
        cout<<endl;
        return;
    }
    //must be unique if not then first will get deleted
    void remove(int val){
        struct Node<T> *ptr = head,*sptr = head->next;
        if(ptr->val == val){
            end->next = head->next;
            head = head->next;
        }
        while(sptr != head){
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
    CLL<char> newCLL;
    newCLL.insert('a');
    newCLL.insert('b');
    newCLL.insert('c');
    newCLL.insert('d');
    newCLL.print();
    newCLL.remove('b');
    newCLL.remove('a');
    newCLL.print();
    newCLL.remove('d');
    newCLL.print();
    return 0;
}