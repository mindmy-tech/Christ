#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int burst_time;
    int remaining_time;
} Process;

void round_robin_preemptive(Process processes[], int n, int time_quantum) {
    int current_time = 0;
    int completed = 0;
    int queue[n];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        queue[rear++] = i;
    }

    while (completed != n) {
        int index = queue[front];
        front = (front + 1) % n;

        if (processes[index].remaining_time <= time_quantum) {
            current_time += processes[index].remaining_time;
            printf("Process %d executed from time %d to %d\n", processes[index].pid, current_time - processes[index].remaining_time, current_time);
            completed++;
            processes[index].remaining_time = 0;
        } else {
            processes[index].remaining_time -= time_quantum;
            current_time += time_quantum;
            printf("Process %d executed from time %d to %d\n", processes[index].pid, current_time - time_quantum, current_time);
            queue[rear++] = index;
            rear %= n;
        }
    }
}

void round_robin_non_preemptive(Process processes[], int n, int time_quantum) {
    int current_time = 0;
    int completed = 0;

    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time <= time_quantum) {
                    current_time += processes[i].remaining_time;
                    printf("Process %d executed from time %d to %d\n", processes[i].pid, current_time - processes[i].remaining_time, current_time);
                    completed++;
                    processes[i].remaining_time = 0;
                } else {
                    processes[i].remaining_time -= time_quantum;
                    current_time += time_quantum;
                    printf("Process %d executed from time %d to %d\n", processes[i].pid, current_time - time_quantum, current_time);
                }
            }
        }
    }
}

int main() {
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    printf("\nPreemptive Round Robin Scheduling:\n");
    round_robin_preemptive(processes, n, time_quantum);

    printf("\nNon-Preemptive Round Robin Scheduling:\n");
    round_robin_non_preemptive(processes, n, time_quantum);

    return 0;
}