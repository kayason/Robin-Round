#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10
#define TIME_QUANTUM 2

struct Process {
    int id;
    int burst_time;
    int remaining_time;
};

int main() {
    struct Process processes[MAX_PROCESS];
    int num_processes, total_time = 0, time = 0, i;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // Input process information
    for (i = 0; i < num_processes; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        total_time += processes[i].burst_time;
    }

    printf("\nProcess\tBurst Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%d\n", processes[i].id, processes[i].burst_time);
    }

    printf("\nGantt Chart:\n");
    printf("0");
    while (time < total_time) {
        for (i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0) {
                int run_time = (processes[i].remaining_time >= TIME_QUANTUM) ? TIME_QUANTUM : processes[i].remaining_time;
                printf(" -> P%d", processes[i].id);
                time += run_time;
                processes[i].remaining_time -= run_time;
            }
        }
    }
    printf("\n");
    return 0;
}

