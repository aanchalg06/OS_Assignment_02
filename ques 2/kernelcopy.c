#include <stdio.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>

#define kernel_2d_memcpy 451

int main()
{
    long system_call_var;

    float *m1[][]={{4,6,3},{12,6,3},{3,8,5}};
    float *m2[][]={{0,0,0},{0,0,0},{0,0,0}};

    system_call_var = syscall(kernel_2d_memcpy,m1,m2,3,3);

    if (!system_call_var)
    {
        printf("451 exec done \n");
    }

    return 0;
}