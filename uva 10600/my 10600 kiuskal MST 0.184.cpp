/*
*  Method     : Kruskal Algorithm
*  Complexity : O(n^2 log n)
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 200;
const int OO  = 10000000;

struct edge
{ 
	int u, v, w, id;
	bool valid;		//To remove and add edges
};

int cost, built;
bool build_MST1;
vector<edge> e;		//Contain Original edges
vector<edge> mst1;	//Contain First MST


/* Data Structures and Algorithms for Disjoint Sets */
int rank[MAX], parent[MAX];

void make_set(int x)
{
	parent[x] = x;
	rank[x] = 0;
}

int find_set(int x)
{
	while(x != parent[x])
		x = parent[x];
	return x;
}

void link(int x, int y)
{
	if(rank[x] > rank[y])
		parent[y] = x;
	else
    {
		parent[x] = y;
		if(rank[x]==rank[y]) 
			rank[y]++;
    }
}

int same_set (int x, int y)
{
	return find_set(x) == find_set(y);
}

void union_sets (edge e)
{
	if (!same_set(e.u, e.v) )
	{
		if(!build_MST1)		//Enter only to build MST1
			mst1.push_back(e);
		
		built++;
		
		cost += e.w;
		link( find_set(e.u), find_set(e.v) );
	}
}

bool edgecmp(const edge& a, const edge& b)
{
	return (a.w < b.w);
}

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

int find(edge path)
{
	int i;
	for(i=0;i<e.size();i++)
		if(path.u == e[i].u && path.v == e[i].v)
			return i;
	return -1;
}

int main()
{
	int i, j, k, n, links, cases;
	int mst1_w, mst2_w;
	edge path;
	
	cin>>cases;
	for(k=1;k<=cases;k++)
	{
		cin>>n>>links;

		mst1.clear();		e.clear();
		cost = built = 0;
		build_MST1 = false;
	
		for (i=0; i<links; i++)
		{
			cin>>path.u >> path.v >>path.w;	
			path.u--;		path.v--;
			path.valid = true;

			if(path.u > path.v )
				swap(path.u, path.v);

			e.push_back(path);			
		}

		sort(e.begin(), e.end() , edgecmp);
		
		/* Generate Kurskal forest */
		for (i=0; i<n; i++)
			make_set(i);
		
		for (i=0; i<e.size(); i++)
		{
			if(built >= n)				break;

			e[i].id = i;		//To make it easy for searching
			union_sets(e[i]);	//Union its u, v
		}
		
		build_MST1 = true;	//We finish building it

		if(built == n-1)	//Graph Not Connected
			mst1_w = cost;
		else
			mst1_w = OO;
		mst2_w = OO;

		//Removeing each edge of MST1 once and running MST again
		if(mst1_w != OO)
			for(j=0;  j<mst1.size(); j++)
			{
				//This better than searching
				e[ mst1[j].id ].valid = false;
				built = cost = 0;
				
				for (i=0; i<n; i++)
					make_set(i);
				
				for (i=0; i<e.size(); i++)
				{
					if(built >= n)	break;	//No need for more edges
					if(e[i].valid)
						union_sets(e[i]);
				}
				
				//Setting the edge again in the set
				e[ mst1[j].id ].valid = true;	//Undo
				
				if(built != n-1) //The minimum to connect 10 nodes= 9 edges
					continue;	//Spanning tree with missing nodes
				
				if(mst2_w > cost)
					mst2_w = cost;
			}
			cout<<mst1_w<<" "<<mst2_w<<"\n";
	}
	return 0;
}