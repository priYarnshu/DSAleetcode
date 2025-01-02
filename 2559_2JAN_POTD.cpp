class Solution {
public:
    bool isvowel(char ch){
        if(ch == 'a' ||ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u' ){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> result;
        
        vector<int> cumsum(n,0);
        for(int i=0;i<n;i++){
            int k = words[i].size();
            if(isvowel(words[i][0]) && isvowel(words[i][k-1])){
                if(i==0){
                    cumsum[i]=1;
                }
                else{
                cumsum[i] += 1+cumsum[i-1];}
            }
            else{
                if(i==0){
                    cumsum[i]=0;
                }
                else{
                cumsum[i]=cumsum[i-1];}
            }
        }

        for(int i=0;i<queries.size();i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int temp;
            if (l > 0) {
                temp = cumsum[r] - cumsum[l - 1];
            } else {
                temp = cumsum[r];
            }
            result.push_back(temp);
        }

    return result;

    }
};