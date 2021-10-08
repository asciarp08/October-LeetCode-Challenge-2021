/**
Time = O(n*l) //n = total calls, l = average word length
Space = O(m*l) //m = insertion calls
**/

class Trie {
private:    
    struct trieNode{
        vector<int> next = vector<int>(26,-1);
        bool isWord = false;
    };
    
    vector<trieNode> trie = vector<trieNode>(1);
    
public:
    Trie() {
        
    }
    
    void insert(string word) {
        int node = 0;
        for(auto c:word){
            if(trie[node].next[c-'a']==-1){
                trie[node].next[c-'a'] = trie.size();
                trie.emplace_back();
            }
            node = trie[node].next[c-'a'];
        }
        trie[node].isWord = true;
    }
    
    bool search(string word) {
        int node = 0;
        for(auto c:word){
            if(trie[node].next[c-'a']==-1)
                return false;
            node = trie[node].next[c-'a'];
        }
        
        if(trie[node].isWord)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        int node = 0;
        for(auto c:prefix){
            if(trie[node].next[c-'a']==-1)
                return false;
            node = trie[node].next[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
