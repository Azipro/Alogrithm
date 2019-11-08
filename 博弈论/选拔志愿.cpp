//HDU 2188
Problem Description
对于四川同胞遭受的灾难，全国人民纷纷伸出援助之手，几乎每个省市都派出了大量的救援人员，这其中包括抢险救灾的武警部队，治疗和防疫的医护人员，
以及进行心理疏导的心理学专家。根据要求，我校也有一个奔赴灾区救灾的名额，由于广大师生报名踊跃，学校不得不进行选拔来决定最后的人选。经过多
轮的考核，形势逐渐明朗，最后的名额将在“林队”和“徐队”之间产生。但是很巧合，2个人的简历几乎一模一样，这让主持选拔的8600很是为难。
无奈，他决定通过捐款来决定两人谁能入选。
选拔规则如下：
1、最初的捐款箱是空的；
2、两人轮流捐款，每次捐款额必须为正整数，并且每人每次捐款最多不超过m元(1<=m<=10)。
3、最先使得总捐款额达到或者超过n元（0<n<10000）的一方为胜者，则其可以亲赴灾区服务。
我们知道，两人都很想入选志愿者名单，并且都是非常聪明的人，假设林队先捐，请你判断谁能入选最后的名单？
 

Input
输入数据首先包含一个正整数C，表示包含C组测试用例，然后是C行数据，每行包含两个正整数n，m，n和m的含义参见上面提到的规则。
 

Output
对于每组测试数据，如果林队能入选，请输出字符串"Grass"， 如果徐队能入选，请输出字符串"Rabbit"，每个实例的输出占一行。
 

Sample Input
2
8 10
11 10
 

Sample Output
Grass
Rabbit



#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 1005
#define mod 10007
using namespace std;
typedef long long ll;

int t, n, m, a, b, ans, which, num[maxn], arr[maxn][20];
bool is, vis[maxn];
char ch, s[maxn], str[maxn];

int main() {
    //freopen("Test.txt", "r", stdin);
    scanf("%d", &t);
    while( t-- ){
        scanf("%d %d", &n, &m);
        if(n % (m + 1) == 0){
            printf("Rabbit\n");
        }else{
            printf("Grass\n");
        }
    }
    return 0;
}
