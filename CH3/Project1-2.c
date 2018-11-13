#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include  <wait.h>
#include <stdlib.h>
#define MAX_LINE 80 
int main(void)
{
char *args[MAX_LINE/2 + 1]; 
char *number1[MAX_LINE/2 + 1];
char *number2[MAX_LINE/2 + 1];
char *number3[MAX_LINE/2 + 1];
int num;
int count=1;

int should_run = 1; 
char c;
int i=0;
int x=0;
int number=0;

pid_t pid;

for(i=0;i<MAX_LINE/2 + 1;i++){
args[i]=(char *)malloc(20*sizeof(char));
strcpy(args[i],"");
number1[i]=(char *)malloc(20*sizeof(char));
strcpy(number1[i],"");
number2[i]=(char *)malloc(20*sizeof(char));
strcpy(number2[i],"");
number3[i]=(char *)malloc(20*sizeof(char));
strcpy(number3[i],"");

}




while (should_run) 
{ 

for(i=0;i<MAX_LINE/2 + 1;i++){
args[i]=(char *)malloc(20*sizeof(char));
strcpy(args[i],"");
}

int h=0;

i=0;
printf("osh>");
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
   if(strcmp(args[i],"&")!=0&&strcmp(args[i],"history")!=0)
   strcpy(number1[x],args[0]);
   if(strcmp(args[i],"&")!=0&&strcmp(args[i],"history")!=0)
   strcpy(number2[x],args[1]);	
   if(strcmp(args[i],"history")!=0)        
   x++;

 if(strcmp(args[i],"&")==0)
 { 
  h=1;
  args[i]=NULL;
  i++;
 }

 else{
 i++;
 args[i]=NULL; 
 }
 


 if(strcmp(args[0],"exit")==0)
    
       should_run=0;
  


pid=fork();

if (pid < 0) 
{ 
fprintf(stderr, "Fork Failed");
return 1;
}
else if (pid == 0) { 
  
   i--;
   
   if(strcmp(args[i],"history")==0)  
 {     
      x--;
      
     if(x<=9)
     {
       int y=x;
             
       int k=x+1;  
       for(y;y>=0;y--)
   //    for(k=0;k<=y;k++) 
     {
        printf("%d %s ",k,number1[y]);
        printf("%s\n",number2[y]);
        k--;
      }
       
      } 
     else{
     
     int u=x;
     int r=10;
  //   int g=u-9; 
     for(u;u>=x-9;u--)
  //  for(g;g<=u;g++) 
   { 
        printf("%d %s ",r,number1[u]);
        printf("%s\n",number2[u]);
        r--;
    }
    
}

     x++;
     
}

if(strcmp(args[i],"!!")==0)
{   
     x=x-2;
   
   if(strcmp(number1[0],"!!")==0&&x==-1)
{
      printf("No commands in history.\n");
           
}   
   else
{
   
   strcpy(args[0],number1[x]);
 
  
  if(strcmp(number2[x],"")==0)
  {

    number3[1]=NULL; 
           
  }
   else 
  {  

	strcpy(number3[1],number2[x]);
	number3[2]=NULL;
	execvp(number1[0],number3);
  }  
   
    
}
  
	  x=x+2;

}

//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]


if(args[0][0]=='!'&&args[0][1]!='\0')
{    
      x=x-2;
      num=args[0][1]-'0';
      switch(num)
{        case 1:
            {
                if(x>=0)
                 {
                    if(x<10)
                    {
                      
                     strcpy(args[0],number1[0]);
 
  
                    if(strcmp(number2[0],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[0]); 
                       number3[2]=NULL;
                       execvp(number1[0],number3);
                       }
                     }
                      if(x>=10)
                     { 
                        int q=x-9;
                       
                     strcpy(args[0],number1[q]);
 
  
                    if(strcmp(number2[q],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[q]); 
                       number3[2]=NULL;
                       execvp(number1[q],number3);
                       }
                        
                     }              
               

                  }
                  else
                  printf("No such command in history.\n");
                  break;
 
             }
//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]

             case 2:
            {
                if(x-1>=0)
                 {
                    if(x<10)
                    {
                      
                     strcpy(args[0],number1[1]);
 
  
                    if(strcmp(number2[1],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[1]); 
                       number3[2]=NULL;
                       execvp(number1[1],number3);
                       }
                     }
                      if(x>=10)
                     { 
                        int q=x-8;
                       
                     strcpy(args[0],number1[q]);
 
  
                    if(strcmp(number2[q],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[q]); 
                       number3[2]=NULL;
                       execvp(number1[q],number3);
                       }
                        
                     }              
               

                  }
                  else
                  printf("No such command in history.\n");
                  break;
 
             } 
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\              
        
             case 3:
            {
                if(x-2>=0)
                 {
                    if(x<10)
                    {
                      
                     strcpy(args[0],number1[2]);
 
  
                    if(strcmp(number2[2],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[2]); 
                       number3[2]=NULL;
                       execvp(number1[2],number3);
                       }
                     }
                      if(x>=10)
                     { 
                        int q=x-7;
                       
                     strcpy(args[0],number1[q]);
 
  
                    if(strcmp(number2[q],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[q]); 
                       number3[2]=NULL;
                       execvp(number1[q],number3);
                       }
                        
                     }              
               

                  }
                  else
                  printf("No such command in history.\n");

                  break;
             }

//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]

               case 4:
            {
                if(x-3>=0)
                 {
                    if(x<10)
                    {
                      
                     strcpy(args[0],number1[3]);
 
  
                    if(strcmp(number2[3],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[3]); 
                       number3[2]=NULL;
                       execvp(number1[3],number3);
                       }
                     }
                      if(x>=10)
                     { 
                        int q=x-6;
                       
                     strcpy(args[0],number1[q]);
 
  
                    if(strcmp(number2[q],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[q]); 
                       number3[2]=NULL;
                       execvp(number1[q],number3);
                       }
                        
                     }              
               

                  }
                  else
                  printf("No such command in history.\n");
                  break;
             }
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


              case 5:
            {
                if(x-4>=0)
                 {
                    if(x<10)
                    {
                      
                     strcpy(args[0],number1[4]);
 
  
                    if(strcmp(number2[4],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[4]); 
                       number3[2]=NULL;
                       execvp(number1[4],number3);
                       }
                     }
                      if(x>=10)
                     { 
                        int q=x-5;
                       
                     strcpy(args[0],number1[q]);
 
  
                    if(strcmp(number2[q],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[q]); 
                       number3[2]=NULL;
                       execvp(number1[q],number3);
                       }
                        
                     }              
               

                  }
                  else
                  printf("No such command in history.\n");
                  break;
 
             }
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
                   
             case 6:
            {
                if(x-5>=0)
                 {
                    if(x<10)
                    {
                      
                     strcpy(args[0],number1[5]);
 
  
                    if(strcmp(number2[5],"")==0)
                      
                           number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[5]); 
                       number3[2]=NULL;
                       execvp(number1[5],number3);
                       }
                     }
                      if(x>=10)
                     { 
                        int q=x-4;
                       
                     strcpy(args[0],number1[q]);
 
  
                    if(strcmp(number2[q],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[q]); 
                       number3[2]=NULL;
                       execvp(number1[q],number3);
                       }
                        
                     }              
               

                  }
                  else
                  printf("No such command in history.\n");
                  break;
 
             }
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\                
                 case 7:
                 {
                if(x-6>=0)
                 {
                    if(x<10)
                    {
                      
                     strcpy(args[0],number1[6]);
 
  
                    if(strcmp(number2[6],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[6]); 
                       number3[2]=NULL;
                       execvp(number1[6],number3);
                       }
                     }
                      if(x>=10)
                     { 
                        int q=x-3;
                       
                     strcpy(args[0],number1[q]);
 
  
                    if(strcmp(number2[q],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[q]); 
                       number3[2]=NULL;
                       execvp(number1[q],number3);
                       }
                        
                     }              
               

                  }
                  else
                  printf("No such command in history.\n");
                  break;
 
             }
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

                case 8:
            {
                if(x-7>=0)
                 {
                    if(x<10)
                    {
                      
                     strcpy(args[0],number1[7]);
 
  
                    if(strcmp(number2[7],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[7]); 
                       number3[2]=NULL;
                       execvp(number1[7],number3);
                       }
                     }
                      if(x>=10)
                     { 
                        int q=x-2;
                       
                     strcpy(args[0],number1[q]);
 
  
                    if(strcmp(number2[q],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[q]); 
                       number3[2]=NULL;
                       execvp(number1[q],number3);
                       }
                        
                     }              
               

                  }
                  else
                  printf("No such command in history.\n");
                  break;
 
             }
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

            case 9:
            {
                if(x-8>=0)
                 {
                    if(x<10)
                    {
                      
                     strcpy(args[0],number1[8]);
 
  
                    if(strcmp(number2[8],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[8]); 
                       number3[2]=NULL;
                       execvp(number1[8],number3);
                       }
                     }
                      if(x>=10)
                     { 
                        int q=x-1;
                       
                     strcpy(args[0],number1[q]);
 
  
                    if(strcmp(number2[q],"")==0)
                      
                         number3[1]=NULL; 
        
                     else 
                      {  

                       strcpy(number3[1],number2[q]); 
                       number3[2]=NULL;
                       execvp(number1[q],number3);
                       }
                        
                     }              
               

                  }
                  else
                  printf("No such command in history.\n");
                  break;
 
             }
              
             default:
             if(args[0][0]!='!'&&args[0][1]!='!')
             printf("No this command");
       

//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
     
}
  x=x+2;

}


 execvp(args[0], args);  


should_run=0;
}
else 
{ 

if(h==0)
wait(NULL);

}



}


return 0;
}
