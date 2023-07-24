//Link - https://leetcode.com/problems/insert-delete-getrandom-o1/description/

class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> p;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)){
            return false;
        }
        mp[val] = p.size();
        p.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val)){
            int last = p.back();
            mp[last] = mp[val];
            p[mp[val]] = last;
            p.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return p[rand() % p.size()];
    }
};
