int FindMajorityEle(vector<int> &v)
{
    int maj_ele = 0, c = 0;
    for (int i = 0; i < v.size(); i++)
    {
        // whenever count becomes zero , we will assume the ith ele to be maj_ele.
        if (c == 0)
        {
            maj_ele = v[i];
        }
        // If the ith ele is same as assumed maj_ele, increase the cout or vice-versa.
        if (v[i] == maj_ele)
        {
            c++;
        }
        else
        {
            c--;
        }
    }
    return maj_ele;
}
