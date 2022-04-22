// TO DO: Fix or remove
struct aho_corasick {
    vector<int> f;
    vector<vector<int>> g, output;
    int unused;
    const char INI = 'a';
    const int ALPH = 26;
    aho_corasick(const vector<string>& words, int states = 1) {
        foi(i,0,words.size()) states += words[i].size();
        unused = 0;
        g.assign(states, vector<int>(ALPH, -1));
        f.resize(states);
        output.resize(states);
        foi(i,0,words.size()) add(words[i], i);
        build();
    }
    void add(const string& s, int id, int curr = 0) {
        for(const char x: s) {
            if(g[curr][x - INI] == -1)
                g[curr][x - INI] = ++unused;
            curr = g[curr][x - INI];
        }
        output[curr].push_back(id);
    }
    void join(int u, int v) {
        foi(i,0,output[v].size())
            output[u].push_back(output[v][i]);
    }
    void failure(int s, int p, int c) {
        p = f[p];
        while(g[p][c] == -1) p = f[p];
        f[s] = g[p][c];
        join(s, f[s]);
    }
    void build() {
        int curr;
        queue<int> q;
        foi(i,0,ALPH)
            if(~g[0][i]) q.push(g[0][i]),f[g[0][i]] = 0;
            else g[0][i] = 0;
        while(q.size()) {
            curr = q.front();q.pop();
            foi(i,0,ALPH)
                if(~g[curr][i]) {
                    failure(g[curr][i], curr, i);
                    q.push(g[curr][i]);
                }
        }
    }
    int next_state(int s, int c) {
        while(g[s][c] == -1)
            s = f[s];
        return g[s][c];
    }
    void match(const string& s, const vector<string>& words, int curr = 0) {
        foi(i,0,s.size()) {
            curr = next_state(curr, s[i] - INI);
            foi(j,0,output[curr].size())
                cout << words[output[curr][j]] << "[" << i - words[output[curr][j]].size() + 1 << ',' << i << "]\n";
        }
    }};
