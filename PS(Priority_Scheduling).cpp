//Priority Scheduling
//It can be both preemptive and non-preemptive
//This code is following preemptive approach
//it includes higher priority
//Implemented by me

#include<bits/stdc++.h>
using namespace std;

int main() {
    int bt[5], p[5], wt[5], tat[5], pr[5], i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat; // Changed to floating-point variables for more accurate averages

    cout << "Higher priority." << endl;//high priority onushoron korbe
    cout << "Enter Total Number Of Processes: ";//process shonkha
    cin >> n;

    cout << "Enter Burst Time and Priority" << endl;
    for (i = 0; i < n; i++) { //O(n) complexity
        cout << endl << "Process " << i + 1 << endl;
        cout << "Burst Time: ";
        cin >> bt[i];
        cout << "Priority: ";
        cin >> pr[i];//priority gulo store kore

        p[i] = i + 1;//process 1 theke shuru
    }
//O(n^2) complexity
    for (i = 0; i < n; i++) { //selection sort ; priority onushare sorted hbe
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (pr[j] < pr[pos]) { //bortoman position e j choto man==highest priority thake
                pos = j; //position ekhn update hoye j hobe karon j highest priority
            }
        }

        swap(pr[i], pr[pos]);//priority onushare burst time, priority time o change hobe
        swap(bt[i], bt[pos]);
        swap(p[i], p[pos]);
    }

    wt[0] = 0;
    total = 0;

    //O(n^2) complexity
    for (i = 1; i < n; i++) {
        wt[i] = 0;//prothome waiting time 0 initialize korbe
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];//burst time jog hote thake
        }
        total += wt[i];//total waiting time count korbe
    }

    avg_wt = total / (float)n; // Calculate average waiting time with floating-point division

    total = 0;
    cout << endl << "Process    Burst Time    Waiting Time    Turnaround Time";
//O(n) complexity
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];//turnaround time count korbe
        total += tat[i];//total turnaround time nibe
        cout << endl << p[i] << "             " << bt[i] << "               " << wt[i] << "                 " << tat[i];
    }
    avg_tat = total / (float)n; // Calculate average turnaround time with floating-point division
    cout << endl << "Average Waiting Time = " << avg_wt;
    cout << endl << "Average TAT = " << avg_tat;
    return 0;

    //total time complexity - O(n^2) complexity
}

