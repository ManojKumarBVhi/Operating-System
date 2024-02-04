#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int id,wt;
	id = fork();
	if(id == 0){
		printf("child - My ID is : %d\n",getpid());
		printf("Child - My parent ID is : %d\n",getppid());
		execl("./2_appl","app2.c","argc","argv[1]",NULL);
		exit(34);
	}
	else if(id > 0){
		wait(&wt);
		printf("Parent - My ID is : %d\n",getpid());
		printf("Parent - My parent ID is : %d\n",getppid());

		if(WIFEXITED(wt)){
			printf("The child terminated normally and status is : %d\n", WEXITSTATUS(wt));
		}
		else if(WIFSIGNALED(wt)){
			printf("The child terminated abnormally and is killed by signal %d\n", WTERMSIG(wt));
		}
	}
}

/*Application

#include<stdio.h>
#include<string.h>

int main(){
	char str[100];
	printf("Enter the string : ");
	scanf("%s",str);
	int len = strlen(str);
	printf("The origianl string is : %s\n",str
	for(int i = 0,j=len-1; i <= j; i++,j--){
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
	printf("The reversed  string is  : %s\n",str);
	
	return 0;
}
*/
