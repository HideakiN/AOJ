/**
* @file Main.cpp
* @breif �P�̐���x��ǂݍ��݁Ax�̂R����v�Z���o�͂���v���O����
* @date 2018/10/20
* @details ���͂Ƃ��ĂP�̐���x���^������B
*          ����x�̂R��̌v�Z���ʂ��P�s�ɏo�͂���B
*          ���͔͈͈͂ȉ��̒ʂ�B
*          �@�E1 <= x <= 100
*/
#include <cstdio>

using namespace std;

/**
* @brief ���鐮�����R����v�Z����
*/
class XCube
{
private:
    //! �ċA�J�E���^
    static const int ThreeTimes = 3;

public:
    /**
    * @fn bool execute(int x, int& response)
    * @brief �v���O�����̃R���g���[��
    * @param[in] x �^�[�Q�b�g�f�[�^
    * @param[out] response �v�Z����
    * @return x���͈͓��Ȃ�true��Ԃ��A�����łȂ����false��Ԃ�
    */
    bool execute(int x, int& response);

private:
    /**
    * @fn int calc(int x, int zan)
    * @brief ���鐮���̂R����v�Z����
    * @param[in] x �^�[�Q�b�g�f�[�^
    * @param[in] zan ��Ɨ�
    * @return ���鐮��x��zan���Ԃ�
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
    if (zan <= 1)
        return x;

    return x * calc(x, zan - 1);
}

/**
* @fn int main()
* @brief �G���g���|�C���g
*/
int main()
{
    int input = 0;
    int output = 0;

    scanf("%d", &input);

    bool rc = XCube().execute(input, output);
    if (!rc)
        return 1;

    printf("%d\n", output);
}