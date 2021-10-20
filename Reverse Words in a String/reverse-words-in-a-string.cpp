/**
Time = O(n)
Space = O(1)
**/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        
        // remove the extra spaces
        
        int j = 0;
        for(int i = 0; i<n;){
            bool word = 0;
            while(i<n && s[i]!=' '){
                s[j++] = s[i++];
                word = 1;
            }
            
            while(i<n && s[i]==' '){
                i++;
            }
            if(i!=n && word)
                s[j++] = ' ';
            
        }
        n = j;
        //reverse the words
        
        for(int i = 0; i<n ;i++){
            int start = i, end = i;
            while(i<n && s[i]!=' '){
                i++;
            }
            end = i-1;
            reverse(s, start, end);
            
        }
        //reverse the string
        
        reverse(s, 0, n-1);
        return s.substr(0,n);
    }
    
    void reverse(string& s, int start, int end){
        int size = end-start+1;
        for(int i = start; i<start+size/2; i++){
            swap(s[i], s[end--]);
        }
    }
};
