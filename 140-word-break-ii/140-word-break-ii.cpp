class Solution {
public:
    
unordered_set<string>st;
vector<string>ans;
void solver(int idx, string &s, vector<string> &dictionary, string &temp)
{

    if (idx == s.size()) {
        temp.pop_back();
        ans.push_back(temp);
        return;
    }

    int n = s.size();

    for (int i = idx; i < n; i++) {

        string x = s.substr(idx, i - idx + 1);

        if (st.find(x) != st.end()) {

            string y = temp;
            temp += x;
            temp += " ";

            solver(i + 1, s, dictionary, temp);

            temp = y;

        }
    }
}
    
    vector<string> wordBreak(string s, vector<string>&dictionary) {
        
        for (auto k : dictionary) {
        st.insert(k);
    }


    string temp = "";

   solver(0, s, dictionary, temp);
    
    return ans;
        
    }
};