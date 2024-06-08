#include <bits/stdc++.h>
using namespace std;
int main()
{
   // vector<int>v1 = {1, 2, 3};
   // vector<int>v2 = {1, 2, 3};
   // if(v1 == v2)
   //    cout << "Arrays are equal" << endl;
   // else
   //    cout << "Arrays are unequal" << endl;
   unordered_map<int, int>m;
   m.insert({2, 3});
   // cout << m.erase(4) << endl;
   m.erase(2);
   for(auto it: m){
      cout << it.first << " " << it.second;
   }
}
