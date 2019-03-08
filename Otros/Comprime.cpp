namespace COMPRESSION {
    int v[MAXN]; /// const int MAXN = Maximo numero de elementos en arr
    /// Comprime todos los numeros comenzando desde BEG en O(nlgn)
    void compress(int arr[], int N, const int BEG = 0) {
        copy(arr, arr + N, v); sort(v, v + N);
        int sz = unique(v, v + N) - v;
        foi(i,0,N) {
            arr[i] = BEG + lower_bound(v, v + sz, arr[i]) - v;
        }
    }}
