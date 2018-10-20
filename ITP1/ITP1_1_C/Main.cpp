/**
* @file Main.cpp
* @brief 長方形の面積と周の長さを求めるプログラム
* @date 2018/10/20
* @details aとbが１つの空白で区切られ与えられる。<br />
* 面積と周の長さを１つの空白で区切って１行に出力する。<br />
* 入力範囲は以下の通り<br />
*   ・1 <= a, b <= 100
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
    * @brief 面積と周の長さを求める
    * @param[out] area 面積
    * @param[out] round 周の長さ
    * @return bool 入力値が範囲内ならtrueを返し、そうでなければfalseを返す
    */
    bool execute(int& area, int& round) const;

protected:
    virtual int getArea() const = 0;

    virtual int getRound() const = 0;

    virtual bool check() const = 0;
};

/**
* @brief 長方形の面積と周の長さを管理する
*/
class Rectangle : public Shape
{
private:
    //! 縦
    int height;
    //! 横
    int width;

public:
    /**
    * デフォルトコンストラクタ
    */
    Rectangle();

    /**
    * @brief コンストラクタ
    */
    Rectangle(int height, int width);

    /**
    * @brief デストラクタ
    */
    virtual ~Rectangle() {}

protected:
    /**
    * @fn int getArea() const
    * @brief 面積を求める
    * @return 面積
    */
    int getArea() const;

    /**
    * @fn int getRound() const
    * @brief 周の長さを求める
    * @return 周の長さ
    */
    int getRound() const;

    /**
    * @fn bool check() const
    * @brief 入力範囲をチェックする
    * @return 入力範囲内ならtrueを返し、そうでなければfalseを返す
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
* @brief 入力値を読み込む
* @param[out] a 縦
* @param[out] b 横
*/
static void read(int& a, int& b)
{
    scanf("%d %d", &a, &b);
}

/**
* @fn void write(int a, int b)
* @brief 計算結果を出力する
*/
static void write(int a, int b)
{
    printf("%d %d\n", a, b);
}

/**
* @fn bool control()
* @brief 入力値から長方形の面積と周の長さを求め、出力する
* @return bool 入力範囲内ならtrueを返し、そうでなければfalseを返す
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