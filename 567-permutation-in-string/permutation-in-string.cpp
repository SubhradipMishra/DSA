class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        unordered_map<char,int> freq1, freq2;
        for(char c : s1) freq1[c]++;

        int i = 0, j = 0;
        while(j < n1) {
            freq2[s2[j]]++;
            j++;
        }

        if(freq1 == freq2) return true;

        while(j < n2) {
            freq2[s2[i]]--;
            if(freq2[s2[i]] == 0) freq2.erase(s2[i]);
            i++;

            freq2[s2[j]]++;
            j++;

            if(freq1 == freq2) return true;
        }

        return false;
    }
};
