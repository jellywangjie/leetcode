class Trie {
private:
    bool is_valid;
    Trie* next[26];//此时next指针未指向任何空间 -> // Trie* next[26]={nullptr};
public:
    /** Initialize your data structure here. */
    Trie() {
        is_valid=false;
    //Sets the first num bytes of the block of memory pointed by ptr to the specified value
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node=this;
        for(auto l:word){
            if(node->next[l-'a']==NULL){
                node->next[l-'a']=new Trie();
            }
            node=node->next[l-'a'];
        }
        node->is_valid=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node=this;
        for(auto l:word){
            if(node->next[l-'a']==NULL){
                return false;
            }
            node=node->next[l-'a'];
        }
        return node->is_valid;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         Trie* node=this;
        for(auto l:prefix){
            if(node->next[l-'a']==NULL){
                return false;
            }
            node=node->next[l-'a'];
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


