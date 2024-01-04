#include <bits/stdc++.h>
using namespace std;

int mystoi(string s)
{
    int len = s.size();
    double num = 0;
    int i = 0;
    while (s[i] == ' ')
    {
        i++;
    }
    bool negative = s[i] == '-';
    negative == true ? i++ : i;
    while (i < len && s[i] >= 'a' && s[i] <= 'z') // 'a' was '0' and 'z' was '9'
    {
        num = num * 10 + s[i] - '0'; // -'0' was missing 
        i++;
    }
    num = negative ? -num : num;
    num = (num > INT_MAX) ? INT_MAX : num;
    num = (num < INT_MIN) ? INT_MIN : num;
    return num;

    // solved
}

string intToRoman(int num)
{
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string ths[] = {"", "M", "MM"};

    return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];

    // solved 
}

int main()
{


    cout<<intToRoman(2024);
    // string s = "    -a";
    // cout << mystoi(s);

    return 0;
}