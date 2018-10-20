/**
* @file Main.cpp
* @brief "Hello World"を表示するプログラム。
* @date 2018/10/20
* @details "Hello World" と一行に出力する。
*/

#include <cstdio>

using namespace std;

/**
* @brief インターフェース
*/
class IHelloWorld
{
public:
    virtual void sayHello() = 0;
};

/**
* @brief "Hello World"を表示する単純なクラス
*/
class HelloWorld final : public IHelloWorld
{
    typedef IHelloWorld super;

public:
    /**
    * @fn void sayHello()
    * @brief "Hello World"を出力する
    */
    void sayHello();
};

void HelloWorld::sayHello()
{
    printf("%s\n", "Hello World");
}

/**
* @fn bool execute()
* @brief プログラムのコントロール
* @return 常にtrueを返す
*/
bool execute()
{
    HelloWorld().sayHello();

    return true;
}

/**
* @fn int main()
* @brief エントリポイント
*/
int main()
{
    (void) execute();
}
