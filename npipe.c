#include <func.h>
int main(int argc, char *argv[])
{
    int fds1[2], fds2[2];
    pipe(fds1);
    pipe(fds2);
    if(fork()){
        close(fds1[0]);
        close(fds2[1]);
        write(fds1[1],"nihao",5);
        printf("write over!\n");
        char buf[1024] = {0};
        read(fds2[0],buf,sizeof(buf));
        printf("I am parent, buf = %s\n", buf);
        wait(NULL);
    }
    else{
        close(fds1[1]);
        close(fds2[0]);
        char buf[1024] = {0};
        sleep(5);
        read(fds1[0],buf,sizeof(buf));
        printf("I am child, buf = %s\n", buf);
        write(fds2[1],"hello",5);
        exit(0);
    }
    return 0;
}


