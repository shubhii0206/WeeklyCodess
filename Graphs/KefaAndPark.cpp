#include<bits/stdc++.h>
using namespace std;
const int N = 228228;
vector<int> adjList[N];
void canReach(int s, int parent, int k, int m,  vector<int> &cats, int &ans)
{
    if(k > m)
    return;

    int canProceed = 1;

    for(int i = 0; i < adjList[s].size(); i++)
    {
        if(adjList[s][i] != parent)
        {
            canProceed = 0;
            canReach(adjList[s][i], s, k * cats[adjList[s][i]] + cats[adjList[s][i]], m, cats, ans);

        }
    }

    ans += canProceed;
}

int main()
{
    int n,  m , x, y;
    cin>>n>>m;
    vector<int> cats(n);
    for(auto &x: cats)
       cin>>x;

  

    for(int i = 0; i < n -1; i++)
    {
         cin>>x>>y;
         x--;
         y--;
         adjList[x].push_back(y);
         adjList[y].push_back(x);
     }   
   int ans = 0;
   canReach(0, -1, cats[0], m,  cats, ans);

   cout<<ans<<endl;
   return 0;


}