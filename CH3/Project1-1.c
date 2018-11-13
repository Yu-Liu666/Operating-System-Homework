#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include  <wait.h>
#include <stdlib.h>
#define MAX_LINE 80 
int main(void)
{
char *args[MAX_LINE/2 + 1]; 
int should_run = 1; 
char c;
int i=0;

pid_t pid;

for(i=0;i<MAX_LINE/2 + 1;i++){
args[i]=(char *)malloc(20*sizeof(char));
strcpy(args[i],"");
}


while (should_run) 
{ 

for(i=0;i<MAX_LINE/2 + 1;i++){
args[i]=(char *)malloc(20*sizeof(char));
strcpy(args[i],"");
}

int h=0;

i=0;
printf("liuyu>>");
fflush(stdout);

while((c=getchar())!='\n')
{

   if(c!=' ')
   { 
    char a[2]={c};
    strcat(args[i],a);
    
   }
   else if(c==' ')
  {
    i++;

  }

}
  
 if(strcmp(args[i],"&")==0)
 { 
  h=1;
  args[i]=NULL;
 }
 else{
 i++;
 args[i]=NULL; 
 }
 if(strcmp(args[0],"exit")==0)
    
       should_run=0;
  


	pid = fork();

	if (pid < 0) 
	{ 
     	   fprintf(stderr, "Fork Failed");	
	   return 1;
	}
	else if (pid == 0) 
        { 
	   execvp(args[0], args);
	}
	else 
	{ 
	if(h==1)
	{
	wait(NULL);
	}

	//printf("Child Complete\n"); //used for testing if parent process wait for child process

	}


	}



return 0;
}
