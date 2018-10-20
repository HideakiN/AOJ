/**
* @file Main.cpp
* @breif �P�̐���x��ǂݍ��݁Ax�̂R����v�Z���o�͂���v���O����
* @date 2018/10/20
* @details ���͂Ƃ��ĂP�̐���x���^������B<br /> 
* ����x�̂R��̌v�Z���ʂ��P�s�ɏo�͂���B<br />
* ���͔͈͈͂ȉ��̒ʂ�B<br />
* �E1 <= x <= 100
*/
#include <cstdio>

using namespace std;

/**
* @brief ���鐮���̂R����v�Z����
*/
class XCube
{
private:
    //! �ċA�J�E���^
    static const int ThreeTimes = 3;

public:
    /**
    * @fn bool execute(int x, int& response)
    * @brief x�̂R����v�Z���A�v�Z���ʂ�Ԃ�
    * @param[in] x �^�[�Q�b�g�f�[�^
    * @param[out] response �v�Z����
    * @return x���͈͓��Ȃ�true��Ԃ��A�����łȂ����false��Ԃ�
    */
    bool execute(int x, int& response);

private:

    /**
    * @fn int calc(int x, int zan)
    * @brief ���鐮���̊K����ċA�I�Ɍv�Z����
    * @param[in] x �^�[�Q�b�g�f�[�^
    * @param[in] zan ��Ɨ�
    * @return ���鐮��x��zan��
    */
    int calc(int x, int zan);
};

const int XCube::ThreeTimes;

bool XCube::execute(int x, int& response)
{
    const int Min = 1;
    const int Max = 100;
    if (Min > x || Max < x)
        return false;

    response = calc(x, ThreeTimes);

    return true;
}

int XCube::calc(int x, int zan)
{
    if (zan <= 0)
        return 1;

    return x * calc(x, zan - 1);
}

/**
* @fn void read(int& input)
* @brief �f�[�^��W�����͂���ǂݍ���
* @param[out] input ���̓f�[�^
*/
void read(int& input)
{
    scanf("%d", &input);
}

/**
* @fn void write(int output)
* @brief �v�Z���ʂ�W���o�͂ɏ����o��
* @param[in] output �o�̓f�[�^
*/
void write(int output)
{
    printf("%d\n", output);
}

/**
* @fn int main()
* @brief �G���g���|�C���g
*/
int main()
{
    int input = 0;
    int output = 0;

    read(input);

    if (!XCube().execute(input, output))
        return 1;

    write(output);
}