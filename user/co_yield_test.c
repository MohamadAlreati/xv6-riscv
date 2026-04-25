#include "kernel/types.h"
#include "user/user.h"

int 
main(void){
    int pid1 = getpid();
    int pid2 = fork();
    if(pid2 == 0){
        // child process
        for(int i = 0;i < 5; i ++){
            int value = co_yield(pid1, 1);
            printf("child %d in the %d iteration\n", value, i);
        }
    } else {
        // parent process
        for(int i = 0;i < 5; i ++){
            int value = co_yield(pid2, 2);
            printf("parent %d in the %d iteration\n", value, i);
        }
    }
    exit(0);
}