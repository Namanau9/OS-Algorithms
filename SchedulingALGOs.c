#include <stdio.h>
#include <stdlib.h>


void fcfs_scheduling(int processes[], int n, int burst_time[]) {
    int waiting_time[n], turnaround_time[n];
    waiting_time[0] = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    // Print results
    printf("\n%-10s%-15s%-15s%-15s", "PID", "Burst Time", "Waiting Time", "Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d%-15d%-15d%-15d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
}

void sjn_scheduling(int processes[], int n, int burst_time[]) {
    // Sort processes based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (burst_time[j] > burst_time[j + 1]) {
                int temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;

                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    fcfs_scheduling(processes, n, burst_time);  // Call FCFS for SJN as well
}

void round_robin_scheduling(int processes[], int n, int burst_time[], int quantum) {
    int waiting_time = 0, remaining_time[n];
    for (int i = 0; i < n; i++) remaining_time[i] = burst_time[i];

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;  // There is a process that is not finished
                if (remaining_time[i] > quantum) {
                    waiting_time += remaining_time[i] - quantum;
                    remaining_time[i] -= quantum;
                } else {
                    waiting_time += remaining_time[i];
                    remaining_time[i] = 0;  // Process is finished
                }
            }
        }
        if (done) break;
    }

    printf("\n%-10s%-15s%-15s\n", "PID", "Burst Time", "Waiting Time");
    for (int i = 0; i < n; i++) {
        printf("%-10d%-15d%-15d\n", processes[i], burst_time[i], waiting_time);
    }
}

void priority_scheduling(int processes[], int n, int burst_time[], int priority[]) {
    // Sort processes based on priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                int temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;

                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    fcfs_scheduling(processes, n, burst_time);  // Call FCFS for priority scheduling as well
}


int main() {
    int processes[] = {1, 2, 3, 4, 5};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {10, 5, 8, 16, 6};
    int quantum = 4;  // Round Robin quantum

    int priority[] = {3, 1, 4, 2, 5};


    puts("\nFCFS Scheduling");
    fcfs_scheduling(processes, n, burst_time);
    puts("\nSJN Scheduling");
    sjn_scheduling(processes, n, burst_time);
    puts("\nRound Robin Scheduling");
    round_robin_scheduling(processes, n, burst_time, quantum);
    puts("\nPriority Scheduling");
    priority_scheduling(processes, n, burst_time, priority);
    
    return 0;
}
