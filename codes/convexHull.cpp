#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct Point
{
    int x, y;
};

// Find orientation of 3 points
// 0 = Collinear
// 1 = Clockwise
// 2 = Counter-clockwise
int orientation(Point a, Point b, Point c)
{

    int value = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);

    if (value == 0)
        return 0;

    return (value > 0) ? 1 : 2;
}

// Distance between two points
int distanceSquared(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) +
           (a.y - b.y) * (a.y - b.y);
}

// Global reference point
Point p0;

// Comparator for sorting points by polar angle
bool compare(Point a, Point b)
{

    int o = orientation(p0, a, b);

    if (o == 0)
        return distanceSquared(p0, a) <
               distanceSquared(p0, b);

    return o == 2;
}

vector<Point> convexHull(vector<Point> points)
{

    int n = points.size();

    if (n < 3)
        return points;

    // Step 1: Find the lowest point
    int lowest = 0;

    for (int i = 1; i < n; i++)
    {
        if (points[i].y < points[lowest].y ||
            (points[i].y == points[lowest].y &&
             points[i].x < points[lowest].x))
        {

            lowest = i;
        }
    }

    // Put lowest point at index 0
    swap(points[0], points[lowest]);

    p0 = points[0];

    // Step 2: Sort points by polar angle
    sort(points.begin() + 1, points.end(), compare);

    // Step 3: Create stack
    stack<Point> st;

    st.push(points[0]);
    st.push(points[1]);
    st.push(points[2]);

    // Step 4: Process remaining points
    for (int i = 3; i < n; i++)
    {

        while (st.size() >= 2)
        {

            Point top = st.top();
            st.pop();

            Point nextTop = st.top();

            // If clockwise, remove the top point
            if (orientation(nextTop, top, points[i]) != 2)
            {
                continue;
            }

            st.push(top);
            break;
        }

        st.push(points[i]);
    }

    // Convert stack to vector
    vector<Point> hull;

    while (!st.empty())
    {
        hull.push_back(st.top());
        st.pop();
    }

    reverse(hull.begin(), hull.end());

    return hull;
}

int main()
{

    vector<Point> points = {
        {0, 3},
        {2, 2},
        {1, 1},
        {2, 1},
        {3, 0},
        {0, 0},
        {3, 3}};

    vector<Point> hull = convexHull(points);

    cout << "Convex Hull:\n";

    for (Point p : hull)
    {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}