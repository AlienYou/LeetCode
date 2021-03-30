class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        while (i < str.length() && str[i] == ' ') ++i;
        int sign = 1;
        if (i < str.length()) {
            if (str[i] == '+')
                ++i;
            else if (str[i] == '-') {
                ++i;
                sign = -1;
            }
        }
        int sum = 0;
        while (i < str.length()) {
            if (!isdigit(str[i]))
                break;
            int c = str[i] - '0';
            if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && c > 7))
                return sign == 1 ? INT_MAX : INT_MIN;
            sum = sum * 10 + c;
            ++i;
        }
        return sign * sum;
    }
};