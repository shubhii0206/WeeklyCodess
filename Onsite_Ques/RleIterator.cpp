class RLEIterator
{
public:
    vector<int> arr;
    int p;
    RLEIterator(vector<int> &encoding)
    {

        this->arr = encoding;
        this->p = 0;
    }

    int next(int n)
    {

        while (p < arr.size())
        {
            if (n <= arr[p])
            {
                arr[p] -= n;
                return arr[p + 1];
            }
            else
            {
                n -= arr[p];
                p += 2;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */