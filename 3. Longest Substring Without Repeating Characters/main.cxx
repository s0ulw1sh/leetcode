class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<bool> ext('~' - ' '); 
        int len = s.size(),
            out = 0,
            i, z;
        
        for(i = 0; i < len; ++i) {
    
            for (z = i; z < len; ++z) {
                if (ext[s[z]-' '])
                    break;

                out = std::max(out, z - i + 1);
                ext[s[z]-' '] = true;
            }
            
            std::fill(ext.begin(), ext.end(), false);
        }

        return out;
    }
};
