// HDU 1703

Description
The police office in Tadu City decides to say ends to the chaos, as launch actions to root up the TWO gangs in the city, Gang Dragon
and Gang Snake. However, the police first needs to identify which gang a criminal belongs to. The present question is, given two 
criminals; do they belong to a same clan? You must give your judgment based on incomplete information. (Since the gangsters are always
acting secretly.)
Assume N (N <= 10^5) criminals are currently in Tadu City, numbered from 1 to N. And of course, at least one of them belongs to Gang
Dragon, and the same for Gang Snake. You will be given M (M <= 10^5) messages in sequence, which are in the following two kinds:

1. D [a] [b]
where [a] and [b] are the numbers of two criminals, and they belong to different gangs.

2. A [a] [b]
where [a] and [b] are the numbers of two criminals. This requires you to decide whether a and b belong to a same gang.
Input

The first line of the input contains a single integer T (1 <= T <= 20), the number of test cases. Then T cases follow. Each test case
begins with a line with two integers N and M, followed by M lines each containing one message as described above.
Output

For each message "A [a] [b]" in each case, your program should give the judgment based on the information got before. The answers might
be one of "In the same gang.", "In different gangs." and "Not sure yet."

Sample Input
1
5 5
A 1 2
D 1 2
A 1 2
D 2 4
A 1 4

Sample Output
Not sure yet.
In different gangs.
In the same gang.

#include <iostream>
#include<cstdio>
#define maxn 100005*2
using namespace std;

int gather[maxn];
int n, m;

int Find(int x) {
    if(gather[x] == x) return x;
    return gather[x] = Find(gather[x]);
}

void Link(int x, int y) {
    int u = Find(x);
    int v = Find(y);
    if(u == v) return;
    gather[u] = v;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        for(int i = 1; i <= 2 * n; i++) {
            gather[i] = i;
        }
        while(m--) {
            char what[3];
            int a, b;
            scanf("%s %d %d",&what,&a,&b);
            if(what[0] == 'A') {
                if(Find(a) == Find(b)) cout << "In the same gang." << endl;
                else if(Find(a) == Find(b + n) && Find(a + n) == Find(b)) cout << "In different gangs." << endl;
                else cout << "Not sure yet." << endl;
            } else if(what[0] == 'D') {
                Link(a, b + n);
                Link(a + n, b);
            }
        }
    }
    return 0;
}
