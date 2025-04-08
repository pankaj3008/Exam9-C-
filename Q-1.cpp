#include<iostream>
using namespace std;

class Stack{
public:
    virtual void push(int value) = 0 ;
    virtual void pop() = 0 ;
    virtual void top() = 0 ;
    virtual bool isEmpty() = 0 ;
    virtual bool isFull() = 0 ;
} ;

class StackImp : public Stack{
private:
    int Capacity ;
    int top1 ;
    int size ;
    int* arr ;

public:
void push(int value){
    if (size == Capacity) {
        cout << "Stack is full" << endl ;
        return ;
    }
    arr[top1+1] = value ;
    top1++ ;
    size++ ;
}

void pop(){
    if (isEmpty()) {
            cout << "Stack is empty" << endl ;
        }
        else {
            top1-- ;
            size-- ;
        }
    }
    
    void top(){
        if (isEmpty()) {
            cout << "Stack is empty" << endl ;
            return;
        }
        cout << arr[top1] ;
    }
    
    bool isEmpty(){
        return size == 0 ;
    }
    
    bool isFull(){
        return size == Capacity ;
    }
    StackImp(int Capacity){
        this -> Capacity = Capacity ;
        arr = new int[Capacity] ;
        top1 = -1 ;
        size = 0 ;
    }
} ;
int main(){
    StackImp S(5);
    int Choice , value;

    do{
        cout << endl <<"=======================" << endl;
        cout << "|      Stack Menu     |" << endl;
        cout << "=======================" << endl;
        cout << "| 1. Push             |" << endl ;
        cout << "| 2. Pop              |" << endl ;
        cout << "| 3. Display Top      |" << endl ;
        cout << "| 4. Check Is Empty   |" << endl ;
        cout << "| 5. Check Is Full    |" << endl ;
        cout << "| 6. Exit...          |" << endl ;
        cout << "=======================" << endl;
        cout << "Enter your choice: " ;
        cin >> Choice ;

        switch (Choice) {
            case 1:
                cout << "Enter value to push: " ;
                cin >> value ;
                S.push(value) ;
                break ;
            case 2:
                S.pop() ;
                break ;
            case 3:
                S.top() ;
                break ;
            case 4:
                cout << S.isEmpty() ;
                break ;
            case 5:
                cout << S.isFull() ;
                break ;
            case 6:
                cout << "Exiting..." ;
                break ;
            default:
                cout << "Invalid choice..." ;
            }
        }
            while(Choice != 6);
    
    return 0;
}
