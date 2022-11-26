int restaurant(int l, int b)
{
    return (l * b) / (__gcd(l, b) * __gcd(l, b));
}
