 #include<stdio.h>
        #include<string.h>
        #include<pthread.h>
        #include<stdlib.h>
        #include<unistd.h>
        #include<stdlib.h>
     
        int AgmalHealth,IrajHealth;
        int counterAgmal;
        int counterIraj;
        pthread_t tid[2];
     
        void *dec(void *arg)
        {
        	int init;
        	init=(int)arg;
        	if (init==0) {
        		while(AgmalHealth>0 && AgmalHealth<=100)
        		{
        			sleep(10);
        			
    			printf("Status Agmal: %d\n",AgmalHealth);
    		
        		}
        	if (counterIraj==3){
			
        	printf("Iraj ayo Tidur is disabled try next 10 second");
        	sleep(10);
        		}
        	}
        	else {
        		while(IrajHealth>0 && IrajHealth<=100)
        		{
        			sleep(10);
        			
    			printf("Status Kepiting : %d\n",IrajHealth);
        		}
        	if (counterAgmal==3){
			
        	printf("Agmal ayo bangun is disabled try next 10 second");
        	sleep(10);
        		}
        		
        	}
        }
     
        int main()
        {
        	int status,pilihan;
        	
        	AgmalHealth=0;
        	IrajHealth=100;
        	status=pthread_create(&(tid[0]),NULL,dec,(void*) 0);
        	if (status) {
        		printf("Thread Agmal Error\n");
        		exit(EXIT_FAILURE);
        	}
        	status=pthread_create(&(tid[1]),NULL,dec,(void*) 1);
        	if (status) {
        		printf("Thread Iraj Error\n");
        		exit(EXIT_FAILURE);
        	}
        	while(1)
        	{
        		system("clear");
        		printf("1. Agmal ayo bangun\n");
        		printf("2. Iraj ayo tidur\n");
        		printf("Pilih Nomor : \n");
        		scanf("%d",&pilihan);
        		if (pilihan==1)
        		{
				
        		AgmalHealth=AgmalHealth+15;
        		counterIraj=counterIraj+1;
        	}
        		else if (pilihan==2)
        		{
				
        		IrajHealth=IrajHealth-20;
        		counterAgmal=counterAgmal+1;
        	}
        		else
        		if (( AgmalHealth>100) && (IrajHealth<=0 )) {
        			printf("Lohan dan Kepiting Mati\n");
        			break;
        		}
        	}
        	exit(EXIT_SUCCESS);
        	return 0;
        }
