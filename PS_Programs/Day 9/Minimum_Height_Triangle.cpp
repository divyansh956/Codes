int lowestTriangle(int base, int area)
{
    return (area * 2) % base == 0 ? (area * 2) / base : (area * 2) / base + 1;
}
