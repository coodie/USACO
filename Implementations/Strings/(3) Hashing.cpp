typedef pair<ll, ll> pll;

template<class T> pair<T,T> operator+(const pair<T,T>& l, const pair<T,T>& r) {
    return {(l.f+r.f)%MOD,(l.s+r.s)%MOD};
}
 
template<class T> pair<T,T> operator-(const pair<T,T>& l, const pair<T,T>& r) {
    return {(l.f-r.f+MOD)%MOD,(l.s-r.s+MOD)%MOD};
}
 
template<class T> pair<T,T> operator*(const pair<T,T>& l, const T& r) {
    return {l.f*r%MOD,l.s*r%MOD};
}

template<class T> pair<T,T> operator*(const pair<T,T>& l, const pair<T,T>& r) {
    return {l.f*r.f%MOD,l.s*r.s%MOD};
}
    
template<int SZ> struct hsh {
    string S; 
    pll po[SZ], ipo[SZ], cum[SZ];
    pll base = mp(948392576,573928192);
    
    ll modpow(ll b, ll p) {
        return !p?1:modpow(b*b%MOD,p/2)*(p&1?b:1)%MOD;
    }
    
    ll inv(ll x) {
        return modpow(x,MOD-2);
    }
    
    void gen(string _S) {
        S = _S;
        po[0] = ipo[0] = {1,1};
        FOR(i,1,SZ) {
            po[i] = po[i-1]*base;
            ipo[i] = {inv(po[i].f),inv(po[i].s)};
        }
        F0R(i,sz(S)) cum[i+1] = cum[i]+po[i]*(ll)(S[i]-'a'+1);
    }
    
    pll get(int l, int r) {
        return ipo[l]*(cum[r+1]-cum[l]);
    }
};

hsh<200000> h;

int main() {
    string _S = "abacaba";
    h.gen(_S);
    F0R(i,_S.length()) FOR(j,i,_S.length()) cout << i << " " << j << " " << h.get(i,j).f << " " << h.get(i,j).s << "\n";
}