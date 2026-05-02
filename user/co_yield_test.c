#include "kernel/types.h"
#include "user/user.h"

void
main(void){
    int pid1 = getpid();
    int pid2 = fork();
    if(pid2 == 0){
        // child process
        for(int i = 0;i < 1000; i ++){    //note : when i=500 i got sched lock error! we should test that
            int value = co_yield(pid1, 1);
            printf("child  received: %d in the %d iteration\n", value, i);
        }
    } else {
        // parent processs
        for(int i = 0;i < 1000; i ++){
            int value = co_yield(pid2, 2);
            printf("parent received: %d in the %d iteration\n", value, i);
        }
    }
}