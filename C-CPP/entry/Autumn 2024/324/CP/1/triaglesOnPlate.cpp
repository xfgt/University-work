//
// Created by MRSLAVE on 29-Nov-24.
//

#include <iostream>

using namespace std;

// A point in 2D
struct Point
{
    int x, y;
};

// Returns determinant value of three points in 2D
bool determinantValue(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if((x1*(y2 - y3) - y1*(x2 - x3) + 1*(x2*y3 - y2*x3)) != 0)
        return true;
    else
        return false;
}

// Returns the number of possible triangles
//from given array of points in 2D.
int countPoints(Point arr[], int n)
{
    int result = 0;  // Initialize result

    // Consider all triplets of points given in inputs
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            for (int k=j+1; k<n; k++)
            {
                if (determinantValue(arr[i].x, arr[i].y, arr[j].x, arr[j].y, arr[k].x, arr[k].y))
                    result++; // Increment the result when determinant of a triplet is not 0.
            }
        }
    }
    return result;
}

int main()
{
    //Point arr[] = {{0, 0}, {1, 1}, {2, 0}, {2, 2}};
    //Point arr[4];
    int n;
    while(cin>>n){
        //cin>>n;
        Point arr[n];
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i].x>>arr[i].y;
        }
        //cin>>arr[0].x>>arr[0].y;
        //int n = sizeof(arr)/sizeof(arr[0]);
        cout << countPoints(arr, n)<<endl;
    }
    return 0;
}




