#include<iostream>
#include<sys/wait.h>
#include<unistd.h>
using namespace std;

void sort(int array[], bool order,int size) {
	if (order == true) { // ascending order sorting
		
		for (int i = 0; i < size; i++) {

			for (int j = 0; j < size; j++) {
				if (array[i] < array[j])
					swap(array[i], array[j]);
			}
		}
	}

	if (order == false) { // decsending order sorting
		 
		for (int i = 0; i < size; i++) {

			for (int j = 0; j < size; j++) {
				if (array[i] > array[j])
					swap(array[i], array[j]);
			}
		}
	}
}


void print(int* array, int size) {
	
	cout << "Printing Array\n";

	for (int index = 0; index < size; index++) {
		cout << array[index] << endl;
	}
}


int main(int argc, char* args[]){
	
	// converting to int array
	int size = argc -1;
	int* array = new int[size];
	
	int counter = 0;
	for(int index = 1; index < argc; index++){
		array[counter] = atoi(args[index]);
		counter++;
	}
	
	pid_t retVal = fork();
	if (retVal > 0){

		pid_t retVal2 = fork();	
		if (retVal2 == 0){		
			cout<<"I am child 2"<<endl;
			sort(array,true,size); 	// true for ascending order sort
			print(array,size);
		}
		wait(NULL);
		cout<<"Parent Process Terminated"<<endl;
	}
	else {
		if (retVal == 0){ // child process		
			cout<<"I am child 1"<<endl;
			sort(array,false,size); 	// true for descending order sort
			print(array,size);
		}
		else 
		{
			if (retVal < 0) {
				cout<<"Error"<<endl;
			}
		
		}
	}
} 
