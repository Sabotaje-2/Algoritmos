struct st {
    vector < vector < int > > table;
    st(vector < int >& arr) {
        int columns = 1 + floor(log2(arr.size()));// C++11
        table.assign(arr.size(), vector < int > (columns , - 2));
        foi(i,0,table.size())  table[i][0] = arr[i];
        foi(j,1,columns)
            for(int i = 0 ; i + (1 << j) <= (int)table.size() ; ++i)
              table[i][j] = max(table[i][j-1], table[i + (1 << (j - 1))][j-1]);
    }
    int query(int i, int j) {
        int len = j - i + 1;
        int k = floor(log2(len));
        int max1 = table[i][k], max2 = table[i + len - (1 << k)][k];
        return max(max1, max2);
    }};
