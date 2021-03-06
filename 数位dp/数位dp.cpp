ll n, m;
ll a[20], dp[20][2];

ll dfs(int pos, int pre, bool limit){
    if(pos == -1) return 1;
    //if(!limit && dp[pos][state] != -1) return dp[pos][state];
    int up = limit ? a[pos] : 9;
    ll ans = 0;
    for(int i = 0 ; i <= up ; i++){
        if(i == 4) continue;
        else if(pre && i == 2) continue;
        ans += dfs(pos - 1, i == 6 ? 1 : 0, limit && a[pos] == i);
    }
    //if(!limit) dp[pos][state] = ans;
    return ans;
}

ll get(ll x){
    int pos = 0;
    while(x){
        a[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, 0, true);
}

int main(){
    //freopen("Test.txt", "r", stdin);
    while(scanf("%lld %lld", &n, &m), n || m){
        memset(dp, -1, sizeof(dp));
        printf("%lld\n", get(m) - get(n - 1));
    }    
    return 0;
}
