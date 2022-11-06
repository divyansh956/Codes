#include <bits/stdc++.h>
using namespace std;

class Queqe
{
   stack<int> s1;
   stack<int> s2;

public:
   void push(int x)
   {
      s1.push(x);
   }

   int pop()
   {
      if (s1.empty() && s2.empty())
      {
         cout << "Queue is Empty" << endl;
         return -1;
      }

      if (s2.empty())
      {
         while (!s1.empty())
         {
            s2.push(s1.top());
            s1.pop();
         }
      }

      int x = s2.top();
      s2.pop();
      return x;
   }

   int front()
   {
      if (s1.empty() && s2.empty())
      {
         cout << "Queue is Empty" << endl;
         return -1;
      }

      if (s2.empty())
      {
         while (!s1.empty())
         {
            s2.push(s1.top());
            s1.pop();
         }
      }

      int x = s2.top();
      return x;
   }

   bool empty()
   {
      if (s1.empty() && s2.empty())
      {
         return true;
      }
      return false;
   }
};

int main()
{
   Queqe q;

   q.push(20);
   q.push(30);
   q.push(40);
   q.push(50);

   q.pop();
   q.pop();

   cout << q.front() << endl;
   q.pop();
   q.pop();
   q.pop();
   q.pop();
   cout << q.empty() << endl;
}
