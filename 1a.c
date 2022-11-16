#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

pthread_t Thr_a;
pthread_t Thr_b;
pthread_t Thr_c;


void* countA(int pri,char pol[]){
    struct sched_param sch;
    int policy=0;

    if(pol=="SCHED_OTHER"){
        policy= SCHED_OTHER;
    }
    else if(pol == "SCHED_FIFO"){
        policy= SCHED_FIFO;
    }
    else{
        policy= SCHED_RR;
    }
    
    sch.sched_priority = pri;

    if (pthread_setschedparam(Thr_a, policy, &sch) ==0)
{
    int i=0;
    while(i<=pow(2,30)){
        i++;
    }
}

}

void* countB(int pri,char pol[]){
    struct sched_param sch;
    int policy=0;

    if(pol=="SCHED_OTHER"){
        policy= SCHED_OTHER;
    }
    else if(pol == "SCHED_FIFO"){
        policy= SCHED_FIFO;
    }
    else{
        policy= SCHED_RR;
    }

    sch.sched_priority = pri;

    if (pthread_setschedparam(Thr_b, policy, &sch) ==0)
{
    int i=0;
    while(i<=pow(2,30)){
        i++;
    }
}

}

void* countC(int pri,char pol[]){
    struct sched_param sch;
    int policy=0;

    if(pol=="SCHED_OTHER"){
        policy= SCHED_OTHER;
    }
    else if(pol == "SCHED_FIFO"){
        policy= SCHED_FIFO;
    }
    else{
        policy= SCHED_RR;
    }

    sch.sched_priority = pri;

    if (pthread_setschedparam(Thr_c, policy, &sch) ==0)
{
    int i=0;
    while(i<=pow(2,30)){
        i++;
    }
}

}

int main(){
    int nice_pri=0;
    int def_pri= 5;
    int min_pri=1;
    int max_pri=10;

    char other[20]="SCHED_OTHER";
    char fifo[20]="SCHED_FIFO";
    char rr[20]="SCHED_RR";
    //THREAD A
    //priority value is 0
    printf("For Thread A: priority value 0");
    printf("For Thread A ; SCHED_OTHER\n");

    struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_a, NULL, countA, (nice_pri,other));
    clock_gettime( CLOCK_REALTIME, &finish);

    double time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread A ; SCHED_RR\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_a, NULL, countA, (nice_pri,rr));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread A ; SCHED_FIFO\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_a, NULL, countA, (nice_pri,fifo));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");




    //priority value is 1
    printf("For Thread A: priority value 1");
    printf("For Thread A ; SCHED_OTHER\n");

    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_a, NULL, countA, (min_pri,other));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread A ; SCHED_RR\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_a, NULL, countA, (min_pri,rr));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread A ; SCHED_FIFO\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_a, NULL, countA, (min_pri,fifo));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");



    //priority value is 5
    printf("For Thread A: priority value 0");
    printf("For Thread A ; SCHED_OTHER\n");

    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_a, NULL, countA, (def_pri,other));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread A ; SCHED_RR\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_a, NULL, countA, (def_pri,rr));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread A ; SCHED_FIFO\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_a, NULL, countA, (def_pri,fifo));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    //priority value is 10
    printf("For Thread A: priority value 0");
    printf("For Thread A ; SCHED_OTHER\n");

    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_a, NULL, countA, (max_pri,other));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread A ; SCHED_RR\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_a, NULL, countA, (max_pri,rr));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread A ; SCHED_FIFO\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_a, NULL, countA, (max_pri,fifo));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");



    //THREAD B
    //priority value is 0
    printf("For Thread B: priority value 0");
    printf("For Thread B ; SCHED_OTHER\n");

    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_b, NULL, countB, (nice_pri,other));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread B ; SCHED_RR\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_b, NULL, countB, (nice_pri,rr));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread B ; SCHED_FIFO\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_b, NULL, countB, (nice_pri,fifo));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");




    //priority value is 1
    printf("For Thread B: priority value 1");
    printf("For Thread B ; SCHED_OTHER\n");

    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_b, NULL, countB, (min_pri,other));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread B ; SCHED_RR\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_b, NULL, countB, (min_pri,rr));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread B ; SCHED_FIFO\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_b, NULL, countB, (min_pri,fifo));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");



    //priority value is 5
    printf("For Thread B: priority value 0");
    printf("For Thread B ; SCHED_OTHER\n");

    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_b, NULL, countB, (def_pri,other));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread B ; SCHED_RR\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_b, NULL, countB, (def_pri,rr));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread B ; SCHED_FIFO\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_b, NULL, countB, (def_pri,fifo));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    //priority value is 10
    printf("For Thread B: priority value 0");
    printf("For Thread B: SCHED_OTHER\n");

    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_b, NULL, countB, (max_pri,other));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread B ; SCHED_RR\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_b, NULL, countB, (max_pri,rr));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread B ; SCHED_FIFO\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_b, NULL, countB, (max_pri,fifo));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");




    //THREAD C
    //priority value is 0
    printf("For Thread C: priority value 0");
    printf("For Thread C ; SCHED_OTHER\n");

    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_c, NULL, countC, (nice_pri,other));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread C ; SCHED_RR\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_c, NULL, countC, (nice_pri,rr));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread C ; SCHED_FIFO\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_c, NULL, countC, (nice_pri,fifo));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");




    //priority value is 1
    printf("For Thread C: priority value 1");
    printf("For Thread C ; SCHED_OTHER\n");

    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_c, NULL, countC, (min_pri,other));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread C ; SCHED_RR\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_c, NULL, countC, (min_pri,rr));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread C ; SCHED_FIFO\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_c, NULL, countC, (min_pri,fifo));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");



    //priority value is 5
    printf("For Thread C: priority value 0");
    printf("For Thread C ; SCHED_OTHER\n");

    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_c, NULL, countC, (def_pri,other));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread C ; SCHED_RR\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_c, NULL, countC, (def_pri,rr));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread C ; SCHED_FIFO\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_c, NULL, countC, (def_pri,fifo));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    //priority value is 10
    printf("For Thread C: priority value 0");
    printf("For Thread C: SCHED_OTHER\n");

    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_c, NULL, countC, (max_pri,other));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread C ; SCHED_RR\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_c, NULL, countC, (max_pri,rr));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");

    printf("For Thread C ; SCHED_FIFO\n");
    // struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start);
    pthread_create( &Thr_c, NULL, countC, (max_pri,fifo));
    clock_gettime( CLOCK_REALTIME, &finish);

    time=(double)( finish.tv_nsec - start.tv_nsec)/ (double)(1000000000);

    for(int i=0;i<time;i+=0.00001){
        printf("*");
    }
    printf("\n");




}
