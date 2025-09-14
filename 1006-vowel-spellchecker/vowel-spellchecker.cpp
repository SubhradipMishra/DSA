class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }

    string devowel(string s) {
        for(char &c : s) {
            if(isVowel(c)) c = '#';
            else c = tolower(c);
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
        unordered_set<string> exact(wordlist.begin(), wordlist.end()); // exact match set
        map<string,string> mp;    // lowercase → প্রথম wordlist match
        map<string,string> vmp;   // devowel → প্রথম wordlist match

        for(int i = 0; i < wordlist.size(); i++) {
            string s = wordlist[i];

            // lowercase তৈরি
            string low = s;
            transform(low.begin(), low.end(), low.begin(), ::tolower);

            if(mp.find(low) == mp.end()) mp[low] = wordlist[i];

            // devowel তৈরি
            string dv = devowel(s);
            if(vmp.find(dv) == vmp.end()) vmp[dv] = wordlist[i];
        }

        vector<string> ans;

        for(int i = 0; i < queries.size(); i++) {
            string org = queries[i];

            
            if(exact.count(org)) {
                ans.push_back(org);
                continue;
            }

          
            string low = org;
            transform(low.begin(), low.end(), low.begin(), ::tolower);
            if(mp.find(low) != mp.end()) {
                ans.push_back(mp[low]);
                continue;
            }

            
            string dv = devowel(org);
            if(vmp.find(dv) != vmp.end()) {
                ans.push_back(vmp[dv]);
                continue;
            }

           
            ans.push_back("");
        }

        return ans;
    }
};
