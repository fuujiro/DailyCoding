class Solution {
public:
    bool isNumber(string s) {
        const char *p = s.c_str(), *q;

        while (isspace(*p))
            ++p;
        if (*p == 0)
            return false;

        if (*p == '-' || *p == '+')
            ++p;

        q = p;
        while (isdigit(*p))
            ++p;

        if (*p == '.') {
            /* .NUMBER */
            if (p == q && !isdigit(*(p+1)))
                return false;
            ++p;

            while (isdigit(*p))
                ++p;
        }

        if (*p == 'e' || *p == 'E') {
            /* e and nothing before */
            if (p == q)
                return false;

            ++p;
            if (*p == '+' || *p == '-')
                ++p;

            if (!isdigit(*p))
                return false;
            while (isdigit(*p))
                ++p;
        }

        while (isspace(*p))
            ++p;
        if (*p != 0)
            return false;

        return true;

    }
};