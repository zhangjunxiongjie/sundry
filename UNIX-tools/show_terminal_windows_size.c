#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <signal.h>

#ifndef TIOCGWINSZ
#include <sys/ioctl.h>
#endif

static void pr_winsize(int fd)
{
	struct winsize size;
	if (ioctl(fd, TIOCGWINSZ, (char*)&size) < 0)
	{
		printf("TIOCGWINSZ error\n");
		exit(1);
	}
	
	printf("%d rows, %d columns.\n", size.ws_row, size.ws_col);

}

static void sig_winch(int signo)
{
	printf("SIGWINCH received.\n");
	pr_winsize(STDIN_FILENO);
}

int main(int argc, char *argv)
{
	//printf("origin rows: , columns: .\n");
	//printf("current rows: , columns: .\n");

	if (isatty(STDIN_FILENO) == 0)
	{
		exit(1);
	}
	if (signal(SIGWINCH, sig_winch) == SIG_ERR) // window size change signal catch.
		printf("signal error.\n");
	
	pr_winsize(STDIN_FILENO); // print current window size.
	
	for (;;) // 
	{
		pause();
	}

	exit(0);
}
