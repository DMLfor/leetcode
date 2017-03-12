bool isMatch(const char *s, const char *p)
{
    if(*p == '\0')
    {
        if(*s == '\0') return true;
        return false;
    }
    if(*(p+1) == '*')
    {
        while(*s != '\0' && (*p == *s || *p == '.'))
        {
            if(isMatch(s, p+2)) return true;
            s++;
        }
        return isMatch(s, p+2);
    }
    if((*p==*s) || ((*p=='.') && (*s!='\0')))
        return isMatch(s+1, p+1);
    return false;
}
