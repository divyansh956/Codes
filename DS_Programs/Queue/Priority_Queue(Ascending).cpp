#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin >> n;

   int nums[n];
   priority_queue<int> pq;

   for (int i = 0; i < n; i++)
   {
      cin >> nums[i];
      pq.push(nums[i]);
   }

   while(!pq.empty())
   {
      cout << pq.top() << " ";
      pq.pop();
   }
   cout << endl;
}
