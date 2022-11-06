#include <bits/stdc++.h>
using namespace std;

int main()
{
   deque<int> dq;

   dq.push_back(1);
   dq.push_front(2);
   dq.push_back(3);
   dq.push_front(4);

   for (auto x : dq)
   {
      cout << x << " ";
   }
   cout << endl;
}
