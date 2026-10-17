class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastInd(26,0);
        for(int i=0; i<s.size();i++){
            lastInd[s[i]-'a']=i;
        }    

            vector<bool> seen(26,0);
            stack<char> st;

            for(int i=0;i<s.size();i++){
                int ch=s[i]-'a';
                if(seen[ch]) continue;
                while(st.size()>0 && st.top()>s[i] && i<lastInd[st.top()-'a']){
                    seen[st.top()-'a']=false;
                    st.pop();
                }
                st.push(s[i]);
                seen[ch]=true;
            }
            string ans="";
            while(st.size()>0){
                ans+=st.top();
                st.pop();
            }
            reverse(ans.begin(),ans.end());
        return ans;
    }
};