#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    char buffer[64] = {0};
    struct timeval tv;
    gettimeofday(&tv, NULL);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S",
             localtime(&(tv.tv_sec)));
    printf("%s.%03d\n", buffer, tv.tv_usec/1000);
    return 0;
}
