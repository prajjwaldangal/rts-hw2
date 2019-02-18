//
//  main.c
//  RTS-HW2
//
//  Created by Prajjwal Dangal on 2/17/19.
//  Copyright © 2019 Prajjwal Dangal. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t N = 4;

struct task {
	char * id;
	float * period;
	float * c;//computation time
	int * priority;
	float * r;//response time
};
typedef struct task task;
float get_response_times(task * task_set);
int comparator(const void *p, const void *q);
void print_tasks(task * task_set);

int main(int argc, const char * argv[]) {
	FILE * fp = fopen("/Users/prajjwaldangal/Documents/cs/spring2019/rts/hw2/file.txt", "r");
   	if(fp == NULL) {
      		perror("Error in opening file");
      		return(-1);
   	}
    
	printf("Input: Enter the number of tasks in the taskset\n");
    if (strncmp(argv[1], "s", 1) == 0){ // s for scan
        scanf("%zu", &N);
    }
    printf("No. of tasks: %zu\n", N);
    
    int s=0;
    int i=0;
    char c;
    task * TS = (task *) malloc(sizeof(task) * N);
    char * tok = (char *) malloc(255);
    while (!feof(fp)) {
        c = fgetc(fp);
        if (c == ' ') {
            s ++;
            if (s==1) {
                TS[i].id = tok;
            } else if (s==2) {
                // convert char array to float
                TS[i].period = (float *) tok;
            } else if (s==3) {
                TS[i].c = (float *) tok;
            } else {
                
            }
            continue;
        }
        if (c == '\n') {
            i ++;
            memset(tok, 0, 255);
            TS[i].priority = (int *) tok;
            continue;
        }
        strncat(tok, &c, 1);
    }
    printf("i = %d\n", i);
    print_tasks(TS);
	return 0;
}





void print_tasks(task * task_set) {
    for (int i =0; i<N; i++) {
        printf("Priority %d", *task_set[i].priority);
    }
}

//float get_response_times(task * task_set) {
//    qsort((void *)task_set, N, sizeof(task *), comparator);
//
//}

int comparator(const void *p, const void *q) {
    task * t1 = (task *)p;
    task * t2 = (task *)q;
    if (t1->priority >= t2->priority) {
        return 1;
    } else {
        return -1;
    }
}
//w[i][0] = task_set.c;

