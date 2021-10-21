/**
Time = O(1) per operation 
Space = O(n)
**/

class RandomizedSet {
private:
    unordered_map<int,int> pos;
    vector<int> v;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(pos.count(val))return false;
        pos[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!pos.count(val))return false;
        // int idx = pos[val];
        swap(v[pos[val]], v[v.size()-1]);
        v.pop_back();
        pos[v[pos[val]]] = pos[val];
        pos.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
