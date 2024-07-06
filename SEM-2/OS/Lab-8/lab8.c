#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
} Process;

int n_processes;
Process processes[MAX_PROCESSES];

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_priority() {
    for (int i = 0; i < n_processes - 1; i++) {
        for (int j = 0; j < n_processes - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void preemptive_priority_scheduling() {
    int time = 0;
    int completed = 0;
    int is_completed[MAX_PROCESSES] = {0};

    printf("\nPreemptive Priority Scheduling:\n");

    while (completed != n_processes) {
        int idx = -1;
        int highest_priority = 999;

        for (int i = 0; i < n_processes; i++) {
            if (processes[i].burst_time > 0 && processes[i].priority < highest_priority && !is_completed[i]) {
                highest_priority = processes[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            processes[idx].burst_time--;
            time++;

            if (processes[idx].burst_time == 0) {
                is_completed[idx] = 1;
                completed++;
                processes[idx].turnaround_time = time;
                processes[idx].waiting_time = processes[idx].turnaround_time - processes[idx].burst_time;
            }

            for (int i = 0; i < n_processes; i++) {
                if (!is_completed[i] && processes[i].burst_time > 0) {
                    processes[i].priority++;  // Aging
                }
            }
        }
    }

    printf("PID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

void non_preemptive_priority_scheduling() {
    int time = 0;
    int completed = 0;
    int is_completed[MAX_PROCESSES] = {0};

    printf("\nNon-Preemptive Priority Scheduling:\n");

    while (completed != n_processes) {
        int idx = -1;
        int highest_priority = 999;

        for (int i = 0; i < n_processes; i++) {
            if (processes[i].burst_time > 0 && processes[i].priority < highest_priority && !is_completed[i]) {
                highest_priority = processes[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            time += processes[idx].burst_time;
            is_completed[idx] = 1;
            completed++;
            processes[idx].turnaround_time = time;
            processes[idx].waiting_time = processes[idx].turnaround_time - processes[idx].burst_time;
        }
    }

    printf("PID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &n_processes);

    for (int i = 0; i < n_processes; i++) {
        printf("Enter burst time and priority for process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].priority);
        processes[i].pid = i + 1;
    }

    sort_by_priority();
    preemptive_priority_scheduling();
    non_preemptive_priority_scheduling();

    return 0;
}