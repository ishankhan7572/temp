
#include <iostream>
using namespace std;

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// Driver program to test above functions
int main()
{
    // Ordered set declared with name o_set
    ordered_set s;

    int n,k;
    cin>>n>>k;

    for (int i = 1; i <=n; ++i)
    s.insert(i);

        int ind=0,t=n;

        while(t)
        {
            ind=(ind+k)%t;
            int ele=*(s.find_by_order(ind));
            cout<<ele<<" ";
            s.erase(s.find(ele));
            t--;
        }

}
