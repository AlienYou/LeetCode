class Solution {
public:
    enum STATE {
        INITAIL, 
        INT_SIGN,
        INT,
        POINT,
        POINT_WITHOUT_INT,
        FRACTION,
        EXP,
        EXP_SIGN,
        EXP_INT,
        END,
    };

    enum CHAR_TYPE {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_SPACE,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_ILLEGAL
    };

    CHAR_TYPE toCharType(char c) {
        if (c == '.')
            return CHAR_POINT;
        else if (c == '-' || c == '+')
            return CHAR_SIGN;
        else if (c == 'e' || c == 'E')
            return CHAR_EXP;
        else if (c >= '0' && c <= '9')
            return CHAR_NUMBER;
        else if (c == ' ')
            return CHAR_SPACE;
        return CHAR_ILLEGAL;
    }

    bool isNumber(string s) {
        unordered_map<STATE, unordered_map<CHAR_TYPE, STATE>> transfer = {
            {INITAIL, { {CHAR_SPACE, INITAIL},
                        {CHAR_POINT, POINT_WITHOUT_INT},
                        {CHAR_NUMBER, INT},
                        {CHAR_SIGN, INT_SIGN}}},
            {INT_SIGN, { {CHAR_POINT, POINT_WITHOUT_INT},
                         {CHAR_NUMBER, INT}}},
            {INT, { {CHAR_NUMBER, INT}, 
                    {CHAR_POINT, POINT}, 
                    {CHAR_EXP, EXP},
                    {CHAR_SPACE, END}}},
            {POINT, { {CHAR_NUMBER, FRACTION},
                      {CHAR_SPACE, END},
                      {CHAR_EXP, EXP} }},
            {POINT_WITHOUT_INT, { {CHAR_NUMBER, FRACTION}}},
            {FRACTION, { {CHAR_NUMBER, FRACTION},
                         {CHAR_EXP, EXP},
                         {CHAR_SPACE, END}}},
            {EXP, { {CHAR_SIGN, EXP_SIGN},
                    {CHAR_NUMBER, EXP_INT} } },
            {EXP_SIGN, { {CHAR_NUMBER, EXP_INT}}},
            {EXP_INT, { {CHAR_NUMBER, EXP_INT},
                        {CHAR_SPACE, END}}},
            {END, { {CHAR_SPACE, END} }}
        };
        int L = s.length();
        STATE st = INITAIL;
        for (int i = 0; i < L; ++i) {
            CHAR_TYPE curType = toCharType(s[i]);
            if (transfer[st].find(curType) == transfer[st].end())
                return false;
            st = transfer[st][curType];
        }   
        return st == FRACTION || st == INT || st == END || st == EXP_INT || st == POINT;
    }
};