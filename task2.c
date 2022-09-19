#include<iostream>
#include<sys/wait.h>
#include<unistd.h>
#include<fstream>
#include<string>
using namespace std;

void removeCharacters(string fileName){
	ifstream input (fileName);
	if (input.is_open()) {
	int c =0;
		while(!input.eof()){
//			char s[100];
			string s;
			getline(input,s);
			
			for(int index=0; index <100; index++){
				if (int(s[index])  > 57 && int(s[index]) < 65 || int(s[index]) > 32 && int(s[index]) < 48 || int(s[index]) > 90 && int(s[index]) < 61 || int(s[index]) > 122 && int(s[index]) < 127) {
					cout<<s[index]<<" ";
					c++;
					}
					
				
			}
		}
					cout<<"Count: "<<c<<endl;
	}
	else {cout<<"Sorry File Not Found:("<<endl;}
			
}
int main(int argc, char* args[]){	
	
	pid_t retVal = fork();
	
	if (retVal > 0 ) { // parent process
		wait(NULL);
		cout<<"Parent Process Terminated"<<endl;
	}
	
	if (retVal == 0){
		char* fileName = args[1];
		cout<<"Child Called\n";
		removeCharacters(fileName);
	}
	
	if (retVal < 0){
		cout<<"Error";
	}
	
	return 0;
}
