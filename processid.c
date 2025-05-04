//In c Process id demo for os.
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(int argc, char**argv)
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		fprintf(stderr,"Fork failed\n");
		return 1;
	}
	else if(pid==0)
	{
	printf("Child process:PID=%d\n",getpid());
	char *args[]={"IS","-1",NULL};
	execvp(args[0],args);
	fprintf(stderr,"Exec failed\n");
	return 1;
	}
	else
	{
		printf("Parent process:PID=%d\n",getpid());
		printf("waiting for child process to complete\n");
		wait(NULL);
		printf("Child process fineshed\n");
	}
	return 0;
}
