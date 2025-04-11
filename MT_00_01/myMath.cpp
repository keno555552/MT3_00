#include "myMath.h"

#pragma region Vector2
Vector2 Vector2::operator+(const Vector2& target)
{
	return { x + target.x, y + target.y };
}

Vector2 Vector2::operator-(const Vector2& target)
{
	return { x - target.x, y - target.y };
}

Vector2 Vector2::operator*(const Vector2& target)
{
	return { x * target.x, y * target.y };
}

Vector2 Vector2::operator/(const Vector2& target)
{
	return { x / target.x, y / target.y };
}

Vector2 Vector2::operator*(const float& target)
{
	return { x * target, y * target };
}

Vector2 operator*(float scalar, const Vector2& vec)
{
	return { vec.x * scalar, vec.y * scalar };
}

Vector2 Vector2::operator/(const float& target)
{
	return { x / target, y / target };
}



Vector2 Vector2::operator*(const int& target)
{
	return { x * (float)target, y * (float)target };
}

Vector2 operator*(int scalar, const Vector2& vec)
{
	return { vec.x * (float)scalar, vec.y * (float)scalar };
}
#pragma endregion

#pragma region Vector3
Vector3 Vector3::operator+(const Vector3& target)
{
	return { x + target.x, y + target.y , z + target.z };
}

Vector3 Vector3::operator-(const Vector3& target)
{
	return { x - target.x, y - target.y , z - target.z };
}

Vector3 Vector3::operator*(const Vector3& target)
{
	return { x * target.x, y * target.y };
}

Vector3 Vector3::operator/(const Vector3& target)
{
	return { x / target.x, y / target.y, z / target.z };
}

Vector3 Vector3::operator*(const float& target)
{
	return { x * target, y * target, z * target };
}

Vector3 operator*(float scalar, const Vector3& vec)
{
	return { vec.x * scalar, vec.y * scalar, vec.z * scalar };
}

Vector3 Vector3::operator/(const float& target)
{
	return { x / target, y / target, z / target };
}



Vector3 Vector3::operator*(const int& target)
{
	return { x * (float)target, y * (float)target, z * (float)target };
}


Vector3 operator*(int scalar, const Vector3& vec)
{
	return { vec.x * (float)scalar, vec.y * (float)scalar , vec.z * (float)scalar };
}

Vector3 Vector3::helmholtz()
{
	//return { sqrtf(x * x + sqrtf(y * y + z * z)) };
	//return { sqrtf(x * x + y * y + z * z) };
	return { sqrtf(x * x),sqrtf(y * y),sqrtf(z * z)};
}

Vector3 Vector3::normalize()
{
	Vector3 length = helmholtz();
	if (length.x != 0 && length.y != 0 && length.z != 0) {
		return { x / length.x, y / length.y, z / length.z };
	}
	return Vector3();
}

///for this task

Vector3 Add(const Vector3& V1, const Vector3& V2) {
	return { V1.x + V2.x, V1.y + V2.y , V1.z + V2.z };
}

Vector3 Subtract(const Vector3& V1, const Vector3& V2) {
	return { V1.x - V2.x, V1.y - V2.y , V1.z - V2.z };
}

Vector3 Multiply(const float& scalar, const Vector3& v) {
	return { scalar * v.x, scalar * v.y, scalar * v.z };
}

float Dot(const Vector3& V1, const Vector3& V2) {
	return V1.x * V2.x + V1.y * V2.y + V1.z * V2.z;
}

float Length(const Vector3& v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector3 Normalize(const Vector3& v) {
	float length = Length(v);
	if (length != 0) {
		return { v.x / length, v.y / length, v.z / length };
	}
	return Vector3();
}

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	static const int kColumnWidth = 60;
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}


#pragma endregion

#pragma region Matrix3x3
Matrix3x3 Matrix3x3::operator+(const Matrix3x3& target)
{
	Matrix3x3 resuit = {};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			resuit.m[i][j] = m[i][j] + target.m[i][j];
		}
	}

	return resuit;
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3& target)
{
	Matrix3x3 resuit = {};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			resuit.m[i][j] = m[i][j] - target.m[i][j];
		}
	}

	return resuit;
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& target)
{
	Matrix3x3 result = {};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				result.m[i][j] += m[i][k] * target.m[k][j];
			}
		}
	}
	return result;
}



////////////////////////////////////////////////////////////////////////////陣列変換

Matrix3x3 MakeTranslateMatrix3x3 (const Vector2 translate) {
	return { 1,0,0,
			 0,1,0,
			  translate.x,translate.y,1 };
}

Vector2 MakeTranslateVector2(const Matrix3x3 translate) {
	return { translate.m[2][0],translate.m[2][1] };
}

////////////////////////////////////////////////////////////////////////////陣列計算

