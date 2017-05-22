#include <stdio.h>
#include <sys/resource.h>
#include<sys/time.h>
int main() {
    struct rlimit lim, lim1, lim2;
    getrlimit(RLIMIT_STACK, &lim);
    printf("stack size: %d\n", (int)lim.rlim_cur);  //rlim_cur is soft limit, which gives the value that the kernel allocates
    getrlimit(RLIMIT_NPROC, &lim1);
    printf("process limit: %d\n", (int)lim1.rlim_cur);
    getrlimit(RLIMIT_NOFILE, &lim2);
    printf("max file descriptors: %d\n", (int)lim2.rlim_cur-1);
    return 0;
}
