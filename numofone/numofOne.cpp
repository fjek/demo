class Solution
{
private:
    /* data */
public:
    int numofOne(int n);
    ~Solution();
};

int Solution::numofOne(int n)
{
    if (n < 1){
        return -1;
    }

    int ret = 0;
    int base = 10;
    int round = n;
    int weight;
    while (round > 0) {
        weight = round % 10;
        round = round / 10;
        ret += round * base;
        if (weight ==1) {
            ret += (n % base) +1;
        }else if(weight > 1){
            ret += base;
        }
        base *= 10;
    }
}

Solution::~Solution()
{
}
