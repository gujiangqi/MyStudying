#include <stack>
#include <cstdlib>
#include <iostream>
using namespace  std;

int main()
{
    stack<int> st;
    //先进后出的容器，所以只能从末尾进行操作
    //所以stack的存取可以称为 出入 栈
    st.push(1);
    st.push(2);
    st.push(3);
    size_t iSize = st.size();
    
}  
