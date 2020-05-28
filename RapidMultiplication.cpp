// 看到的一个有趣的计算乘法的方法
// m 为偶数时 m * n = (m / 2) * (n * 2) 
// m 为奇数时 m * n = (m / 2) * (n * 2) + n
int RapidMulti(int n, int num)
{
    if(n == 1)
        return num;
    int result = RapidMulti(n >> 1, num << 1);
    if(n & 0x01)
        result += num;
    return result;
}

int RapidMulti_1(int r, int n, int num)
{
    //尾递归版本
    // r 实际类似余数，就是把m 为奇数时的那个额外加的n 给带进下一次的递归
    if(n == 1)
        return r + num;
    if(n & 0x01)
        return RapidMulti_1(r + num, n >> 1, num << 1);
    else
        return RapidMulti_1(r, n >> 1, num << 1);

}

int RapidMulti_2(int r, int n, int num)
{
    // 比 1 计算速度稍快些
    if(n == 1)
        return r + num;
    if(n & 0x01)
        r += num;
    return RapidMulti_2(r, n >> 1, num << 1);
}

int RapidMulti_3(int r, int n, int num)
{
    // 考虑到n取到1是比较少的，而n 为偶数时没有必要进行== 1 的判定
    if(n & 0x01)
    {
        r += num;
        if(n == 1)
            return r;
    }
    return RapidMulti_3(r, n >> 1, num << 1);
}

int RapidMulti_4(int r, int n, int num)
{
    while(n != 0x01)
    {
        if(n & 0x01)
            r += num;
        num <<= 1;
        n >>= 1;
    }
    return r + num;
}
