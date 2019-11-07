//HUD 1686
Problem Description
The French author Georges Perec (1936–1982) once wrote a book, La disparition, without the letter 'e'. He was a member of the Oulipo group.
A quote from the book:
Tout avait Pair normal, mais tout s’affirmait faux. Tout avait Fair normal, d’abord, puis surgissait l’inhumain, l’affolant. 

Il aurait voulu savoir où s’articulait l’association qui l’unissait au roman : stir son tapis, assaillant à tout instant son imagination, 
l’intuition d’un tabou, la vision d’un mal obscur, d’un quoi vacant, d’un non-dit : la vision, l’avision d’un oubli commandant tout, 
où s’abolissait la raison : tout avait l’air normal mais…
Perec would probably have scored high (or rather, low) in the following contest. People are asked to write a perhaps even meaningful 
text on some subject with as few occurrences of a given “word” as possible. Our task is to provide the jury with a program that counts 
these occurrences, in order to obtain a ranking of the competitors. These competitors often write very long texts with nonsense meaning; 
a sequence of 500,000 consecutive 'T's is not unusual. And they never use spaces.
So we want to quickly find out how often a word, i.e., a given string, occurs in a text. More formally: 
given the alphabet {'A', 'B', 'C', …, 'Z'} and two finite strings over that alphabet, a word W and a text T, count the number of 
occurrences of W in T. All the consecutive characters of W must exactly match consecutive characters of T. Occurrences may overlap.

 

Input
The first line of the input file contains a single number: the number of test cases to follow. Each test case has the following format:

One line with the word W, a string over {'A', 'B', 'C', …, 'Z'}, with 1 ≤ |W| ≤ 10,000 (here |W| denotes the length of the string W).
One line with the text T, a string over {'A', 'B', 'C', …, 'Z'}, with |W| ≤ |T| ≤ 1,000,000.
 

Output
For every test case in the input file, the output should contain a single number, on a single line: the number of occurrences of the word 
W in the text T.

 

Sample Input
3
BAPC
BAPC
AZA
AZAZAZA
VERDI
AVERDXIVYERDIAN
 

Sample Output
1
3
0



#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<map>
#define maxn 10005
using namespace std;

int ans;
int t, n, m, prefix[maxn];
char s[maxn * 100], in[maxn];

void setPrefix() {
    int i = 0;
    int len = -1;
    prefix[0] = -1;
    while(i < m) {
        if(len == -1 || in[i] == in[len]) {
            len++;
            i++;
            prefix[i] = len;
        } else {
            len = prefix[len];
        }
    }
}

void KMP() {
    int i = 0;
    int j = 0;
    while(i < n && j < m) {
        if(j == -1 || s[i] == in[j]) {
            i++;
            j++;
        } else {
            j = prefix[j];
        }
        if(j == m) {
            ans++;
            j = prefix[j];
        }
    }
}

int main() {
    //freopen("text.txt", "r", stdin);
    scanf("%d", &t);
    while(t--) {
        ans = 0;
        scanf("%s%s", in, s);
        m = strlen(in);
        n = strlen(s);
        setPrefix();
        KMP();
        printf("%d\n", ans);
    }
    return 0;
}
