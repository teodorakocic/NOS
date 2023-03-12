#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define __NR_identity 451

long identity_syscall(int p_id)
{
    return syscall(__NR_identity, p_id);
}

int main(int argc, char *argv[])
{
	long activity;
	int count;

	srand(time(NULL));
	count = (rand() % 16) + 5;
	printf("Syscall will be called for %d processes that have been created!\n", count);
	for (int i=0; i<count; i++) {
		if(fork() == 0)
		{
			activity = identity_syscall(getpid());
			if(activity < 0)
			{
				perror("Sorry, Jasper. Your system call appears to have failed.");
			}

			else
			{
				printf("Congratulations, Jasper! Your system call is functional and working for process with id: %d and parent [%d]. Run the command dmesg in the terminal and find out!\n", getpid(), getppid());
			}
		    exit(0);
		}
	}
	for(int i=0; i<count; i++) {
		wait(NULL);
	}

    return 0;
}
