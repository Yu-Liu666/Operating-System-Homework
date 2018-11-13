#include <pthread.h>  
#include <stdio.h>  
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
 
int c=0;
pthread_mutex_t mutex ;  
void *print_msg(void *arg){  
        int i=0;  
     pthread_mutex_lock(&mutex);  
           
    for (i = 0; i < 1000000; i ++)
    {
        double x = (double)2.0*rand() / (RAND_MAX)-1.0;
        double y = (double)2.0*rand() / (RAND_MAX)-1.0;
        if (x * x + y * y <= 1.0)
        {
            c++;
        }
    }
         printf("%d\n",c);
        pthread_mutex_unlock(&mutex);  
}  

int main(int argc,char** argv){  
  
        pthread_t id[10];
       
        pthread_attr_t attr;
        pthread_attr_init(&attr);
 
        pthread_mutex_init(&mutex,NULL);  
   
       int i=0;
       for(i=0;i<10;i++)
       {
          pthread_create(&id[i],&attr,print_msg,NULL);
         }
  
          for(i=0;i<10;i++)
        {
        pthread_join(id[i],NULL);  
        }       
 
        
      
        pthread_mutex_destroy(&mutex);  
        printf("%lf\n",4.0*c/10000000.0);
        return 1;  
}  
