#include <bits/stdc++.h>
using namespace std;
int curr = INT_MAX;
double avgTurnAroundTime = 0, avgwaitingTime = 0, avgresponseTime = 0;

class SJF
{
public:
    string name;
    int completionTime, arrivalTime, burstTime, turnAroundTime, responseTime, waitingTime;
};

bool cmp1(const SJF &o1, const SJF &o2)
{
    if (o1.arrivalTime == o2.arrivalTime)
    {
        return o1.burstTime < o2.burstTime;
    }
    return o1.arrivalTime < o2.arrivalTime;
}

bool cmp2(const SJF &o1, const SJF &o2)
{
    if (curr >= o2.arrivalTime && curr >= o1.arrivalTime)
    {
        return o1.burstTime < o2.burstTime;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<SJF> process(n);

    for (int i = 0; i < n; i++)
    {
        process[i].name = "P" + to_string(i + 1);
        cin >> process[i].arrivalTime;
        curr = min(curr, process[i].arrivalTime);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> process[i].burstTime;
    }

    sort(process.begin(), process.end(), cmp1);

    for (int i = 0; i < n; i++)
    {
        process[i].responseTime = curr - process[i].arrivalTime;
        process[i].completionTime = curr + process[i].burstTime;

        if (i < n - 1)
        {
            curr = max(process[i].completionTime, process[i + 1].arrivalTime);
        }

        process[i].turnAroundTime = process[i].completionTime - process[i].arrivalTime;
        process[i].waitingTime = process[i].turnAroundTime - process[i].burstTime;

        avgTurnAroundTime += process[i].turnAroundTime;
        avgresponseTime += process[i].responseTime;
        avgwaitingTime += process[i].waitingTime;

        sort(process.begin() + i + 1, process.end(), cmp2);
    }

    cout << "    AT\tBT\tCT\tTAT\tWT\tRT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << process[i].name << ":  ";
        cout << process[i].arrivalTime << "\t" << process[i].burstTime << "\t" << process[i].completionTime << "\t" << process[i].turnAroundTime << "\t" << process[i].waitingTime << "\t" << process[i].responseTime;
        cout << endl;
    }

    cout << endl;
    cout << setprecision(2) << fixed;
    cout << "Average TurnAroundTime: " << avgTurnAroundTime / n << "\n";
    cout << "Average WaitingTime: " << avgwaitingTime / n << "\n";
    cout << "Average ResponseTime: " << avgresponseTime / n << "\n";

    cout << endl;
    cout << process[0].arrivalTime << "  |" << process[0].name << "|  ";
    for (int i = 0; i < n - 1; i++)
    {
        cout << process[i].completionTime << "  |" << process[i + 1].name << "|  ";
    }
    cout << process[n - 1].completionTime;
    cout << endl;
}
