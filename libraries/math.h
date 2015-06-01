/*
	TODO: Finish this
*/

void AngleVectors(const QAngle& angles, Vector *forward);
void AngleVectors(const QAngle& angles, Vector *forward, Vector *right, Vector *up);
void AngleVectorsTranspose(const QAngle& angles, Vector *forward, Vector *right, Vector *up);
void VectorAngles(const Vector &forward, QAngle &angles);
void VectorAngles(const Vector &forward, const Vector &pseudoup, QAngle &angles);
void VectorMatrix(const Vector &forward, matrix3x4_t &mat);
void VectorVectors(const Vector &forward, Vector &right, Vector &up);
void SetIdentityMatrix(matrix3x4_t &mat);
void SetScaleMatrix(float x, float y, float z, matrix3x4_t &dst);
void MatrixBuildRotationAboutAxis(const Vector &vAxisOfRot, float angleDegrees, matrix3x4_t &dst);
void VectorTransform(class Vector const &, struct matrix3x4_t const &, class Vector &);
void MatrixAngles(const matrix3x4_t& matrix, QAngle &angles, Vector &position);
void MatrixAngles(const matrix3x4_t& matrix, RadianEuler &angles, Vector &position);
void MatrixAngles(const matrix3x4_t& matrix, Angle &angles, Vector &position)
{
	RadianEuler NewAngles;
	NewAngles.x = angles.x;
	NewAngles.y = angles.y;
	NewAngles.z = angles.z;
	MatrixAngles( matrix, NewAngles, position );
}
#pragma comment(lib, "mathlib.lib")
