class Solution {
public:

    string encode(vector<string>& strs) {
        string delimiter = "__#__";
        string result = delimiter;
        for (const string& s : strs) {
            result += s + delimiter;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string delimiter = "__#__";

        for (int ptr = 0; ptr < s.length() - delimiter.length();)
        {
            if (s.substr(ptr, 5) == "__#__")
            {
                ptr += 5;
                if (ptr > s.length()) break;

                string temp = "";
                while (s.substr(ptr, 5) != "__#__")
                {
                    temp += s[ptr];
                    ptr++;
                }

                result.push_back(temp);
            }
        }

        return result;
    }
};
