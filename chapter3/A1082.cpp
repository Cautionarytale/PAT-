#include <iostream>
#include <string>
using namespace std;
char unit[5][5] = {" ", "Shi", "Bai", "Qian"};
char unit2[3][5] = {" ", "Wan", "Yi"};
char number[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
    string str;
    cin >> str;
    if (str == "0") {
        printf("ling");
        return 0;
    }
    if (str[0] == '-') {
        printf("Fu ");
        str.erase(0, 1);
    }
    int len = str.length() - 1;
    for (int i = 0; i < str.length(); i++, len--) {
        if (i > 0 && str[i] != '0' && str[i - 1] == '0')printf(" ling");
        if (str[i] != '0') {
            if (i != 0)printf(" ");
            printf("%s", number[str[i] - '0']);
            if (len % 4 != 0)printf(" %s", unit[len % 4]);
        }
        if (len % 4 == 0 && len / 4 != 0)printf(" %s", unit2[len / 4]);
    }
    return 0;
}

