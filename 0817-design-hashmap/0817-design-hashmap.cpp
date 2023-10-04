class MyHashMap {
    static const unsigned int MAX = 1000001;
    int hash[MAX];
public:
    MyHashMap() {
        memset(hash, -1, sizeof(hash));
    }
    
    void put(int key, int value) {
        this->hash[key] = value;
    }
    
    int get(int key) {
        return this->hash[key];
    }
    
    void remove(int key) {
        this->hash[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */