//Airaj Hussain
#include "myshell.h" // include header file 

int main (int argc, char *argv[]) { 
	
	//initialize variables for enviroment var, current directory and shell location 
	
	//arrays for buffers and args 
	char envi[2][maxblock]= {0};
	
	//array for current direct (pwd) 
	char cdirect[maxblock]= {0};
	
	//array for user input (command) 
	char user_input[maxblock]= {0}; 
	
	char block[maxblock]= {0}; 
	
	char terminal[maxblock]= {0}; 
	
	//holding total tokens 
	int totaltoken=0; 
	
	
	char token[args][maxblock] ={0}; //token storage 
	
	char cwd[maxblock]; //the current working directroy block 
	
	//creating file pointer
	FILE*pointer=NULL; 
	
	// Parsing commands 
	if (argc>1) { 
	
		//reading 
		pointer = fopen(argv[1], "r");
		
		if (pointer == NULL) { 
		
			//error message in opening batch file 
			printf("there was an error in opening the batch file \n"); 
			return EXIT_FAILURE; 
		}
	}
	
	else { 
		pointer = stdin; 
	}
	
	
	//Welcoming messge 
	printf("\nWelcome to OS lab 2 shell\n"); 
	
	//going to the current directory 
	getcwd(cdirect, maxblock);
	
	//get the terminal directory
	getcwd(terminal, maxblock); 
	
	//Setting the environment variables 
	strcpy(envi[0], "the current directory: "); 
	strcat(envi[1], terminal); 
	
	//print current directory 
	printf("%s:$ ", cdirect); 
	
	
	
	
	
	while(fgets(block,maxblock,pointer)!= NULL){ 
	
		printf("%s $ ", getcwd(cwd, sizeof(cwd))); // printing current directory 
		
		//Sepearating the command from args 
	
		int x=0; 
		
		while(block[x] != '\n') { 
			x++; 
		}
		
		block[x] = '\0';

		//Token the input
		totaltoken = tokenset(block, token); 
		
		//store input 
		strcpy(user_input,token[0]);
	
	
	//Commands entered by user 
	
		//printing current directory 
		if (strcmp(user_input, "pwd") == 0){ 
			//printing out current directory
			printf("\n%s\n", envi[0]);
		}
		
		else if (strcmp(user_input,"cd") == 0) { 
		
			change(cdirect, token[1]);
			
			//changing env variables 
			strcpy(envi[0],"THE PWD Var: "); 
			strcat(envi[0],cdirect);
		}
		
		//clearing screen 
		else if (strcmp(user_input,"clear") ==0){ 
				clearing();
		}
		
		//Showing directory 
		else if (strcmp(user_input,"dir")==0) {
		 	showdir(token[1]);
		 	printf("\n");
		} 
		
		//stating env variables
		else if (strcmp(user_input,"environ")==0) {
		 	environs(envi);
		} 
		
		//help 
		else if (strcmp(user_input,"help")==0) { 
			printf("\nCommands listed below"); 
			printf("help - displays the help menu\n"); 
			printf("pwd- shows the current directory\n"); 
			printf("cd <path> - takes you to the desired directory\n"); 
			printf("dir <directory> - displays the contents of that directory\n"); 
			printf("environ- displays the environ variables\n"); 
			printf("pause- pauses the program\n"); 
			printf("echo <comment> shows the comment");
		}
		//echoing
		else if (strcmp(user_input,"echo") == 0) { 
			printf("%s:$ ", cdirect); 
			for (int x=1; x< totaltoken; x++) { 
				printf("%s ", token[x]);
			}
			printf("\n");
		}
		
		//pausing shell
		else if (strcmp(user_input, "pause")==0) {
			pausing(); 
		}
		
		//if no command was found 
		else {
			printf("\n%s: No command was found. For further assistance type 'help' \n", user_input); 
			printf("\n%s $ ", getcwd(cwd, sizeof(cwd)));
		}

			
		
	}
	
	return EXIT_SUCCESS; 
	
}
