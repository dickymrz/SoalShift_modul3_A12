#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void* fak(void *a)
{
	int y =*((int *)a);
    int fact = 1;

    int z;
    for (z = 1; z <= y; z++)
    {
        fact = fact * z;
    }

    printf("%d! = %d\n", y, fact);
}

int main(int argc, char** argv)
{
    int x[100];
    for (int i = 0; i < argc-1; ++i)
    	x[i]=atoi(argv[i+1]);
    
    //Selection Sort
    int c;
    int d;
    int swap;
    int position;
    for (c = 0; c < (argc - 1); c++)
    {
        position = c;

        for (d = c + 1; d < argc - 1; d++)
        {

            if (x[position] > x[d])
                position = d;

        }

        if (position != c)
        {

            swap = x[c];
            x[c] = x[position];
            x[position] = swap;

        }
    }

    for(int i=0; i < argc-1; i++){
	pthread_t tid;
	pthread_create(&tid,NULL,fak,&x[i]);
	pthread_join(tid,NULL);

	}
	

    return 0;
}

