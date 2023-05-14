#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
#include<queue>
#include<stdio.h>
#include<functional>
#include<set>
#include<string.h>
#include<limits>

using namespace std;


const vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0}};

//字典树
class Trie {
    struct TrieNode {
        bool end;
        TrieNode* tns[26];
        TrieNode() : end(false) {
            memset(tns, 0, sizeof(tns));
        }
    };

    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    void insert(string s) {
        TrieNode* p = root;
        for(int i = 0; i < s.length(); i++) {
            int u = s[i] - 'a';
            if (p->tns[u] == nullptr) p->tns[u] = new TrieNode();
            p = p->tns[u]; 
        }
        p->end = true;
    }

    bool search(string s) {
        TrieNode* p = root;
        for(int i = 0; i < s.length(); i++) {
            int u = s[i] - 'a';
            if (p->tns[u] == nullptr) return false;
            p = p->tns[u]; 
        }
        return p->end;
    }

    bool startsWith(string s) {
        TrieNode* p = root;
        for(int i = 0; i < s.length(); i++) {
            int u = s[i] - 'a';
            if (p->tns[u] == nullptr) return false;
            p = p->tns[u]; 
        }
        return true;
    }
};

//链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//树
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
//分割字符串
std::vector<std::string> splitString(std::string str, char delimiter) {
    std::vector<std::string> result;
    std::string token;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == delimiter) {
            result.push_back(token);
            token = "";
        } else {
            token += str[i];
        }
    }
    result.push_back(token);
    return result;
}
//二叉树dfs
void dfs(TreeNode* root){
        if(root==nullptr){
            return;
        }
        dfs(root->left);
        dfs(root->right);
}

bool check(int newx, int newy, int m,int n){
    if(newx>=0 && newx<m && newy>=0 && newy<n){
        return true;
    }
    return false;
}

// bool dfs(vector<vector<int>>& grid,int x,int y, int num, vector<vector<bool>>& visited){
//     visited[x][y] = true;
//     int m = grid.size();
//     int n = grid[0].size();
//     for (int i = 0; i < dirctions.size(); i++)
//     {
//         int newx = x + dirction[i][0];
//         int newy = y + dirction[i][1];
//         if(check(newx,newy,m,n)&&grid[newx][newy]<=num&&!visited[newx][newy]){
//             if(newx==m-1&&newy==n-1){
//                 return true;
//             }
//             if(dfs(grid,newx,newy,num,visited)){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

//并查集
int find(vector<int>& f, int x) {
    if (f[x] == x) {
        return x;
    }
    int fa = find(f, f[x]);
    f[x] = fa;
    return fa;
}
void merge(vector<int>& f, int x, int y) {
    int fx = find(f, x), fy = find(f, y);
    f[fx] = fy;
}

struct Entry{
    int x;
    int y;
    int val;
    Entry(int x,int y,int val):x(x),y(y),val(val){};
    bool operator<(const Entry& other) const{
        return this->val > other.val;
    }
};
// priority_queue<Entry,vector<Entry>,function<bool(const Entry& x, const Entry& other)>> pq(&Entry::operator<);
// vector<vector<bool>> visited(n,vector<bool>(n,false));

struct MyComp {
    bool operator()(const pair<int,int>& s1, const pair<int,int>& s2) const {
        if(s1.first==s2.first){
            return s1.second>s2.second;
        }
        return s1.first<s2.first;
    }
};


bool myless(const pair<int,int>& lhs, const pair<int,int>& rhs){
    return lhs.second>rhs.second;
}

class Solution {
public:
};

int main(){
    Solution s;
    vector<int> test = {4,3,2,3,5,2,1};
    // string st("catsandogcat");
    // s.longestPalindrome(st);
    // s.lengthLongestPath(st);
    // s.isValidSerialization(st);
    // vector<vector<int>> grid = {{0,2},{1,3}};
    // s.swimInWater(grid);
    // const int & a = 10;
    // s.letterCombinations(st);
    // s.combinationSum2(test,8);
    // s.maxArea(test);
    // vector<string> s_test = {"cats","dog","sand","and","cat","an"};
    // s.wordBreak(st,s_test);
    // s.canPartitionKSubsets(test, 4);

    return 0;
}

