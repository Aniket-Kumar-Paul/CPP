#include <iostream>
#include <algorithm>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b)
{
    // ratio = value / weight
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return r1 > r2;
}

void pairsort(int a[], int b[], int n)
{
    pair<int, int> pairs[n];

    for (int i = 0; i < n; i++)
    {
        pairs[i].first = a[i];
        pairs[i].second = b[i];
    }

    // Sorting the pair array.
    sort(pairs, pairs + n, comparator);

    // Modify original arrays
    for (int i = 0; i < n; i++)
    {
        a[i] = pairs[i].first;
        b[i] = pairs[i].second;
    }
}

double fractionalKnapsack(int W, int val[], int wt[], int n)
{
    // sort based on v/w ratio
    pairsort(val, wt, n);

    int currentWt = 0, remainingWt;
    double profit = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (currentWt + wt[i] <= W)
        {
            currentWt += wt[i];
            profit += val[i];
        }
        else
        {
            remainingWt = W - currentWt;
            profit += ((double)remainingWt / wt[i]) * val[i];
            break;
        }
    }

    return profit;
}

int main()
{
    int W, n;
    cin >> W >> n;
    int value[n], weight[n];
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << fractionalKnapsack(W, value, weight, n);
    return 0;
}