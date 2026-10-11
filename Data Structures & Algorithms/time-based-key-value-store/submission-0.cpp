class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> m;
public:
    TimeMap() {}
    
    void set(const string &key, const string &value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }

    string get(const string &key, int timestamp) {
        auto found = m.find(key);
        if (found == m.end()) return "";
        const auto &it = found->second;

        int left = 0;
        int right = it.size() - 1;
        const string *temp = nullptr;

        while (left <= right)
        {
            int mid = (left + right)/2;
            if (it[mid].first == timestamp) return it[mid].second;

            else if (it[mid].first > timestamp) right = mid - 1;
            else if (it[mid].first < timestamp)
            {
                temp = &it[mid].second;
                left = mid + 1;
            }
        }
        return temp ? *temp : "";
    }
};