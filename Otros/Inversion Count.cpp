#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<
ii,
null_type,
less<ii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int inversions(vector<int> arr) {
    int ans = 0, t = 0;
    ordered_set s;
    for(auto x : arr) s.insert(ii(x, t++));
    foi(i,0,arr.size()) {
        s.erase(s.lower_bound(ii(arr[i], 0)));
        ans += s.order_of_key(ii(arr[i], 0)); // Cuenta las inversiones en la i-esima posicion
    }
    return ans;
}
