// 1030 完美数列 （25 分）
// 给定一个正整数数列，和正整数 p，设这个数列中的最大值是 M，最小值是 m，如果 M≤mp，则称这个数列是完美数列。

// 现在给定参数 p 和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

// 输入格式：
// 输入第一行给出两个正整数 N 和 p，其中 N（≤10^5）是输入的正整数的个数，p(≤10^9)
// ​​是给定的参数。第二行给出 N 个正整数，每个数不超过 10^9

// 输出格式：
// 在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

// 输入样例：
// 10 8
// 2 3 20 4 5 1 6 7 8 9
// 输出样例：
// 8

//现将数组从小到大排序
//max为最长的完美数列的长度
//i从0到arr_size，j从i+max到arr_size
//固定i，然后循环j，得到满足条件的新的长度就更新max
//之所以j从i+max开始循环是为了减少不必要的循环，
//例如[1, 2, 3, 4, 5, 6, 7, 8, 9]，p为6
//那么第一遍遍历已找到了满足条件的最大数为6，最小数为1，max为6
//那么第二遍遍历我就不需要用3去除2了，因为3/2 = 1.5即使满足小与6，他的长度也才等于2，所以肯定不满足条件
//所以我们直接从7开始寻找可以除去很多不必要的循环

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int numcount;
    double p;
    cin >> numcount >> p;
    int arr[numcount];
    for (int i = 0; i < numcount; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + numcount);
    int max = 0;
    for (int i = 0; i < numcount; i++) {
        for (int j = i + max; j < numcount; j++) {
            if ((arr[j] * 1.0 / arr[i]) <= p && j - i + 1 > max ) {
                max = j - i + 1;
            }
            else {
                break;
            }
        }
    }
    cout << max <<endl;
    return 0;
}