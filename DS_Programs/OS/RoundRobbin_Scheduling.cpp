#include <bits/stdc++.h>
using namespace std;
int curr = INT_MAX;
double avgTurnAroundTime = 0, avgwaitingTime = 0, avgresponseTime = 0;

class roundRobbin
{
public:
    string name;
    int completionTime, arrivalTime, burstTime, turnAroundTime, responseTime, waitingTime, remburstTime;
};

int main()
{
    int n, TQ;
    cin >> n >> TQ;

    vector<roundRobbin> process(n);
    queue<roundRobbin> q;

    for (int i = 0; i < n; i++)
    {
        process[i].name = "P" + to_string(i + 1);
        cin >> process[i].arrivalTime;
        curr = min(curr, process[i].arrivalTime);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> process[i].burstTime;
        process[i].remburstTime = process[i].burstTime;
    }

    int i = 0;
    while (i < n && curr == process[i].arrivalTime)
    {
        q.push(process[i]);
        i++;
    }

    cout << "|  " << curr << "  |";
    while (!q.empty())
    {
        roundRobbin x = q.front();
        q.pop();
        int p = x.name[1] - '0' - 1;

        while (i < n && curr + TQ >= process[i].arrivalTime)
        {
            q.push(process[i]);
            i++;
        }

        cout << process[p].name << "|  ";

        if (x.remburstTime == x.burstTime)
        {
            process[p].responseTime = curr - process[p].arrivalTime;
        }

        if (x.remburstTime > TQ)
        {
            curr += TQ;
            cout << curr << "  |";
            x.remburstTime -= TQ;
            q.push(x);
        }
        else
        {
            curr += x.remburstTime;
            cout << curr << "  |";
            x.remburstTime = 0;
            process[p].completionTime = curr;
            process[p].turnAroundTime = process[p].completionTime - process[p].arrivalTime;
            process[p].waitingTime = process[p].turnAroundTime - process[p].burstTime;

            avgTurnAroundTime += process[p].turnAroundTime;
            avgresponseTime += process[p].responseTime;
            avgwaitingTime += process[p].waitingTime;
        }
    }
    cout << endl;
    cout << endl;

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
}
