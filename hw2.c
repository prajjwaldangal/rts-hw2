#include <stdio.h>

struct task {
	char id;
	float period;
	float c;//computation time
	int priority;
	float r;//response time
};
typedef struct task task;

int main() {
	FILE * fp = fopen("/Users/prajjwaldangal/Documents/cs/spring2019/rts/hw2/file.txt", "r");
	int c;
   	if(fp == NULL) {
      		perror("Error in opening file");
      		return(-1);
   	}
	int t = 4;
	printf("Input: Enter the number of tasks in the taskset");
	scanf("%d", &t);
	int pos;
	while (!feof(fp)){
      		c = fgetc(fp);
		
	}
	fclose(fp);
	return 0;
}
