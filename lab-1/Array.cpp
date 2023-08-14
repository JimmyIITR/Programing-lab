#include<iostream>
using namespace std;

template<class T> class Array{
    public:
    int size=0;
    T *Arr;
    void push_back(T val){
        size+=1;
        T *newArr = new T(size);
        for(int i=0;i<size-1;i++){
            newArr[i] = Arr[i];
        }
        newArr[size-1] = val;
        Arr=newArr; 
        return;
    }
    void push_front(T val){
        size+=1;
        T *newArr = new T(size);
        newArr[0] = val;
        for(int i=0;i<size-1;i++){
            newArr[i+1] = Arr[i];
        }
        Arr=newArr; 
        return;
    }
    void insert(int index,T val){
        T *newArr= new T(size+1);
        for(int i=0;i<size;i++){
            if(i==index){
                newArr[i] = val;
                while(i<size){
                    newArr[i+1] = Arr[i];
                    i++;
                }
                break;
            }
        }        
        size++;
        Arr = newArr;
        return;
    }
    void removebyIndex(int index){
        T *newArr= new T(size-1);
        for(int i=0;i<size;i++){
            if(i==index){
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
    void removebyValue(T val){
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
    int n(){
        return size;
    }
    int find(T a){
        for(int i=0;i<size;i++){
            if(Arr[i] == a)
                return i;
        }
        return -1;
    }
    int findallandcount(T a){
        int count = 0;
        for(int i=0;i<size;i++){
            if(Arr[i] == a)
                count++;
        }
        return count;
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<Arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    T access(int index){
        return Arr[index];
    }
};

// int main(){
//     Array<char> newArr;
//     newArr.insert('a');
//     newArr.insert('b');
//     newArr.insert('c');
//     newArr.insert('d');
//     newArr.print();
//     newArr.remove('a');
//     newArr.remove('c');
//     newArr.print();

//     return 0;
// }
