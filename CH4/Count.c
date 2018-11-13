#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
 

 int c = 0;


void * count()
{
   
       
    for (int i = 0; i < 100000000; i ++)
    {
        double x = (double)2.0*rand() / (RAND_MAX)-1.0;
        double y = (double)2.0*rand() / (RAND_MAX)-1.0;
        if (x * x + y * y <= 1.0)
        {
            c++;
        }
    }
         
      pthread_exit(0);
}

int main()
{

pthread_t id;
pthread_attr_t attr;
pthread_attr_init(&attr);

pthread_create(&id,&attr,count,NULL);

pthread_join(id,NULL);

printf("%lf\n",4.0*c/100000000.0);

}





