#include<iostream>
using namespace std;

template<class T> class Array{
    public:
    int size=0;
    T *Arr;
    void insert(int val){
        size+=1;
        T *newArr = new T(size);
        for(int i=0;i<size-1;i++){
            newArr[i] = Arr[i];
        }
        newArr[size-1] = val;
        Arr=newArr; 
        return;
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<Arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    //must be unique if not then first will get deleted
    void remove(int val){
        T *newArr= new T(size-1);
        for(int i=0;i<size;i++){
            if(Arr[i]==val){
                while(i<size){
                    newArr[i] = Arr[i+1];
                    i++;
                }
                break;
            }
            newArr[i] = Arr[i];
        }        
        size--;
        Arr = newArr;
        return;
    }
};

int main(){
    Array<char> newArr;
    newArr.insert('a');
    newArr.insert('b');
    newArr.insert('c');
    newArr.insert('d');
    newArr.print();
    newArr.remove('a');
    newArr.remove('c');
    newArr.print();

    return 0;
}