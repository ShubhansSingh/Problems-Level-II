
class disjoint_set
{
    public:
  vector<int> v;
    int sz;
    disjoint_set(int size)
    {
        sz = size;
        v = vector<int>(size);
        for(int i=0; i<size; i++)
            v[i] = i;
    }
    int find(int i)
    {
        if(v[i] != i)
            v[i] = find(v[i]);
        return v[i];
    }
    void join(int i, int j)
    {
        int ii=find(i), jj=find(j);
        if(ii != jj)
            v[ii] = jj;
        sz--;
    }
    int size()
    {
        return sz;
    }
};
