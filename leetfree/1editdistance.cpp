//https://www.geeksforgeeks.org/check-if-two-given-strings-are-at-edit-distance-one/


#include<bits/stdc++.h>
using namespace std;


 bool is_Subsequence(string a, string b)
 {
     int n = a.size(), m = b.size();

     for(int i = 0;i < n; i++)
     {
         if(a[i] == b[j])
         j++;
     }
     return j == m;
 }


int  main()
{
    string s1, s2;
    cin>>s1>>s2;

    int n = s1.size(), m = s2.size();


     if(s1.compare(s2) == 0)
    { cout<<true;
     return 0;}

     if(is_Subsequence(s1, s2) || is_Subsequence(s2, s1))
     {cout<<true;
     return 0;}

    if(abs(n - m) >= 2)
    {cout<<false;
    return 0;}
    int cnt =0;

   for(int i = 0; i < n; i++)
   {
      if(s1[i] != s2[i])
         cnt++;
   }

   if(cnt <= 1)
   cout<<true;
   else
   cout<<false;
   return 0;


}
