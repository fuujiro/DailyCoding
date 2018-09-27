class Solution {
public:
    string intToRoman(int num) {
        vector<int> roman;
        string road = "";
        while(num) {
            roman.push_back(num % 10);
            num /= 10;
        }
        int length = roman.size();
        for(int i = length - 1; i >= 0; i--) {
            if(i == 3) {
                for(int j = roman[i] - 1; j >= 0; j--) {
                    road += 'M';
                }
            }
            if(i == 2) {
                if(roman[i] >= 4) {
                    if(roman[i] == 9)
                        road += "CM";
                    else if(roman[i] == 4)
                        road += "CD";
                    else {
                        road += 'D';
                        int j = roman[i] - 5;
                        for(int k = j - 1; k >= 0; k--)
                            road += 'C';
                    }
                } else {
                    for(int k = roman[i] - 1; k >= 0; k--)
                        road += 'C';
                }
            }
            if(i == 1) {
                if(roman[i] >= 4) {
                    if(roman[i] == 9)
                        road += "XC";
                    else if(roman[i] == 4)
                        road += "XL";
                    else {
                        road += 'L';
                        int j = roman[i] - 5;
                        for(int k = j - 1; k >= 0; k--)
                            road += 'X';
                    }
                } else {
                    for(int k = roman[i] - 1; k >= 0; k--)
                        road += 'X';
                }
            }
            if(i == 0) {
                if(roman[i] >= 4) {
                    if(roman[i] == 9)
                        road += "IX";
                    else if(roman[i] == 4)
                        road += "IV";
                    else {
                        road += 'V';
                        int j =roman[i] - 5;
                        for(int k = j - 1; k >= 0; k--)
                            road += 'I';
                    }
                } else {
                    for(int k = roman[i] - 1; k >= 0; k--)
                        road += 'I';
                }
            }
        }
        return road;
    }
};
