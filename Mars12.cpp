#include <iostream>
#define CAPACITY 10
using namespace std;

class Stack {
    public:
    int data[CAPACITY];
    int sp;

    Stack(){
        sp = -1;
        for(int i=0; i<CAPACITY; i++){
            data[i] = 0;
        }
    }
    void push(int x) {
        if(sp == CAPACITY - 1){
            cout << "Stack is full ... cannot push new element" << endl;
            return;
        }
        sp++;
        data[sp] = x;
    };

    int pop() {
        if(sp == -1){
            cout << "Stack is empty ... cannot pop element" << endl;
            return -1;
        }
        int temp = data[sp];
        sp --;
        return temp;
    }

    void display() {
        if(sp == -1){
            cout << "Stack is empty" << endl;
            return;
        }
        for(int i = sp; i >= 0; i--){
            cout << " -- " << endl;
            cout << "| " << data[i] << " |" << endl;
        }
    }
};

int main() {
    Stack s;

    s.push(9);
    s.push(4);
    s.push(8);
      s.push(3);
  s.push(12);
  s.push(30);
  s.push(33);
    s.display();

    cout << "Popped: " << s.pop() << endl;

    s.display();

    return 0;
}
