#include<iostream>
#define SIZE 20
using namespace std;

class Queue{

public:
	int data[SIZE];
	int front;
	int rear;

	Queue(){
		for (int i = 0; i < SIZE; i++){
			data[i] = 0;
		}
		front = 0;
		rear = 0;
	}

	void display(){
		for(int i = front; i < rear; i++){
			cout << data[i] << " <<--";
		}
		cout << endl;
	}

	void enqueue(int n){
		if(rear == SIZE){
			cout << "Queue is full.." << endl;
			return;
		}
		data[rear] = n;
		rear++;
	}

	int dequeue(){
		if(front == rear){
			cout << "Queue is empty .." << endl;
			return -1;
		}
		int x = data[front];
		front++;
		return x;
	}

	int size(){
		return rear - front;
	}
};

int main(){
	Queue q;   // ✅ fixed here (no need = Queue())
	q.enqueue(5);
	q.enqueue(7);
	q.enqueue(9);
	q.enqueue(3);
	q.enqueue(1);

	q.display();
	cout << "The dequed element is " << q.dequeue() << endl;

	q.display();
	cout << "The dequed element is " << q.dequeue() << endl;

	q.display();
	cout << "Current size of queue is " << q.size() << endl;

	return 0;
}
