/**
* @file Main.cpp
* @brief "Hello World"��\������v���O�����B
* @date 2018/10/20
* @details "Hello World" �ƈ�s�ɏo�͂���B
*/

#include <cstdio>

using namespace std;

/**
* @brief �C���^�[�t�F�[�X
*/
class IHelloWorld
{
public:
    virtual void sayHello() = 0;
};

/**
* @brief "Hello World"��\������P���ȃN���X
*/
class HelloWorld final : public IHelloWorld
{
    typedef IHelloWorld super;

public:
    /**
    * @fn void sayHello()
    * @brief "Hello World"���o�͂���
    */
    void sayHello();
};

void HelloWorld::sayHello()
{
    printf("%s\n", "Hello World");
}

/**
* @fn bool execute()
* @brief �v���O�����̃R���g���[��
* @return ���true��Ԃ�
*/
bool execute()
{
    HelloWorld().sayHello();

    return true;
}

/**
* @fn int main()
* @brief �G���g���|�C���g
*/
int main()
{
    (void) execute();
}
