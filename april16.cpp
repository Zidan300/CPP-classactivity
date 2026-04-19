#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int n){
        data = n;
        left = NULL;
        right = NULL;
    }
};

class BTree{
    public:
    Node *root;
    
    BTree(){
        root = NULL;
    }
    
	void insertinto(Node *n, int num){
		if(num < n->data){
			if(n->left == NULL){
				n->left = new Node(num);
			}
			else{
				insertinto(n->left, num);
			}
		}
		else{
			if(n->right == NULL){
				n->right = new Node(num);
			}
			else{
				insertinto(n->right, num);
			}
		}
	}
	
	void insert(int num){
		if(root == NULL){
			root = new Node(num);
		}
		else{
			insertinto(root, num);
		}
	}
	
	
	void print2DUtil(Node *leaf, int space)  
	{	  
    	// Base case  
    	if (leaf == NULL)  
        	return;  
  
    	// Increase distance between levels  
    	space += 5;  
  
    	// Process right child first  
    	print2DUtil(leaf->right, space);  
  
    	// Print current node after space  
    	// count  
    	cout<<endl;  
    	for (int i = 5; i < space; i++)  
        	cout<<" ";  
    	
		cout<<leaf->data<<"\n";  
  
    	// Process left child  
    	print2DUtil(leaf->left, space);  
	}  
  
// Wrapper over print2DUtil()  
void print2D()  
	{  
    	// Pass initial space count as 0  
    	print2DUtil(root, 0);  
	}  
	//copied code upto here.  
};

int main() {
    
    
    BTree bt = BTree();
    
    bt.insert(78);
    bt.insert(31);
    bt.insert(15);
    bt.insert(110);
    bt.insert(100);
    bt.insert(114);
    bt.insert(35);
    bt.print2D();
    return 0;
}
