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
        int n;
        in >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            in >> arr[i];
        }
        int key, count = 0, li = -1, ui = -1;
        in >> key;
        int l = 0, u = n, m = (l + u) / 2;
        // while (l < u)
        // {
        //     if (arr[m] == key)
        //     {
        //         count++;
        //         for (int i = m + 1; i < n && arr[i] == key; i++)
        //             count++;
        //         for (int i = m - 1; i >= 0 && arr[i] == key; i--)
        //             count++;
        //         out << key << " - " << count << endl;
        //         goto outer;
        //     }
        //     else if (arr[m] < key)
        //         l = m + 1;
        //     else
        //         u = m;
        //     m = (l + u) / 2;
        // }
        while (l < u)
        {
            if (arr[m] == key)
            {
                if (m == 0 || arr[m - 1] != key)
                {
                    li = m;
                    break;
                }
                else
                    u = m;
            }
            else if (arr[m] < key)
                l = m + 1;
            else
                u = m;
            m = (l + u) / 2;
        }
        if (li >= 0)
        {
            l = 0, u = n, m = (l + u) / 2;
            while (l < u)
            {
                if (arr[m] == key)
                {
                    if (m == n - 1 || arr[m + 1] != key)
                    {
                        ui = m;
                        break;
                    }
                    else
                        l = m + 1;
                }
                else if (arr[m] < key)
                    l = m + 1;
                else
                    u = m;
                m = (l + u) / 2;
            }
            out << key << " - " << (ui - li + 1) << endl;
        }
        else
            out << "Key not present" << endl;
    outer:
        continue;
    }

    return 0;
}