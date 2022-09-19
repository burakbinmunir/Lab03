#include<iostream>
#include<unistd.h>
#include<sys/wait.h>

using namespace std;

int main(int argc, char* args[]){		

	execlp("/bin/mkdir", "mkdir", "lab3-task2",NULL);
//	execlp("/bin/ls", "-l", NULL);
// 	execlp("touch" ,"touch","file1.txt","./lab3-task2",NULL);
//	execlp("ls","-l",NULL);
//	execlp("rm" ,"rm" , "file1.txt", NULL);
//	execlp("bin/ls" ,"-l", "./lab3-task2", NULL);
	
}
