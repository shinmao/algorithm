// 這題比較重要的是getPrefix的部分
// 一開始我的思路是數 node的child有幾個
// 如果為1個或0個那便是我們要的unique prefix
// 然而仔細想想，如果字典中存在著 ["a", "aa", "aaa"]
// 按照之前的邏輯我們會輸出"a"呢！
// 所以要換個邏輯：換成計算以當前node為prefix的字串有幾個？
// 所以我們為TrieNode都另外維護了count
// 舉上面的例子：在第一個節點count會得到3，在第二個節點count會得到2，在第三個節點會得到1
class TrieNode {
public:
    TrieNode *next[26];
    bool isword;
    int count;
    TrieNode() {
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
        isword = false;
        count = 0;
    }
};

class Trie {
private:
    TrieNode *root;
public:    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *p = root;
        for(int i = 0; i < word.length(); i++) {
            if(p->next[word[i] - 'a'] == NULL)
                p->next[word[i] - 'a'] = new TrieNode();
            p = p->next[word[i] - 'a'];
            p->count++;
        }
        p->isword = true;
    }
    // 
    string getPrefix(string word) {
        TrieNode *p = root;
        for(int i = 0; i < word.length(); i++) {
            if(p->count == 1)
                // count為1，代表以目前node為prefix的人只有一個，所以輸出答案
                return word.substr(0, i);
            p = p->next[word[i] - 'a'];
        }
        // 另外一種情況則是到死都有不止一個count
        // 代表這個string為其他人的prefix
        // 那麼他本身也是答案之一
        return word;
    }
};

class Solution {
public:
    /**
     * @param stringArray: a string array
     * @return: return every strings'short peifix
     */
    vector<string> ShortPerfix(vector<string> &stringArray) {
        vector<string> res(stringArray.size(), "");
        Trie * dictree = new Trie();
        for(auto i : stringArray) {
            dictree->insert(i);
        }
        for(int i = 0; i < stringArray.size(); i++) {
            res[i] += dictree->getPrefix(stringArray[i]);
        }
        return res;
    }
};