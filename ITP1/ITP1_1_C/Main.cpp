/**
* @file Main.cpp
* @brief �����`�̖ʐςƎ��̒��������߂�v���O����
* @date 2018/10/20
* @details a��b���P�̋󔒂ŋ�؂��^������B<br />
* �ʐςƎ��̒������P�̋󔒂ŋ�؂��ĂP�s�ɏo�͂���B<br />
* ���͔͈͈͂ȉ��̒ʂ�<br />
*   �E1 <= a, b <= 100
*/
#include <cstdio>

using namespace std;

class Shape
{
public:
    virtual ~Shape() {}

public:
    /**
    * @fn bool execute(int& area, int& round) const
    * @brief �ʐςƎ��̒��������߂�
    * @param[out] area �ʐ�
    * @param[out] round ���̒���
    * @return bool ���͒l���͈͓��Ȃ�true��Ԃ��A�����łȂ����false��Ԃ�
    */
    bool execute(int& area, int& round) const;

protected:
    virtual int getArea() const = 0;

    virtual int getRound() const = 0;

    virtual bool check() const = 0;
};

/**
* @brief �����`�̖ʐςƎ��̒������Ǘ�����
*/
class Rectangle : public Shape
{
private:
    //! �c
    int height;
    //! ��
    int width;

public:
    /**
    * �f�t�H���g�R���X�g���N�^
    */
    Rectangle();

    /**
    * @brief �R���X�g���N�^
    */
    Rectangle(int height, int width);

    /**
    * @brief �f�X�g���N�^
    */
    virtual ~Rectangle() {}

protected:
    /**
    * @fn int getArea() const
    * @brief �ʐς����߂�
    * @return �ʐ�
    */
    int getArea() const;

    /**
    * @fn int getRound() const
    * @brief ���̒��������߂�
    * @return ���̒���
    */
    int getRound() const;

    /**
    * @fn bool check() const
    * @brief ���͔͈͂��`�F�b�N����
    * @return ���͔͈͓��Ȃ�true��Ԃ��A�����łȂ����false��Ԃ�
    */
    bool check() const;
};

bool Shape::execute(int& area, int& round) const
{
    if (!check())
        return false;

    area = getArea();

    round = getRound();

    return true;
}

Rectangle::Rectangle()
    : height(0)
    , width(0)
{
}

Rectangle::Rectangle(int height, int width)
    : height(height)
    , width(width)
{
}

int Rectangle::getArea() const
{
    return height * width;
}

int Rectangle::getRound() const
{
    return (height + width) * 2;
}

bool Rectangle::check() const
{
    const int Min = 1;
    const int Max = 100;

    if (Min > height || Max < height &&
        Min > width || Max < width)
        return false;

    return true;
}

/**
* @fn void read(int a, int b)
* @brief ���͒l��ǂݍ���
* @param[out] a �c
* @param[out] b ��
*/
static void read(int& a, int& b)
{
    scanf("%d %d", &a, &b);
}

/**
* @fn void write(int a, int b)
* @brief �v�Z���ʂ��o�͂���
*/
static void write(int a, int b)
{
    printf("%d %d\n", a, b);
}

/**
* @fn bool control()
* @brief ���͒l���璷���`�̖ʐςƎ��̒��������߁A�o�͂���
* @return bool ���͔͈͓��Ȃ�true��Ԃ��A�����łȂ����false��Ԃ�
*/
static bool control()
{
    int a = 0;
    int b = 0;
    int area = 0;
    int round = 0;

    read(a, b);

    Shape* shape = new Rectangle(a, b);

    if (!shape->execute(area, round))
        return false;

    write(area, round);

    delete shape;

    shape = NULL;

    return true;
}

int main()
{
    if (!control())
        return 1;
}