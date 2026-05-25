class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode*node = root;
        for(auto ch:word){
            int ind = ch-'a';
            if(node->children[ind]==NULL){
                node->children[ind] = new TrieNode();
            }
            node = node->children[ind];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(auto ch:word){
            int ind = ch-'a';
            if(node->children[ind]==NULL)return false;
            node = node->children[ind];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto ch:prefix){
            int ind = ch-'a';
            if(node->children[ind]==NULL)return false;
            node=node->children[ind];
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