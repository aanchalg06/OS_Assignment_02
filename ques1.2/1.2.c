#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sched.h>
#include <time.h>


char s0[]="bash";
char s1[]="bashfile1.sh";
char s2[]="bashfile2.sh";
char s3[]="bashfile3.sh";

int n1;
int n2;
int n3;

int pri1=2;
int pri2=5;
int pri3=8;

struct timespec start, finish;
struct sched_param pa,pb,pc;

double subtract_timespec(const struct timespec *t1,const struct timespec *t2){
  return (t1->tv_sec - t2->tv_sec) + (t1->tv_nsec - t2->tv_nsec) / 1000000000.0;
}

void make_fork(){
  n1=fork();
  n2=fork();
  n3=fork();
}

void set_priority(){
  pa.sched_priority = pri1;
  pb.sched_priority = pri2;
  pc.sched_priority = pri3;
}

void wait_pid(){
  waitpid(n1,NULL,0);
  waitpid(n2,NULL,0);
  waitpid(n3,NULL,0);
}

void pa_schdueler(){
  sched_setscheduler(getpid(),SCHED_RR,&pa);
}

void pb_schdueler(){
  sched_setscheduler(getpid(),SCHED_FIFO,&pb);
}

void pc_schdueler(){
  sched_setscheduler(getpid(),SCHED_RR,&pc);
}


int main()
{
  make_fork();

  set_priority();

  if(n3<0 || n1<0 || n2<0){
      printf("Error in fork");
    }  

    if (n1==0 && n2 >0 && n3 > 0){
      char *argumenta[]={s0,s1,NULL};
      execvp(argumenta[0],argumenta);        

        //@stackoverflow stackoverflow.com/questions/68804469/subtract-two-timespec-objects-find-difference-in-time-or-duration
        double time=subtract_timespec(clock_gettime( CLOCK_REALTIME, &start),clock_gettime( CLOCK_REALTIME, &finish));

      

        printf("%lf ",time);


        return 0;
    }

    if(n3<0 || n1<0 || n2<0){
      printf("Error in fork");
    }  

    if (n2==0 && n1 >0 && n3 > 0){

      //@stackoverflow https://stackoverflow.com/questions/63913550/using-execvp-to-read-command-line-arguments-as-commands-error
      char *argumentb[]={s0,s2,NULL};
      
        execvp(argumentb[0],argumentb);        

        double time=subtract_timespec(clock_gettime( CLOCK_REALTIME, &start),clock_gettime( CLOCK_REALTIME, &finish));

        printf("%lf ",time);


        return 0;
    }

    if(n3<0 || n1<0 || n2<0){
      printf("Error in fork");
    }  

    if (n3==0 && n1 >0 && n2 > 0){
      char *argumentc[]={s0,s3,NULL};
      
        execvp(argumentc[0],argumentc);
        

        double time=subtract_timespec(clock_gettime( CLOCK_REALTIME, &start),clock_gettime( CLOCK_REALTIME, &finish));

        printf("%lf ",time);


        return 0;
    }

    if(n3<0 || n1<0 || n2<0){
      printf("Error in fork");
    }  

    wait_pid();

    if(n3<0 || n1<0 || n2<0){
      printf("Error in fork");
    }  

    
	return 0;
}