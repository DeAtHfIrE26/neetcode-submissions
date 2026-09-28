class TimeMap {
    unordered_map<string, vector<pair<int, string>>>mp;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& v = mp[key];

        auto it = upper_bound(v.begin(), v.end(), timestamp,
        [](int t, const pair<int, string>& p){return t < p.first;});

        return it == v.begin() ? "" : prev(it)->second;
    }
};
