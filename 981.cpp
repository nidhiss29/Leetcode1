class TimeMap
{
public:
    unordered_map<string, map<int, string>> t_map;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        t_map[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        if (!t_map.count(key))
            return "";
        auto it = t_map[key].upper_bound(timestamp);
        return it == t_map[key].begin() ? "" : (--it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */