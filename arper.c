#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define charsize 50

char *pingu(char *c) { 

char *ping = (char*)calloc(charsize, sizeof(ping)); //dynamic allocation for beginning to create ping command
char *find = (char*)calloc(charsize, sizeof(find)); //dynamic allocation to pointing it "Pinging" string

strcpy(find, " | findstr Pinging"); //for avoiding buffer/stack overflow

snprintf(ping, charsize, "ping -a -n 1 -w 10 %s %s", c, find); //assignment of strings;

return ping; //return the next string command

}

int main(int argc, char* argv[]) {
//setup
int w; //iter
char *input = NULL;
char *max = NULL;
char *init = NULL;
int begin;
int end;
char *cmd;
char *su = (char*)calloc(charsize, sizeof(su));
char *ip = (char*)calloc(charsize, sizeof(ip));

for (int i = 1; i < argc; i++)
{
    if((strcmp(argv[i], "-m") == 0) && i + 1 < argc) { //if exist -m flag we can it inserting ip address
        input = argv[++i]; //for inserting another args
    }

    else if((strcmp(argv[i], "-b") == 0) && i + 1 < argc) { //for specifies the init value(u must insert it)
    	init = argv[++i];
    }
    
    else if((strcmp(argv[i], "-e") == 0) && i + 1 < argc) { //for specifies the end value(u must insert it)
    	max = argv[++i];
    	
    } else {
        printf("nope :(");
        return 0;
    }
    
}

if(input && init && max) {
	
	printf("-------------\n");
		
	begin = atoi(init); //convert a string into int
	end = atoi(max);
	
    for (w = begin; w < end; w++)
    {
        snprintf(su, charsize, "%d", w); //save the iterator converted into string inside a other string
        snprintf(ip, charsize, "%s.%s", input, su); //create the complete ip address 

        cmd = pingu(ip); //save the command in a apposities variable
        system(cmd); //execute the final command
        free(cmd); //free memory after have it used 
    }
} else { //options menu
	printf("arper syntax:\n");
	printf("-m manually: insert a ip address, but without last number(ex: 192.168.1)\n");
	printf("-b begin: setup a init value\n");
	printf("-e end: setup a end value\n");
	printf("\n example arper -m <ip address> -b <begin value> -e <end value>\n");
}

free(su); //dealloc to end operation for free useless block of memory
free(ip);
return 0;

}
