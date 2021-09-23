#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int t;
    in >> t;
    while (t--)
    {
        int n,x,count;
        in >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            in >> arr[i];
        }
        in >> x;
        count = 0;
        int l=0,u=n,m = (l+u)/2;
        while (l<u)
        {
            count++;
            if (arr[m] == x)
            {
                out << "Present " << count << endl;
                goto outer;
            }
            else if (arr[m]<x)
                l = m+1;
            else
                u = m;
            m = (l+u)/2;
        }
        out << "Not Present " << count << endl;
        outer: continue;
    }
    return 0;
}