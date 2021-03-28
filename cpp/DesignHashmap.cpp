// Source : https://leetcode-cn.com/problems/design-hashmap/
// Author : jkbs487
// Date   : 2021-03-14

/***************************************************************************************************** 
 *
 * Design a HashMap without using any built-in hash table libraries.
 * 
 * Implement the MyHashMap class:
 * 
 * 	MyHashMap() initializes the object with an empty map.
 * 	void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key 
 * already exists in the map, update the corresponding value.
 * 	int get(int key) returns the value to which the specified key is mapped, or -1 if this map 
 * contains no mapping for the key.
 * 	void remove(key) removes the key and its corresponding value if the map contains the 
 * mapping for the key.
 * 
 * Example 1:
 * 
 * Input
 * ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
 * [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
 * Output
 * [null, null, null, 1, -1, null, 1, null, -1]
 * 
 * Explanation
 * MyHashMap myHashMap = new MyHashMap();
 * myHashMap.put(1, 1); // The map is now [[1,1]]
 * myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
 * myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
 * myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
 * myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
 * myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
 * myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
 * myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
 * 
 * Constraints:
 * 
 * 	0 <= key, value <= 106
 * 	At most 104 calls will be made to put, get, and remove.
 * 
 * Follow up: Please do not use the built-in HashMap library.
 ******************************************************************************************************/

// chain address method
class MyHashMap {
public:
    vector<list<pair<int, int>>> data;
    const static int base = 50000;
    static int hash(int key) {
        return key % base;
    }
    /** Initialize your data structure here. */
    MyHashMap(): data(base) {

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = hash(key);
        for (auto it = data[index].begin(); it != data[index].end(); it++) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        data[index].push_back(make_pair(key, value));
        return;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = hash(key);
        for (auto it = data[index].begin(); it != data[index].end(); it++) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = hash(key);
        for (auto it = data[index].begin(); it != data[index].end(); it++) {
            if (it->first == key) {
                data[index].erase(it);
                break;
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