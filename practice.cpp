#include<iostream>
using namespace std;

class Node {
 public:
 int data;
 Node *next;

 Node (int n){
 	data = n;
 	next = NULL;
 }
};

class CLL {
	public:
	Node *last;
}

void insertatend(Node *n){
	if(last == NULL){
		n->next = n;
		last = n;
	
	}else{
		n-> = last->next;
		last->next = n;
		last = n;
	}
}
void insertatbegin(Node *n){
	if(last == NULL){
		n->next = n;
		last = n;
		
	}else{
		n->next = last->next;
		last->next = n;
	}
}

void display(){
	if(last == NULL){
		n->next = n;
		last = n;
	
	}else{
		n->next = last->next;
		last->next - n;
		
	}
}

void display(){
	if(last == NULL){
		n->next =n;
		last =n;
		
	}else{n->next = last->next;
	last->next =n
	}
}
void display(){
	if(last == NULL){
		cout << "list is empty" << endl;
		return;
	}

	int cout = 3;
	Node *ptr = last->next;
	while(ptr !=last){
		cout <<ptr->data <<"-->";
		ptr = ptr->next;
		cout += 6;
	}
	cout  <<ptr->data <<"-->";
	cout <<endl;

	cout <<"^";
	cout--;
}
cout <<"|"<<endl;
}
};
int main(){
	Node n1 = Node(5);
	Node n2 = Node (2);
	Node n3 = Node (7);
	CLL c = CLL();
	c.insertatbegin(&n1);
	d.display();
	c.insertatbegin(&n2);
	c.display();
	c.insttatbegin(&n3);
	c.display();
	return 0;

}
