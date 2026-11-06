struct Node{
    string str;
    int seq_len;
};

class Solution {
private:

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> words(wordList);

        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == beginWord) {words.erase(words.begin() + i); break;}
        }

        queue<Node> q;
        q.push({beginWord, 1});

        while (!q.empty())
        {
            auto root = q.front();
            q.pop();

            int curr_len = root.seq_len;
            if (root.str == endWord) return curr_len;
            
            for (int i = 0; i < words.size(); i++)
            {
                if (isadj(root.str, words[i])) 
                {
                    q.push({words[i], curr_len+1});
                    auto it = words.begin() + i;
                    words.erase(it);
                    i--;
                }
            }
        }

        return 0;
    }

    bool isadj(string s1, string s2)
    {
        int n = s1.size();

        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i]) temp++;
            if (temp > 1) return false;
        }
        return temp == 1;
    }
};