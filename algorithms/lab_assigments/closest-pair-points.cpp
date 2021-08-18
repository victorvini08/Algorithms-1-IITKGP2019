#include <bits/stdc++.h>
using namespace std;
#define cp ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int  
#define vint vector<int>
#define vllint vector<ll>
#define pair_int pair<int , int>
#define pair_ll pair<ll , ll>
#define vector_of_pair_int vector<pair_int>
# define vector_of_pair_ll vector<pair_ll>
#define pb push_back 
#define test_case int t; cin>>t; while(t--)
#define umap unordered_map <ll,ll> 
#define map map<int,int>
#define inf 1000000000

struct point
{
    int x;
    int y;
};

bool compare_points(point a,point b)
{
    if(a.x<=b.x)
        return 1;
    else 
        return 0;
}
bool comparey(point a,point b)
{
    if(a.y<=b.y)
        return 1;
    else 
        return 0;
}

float min(float x, float y)  
{  
    return (x < y)? x : y;  
}  
  

float dist(point p1, point p2)  
{  
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +  
                (p1.y - p2.y)*(p1.y - p2.y)  
            );  
}  
float bruteForce(point P[], int n)  
{  
    float min = inf;  
    for (int i = 0; i < n; ++i)  
        for (int j = i+1; j < n; ++j)  
            if (dist(P[i], P[j]) < min)  
                min = dist(P[i], P[j]);  
    return min;  
}
float stripClosest(point strip[], int size, float d)  
{  
    float min = d; // Initialize the minimum distance as d  
  
    sort(strip,strip+size,comparey);  
  
    // Pick all points one by one and try the next points till the difference  
    // between y coordinates is smaller than d.  
    // This is a proven fact that this loop runs at most 6 times  
    for (int i = 0; i < size; ++i)  
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)  
            if (dist(strip[i],strip[j]) < min)  
                min = dist(strip[i], strip[j]);  
  
    return min;  
}  
 

float  closest_pair(point points[],int n)
 {
       if(n<=3)
       {
         return bruteForce(points, n);  
       }
       else

       {
         int mid= n/2;

         float dl = closest_pair(points,mid);
         float dr= closest_pair(points+mid,n-mid);

         float d= min(dl,dr);

         point arr[n];
         int count=0;
         for(int i=0;i<n;i++)
         {
            if(dist(points[i],points[mid])<=d)
               {
                arr[count]= points[i];
                count++;
               }
         }


    return min(d, stripClosest(arr, count, d));  

       }
 }
int main()
{
	/* code */
    int n;
    cin>>n;
    
    point points[n];

    for (int i = 0; i < n; ++i)
    {
        /* code */
        int temp;
        cin>>temp;
        points[i].x= temp;
    }

    for (int i = 0; i < n; ++i)
    {
        /* code */
        int temp;
        cin>>temp;
        points[i].y= temp;
    }

    sort(points,points+n,compare_points);

    cout<<closest_pair(points,n);


    


	return 0;
}