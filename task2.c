#include<iostream>
#include<sys/wait.h>
#include<unistd.h>
#include<fstream>
using namespace std;

void removeCharacters(string fileName){
	

int main(int argc, char* args[]){	
	
	pid_t retVal = fork();
	
	if (retVal > 0 ) { // parent process
		wait(NULL);
		cout<<"Parent Process Terminated"<<endl;
	}
	
	if (retVal == 0){
		string fileName = args[1];
		
	
	return 0;
}
