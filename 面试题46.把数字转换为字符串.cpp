
class Solution {
public:
    int translateNum(int num) {//滚动数组
        string src = to_string(num);//转换为字符串
        int p = 0, q = 0, r = 1;
        for (int i = 0; i < src.size(); ++i) {
            p = q; //p存储上一次的q,即p存储上上次的r
            q = r; //q存储上一次的r
            r = 0;//r归零
            //相当于r=q，而q存储的是上一次的r，即r等于上一次的r；而上一次的r有可能累加了p（即上上次的r），也有可能仅来自于上一次的q（即上次的r）
            r += q;
            std::cout<<"r=="<<r<<std::endl;
            if (i == 0) {
                continue;
            }
            auto pre = src.substr(i - 1, 2);
            if (pre <= "25" && pre >= "10") {//字符串直接比较大小
            //只增加数量，不用存储具体形式   
            //当25满足条件时，r=3，p=2，,r+=p->5,此时p代表前一个子字符串的翻译种数，f(i)=f(i−1)+f(i−2)[i−1≥0,10≤x≤25]
            //current_r = last_r->current_q + current_p;
            //current_p = last_q;   last_q = last_last_r;
            //current_r = last_r + last_last_r;
            //如果当前数字不存在不同翻译，即pre >= 25,则current_r = last_r;
                r += p;
                std::cout<<"r="<<r<<std::endl;
            }
        }
        return r;
    }
};