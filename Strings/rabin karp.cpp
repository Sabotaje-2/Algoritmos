const int PRIME = 3;
const int MOD = 1e9 + 7;
int minv;// modular inverse
bool compare(char *text, char * pattern, int p, int& plen) {
    foi(i, 0, plen)
        if(pattern[i] != text[i + p]) return false;
    return true;
}
int rabin_karp(char *text, char *pattern) {
    int hp, pp, ht;// hash_pattern , prime_power & hash_text
    hp = ht = 0;
    int plen = strlen(pattern), tlen = strlen(text);
    pp = 1;
    foi(i, 0, plen) {
        hp = (hp + (1ULL * pattern[i] * pp)) % MOD;
        ht = (ht + (1ULL * text[i] * pp)) % MOD;
        pp = (1ULL * pp * PRIME) % MOD;
    }
    pp = (1ULL * pp * minv) % MOD;
    if(hp == ht)
        if(compare(text, pattern, 0, plen))  return 0;
    foi(i, plen, tlen) {
        ht = (ht - text[i - plen] + MOD) % MOD;
        ht = (1ULL * ht * minv) % MOD;
        ht = (ht + ((1ULL * text[i] * pp) % MOD)) % MOD;
        if(ht == hp)
            if(compare(text, pattern, i - plen + 1, plen)) return i - plen + 1;
    }
    return -1;
}
minv = fast_pow(PRIME, MOD - 2); // poner en main
