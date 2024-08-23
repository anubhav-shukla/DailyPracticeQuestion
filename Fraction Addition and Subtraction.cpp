class Solution {
public:
    int n;
    pair<int, int> getNum(int& idx, string& expression) {
        int num = 0, den = 0;
        while (idx < n && isdigit(expression[idx]))
            num = num * 10 + expression[idx++] - '0';
        idx++;
        while (idx < n && isdigit(expression[idx]))
            den = den * 10 + expression[idx++] - '0';
        return {num, den};
    }

    int gcd(int x, int y) {
        while (x && y) {
            x %= y;
            swap(x, y);
        }
        return (x == 0 ? y : x);
    }

    pair<int, int> mul(pair<int, int>& prevResult, pair<int, int>& frac) {
        pair<int, int> result;
        result.first = prevResult.first * frac.second + prevResult.second * frac.first;
        result.second = prevResult.second * frac.second;
        int d = gcd(abs(result.first), abs(result.second));
        result.first /= d;
        result.second /= d;
        return result;
    }

    string fractionAddition(string expression) {
        n = expression.size();
        pair<int, int> result{0, 1};
        for (int idx = 0; idx < n;) {
            if (expression[idx] == '-') {
                idx++;
                auto frac = getNum(idx, expression);
                frac.first *= -1;
                result = mul(result, frac);
            } else if (idx == 0 || expression[idx] == '+') {
                idx += (idx != 0);
                auto frac = getNum(idx, expression);
                result = mul(result, frac);
            }
        }
        return to_string(result.first) + '/' + to_string(result.second);
    }
};