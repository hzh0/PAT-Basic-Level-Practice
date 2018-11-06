//注意judge函数的第一个参数，其表示了甲乙丙的能力值
//但需要注意当传入参数为丙的能力值时
//丙可能是浮点数，多以参数类型为double，而不能是int
//例如，丙的能力值为4.5，而自己的能力值为4，则int(4.5) = 4，会有一个测试无法通过

#include <cstdio>
#include <cmath>

using namespace std;

void judge(double num1, int num2) {
    if (num1 > num2) {
        printf("Cong");
    }
    else if (num1 == num2) {
        printf("Ping");
    }
    else {
        printf("Gai");
    }
}

int main(void)
{
    int my_level, x, y;
    scanf("%d %d %d", &my_level, &x, &y);
    for (int i = 99; i >= 10; i--) {
        int level_yi = (i % 10) * 10 + i / 10;
        if (abs(i - level_yi) / (level_yi*1.0) == (x / (y*1.0))) {
            printf("%d ", i);
            judge(i, my_level);
            printf(" ");
            judge(level_yi, my_level);
            printf(" ");
            judge((level_yi*1.0 / y), my_level);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
