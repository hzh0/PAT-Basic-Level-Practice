// 1028 人口普查 （20 分）
// 某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

// 这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过 200 岁的老人，而今天是 2014 年 9 月 6 日，所以超过 200 岁的生日和未出生的生日都是不合理的，应该被过滤掉。

// 输入格式：
// 输入在第一行给出正整数 N，取值在(0,10
// ​5
// ​​ ]；随后 N 行，每行给出 1 个人的姓名（由不超过 5 个英文字母组成的字符串）、以及按 yyyy/mm/dd（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。

// 输出格式：
// 在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

// 输入样例：
// 5
// John 2001/05/12
// Tom 1814/09/06
// Ann 2121/01/30
// James 1814/09/05
// Steve 1967/11/20
// 输出样例：
// 3 Tom John

//解题思路很简单，就是用两个变量保存最大的年龄和最小的年龄
//每输入一个人的信息，若生日合理，则和当前的最大最小年龄比较并更新
//这道题的生日都是合理的，所以不必考虑日期不和法的情况
//需要注意的是可能所有人的生日都不合理，就不必输入年龄最大和最小的两个人的名字了

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int BIGGER = 0;
int SMALLER = 1;
int EQUAL = 2;


struct date {
    int year;
    int month;
    int day;

    date(int num1, int num2, int num3) {
        year = num1;
        month = num2;
        day = num3;
    }
    
    void set(date date1) {
    	year = date1.year;
    	month = date1.month;
    	day = date1.day;
    } 
};

bool date_is_legal(int year, int month, int day);
int judge_more_or_less(date date1, date date2);

int main(void) {
    int totalpeople, legalnum = 0;
    string name, max = "", min = "";
    int year, month, day;
    int lastyear = 0, lastmonth = 0, lastday = 0;
    date maxdate(9999, 9999, 9999), mindate(0, 0, 0);
    cin >> totalpeople;
    for (int i = 0; i < totalpeople; i++) {
        cin >> name;
        scanf("%d/%d/%d", &year, &month, &day);
        if (date_is_legal(year, month, day)) {
            legalnum++;
        }
        else {
        	continue;
        }
        date nowdate(year, month, day);
        if (judge_more_or_less(maxdate, nowdate) == SMALLER) {
            max = name;
            maxdate.set(nowdate);
        }
        if (judge_more_or_less(mindate, nowdate) == BIGGER) {
            min = name;
            mindate.set(nowdate);
        }
        cout << max << " " << min << endl;
    }
    cout << legalnum << " " << max << " " << min << endl;
}

bool date_is_legal(int year, int month, int day) {
    if (year > 2014 || year < 1814) return false;
	else if (month < 1 || month > 12) return false;
	else if (day < 1 || day > 31) return false;
	if (year == 1814 && ((month == 9 && day < 6) || month < 9)) return false;
	if (year == 2014 && ((month == 9 && day > 6) || month > 9)) return false;
    return true;
}

int judge_more_or_less(date date1, date date2) {
    if (date1.year > date2.year) return SMALLER;
    else if (date1.year == date2.year) {
        if (date1.month > date2.month) return SMALLER;
        else if (date1.month == date2.month) {
            if (date1.day > date2.day) return SMALLER;
            else if (date1.day == date2.day) return EQUAL;
        }
    }
    return BIGGER;
}

		