Vector2 Vector2xMatrix3x3(const Vector2 vector, const Matrix3x3 matrix) {
	Vector2 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	float w = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	return result;
}

Matrix3x3 MakeRotateMatrix(const float theta) {
	return{ cosf(theta) ,sinf(theta),0,
			-sinf(theta),cosf(theta),0,
			0,0,1 };
}

Matrix3x3 Inverse(Matrix3x3 matrix) {
	float determinant = (matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] +
		matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0] +
		matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1])
		-
		(matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0] +
			matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2] +
			matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1]);

	return Matrix3x3{ (matrix.m[1][1] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][1]) / determinant,
					 -(matrix.m[0][1] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][1]) / determinant,
					  (matrix.m[0][1] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][1]) / determinant,

					 -(matrix.m[1][0] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][0]) / determinant,
					  (matrix.m[0][0] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][0]) / determinant,
					 -(matrix.m[0][0] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][0]) / determinant,

					  (matrix.m[1][0] * matrix.m[2][1] - matrix.m[1][1] * matrix.m[2][0]) / determinant,
					 -(matrix.m[0][0] * matrix.m[2][1] - matrix.m[0][1] * matrix.m[2][0]) / determinant,
					  (matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0]) / determinant };
}


Matrix3x3 Transpose(Matrix3x3 matrix) {

	return Matrix3x3{ matrix.m[0][0],matrix.m[1][0],matrix.m[2][0],
					  matrix.m[0][1],matrix.m[1][1],matrix.m[2][1],
					  matrix.m[0][2],matrix.m[1][2],matrix.m[2][2] };
}

////////////////////////////////////////////////////////////////////////////陣列表示

//void MatrixScreenPrintf(int x, int y, Matrix3x3 matrix) {
//	int kColumnWidth = 80;
//	int kRowHeight = 40;
//	for (int row = 0; row < 3; ++row) {
//		for (int column = 0; column < 3; ++column) {
//			Novice::ScreenPrintf(
//				x + column * kColumnWidth,
//				y + row * kRowHeight,
//				"%.02f",
//				matrix.m[row][column]
//			);
//		}
//	}
//}

////////////////////////////////////////////////////////////////////////////陣列結合

Matrix3x3 MakeAffineMatrix(Vector2 scale, float rotate, Vector2 translate) {
	return { scale.x * cosf(rotate),scale.x * sinf(rotate),0,
			 -scale.y * sinf(rotate),scale.y * cosf(rotate),0,
			  translate.x,translate.y,1 };
}

Matrix3x3 MatrixMix(Matrix3x3 matrix1, Matrix3x3 matrix2)
{
	Matrix3x3 result = matrix1 * matrix2;
	return result;
}

Matrix3x3 MatrixMix(Matrix3x3 matrix1, Matrix3x3 matrix2, Matrix3x3 matrix3)
{
	Matrix3x3 result = matrix1 * matrix2 * matrix3;
	return result;
}

Matrix3x3 MatrixMix(Matrix3x3 matrix1, Matrix3x3 matrix2, Matrix3x3 matrix3, Matrix3x3 matrix4)
{
	Matrix3x3 result = matrix1 * matrix2 * matrix3 * matrix4;
	return result;
}

////////////////////////////////////////////////////////////////////////////world改変陣列

Matrix3x3 MakeWorldMatrix(Matrix3x3 origin) {
	return origin;
}

Matrix3x3 MakeViewMatrix(Matrix3x3 origin, Vector2 pos)
{
	Vector2 move = pos;
	Matrix3x3 move2 = MakeTranslateMatrix3x3(move);
	Matrix3x3 result = MatrixMix(origin, move2);
	return Inverse(result);
}

Matrix3x3 MakeOrthographicMatrix(Vector2 leftTop, Vector2 rightBottom)
{
	return{ 2.0f / (rightBottom.x - leftTop.x),0.0f,0.0f,
			0.0f,2.0f / (leftTop.y - rightBottom.y),0.0f,
			(leftTop.x + rightBottom.x) / (leftTop.x - rightBottom.x),(leftTop.y + rightBottom.y) / (rightBottom.y - leftTop.y),1.0f };
}

Matrix3x3 MakeViewportMatrix(Vector2 leftTop, Vector2 rightBottom)
{
	return{ rightBottom.x / 2.0f,0.0f,0.0f,
			0.0f,-(rightBottom.y / 2.0f),0.0f,
			leftTop.x + (rightBottom.x / 2.0f),leftTop.y + (rightBottom.y / 2.0f),1.0f };
}
#pragma endregion

#pragma region Other
bool binaryComparator(int binary, int target) {
	if (binary == (target & binary)) {
		return true;
	}
	return false;
}
#pragma endregion