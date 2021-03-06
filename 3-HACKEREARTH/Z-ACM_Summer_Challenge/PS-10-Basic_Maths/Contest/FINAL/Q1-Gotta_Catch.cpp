#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long ll;

void b_v_r()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

double polygonArea(double X[], double Y[], int n)
{
    // Initialze area
    double area = 0.0;

    // Calculate value of shoelace formula
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i; // j is previous vertex to i
    }

    // Return absolute value
    return abs(area / 2.0);
}

struct Point
{
    double x, y;
};
bool compare(Point a, Point b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
//Returns positive value if B lies to the left of OA, negative if B lies to the right of OA, 0 if collinear
double cross(const Point &O, const Point &A, const Point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
//Returns a list of points on the convex hull
vector<Point> convex_hull(vector<Point> P)
{
    int n = P.size(), k = 0;
    vector<Point> H(2 * n);
    sort(P.begin(), P.end(), compare);
    // Build lower hull
    for (int i = 0; i < n; ++i)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }

    // Build upper hull
    //i starts from n-2 because n-1 is the point which both hulls will have in common
    //t=k+1 so that the upper hull has atleast two points to begin with
    for (int i = n - 2, t = k + 1; i >= 0; i--)
    {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }
    //the last point of upper hull is same with the fist point of the lower hull
    H.resize(k - 1);
    return H;
}

int main()
{
    b_v_r();
    int n;
    cin >> n;
    vector<Point> points(n);
    vector<Point> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }
    if (n < 3)
    {
        cout << "-1" << endl;
    }
    else
    {
        ans = convex_hull(points);
        int size = ans.size();
        if (size < 3)
        {
            cout << "-1" << endl;
        }
        else
        {
            double X[size];
            double Y[size];
            for (unsigned int i = 0; i < ans.size(); i++)
            {
                X[i] = ans[i].x;
                Y[i] = ans[i].y;
            }
            // for(int i=0;i<ans.size();i++)
            // {
            //     cout << X[i] << " " << Y[i] << endl;
            // }
            int k = sizeof(X) / sizeof(X[0]);
            cout << (ll)(polygonArea(X, Y, k) * (2.0)) << endl;
        }
    }

    return 0;
}