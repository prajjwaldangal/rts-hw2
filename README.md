# rts-hw2
This is the response time analysis of real-time systems in C. This is done using fixed priority scheduling. Sample output:

Input: Enter the number of tasks in the taskset                                         
3                                                                                  
No. of tasks: 3                                                                                  
################################################## Sorting by priority.......                                                 
Task: c                                                                                  
Period: 20.00                                                                                  
Computation Time: 5.00 Priority 3                                                                                  
Response time: 0.00                                                                                  
Task: b                                                                                  
Period: 40.00 Computation Time: 10.00 Priority 2                                                                              
Response time: 0.00                                                                                  
Task: a                                                                                  
Period: 80.00 Computation Time: 40.00 Priority 1                                         
Response time: 0.00                                                                                  
################################################## Calculating response times.......
i: 1, n: 0, val: 15
i: 1, n: 1, val: 15
i: 2, n: 0, val: 60 i: 2, n: 1, val: 75 i: 2, n: 2, val: 80 i: 2, n: 3, val: 80 Task: c
Period: 20.00 Computation Time: 5.00 Priority 3
Response time: 5.00
Task: b
Period: 40.00 Computation Time: 10.00 Priority 2
Response time: 15.00
Task: a
Period: 80.00 Computation Time: 40.00 Priority 1
Response time: 80.00

Program ended with exit code: 0
