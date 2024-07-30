class Solution {
public:
    int minimumDeletions(string &s) noexcept {
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        std::string_view s_v = s;
        int last_char = s_v[0];
        int num_of_last_chars = 1;
        int to_delete = 0;
        for (int ch = 1; ch < s_v.length(); ch++) {
            if (s_v[ch] == 'b') {
                if (last_char == 'b') {
                    num_of_last_chars++;
                }
                else {
                    last_char = 'b';
                    num_of_last_chars = 1;
                }
            }
            else {
                if (last_char == 'b') {
                    to_delete++;
                    num_of_last_chars--;
                    if (num_of_last_chars == 0) {
                        last_char = 'a';
                    }
                }
            }
        }
        return to_delete;
    }
};