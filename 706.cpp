class MyHashMap
{
private:
    vector<list<pair<int, int>>> map;
    const int sizeMap = 10000;

public:
    MyHashMap()
    {
        map.resize(sizeMap);
    }

    void put(int key, int value)
    {
        auto &list = map[key % sizeMap];

        for (auto &keyValue : list)
        {
            if (keyValue.first == key)
            {
                keyValue.second = value;
                return;
            }
        }
        map[key % sizeMap].push_front(make_pair(key, value));
    }

    int get(int key)
    {
        auto &list = map[key % sizeMap];
        for (auto &keyValue : list)
        {
            if (keyValue.first == key)
            {
                return keyValue.second;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        auto &list = map[key % sizeMap];
        for (auto &keyValue : list)
        {
            if (keyValue.first == key)
            {
                list.remove(keyValue);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */