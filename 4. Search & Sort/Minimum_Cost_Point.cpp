/*
Given a set of coordinates points of the form [p, q] and a line L of the form ax + by + c = 0. The task is to find a point on a given line for which the sum of distances from a given set of coordinates is minimum. 

Example 1:
Input: points = [[1, 1], [2, 2], [3, 3]], a = 1, b = -1, c = -2
Output: 2
Explanation: The line is 1x - y - 2 = 0. The sum of distances from the points to the line is 2 + sqrt(2) + 2 = 6.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 10^5
-10^3 <= point[i] <= 10^3


Approach 1:
We can solve this problem mathematically using the concept of differential calculus. 
Let the moving point be (x, y) as we know that this lies on line so there is a relation between x and y. It is given by the equation of line ax + by + c = 0.
So, y = (-ax - c)/b

Now, we have to find the value of x and y for which the sum of distances is minimum.
Let the sum of distances be S(x, y) = ∑(√((x - xi)^2 + (y - yi)^2)) for all points p[i] in the given set of points.
Now, we have to find the value of x and y for which S(x, y) is minimum.
Here we replace the variable y in the form of x such that the whole equation becomes a function of x only.

S(x) = ∑(√((x - xi)^2 + ((-ax - c)/b - yi)^2)) for all points p[i] in the given set of points.
Now, we have to find the value of x for which S(x) is minimum.

We know that the derivative of a function is the slope of the tangent line to the curve at any point on the curve. So, we will find the derivative of S(x) and equate it to 0 to find the value of x for which S(x) is minimum.

The square root term will be minimum when the whole term is minimum. So, we will take the derivative of the whole term and equate it to 0 to find the value of x for which the whole term is minimum.

dS(x)/dx = ∑(2*(x - xi)*1 + 2*((-ax - c)/b - yi)*(-a/b)) for all points p[i] in the given set of points.

Now we put it to 0 and solve for x.
x = (∑(a*yi/b - xi + a*c/b^2))/N(a^2/b^2 + 1)


Approach 2:
We can also solve this problem using the concept of terenary search.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    double findOptimumCost1(tuple<int,int,int>l, vector<pair<int,int>>p, int n){
	    //Write your code here
	    double sum = 0;
	    double a = get<0>(l);
	    double b = get<1>(l);
	    double c = get<2>(l);
		for(int i=0; i<p.size(); i++){
			double xi = p[i].first;
			double yi = p[i].second;
	        sum += (a*yi/b - xi + a*c/b*b);
	    }
		double x = -sum/(n*(a*a/b*b + 1));
		double y = (-a*x - c)/b;
	    double ans = 0;
		for(int i=0; i<p.size(); i++){
			double xi = p[i].first;
			double yi = p[i].second;
	        ans += sqrt((x - xi)*(x - xi) + (y - yi)*(y - yi));
	    }
	    return ans;
    }
	
};

