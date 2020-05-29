#define  Multiplication typename
#define  Integer typename

template <Integer N>
bool odd(N n)
{
    return bool(n & 0x01);
}

template <Integer N>
N  half(N n)
{
    return n >> 1;
}

template<Multiplication A, Integer N>
A multiplyAccumulateSemigroup(A r, N n, A a)
{
    if(n == 0)
        return r;
    while(1)
    {
        if(odd(n))
        {
            r += a;
            if(n == 1)
                return r;
        }
        n = half(n);
        a += a;
    }
}

//半群
template<Multiplication A, Integer N>
A MultiplySemigroup(A a, N n)
{
    while(!odd(a))
    {
        n = half(n);
        a += a;
    }
    if(n == 1)
        return a;
    return multiplyAccumulateSemigroup(a, half(n - 1), a + a);
}

template<Multiplication A, Integer N>
A MultiplyMonid(A a, N n)
{
    if(n == 0)
        return A(0);
    MultiplySemigroup(a, n);
}

template<Multiplication A, Integer N>
A MultiplyGroup(A a, N n)
{
    if(n < 0)
    {
        a = -a;
        n = -n;
    }
    MultiplyMonid(a, n);
}
