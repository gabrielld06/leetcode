class Solution {
public:
    bool isUpperCase(char &c) {
        return c < 'a';
    }

    int vowelIndex(char &c) {
        switch(c) {
            case 'a':
            case 'A':
                return 0;
            case 'e':
            case 'E':
                return 1;
            case 'i':
            case 'I':
                return 2;
            case 'o':
            case 'O':
                return 3;
            case 'u':
            case 'U':
                return 4;
            default:
                return -1;
        }
    }

    string sortVowels(string s) {
        char upper_case[] = { 'A', 'E', 'I', 'O', 'U' };
        char lower_case[] = { 'a', 'e', 'i', 'o', 'u' };
        int vowel_idx, upper_case_vowels[5] = { 0 }, lower_case_vowels[5] = { 0 };
        vector<int> vowel_indexes;

        for(int i = 0;i < s.length();i++) {
            vowel_idx = vowelIndex(s[i]);

            if(vowel_idx == -1) continue;

            vowel_indexes.push_back(i);

            if(isUpperCase(s[i])) {
                upper_case_vowels[vowel_idx]++;
            } else {
                lower_case_vowels[vowel_idx]++;
            }
        }

        int idx = 0, vowel = 0;
        while(vowel < 5 && upper_case_vowels[vowel] == 0) {
            vowel++;
        }
        while(vowel < 5) {
            vowel_idx = vowel_indexes[idx];
            idx++;

            s[vowel_idx] = upper_case[vowel];
            upper_case_vowels[vowel]--;

            while(vowel < 5 && upper_case_vowels[vowel] == 0) {
                vowel++;
            }
        }

        vowel = 0;
        while(vowel < 5 && lower_case_vowels[vowel] == 0) {
            vowel++;
        }
        while(vowel < 5) {
            vowel_idx = vowel_indexes[idx];
            idx++;

            s[vowel_idx] = lower_case[vowel];
            lower_case_vowels[vowel]--;

            while(vowel < 5 && lower_case_vowels[vowel] == 0) {
                vowel++;
            }
        }

        return s;
    }
};