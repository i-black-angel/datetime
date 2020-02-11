#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <string>

namespace mpl
{
    std::string now() {
        char buffer[64] = { 0x00 };
        struct timeval tv;
        gettimeofday(&tv, NULL);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S",
        localtime(&(tv.tv_sec)));
        return std::string(buffer);
    }
} // namespace mpl

int main(int argc, char *argv[]) {
    char buffer[64] = {0};
    struct timeval tv;
    gettimeofday(&tv, NULL);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S",
             localtime(&(tv.tv_sec)));
    printf("%s.%03d\n", buffer, tv.tv_usec/1000);

    printf("mpl::now() %s\n", mpl::now().c_str());
    return 0;
}
