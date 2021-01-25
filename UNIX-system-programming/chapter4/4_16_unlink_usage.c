#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if ((argc == 2) && (open(argv[1], O_RDWR) < 0))
		err_sys("open error, %s ", argv[1]);
	
	if (unlink(argv[1]) < 0)
		err_sys("unlink error, %s ", argv[1]);
	
	printf("%s unlinked\n", argv[1]);

	sleep(15);
	printf("done\n");
	exit(0);
}
