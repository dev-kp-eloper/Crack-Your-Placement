//Link - https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

class RandomizedCollection {
public:
    unordered_map<int,vector<int>> mp;
    vector<pair<int,int>> p;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool temp = true;
        if(mp.count(val)) temp = false;
        mp[val].push_back(p.size());
        p.push_back(make_pair(val,mp[val].size()-1));
        return temp;
    }
    
    bool remove(int val) {
        int temp = false;
        if(mp.count(val)){
            temp = true;
            auto last = p.back();
            mp[last.first][last.second] = mp[val].back();
            p[mp[val].back()] = last;
            mp[val].pop_back();
            if(mp[val].empty()){
                mp.erase(val);
            }
            p.pop_back();
        }
        return temp;
    }
    
    int getRandom() {
        int temp = p[rand() % p.size()].first;
        return temp;
    }
};
