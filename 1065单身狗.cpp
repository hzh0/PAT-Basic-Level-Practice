// 1065 单身狗 （25 分）
// “单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。

// 输入格式：
// 输入第一行给出一个正整数 N（≤ 50 000），是已知夫妻/伴侣的对数；随后 N 行，每行给出一对夫妻/伴侣——为方便起见，每人对应一个 ID 号，为 5 位数字（从 00000 到 99999），ID 间以空格分隔；之后给出一个正整数 M（≤ 10 000），为参加派对的总人数；随后一行给出这 M 位客人的 ID，以空格分隔。题目保证无人重婚或脚踩两条船。

// 输出格式：
// 首先第一行输出落单客人的总人数；随后第二行按 ID 递增顺序列出落单的客人。ID 间用 1 个空格分隔，行的首尾不得有多余空格。

// 输入样例：
// 3
// 11111 22222
// 33333 44444
// 55555 66666
// 7
// 55555 44444 10000 88888 22222 11111 23333
// 输出样例：
// 5
// 10000 23333 44444 55555 88888


//我的思路是先创建一个hashmap<string, string>(partner)把所有的情侣保存下来
//在输入一个来客的ID时，去partner表中查找，如果该用户没有伴侣，则其为单生狗
//再创将一个hashmap<string, map>(people)来保存那些有情侣但不知道伴侣是否来了的来客
//面对一个来客，在people表中寻找该来客的伴侣是否已存在people中
//若不存在：则将该来客以<id, 0>存储在people表中，0意味着有伴侣但伴侣没来
//若存在：则将该来客以<id, 1>存储在people表中，并将其伴侣的value也置为1, 1意味着一对伴侣都来了
//之后遍历people表，value为0的都为单身狗

//注意测试点1，当单身狗个数为0时，注意输入

#include <iostream> 
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    unordered_map<string, string> partner;
    unordered_map<string, int> people;
    vector<string> singledog;
    int partnernumber;
    int peoplenumber;
    cin >> partnernumber;
    string man, woman;
    for (int i = 0; i < partnernumber; i++) {
        cin >> man >> woman;
        partner.insert(make_pair(man, woman));
        partner.insert(make_pair(woman, man));
    }
    int peoplenum;
    cin >> peoplenum;
    int total = 0;
    for (int i = 0; i < peoplenum; i++) {
        cin >> man;
        auto itr = partner.find(man);
        if (itr == partner.end()) {
            singledog.push_back(man);
            total++;
        }
        else {
            auto itr2 = people.find(itr->second);
            if (itr2 == people.end()) {
                people.insert(make_pair(man, 0));
            }
            else {
                itr2->second = 1;
                people.insert(make_pair(man, 1));
            }
        }
    }
    for (auto itr = people.begin(); itr != people.end(); itr++) {
        if (itr->second == 0) {
            singledog.push_back(itr->first);
            total++;
        }
    }
    
    cout << total << endl;
    if (total == 0) {
        return 0;
    }
    sort(singledog.begin(), singledog.end());

    for (int i = 0; i < singledog.size() - 1; i++) {
        cout << singledog[i] << " ";
    }
    cout << singledog[singledog.size() - 1] << endl;
    return 0;
}