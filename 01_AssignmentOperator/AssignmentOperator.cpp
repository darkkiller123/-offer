/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题1：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。
// 思考点，这里没能做到线程安全 - - 

#include<cstring>
#include<cstdio>

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);

    void Print();
      
private:
    char* m_pData;
};

// 如果穿入为空，那么搞一个'\0'出来
// 否则申请length+1再将数据拷贝过来
CMyString::CMyString(char *pData)
{
    if(pData == nullptr)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

// 拷贝构造函数
// 直接复制
CMyString::CMyString(const CMyString &str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

// 释放
CMyString::~CMyString()
{
    delete[] m_pData;
}

// 赋值运算符重载运算 三部曲，防止自拷贝 释放内存 申请内存 拷贝
// 为什么要返回自己的引用---->解决连续赋值问题
// str3 = str2 = str1 
// 实际等价于
// tmp_res = fun(str2, str1)
// tmp_res2 = fun(str3, tmp_res)
// 懂了吧。。。
CMyString& CMyString::operator = (const CMyString& str)
{
    // 防止自拷贝
    if(this == &str)
        return *this;

    // 释放内存
    delete []m_pData;
    // 释放完内存后都要习惯性将指针置空，这只是比较良好的编程风格。
    m_pData = nullptr;

    // 申请内存
    m_pData = new char[strlen(str.m_pData) + 1];

    // 拷贝内容
    strcpy(m_pData, str.m_pData);

    return *this;
}

// ====================测试代码====================
void CMyString::Print()
{
    printf("%s", m_pData);
}

void Test1()
{
    printf("Test1 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

// 赋值给自己
void Test2()
{
    printf("Test2 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}

// 连续赋值
void Test3()
{
    printf("Test3 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}

