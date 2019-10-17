//瀛愮被鐖剁被涓殑鏋愭瀯涓庢瀯閫?

//缁ф壙涓殑鏋勯�犲拰鏋愭瀯
#include <iostream>
using namespace std;
//先调用父类构造函数，再调用子类的构造函数
//析构顺序相反
//绫诲瀷鍏煎鍘熷垯

class Parent
{
private:
    int a, b;

public:
    Parent(int a, int b)
    {
        this->a = a;
        this->b = b;
        printf("父类构造函数 \n");
    };
    ~Parent()
    {
        printf("父类析构函数函数 \n");
    };
    void print(int a, int b)
    {
        this->a = a;
        this->b = b;
        printf("我是爹 \n");
    };
};

class child : public Parent
{
public:
    child(int a, int b, int c) : Parent(a, b)
    {
        this->c = c;
        cout << "子类构造函数" << endl;
    }
    ~child()
    {
        cout << "子类析构函数" << endl;
    }
    void printC()
    {
        printf("杩欐槸鍎垮瓙");
    };

private:
    int c;
};
void playobj()
{
    child c1(1, 2, 3);
}
int main()
{
    //  Parent p(1, 2);
    playobj();
    system("pause");
    return 0;
}
