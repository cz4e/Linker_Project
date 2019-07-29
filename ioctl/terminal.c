#ifndef  _TERMINAL_
#define  _TERMINAL_
#endif

#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>

struct winsize WindowSize;

void
getWindowSize(void)
{
	ioctl(STDOUT_FILENO,TIOCGWINSZ,WindowSize);
	return ;
}

long
getWindowSizeRow(void)
{
	return (WindowSize.ws_row);
}

long
getWindowSizeCol(void)
{
	return (WindowSize.ws_col);
}
