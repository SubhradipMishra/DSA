class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }

    string devowel(string s) {
        for(char &c : s) 
            c = isVowel(c) ? '#' : tolower(c);
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string,string> mp, vmp;

        for(string w : wordlist) {
            string low = w; 
            transform(low.begin(), low.end(), low.begin(), ::tolower);
            if(mp.find(low) == mp.end()) mp[low] = w;

            string dv = devowel(w);
            if(vmp.find(dv) == vmp.end()) vmp[dv] = w;
        }

        vector<string> ans;
        for(string q : queries) {
            if(exact.find(q) != exact.end()) {
                ans.push_back(q);
                continue;
            }

            string low = q; 
            transform(low.begin(), low.end(), low.begin(), ::tolower);
            if(mp.find(low) != mp.end()) {
                ans.push_back(mp[low]);
                continue;
            }

            string dv = devowel(q);
            if(vmp.find(dv) != vmp.end()) {
                ans.push_back(vmp[dv]);
                continue;
            }

            ans.push_back("");
        }
        return ans;
    }
};
