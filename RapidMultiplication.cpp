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