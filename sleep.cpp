#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void sleep_seconds(int seconds) {
    #ifdef _WIN32
        int miliseconds = seconds * 1000;
        Sleep(miliseconds);
    #else
        sleep(seconds);
    #endif
}
