#include <stdio.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>

//@reference: https://cool-dev.in/posts/How-to-Implement-a-System-Call-In-Linux/

#define kernel_2d_memcpy 451

int main()
{
    long system_call_var;
    
   

    float *m1[][2]={{1,1},{1,1}};
    
    
    float *m2[][2]={{0,0},{0,0};
    
     printf("Matrix 1 function is: ");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%f ",m1[i][j]);
        }
        printf("\n");
    }

    system_call_var = syscall(kernel_2d_memcpy,m2,m1,2,2);

    if (!system_call_var)
    {
        printf("451 exec done \n");
    }
    printf("Matrix 1 function is: ");
                   
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%f ",m1[i][j]);
        }
        printf("\n");
    }
    return 0;
}
