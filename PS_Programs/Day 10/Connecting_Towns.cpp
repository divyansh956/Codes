int connectingTowns(int n, vector<int> routes)
{
    int p = 1;
    int mod = 1234567;
    for (auto x : routes)
    {
        p = (p * x) % (mod);
    }
    return p;
}
