#include<iostream>
#define SIZE 10
using namespace std;

class HashTable{
	public:
	int data[SIZE];

	HashTable(){
		for(int i=0; i<SIZE; i++){
			data[i] = -1;
		}
	}
	int hashfxn(int data){
		return data%SIZE;
	}

	void insert(int n){
		int index = hashfxn(n);
		if(data[index] == -1){
			data[index] = n;
		}else{
			cout<<"The hash table for index "<<index<<" is already occupied."<<endl;
		}
	} 
	void printarray(){
		for(int i=0; i<SIZE; i++){
			if(data[i] == -1){
				cout<<"| EMPTY |";
			}else{
				cout<<"|"<<data[i]<<"|";
			}
		}
		cout<<endl<<endl;
	}
};

int main(){
	HashTable ht;
	ht.printarray();
	ht.insert(57);
	ht.printarray();
	ht.insert(53);
	ht.printarray();
	ht.insert(12);
	ht.printarray();
	ht.insert(98);
	ht.printarray();
	ht.insert(13);

	return 0;
}
