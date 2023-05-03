#include <bits/stdc++.h>
using namespace std;

class FSFC
{
public:
    string name;
    int currentTime, arrivalTime, burstTime, turnAroundTime, responseTime, waitingTime;
    double avgTurnAroundTime = 0, avgwaitingTime = 0, avgresponseTime = 0;
};

bool cmp1(const FSFC &o1, const FSFC &o2)
{
    if (o1.arrivalTime == o2.arrivalTime)
    {
        return o1.burstTime < o2.burstTime;
    }
    return o1.arrivalTime < o2.arrivalTime;
}

int main()
{
    int n;
    cin >> n;

    vector<FSFC> process(n);
    int curr = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        process[i].name = "P" + to_string(i);
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
        process[i].currentTime = curr + process[i].burstTime;

        if (i < n - 1)
        {
            curr = max(process[i].currentTime, process[i + 1].arrivalTime);
        }

        process[i].turnAroundTime = process[i].currentTime - process[i].arrivalTime;
        process[i].waitingTime = process[i].turnAroundTime - process[i].burstTime;

        process[i].avgTurnAroundTime += process[i].turnAroundTime;
        process[i].avgresponseTime += process[i].responseTime;
        process[i].avgwaitingTime += process[i].waitingTime;
    }

    cout << "    AT\tBT\tCT\tTAT\tWT\tRT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << process[i].name << ":  ";
        cout << process[i].arrivalTime << "\t" << process[i].burstTime << "\t" << process[i].currentTime << "\t" << process[i].turnAroundTime << "\t" << process[i].waitingTime << "\t" << process[i].responseTime;
        cout << endl;
    }

    cout << endl;
    cout << 0 << "  |" << process[0].name << "|  ";
    for (int i = 0; i < n - 1; i++)
    {
        cout << process[i].currentTime << "  |" << process[i + 1].name << "|  ";
    }
    cout << process[n - 1].currentTime;
    cout << endl;
}
