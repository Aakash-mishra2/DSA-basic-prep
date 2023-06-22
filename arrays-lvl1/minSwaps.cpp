#include <bits/stdc++.h>
using namespace std;
// non intersecting cycles of swaps
int countMinSwaps(vector<int> arr)
{
    int n = arr.size();

    pair<int, int> ap[n];
    for (int i = 0; i < n; i++)
    {
        ap[i].first = arr[i];
        ap[i].second = i;
    }

    // sorting
    sort(ap, ap + n);

    // build the main logic now!
    vector<bool> visited(n, false);
    int swap_count;

    for (int i = 0; i < arr.size(); i++)
    {

        // if element is visited or element is in right position
        int old_position = ap[i].second;
        if (visited[i] == true or old_position == i)
            continue;

        int node = i; // visiting the element(index) for first time
        int cycle = 0;
        while (!visited[node]) // or while(visited[node] == false)
        {
            visited[node] = true;
            int next_node = ap[node].second;
            cycle++;
            node = next_node;
        }
        // adding no. of swaps for each i on basis of its cycle size.
        swap_count += (cycle - 1);
    }
    return swap_count;
}
int main()
{
    vector<int> arr{5, 4, 3, 2, 1};
    cout << countMinSwaps(arr) << endl;
    return 0;
}