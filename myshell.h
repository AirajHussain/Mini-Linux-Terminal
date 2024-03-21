//Airaj Hussain
//including libraries 
#include <stdio.h>  //input/output
#include <stdlib.h>
#include <unistd.h> 
#include <string.h> //strig manipulation function


#include <errno.h> //error handling
#include <dirent.h> //directory handling functions
#include <ctype.h> //character class function

//system libraries 
#include <sys/types.h> //system types 
#include <sys/wait.h> //wait for the process to terminmate 





//define max buffer size and max number of args 
#define maxblock 1024
#define args 10 

//defining functions 
int tokenset (char* str, char token[][maxblock]); //tokenize the string
void change (char* cdir, char* loc); //change directory 
void clearing();  //clear screen
void pausing(); //pause 
void showdir(char* loc); //display directory contents  
void environs(char enviro[][maxblock]); //show environment variables
