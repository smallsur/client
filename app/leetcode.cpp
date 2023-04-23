#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int x=0,y=0;
        int value = -1;
        vector<vector<int>> dp(len,vector<int>(len,0));
        for (int i = 0; i < len-1; i++)
        {
            dp[i][i] = 1;
        }
        for (int j = 1; j < len; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1]+2;
                }
                if(dp[i][j]>value){
                    value = dp[i][j];
                    x = i;y=j;
                }
            }      
        }
        return s.substr(x,y-x);
    }
    int lengthLongestPath(string input) {
        int ans = 0;

        int len = input.size();
        int i = 0;
        map<int,int> count;
        while (i<len)
        {
            int t = i;
            int depth = 0;
            while (t<len&&input[t]=='\t')
            {
                depth++;
                t++;
            }

            int len_word = 0;
            bool isFile = false;
            while (t<len&&input[t]!='\n')
            {
                len_word++;
                t++;
                if(input[t]=='.'){
                    isFile = true;
                }
            }

            if(count.count(depth-1)){
                len_word += count[depth] + 1;
            }

            if(isFile){
                ans = max(ans,len_word);
            }else{
                count[depth] = len_word;
            }
            i = t + 1;
        }
        
        return ans;
    }
    
};



int main(){
    Solution s;
    vector<int> test = {3,2,4};
    string st("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
    // s.longestPalindrome(st);
    s.lengthLongestPath(st);
    return 0;
}

