#include<stdio.h>
#include<stdarg.h>
#include<time.h>

void tlog(const char* fmt,...)
{
    char msg[50];
    strftime(msg, sizeof msg, "%T", localtime(&(time_t){time(NULL)}));
    printf("[%s] ", msg);
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    
}


int main(void)
{
    tlog("Logging %d %d %d ....\n", 1, 2, 3);
}