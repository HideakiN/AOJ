/**
* @file Main.cpp
* @breif １つの整数xを読み込み、xの３乗を計算し出力するプログラム
* @date 2018/10/20
* @details 入力として１つの整数xが与えられる。<br /> 
* 整数xの３乗の計算結果を１行に出力する。<br />
* 入力範囲は以下の通り。<br />
* ・1 <= x <= 100
*/
#include <cstdio>

using namespace std;

/**
* @brief ある整数の３乗を計算する
*/
class XCube
{
private:
    //! 再帰カウンタ
    static const int ThreeTimes = 3;

public:
    /**
    * @fn bool execute(int x, int& response)
    * @brief xの３乗を計算し、計算結果を返す
    * @param[in] x ターゲットデータ
    * @param[out] response 計算結果
    * @return xが範囲内ならtrueを返し、そうでなければfalseを返す
    */
    bool execute(int x, int& response);

private:

    /**
    * @fn int calc(int x, int zan)
    * @brief ある整数の階乗を再帰的に計算する
    * @param[in] x ターゲットデータ
    * @param[in] zan 作業量
    * @return ある整数xのzan乗
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
* @brief データを標準入力から読み込む
* @param[out] input 入力データ
*/
void read(int& input)
{
    scanf("%d", &input);
}

/**
* @fn void write(int output)
* @brief 計算結果を標準出力に書き出す
* @param[in] output 出力データ
*/
void write(int output)
{
    printf("%d\n", output);
}

/**
* @fn int main()
* @brief エントリポイント
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