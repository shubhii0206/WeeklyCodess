//https : //www.geeksforgeeks.org/efficiently-check-string-duplicates-without-using-additional-data-structure/
        bool
        areChractersUnique(string str)
{
    // An integer to store presence/absence
    // of 26 characters using its 32 bits.
    int checker = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        int val = (str[i] - 'a');

        // If bit corresponding to current
        // character is already set
        if ((checker & (1 << val)) > 0)
            return false;

        // set bit in checker
        checker |= (1 << val);
    }

    return true;
}

2nd approach is to sort the string and check s[i] == s[i+1]