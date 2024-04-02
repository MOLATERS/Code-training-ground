#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

// compare的比较函数，相等返回0，大于返回1，小于返回-1
int compare(string str1, string str2){
    int len1 = str1.length();
    int len2 = str2.length();
    if(len1 == len2) return str1.compare(str2);
    return len1 < len2 ? -1 : 1;
}

string add(string str1, string str2){
    string str;
    int len1 = str1.length();
    int len2 = str2.length();
    // 在前面补0，长度维持相同
    if (len1 < len2){
        for(int i = 0; i < len2-len1; i++){
            str1 = "0" + str1;
        }
    }
    else{
        for(int i = 0; i < len1-len2; i++){
            str2 = "0" + str2;
        }
    }
    len1 = str1.length();
    //下面是加法过程
    int cf = 0; //表示进位
    for(int i = len1-1; i >= 0; i--){
        int temp = str1[i] - '0' + str2[i] - '0' + cf;
        cf = temp / 10;
        temp %= 10;
        str = char(temp + '0') + str;
    }
    return str;
}

// 高精度减法 只能是两个正数相减 而且要大减去小
string sub(string str1, string str2){
    string str;
    int len1 = str1.length();
    int len2 = str2.length();
    int cf = 0;
    for(int i = len2-1; i >= 0; i--){
        if(str1[len1-len2+i] < str2[i] + cf){
            str = char(str1[len1-len2 +i] - str2[i] - cf + '0' + 10);
            cf = 1; // 表示借位
        }
        else{
            str = char(str1[len1-len2+i] - str2[i] - cf + '0');
        }
    }
    str.erase(0,str.find_first_not_of('0')); //去除结果中多余的前导0
    return str;
}

// 高精度乘法 只能是两个正数相乘
string mul(string str1, string str2){
    string str;
    int len1 = str1.length();
    int len2 = str2.length();
    string tempstr;
    for(int i = len2 -1 ; i >= 0; i--){
        tempstr = "";
        int temp = str2[i] - '0'; //找到该字符对应的数字
        int t = 0;
        int cf = 0;
        if(temp){
            for(int j = 1; j <len2; j++){
                tempstr += "0";
            }
            for(int j = len1-1; j >= 0; j--){
                t = (temp * (str1[j] - '0') + cf)% 10;
                cf = (temp * (str1[j] - '0') + cf) / 10;
                tempstr = char(t + '0') + tempstr;
            }
            str = add(str,tempstr); // 将当前的结果使用高精度加法相加
        }
    }

    str.erase(0,str.find_first_not_of('0'));
    return str;
}

void div(string str1,string str2,string &quotient,string &residue){
    quotient=residue="";//清空
    if(str2=="0")//判断除数是否为0
    {
        quotient=residue="ERROR";
        return;
    }
    if(str1=="0")//判断被除数是否为0
    {
        quotient=residue="0";
        return;
    }
    int res=compare(str1,str2);
    if(res<0)
    {
        quotient="0";
        residue=str1;
        return;
    }
    else if(res==0)
    {
        quotient="1";
        residue="0";
        return;
    }
    else
    {
        int len1=str1.length();
        int len2=str2.length();
        string tempstr;
        tempstr.append(str1,0,len2-1);
        for(int i=len2-1;i<len1;i++)
        {
            tempstr=tempstr+str1[i];
            tempstr.erase(0,tempstr.find_first_not_of('0'));
            if(tempstr.empty())
              tempstr="0";
            for(char ch='9';ch>='0';ch--)//试商
            {
                string str,tmp;
                str=str+ch;
                tmp=mul(str2,str);
                if(compare(tmp,tempstr)<=0)//试商成功
                {
                    quotient=quotient+ch;
                    tempstr=sub(tempstr,tmp);
                    break;
                }
            }
        }
        residue=tempstr;
    }
    quotient.erase(0,quotient.find_first_not_of('0'));
    if(quotient.empty()) quotient="0";
}

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    cout << sub(str1,str2);
}