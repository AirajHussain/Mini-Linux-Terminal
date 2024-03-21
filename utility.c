//Airaj Hussain

//including header file 

#include "myshell.h" 

//tokenizating the args 
int tokenset(char *str, char token[][maxblock]) { 

	const char separator[1] = " "; 
	
	int totaltokens=0; 
	
	char* tk= strtok(str,separator); 
	
	//looping thru string to get tokens 
	while(tk !=NULL) { 
		
		//copy tokens to the array
		strcpy(token[totaltokens],tk);
		
		//add 1 to token 
		totaltokens++; 
		
		//get next token 
		tk =strtok(NULL,separator);
	}
	
	return totaltokens;
}

//function for changing directory 
void change (char *cdir, char* loc) {

	int changing = chdir(loc); 
	
	if( strcmp(loc,"") != 0) { 
		if (changing == 0) { 
		printf("\n");
		
		//change the current directory to the updatedo ne 
		getcwd(cdir,maxblock);
		}
		else {
			printf("%s: Directory doesn't exist\n", loc);
		}
	}
}


//used to clear screen
void clearing() { 
	//clear the screen using clear 
	system("clear");
	
}




//Pausing the screen
void pausing () { 
	
	//Outputting message 
	
	printf("\nthe shell is paused. Pressing 'ENTER' will continue the program:\n"); 
	
	//checking the screen
	char inp = (char)getchar();
	
	//keep looping if enter isn't entered. 
	while (inp !='\n') { 
		inp = (char)getchar(); 
	}

}


//display directory 

void showdir(char* loc) {

	struct dirent *current_entry; 
	DIR *directory_handle = NULL; 
	
	if (strcmp(loc, "") == 0){ 
		directory_handle = opendir("."); //opening the current directory 
	}
	else { 
		directory_handle = opendir(loc); //opening specified directory 
	}
	
	if(directory_handle == NULL) { 
		printf("\ndir: cant get to '%s': Doesn't exist\n", loc);
	}
	
	//loop thru directory entries and display them 
	while ((current_entry = readdir(directory_handle)) != NULL) { 
		printf("%s\n", current_entry->d_name);
	}
	
	closedir(directory_handle);	//close directory 
	
}

//showing the environment variables 
void environs(char enviro[][maxblock]) { 
	printf("%s\n%s", enviro[0], enviro[1]); //print environment variables
}


