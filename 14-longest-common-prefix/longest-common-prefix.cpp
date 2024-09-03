class TrieNode{
    public:
        TrieNode *children[26];
        bool isTerminal;
        int childCount;
    TrieNode(){
        for(int i{0};i<26;i++){
            children[i] = nullptr;
        }
        isTerminal = false;
        childCount = 0;
    }
};    
class Node{
    public:
        TrieNode *root = new TrieNode();

        void insert(string key){
            TrieNode *currNode = root;
            int n = key.size();
            for(int i{0};i<n;i++){
                int index = key[i]-'a';
                if(currNode->children[index] == nullptr){
                    TrieNode *newNode = new TrieNode();
                    currNode->children[index] = newNode;
                    currNode->childCount++;
                }
                currNode=currNode->children[index];
            }
            currNode->isTerminal = true;
        }
        void sol(string str,string &ans){
            TrieNode *currNode = root;
            int n = str.size();
            for(int i{0};i<n;i++){
                if(currNode->childCount == 1){
                    ans += str[i];
                    currNode=currNode->children[str[i]-'a'];
                }
                else break;
                if(currNode->isTerminal == true) break;
            }
        }

};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Node *root = new Node();
        int n = strs.size();
        string ans = "";
        for(int i{0};i<n;i++){
            if(strs[i] == "")
                return "";
            else
               root->insert(strs[i]);
        }

        string first = strs[0];
        root->sol(first,ans);

        return ans;
    }
};