int strangeGrid(int r, int c)
{

    if (r % 2 != 0)
    {
        return (r / 2) * 10 + (c - 1) * 2;
    }
    return (r / 2 - 1) * 10 + ((c * 2) - 1);
}
