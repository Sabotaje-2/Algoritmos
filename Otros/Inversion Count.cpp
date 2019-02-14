#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ordered_set = tree<ii,
null_type, less<ii>,
rb_tree_tag, tree_order_statistics_node_update>;

ll inversions(int arr[], int sz) {
    ll ans = 0, t = 0;
    ordered_set s;
    for(int i = sz - 1; i >= 0; --i) {
        ans += (1LL * s.order_of_key(ii(arr[i], 0))); // Cuenta las inversiones en la i-esima posicion
        s.insert(ii(arr[i], t++));
    }
    return ans;
}
