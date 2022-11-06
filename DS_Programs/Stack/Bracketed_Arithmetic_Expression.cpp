#include <bits/stdc++.h>
using namespace std;

bool validParenthesis(string ss)
{
   stack<char> s[100];
   int i = 0;
   while (ss[i] != '\0')
   {
      if (ss[i] == '[' || ss[i] == '{' || ss[i] == '(')
      {
         s->push(ss[i]);
      }
      else
      {
         if (s->empty() || (ss[i] == ']')
         {
            if (s->top() != '[')
            {
               return false;
            }
            else
            {
               s->pop();
            }
         }
         else if (s->empty() || ss[i] == '}')
         {
            if (s->top() != '{')
            {
               return false;
            }
            else
            {
               s->pop();
            }
         }
         if (ss[i] == ')')
         {
            if (s->empty() || s->top() != '(')
            {
               return false;
            }
            else
            {
               s->pop();
            }
         }
      }
      i++;
   }
   return true;
}

int main()
{
   string ss;
   cin >> ss;

   cout << validParenthesis(ss) << endl;
}
