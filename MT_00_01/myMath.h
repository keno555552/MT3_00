#pragma once
#include <assert.h>
#include <math.h>
#include <Novice.h>

///by keno v1.1

#pragma region Vector2
typedef struct Vector2 {

	///定義
	float x, y;

	///演算子再定義
	Vector2 operator+(const Vector2& target);
	Vector2 operator-(const Vector2& target);
	Vector2 operator*(const Vector2& target);
	Vector2 operator/(const Vector2& target);
	Vector2 operator*(const float& target);
	friend Vector2 operator*(float scalar, const Vector2& vec);
	Vector2 operator/(const float& target);

	///int
	Vector2 operator*(const int& target);
	friend Vector2 operator*(int scalar, const Vector2& vec);

}Vector2;

#pragma endregion

#pragma region Vector3
typedef struct Vector3 {

	///定義
	float x, y, z;

	///演算子再定義
	Vector3 operator+(const Vector3& target);
	Vector3 operator-(const Vector3& target);
	Vector3 operator*(const Vector3& target);
	Vector3 operator/(const Vector3& target);
	Vector3 operator*(const float& target);
	friend Vector3 operator*(float scalar, const Vector3& vec);
	Vector3 operator/(const float& target);

	///int
	Vector3 operator*(const int& target);
	friend Vector3 operator*(int scalar, const Vector3& vec);

	///ヘルム
	Vector3 helmholtz();
	///正規化
	Vector3 normalize();
}Vector3;

/// ////////////////////////////////for this task

// 加算
Vector3 Add(const Vector3& v1, const Vector3& v2);

// 減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);

// スカラー倍
Vector3 Multiply(const float& scalar, const Vector3& v);

// 内積
float Dot(const Vector3& v1, const Vector3& v2);

// 長さ（ノルム）
float Length(const Vector3& v);

// 正規化
Vector3 Normalize(const Vector3& v);

#pragma endregion

#pragma region Matrix3x3

typedef struct Matrix3x3 {

	///定義
	float m[3][3];

	///演算子再定義
	Matrix3x3 operator+(const Matrix3x3& target);
	Matrix3x3 operator-(const Matrix3x3& target);
	Matrix3x3 operator*(const Matrix3x3& target);

}Matrix3x3;



////////////////////////////////////////////////////////////////////////////陣列表示

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label);

////////////////////////////////////////////////////////////////////////////陣列変換

/// <summary>
/// Vector2からMatrix3x3への変換
/// </summary>
/// <param name="translate">Vector2</param>
/// <returns>結果Matrix3x3</returns>
Matrix3x3 MakeTranslateMatrix3x3(const Vector2 translate);

/// <summary>
/// Matrix3x3からVector2への変換
/// </summary>
/// <param name="translate">Matrix3x3</param>
/// <returns>結果Vector2</returns>
Vector2 MakeTranslateVector2(const Matrix3x3 translate);

////////////////////////////////////////////////////////////////////////////陣列計算

/// <summary>
/// Matrix3x3掛けるVector2
/// </summary>
/// <param name="changeMatrix">変換したいMatrix3x3</param>
/// <param name="vector">Vector2</param>
/// <returns>結果Matrix3x3</returns>
Vector2 Vector2xMatrix3x3(const Vector2 vector, const Matrix3x3 matrix);

/// <summary>
/// 回転行列行列
/// </summary>
/// <param name="theta">回転角度(radian)</param>
/// <returns></returns>
Matrix3x3 MakeRotateMatrix(const float theta);

/// <summary>
/// Matrix3x3の逆行列を探す
/// </summary>
/// <param name="matrix">元のMatrix3x3</param>
/// <returns>結果Matrix3x3</returns>
Matrix3x3 Inverse(Matrix3x3 matrix);

/// <summary>
/// Matrix3x3の転置行列を探す
/// </summary>
/// <param name="matrix">元のMatrix3x3</param>
/// <returns>結果Matrix3x3</returns>
Matrix3x3 Transpose(Matrix3x3 matrix);

////////////////////////////////////////////////////////////////////////////陣列表示

///// <summary>
///// Matrix3x3を描写する
///// </summary>
///// <param name="x">左上のposX</param>
///// <param name="y">左上のposY</param>
///// <param name="matrix">描写したいMatrix3x3</param>
//void MatrixScreenPrintf(int x, int y, Matrix3x3 matrix);

////////////////////////////////////////////////////////////////////////////陣列結合

/// <summary>
/// 使わない、例の結合用関数
/// </summary>
/// <param name="scale"></param>
/// <param name="rotate"></param>
/// <param name="translate"></param>
/// <returns></returns>
Matrix3x3 MakeAffineMatrix(Vector2 scale, float rotate, Vector2 translate);

/// <summary>
/// 二つのMatrix3x3を掛け算する
/// </summary>
/// <param name="matrix1">Matrix3x3 その1</param>
/// <param name="matrix2">Matrix3x3 その2</param>
/// <returns>結果Matrix3x3</returns>
Matrix3x3 MatrixMix(Matrix3x3 matrix1, Matrix3x3 matrix2);

/// <summary>
/// 三つのMatrix3x3を掛け算する
/// </summary>
/// <param name="matrix1">Matrix3x3 その1</param>
/// <param name="matrix2">Matrix3x3 その2</param>
/// <param name="matrix2">Matrix3x3 その3</param>
/// <returns>結果Matrix3x3</returns>
Matrix3x3 MatrixMix(Matrix3x3 matrix1, Matrix3x3 matrix2, Matrix3x3 matrix3);

/// <summary>
/// 四つのMatrix3x3を掛け算する
/// </summary>
/// <param name="matrix1">Matrix3x3 その1</param>
/// <param name="matrix2">Matrix3x3 その2</param>
/// <param name="matrix2">Matrix3x3 その3</param>
/// <param name="matrix2">Matrix3x3 その4</param>
/// <returns>結果Matrix3x3</returns>
Matrix3x3 MatrixMix(Matrix3x3 matrix1, Matrix3x3 matrix2, Matrix3x3 matrix3, Matrix3x3 matrix4);


////////////////////////////////////////////////////////////////////////////world改変陣列

/// <summary>
/// ローカル座標からのワルド座標へ改変
/// </summary>
/// <returns></returns>
Matrix3x3 MakeWorldMatrix(Matrix3x3 origin);

/// <summary>
/// ビュー変換数列生成
/// </summary>
/// <returns></returns>
Matrix3x3 MakeViewMatrix(Matrix3x3 origin, Vector2 pos);

/// <summary>
/// 正射影変換数列生成
/// </summary>
/// <returns></returns>
Matrix3x3 MakeOrthographicMatrix(Vector2 leftTop, Vector2 rightBottom);

/// <summary>
/// ビューポート変換数列生成
/// </summary>
/// <returns></returns>
Matrix3x3 MakeViewportMatrix(Vector2 leftTop, Vector2 rightBottom);

#pragma endregion

#pragma region Other
/// <summary>
/// 二進数比較器
/// </summary>
/// <param name="binary">比較基準</param>
/// <param name="target">目標</param>
/// <returns>=ならtrue</returns>
bool binaryComparator(int binary, int target);

#pragma endregion