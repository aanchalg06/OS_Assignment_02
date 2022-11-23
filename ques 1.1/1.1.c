#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


struct timespec start, finish;
pthread_t Thr_a;
pthread_t Thr_b;
pthread_t Thr_c;

int pri=0;
int pol=0;

//sched_other=0, sched_fifo=1,sched_rr=2


void* countA(){
   
    struct sched_param sch;
    int policy=0;

    if(pol==0){
        policy= SCHED_OTHER;
    }
    else if(pol == 1){
        policy= SCHED_FIFO;
    }
    else{
        policy= SCHED_RR;
    }
    
    sch.sched_priority = pri;

    
    long long int i=0;
    while(i<=4294967296){
        i++;
    }
    }

void* countB(){
    
   
    struct sched_param sch;
    int policy=0;

    if(pol==0){
        policy= SCHED_OTHER;
    }
    else if(pol == 1){
        policy= SCHED_FIFO;
    }
    else{
        policy= SCHED_RR;
    }
    
    sch.sched_priority = pri;

    
    long long int i=0;
    while(i<=4294967296){
        i++;
    }
    }

void* countC(){
    
   
    struct sched_param sch;
    int policy=0;

    if(pol==0){
        policy= SCHED_OTHER;
    }
    else if(pol == 1){
        policy= SCHED_FIFO;
    }
    else{
        policy= SCHED_RR;
    }
    
    sch.sched_priority = pri;

    
    long long int i=0;
    while(i<=4294967296){
        i++;
    }
    }




int main(){

    //priority value is 1
    printf("\033[1;30m");
    printf("priority value 1\n");
    
    printf("SCHED_OTHER ");

    clock_gettime( CLOCK_REALTIME, &start);
    pol=0;
    pri=1;
    pthread_create( &Thr_a, NULL, countA, NULL);
    pthread_join(Thr_a,NULL);
    clock_gettime( CLOCK_REALTIME, &finish);
    double time;

    time=(double)( finish.tv_sec - start.tv_sec)+( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    printf("%lf\n",time);

    for(double i=0;i<time;i+=0.1){
        printf("*");
    }
    printf("\n");

    printf("\033[1;34m");
    printf("SCHED_RR ");

    
    clock_gettime( CLOCK_REALTIME, &start);
    pol=1;
    pri=1;
    pthread_create( &Thr_b, NULL, countB, NULL);
    pthread_join(Thr_b,NULL);
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_sec - start.tv_sec)+( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    printf("%lf\n",time);

    for(double i=0;i<time;i+=0.1){
        printf("*");
    }
    printf("\n");
    printf("\033[1;32m");

    printf("SCHED_FIFO ");

    
    clock_gettime( CLOCK_REALTIME, &start);
    pol=2;
    pri=1;
    pthread_create( &Thr_c, NULL, countC, NULL);
    pthread_join(Thr_c,NULL);
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_sec - start.tv_sec)+( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    printf("%lf\n",time);

    for(double i=0;i<time;i+=0.1){
        printf("*");
    }
    printf("\n");
    printf("\n");

    

    //priority value is 5
    printf("\033[1;30m");
    printf("priority value 5\n");
    printf("SCHED_OTHER ");

    
    clock_gettime( CLOCK_REALTIME, &start);
    pol=0;
    pri=5;
    pthread_create( &Thr_a, NULL, countA, NULL);
    pthread_join(Thr_a,NULL);
    
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_sec - start.tv_sec)+( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    printf("%lf\n",time);

    for(double i=0;i<time;i+=0.1){
        printf("*");
    }
    printf("\n");

    printf("\033[1;34m");
    printf("SCHED_RR ");

    
    clock_gettime( CLOCK_REALTIME, &start);
    pol=1;
    pri=5;
    pthread_create( &Thr_b, NULL, countB, NULL);
    pthread_join(Thr_b,NULL);
    
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_sec - start.tv_sec)+( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    printf("%lf\n",time);

    for(double i=0;i<time;i+=0.1){
        printf("*");
    }
    printf("\n");
    printf("\033[1;32m");

    printf("SCHED_FIFO ");

    
    clock_gettime( CLOCK_REALTIME, &start);
    pol=2;
    pri=5;
    pthread_create( &Thr_c, NULL, countC, NULL);
    pthread_join(Thr_c,NULL);
   
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_sec - start.tv_sec)+( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    printf("%lf\n",time);

    for(double i=0;i<time;i+=0.1){
        printf("*");
    }
    printf("\n");
    printf("\n");



    //priority value is 10
    printf("\033[1;30m");
    printf("priority value 10\n");
    printf("SCHED_OTHER ");

    
    clock_gettime( CLOCK_REALTIME, &start);
    pol=0;
    pri=10;
    pthread_create( &Thr_a, NULL, countA, NULL);
    pthread_join(Thr_a,NULL);
    
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_sec - start.tv_sec)+( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    printf("%lf\n",time);

    for(double i=0;i<time;i+=0.1){
        printf("*");
    }
    printf("\n");

    printf("\033[1;34m");
    printf("SCHED_RR ");
    
    
    clock_gettime( CLOCK_REALTIME, &start);
    pol=1;
    pri=10;
    pthread_create( &Thr_b, NULL, countB, NULL);
    pthread_join(Thr_b,NULL);
    
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_sec - start.tv_sec)+( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    printf("%lf\n",time);

    for(double i=0;i<time;i+=0.1){
        printf("*");
    }
    printf("\n");
    printf("\033[1;32m");

    printf("SCHED_FIFO ");

   
    clock_gettime( CLOCK_REALTIME, &start);
    pol=2;
    pri=10;
    pthread_create( &Thr_c, NULL, countC, NULL);
    pthread_join(Thr_c,NULL);
    
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_sec - start.tv_sec)+( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    printf("%lf\n",time);

    for(double i=0;i<time;i+=0.1){
        printf("*");
    }
    printf("\n");
    printf("\n");



}
