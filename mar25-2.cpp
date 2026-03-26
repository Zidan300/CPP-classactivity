#include<iostream>
#include <math.h>
using namespace std;

int binsearch(int arr[], int size, int searchfor){
	int low_index = 0;
	int high_index = size - 1;   // fixed
	int mid_index;

	while(low_index <= high_index){
		mid_index = (low_index+high_index)/2;
		if(arr[mid_index] == searchfor){
			return mid_index;
		}else if (searchfor>arr[mid_index]){
			low_index = mid_index+1;
		}else{
			high_index = mid_index-1;
		}
	}
	return -1;
}

int main(){
	int arr[8] = {2, 5, 8, 11, 17, 32, 45, 67}; // fixed (sorted)
	int searchfor=45;

	int res = binsearch(arr, 8, searchfor);

	if(res != -1){   // fixed
		cout<< "Item found at location "<<res<<" and item is "<<arr[res]<<endl;
	}else{
		cout<<"Item cound not be found at location "<< endl;
	}

	return 0;
}
