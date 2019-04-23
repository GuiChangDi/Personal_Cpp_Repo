unsigned int
Hash(const char *key,int TableSize)
{
    unsigned int HashVal = 0;

    while(*key != '\0')
        HashVal = (HashVal << 5) + *key++;
    return HashVal % TableSize;
}