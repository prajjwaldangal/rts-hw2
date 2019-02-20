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
#include <math.h>

size_t N = 3;

struct task {
	char * id;
	float period;
	float c;//computation time
	int priority;
	float r;//response time
};
typedef struct task task;
task * get_response_times(task * task_set);
int comparator(const void *p, const void *q);
void print_tasks(task * task_set);
void freeStr(char ** str);

int main(int argc, const char * argv[]) {
    // Open file with task set info
    FILE * fp = fopen(argv[2], "r");
   	if(fp == NULL) {
      		perror("Error in opening file");
      		return(-1);
   	}
    
	printf("Input: Enter the number of tasks in the taskset\n");
    if (strncmp(argv[1], "s", 1) == 0){ // s for scan
        scanf("%zu", &N);
    }
    printf("No. of tasks: %zu\n", N);
    
    // store task in program structs / arrays
    int s=0;
    int i=0;
    char c = '@';
    task * TS = (task *) malloc(sizeof(task) * N);
    char * tok = (char *) malloc(256);
    char prev = '$';
    
    // reset s after each line, tok after each data piece
    while (!feof(fp)) {
        c = fgetc(fp);
        // cnt ++;
        if (c == ' ' && prev != ' ') {
            s ++;
            if (s==1) {
                TS[i].id = (char *) malloc(256);
                strncpy(TS[i].id, tok, 256);
                // TS[i].id = tok;
            } else if (s==2) {
                float period;
                // copy array to float
                sscanf(tok, "%f", &period);
                TS[i].period = period;
            } else if (s==3) {
                float c;
                sscanf(tok, "%f", &c);
                TS[i].c = c;
            } else if (s == 4) {
                int priority;
                sscanf(tok, "%d", &priority);
                TS[i].priority = priority;
            }
        } else if (c==' ' && prev == ' ') {
            continue;
        } else if (c == '\n') {
            s = 0;
            i ++;
        } else {
            strncat(tok, &c, 1);
            prev = c;
            continue;
        }
        prev = c;
        freeStr(&tok);
        tok = (char *) malloc(256);
    }
    
    task * t = get_response_times(TS);
    print_tasks(t);
//    printf("n       exp\n");
//    for (int n=1; n<10; n++) {
//        printf("%d      %f", n, (pow(2, 1/n)-1) * n);
//    }
	return 0;
}

void print_tasks(task * task_set) {
    for (int i =0; i<N; i++) {
        printf("Task: %s\nPeriod: %.2f\nComputation Time: %.2f\nPriority %d\nResponse time: %.2f\n\n", \
               task_set[i].id, task_set[i].period, task_set[i].c, task_set[i].priority, task_set[i].r);
    }
}

void freeStr(char **str)
{
    free( *str );
    *str = NULL;
}

task * get_response_times(task * task_set) {
    printf("\n##################################################\n");
    printf("Sorting by priority.......\n");
    qsort(task_set, N, sizeof(task), comparator);
    print_tasks(task_set);
    printf("\n##################################################\n");
    printf("Calculating response times.......\n");
    for (int i=1; i<N; i++) {
        task_set[i].r = INFINITY;
    }
    task_set[0].r = task_set[0].c;
    int n;
    int w[N][100];
    int val = 0;
    for (int i=1; i<N; i++) {
        n = 0;
        w[i][0] = task_set[i].c;
        while (1) {
            val = 0;
            if (w[i][n] > task_set[i].period) {
                break;
            }
            for (int j=0; j<i; j++) {
                val += ceil(w[i][n] / task_set[j].period) * task_set[j].c;
            }
            w[i][n+1] = task_set[i].c + val;
            printf("i: %d, n: %d, val: %d\n", i, n, w[i][n+1]);
            if (w[i][n+1] == w[i][n]) {
                task_set[i].r = w[i][n];
                break;
            }
            n++;
        }
    }
    return task_set;
}

int comparator(const void *p, const void *q) {
    task * t1 = (task *)p;
    task * t2 = (task *)q;
    return -(t1->priority - t2->priority);
}
