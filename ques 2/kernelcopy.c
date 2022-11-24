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
    
    printf("Matrix 1 function is: ");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%f ",m1[i][j]);
        }
        printf("\n");
    }

    float *m1[][2]={{4,6},{12,6}};
    
    
    float *m2[][2]={{0,0},{0,0};

    system_call_var = syscall(kernel_2d_memcpy,m1,m2,2,2);

    if (!system_call_var)
    {
        printf("451 exec done \n");
    }
    printf("Matrix 2 function is: ");
                   
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%f ",m2[i][j]);
        }
        printf("\n");
    }
    return 0;
}
