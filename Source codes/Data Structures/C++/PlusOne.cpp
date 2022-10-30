class Solution {
public:
   vector<int> plusOne(vector<int> &digits){

unsigned short n = digits.size();
if (digits[0] == 0) {
    digits[0]++;
    return digits;
}
 for (int i = 0; i < n; i++)
{
    if (digits[n - 1 - i] == 9)
        digits[n - 1 - i] = 0;
    else
    {
        digits[n - 1 - i]++;
        break;
    }
}

if (digits[0] == 0)
    digits.insert(digits.begin(), 1);
return digits;
}
    
};
