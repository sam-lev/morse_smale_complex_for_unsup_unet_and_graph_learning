#ifndef FLTK_ARITHMETIC
#define FLTK_ARITHMETIC


#define PI 3.14159

namespace FLTK_ARITH {

	inline float ToRadians(float degrees) {
		return degrees * PI / 180;
	};

	inline float ToDegrees(float radians) {
		return radians * 180.0 / PI;
	};

	struct Matrix4 {
		float vals[16];
	};

	struct Vector4 {
		float vals[4];
	};
	//
	//struct Quaternion4 {
	//	float vals[4];
	//};

	float Dot3(Vector4 A, Vector4 B) {
		return A.vals[0]*B.vals[0] +A.vals[1]*B.vals[1] +A.vals[2]*B.vals[2];
	}; 

	float InteriorAngle(Vector4 A, Vector4 B) {
		return ToDegrees(acos(Dot3(A,B)));
	}; 

	int Normalize3(Vector4* v) {
		float denom = v->vals[0] * v->vals[0] + v->vals[1] * v->vals[1] + v->vals[2] * v->vals[2];
		if (denom == 0.0) return 0;
		denom = 1.0 / sqrt(denom);
		v->vals[0] *= denom;
		v->vals[1] *= denom;
		v->vals[2] *= denom;
		return 1;
	};

	void Normalize4(Vector4* v) {
		float denom = v->vals[0] * v->vals[0] + v->vals[1] * v->vals[1] + v->vals[2] * v->vals[2] + v->vals[3] * v->vals[3];
		denom = sqrt(denom);
		if (denom == 0.0) return;
		v->vals[0] /= denom;
		v->vals[1] /= denom;
		v->vals[2] /= denom;
		v->vals[3] /= denom;
	};



	Vector4 Cross(Vector4 a, Vector4 b) {
		Vector4 c;
		c.vals[0] = a.vals[1]*b.vals[2] - a.vals[2]*b.vals[1];
		c.vals[1] = a.vals[2]*b.vals[0] - a.vals[0]*b.vals[2];
		c.vals[2] = a.vals[0]*b.vals[1] - a.vals[1]*b.vals[0];
		c.vals[3] = 0;
		return c;

	};




	inline Vector4 GMVMf(Matrix4 mat, Vector4 vect) {
		Vector4 res;
		res.vals[0] = mat.vals[0]*vect.vals[0] + mat.vals[1]*vect.vals[1] + mat.vals[2]*vect.vals[2] + mat.vals[3]*vect.vals[3];
		res.vals[1] = mat.vals[4]*vect.vals[0] + mat.vals[5]*vect.vals[1] + mat.vals[6]*vect.vals[2] + mat.vals[7]*vect.vals[3];
		res.vals[2] = mat.vals[8]*vect.vals[0] + mat.vals[9]*vect.vals[1] + mat.vals[10]*vect.vals[2] + mat.vals[11]*vect.vals[3];
		res.vals[3] = mat.vals[12]*vect.vals[0] + mat.vals[13]*vect.vals[1] + mat.vals[14]*vect.vals[2] + mat.vals[15]*vect.vals[3];
		return res;
	};

	inline Matrix4 GMMMf(Matrix4 A, Matrix4 B) {
		Matrix4 C;
		C.vals[0] = A.vals[ 0]*B.vals[ 0] + A.vals[ 1]*B.vals[ 4] + A.vals[ 2]*B.vals[ 8] + A.vals[ 3]*B.vals[12];
		C.vals[1] = A.vals[ 0]*B.vals[ 1] + A.vals[ 1]*B.vals[ 5] + A.vals[ 2]*B.vals[ 9] + A.vals[ 3]*B.vals[13];
		C.vals[2] = A.vals[ 0]*B.vals[ 2] + A.vals[ 1]*B.vals[ 6] + A.vals[ 2]*B.vals[10] + A.vals[ 3]*B.vals[14];
		C.vals[3] = A.vals[ 0]*B.vals[ 3] + A.vals[ 1]*B.vals[ 7] + A.vals[ 2]*B.vals[11] + A.vals[ 3]*B.vals[15];

		C.vals[4] = A.vals[ 4]*B.vals[ 0] + A.vals[ 5]*B.vals[ 4] + A.vals[ 6]*B.vals[ 8] + A.vals[ 7]*B.vals[12];
		C.vals[5] = A.vals[ 4]*B.vals[ 1] + A.vals[ 5]*B.vals[ 5] + A.vals[ 6]*B.vals[ 9] + A.vals[ 7]*B.vals[13];
		C.vals[6] = A.vals[ 4]*B.vals[ 2] + A.vals[ 5]*B.vals[ 6] + A.vals[ 6]*B.vals[10] + A.vals[ 7]*B.vals[14];
		C.vals[7] = A.vals[ 4]*B.vals[ 3] + A.vals[ 5]*B.vals[ 7] + A.vals[ 6]*B.vals[11] + A.vals[ 7]*B.vals[15];

		C.vals[8] = A.vals[ 8]*B.vals[ 0] + A.vals[ 9]*B.vals[ 4] + A.vals[10]*B.vals[ 8] + A.vals[11]*B.vals[12];
		C.vals[9] = A.vals[ 8]*B.vals[ 1] + A.vals[ 9]*B.vals[ 5] + A.vals[10]*B.vals[ 9] + A.vals[11]*B.vals[13];
		C.vals[10] = A.vals[ 8]*B.vals[ 2] + A.vals[ 9]*B.vals[ 6] + A.vals[10]*B.vals[10] + A.vals[11]*B.vals[14];
		C.vals[11] = A.vals[ 8]*B.vals[ 3] + A.vals[ 9]*B.vals[ 7] + A.vals[10]*B.vals[11] + A.vals[11]*B.vals[15];

		C.vals[12] = A.vals[12]*B.vals[ 0] + A.vals[13]*B.vals[ 4] + A.vals[14]*B.vals[ 8] + A.vals[15]*B.vals[12];
		C.vals[13] = A.vals[12]*B.vals[ 1] + A.vals[13]*B.vals[ 5] + A.vals[14]*B.vals[ 9] + A.vals[15]*B.vals[13];
		C.vals[14] = A.vals[12]*B.vals[ 2] + A.vals[13]*B.vals[ 6] + A.vals[14]*B.vals[10] + A.vals[15]*B.vals[14];
		C.vals[15] = A.vals[12]*B.vals[ 3] + A.vals[13]*B.vals[ 7] + A.vals[14]*B.vals[11] + A.vals[15]*B.vals[15];
		return C;
	};

	Matrix4 Translate3f(float x, float y, float z) {
		Matrix4 C;
		C.vals[0] = x; C.vals[1] = 0; C.vals[2] = 0; C.vals[3] = 0;
		C.vals[4] = 0; C.vals[5] = y; C.vals[6] = 0; C.vals[7] = 0;
		C.vals[8] = 0; C.vals[9] = 0; C.vals[10] = z; C.vals[11] = 0;
		C.vals[12] = 0; C.vals[13] = 0; C.vals[14] = 0; C.vals[15] = 1;
		return C;
	};

	Matrix4 GMSMf(Matrix4 A, float b) {
		for (int i = 0; i < 16; i++) A.vals[i] *= b;
		return A;
	};

	Matrix4 GMMAf(Matrix4 A, Matrix4 B) {
		for (int i = 0; i < 16; i++) A.vals[i] += B.vals[i];
		return A;
	};

	Matrix4 MIdentity() {
		Matrix4 C;
		C.vals[0] = 1; C.vals[1] = 0; C.vals[2] = 0; C.vals[3] = 0;
		C.vals[4] = 0; C.vals[5] = 1; C.vals[6] = 0; C.vals[7] = 0;
		C.vals[8] = 0; C.vals[9] = 0; C.vals[10] = 1; C.vals[11] = 0;
		C.vals[12] = 0; C.vals[13] = 0; C.vals[14] = 0; C.vals[15] = 1;
		return C;
	};


	// rotate around UNIT vect a around origin, alpha degrees
	Matrix4 RoatateAVO(float alpha, Vector4 a) {
		Matrix4 I = MIdentity();
		Matrix4 A;
		A.vals[0] = 0;           A.vals[1] = -a.vals[2]; A.vals[2] = a.vals[1];  A.vals[3] = 0;
		A.vals[4] = a.vals[2];   A.vals[5] = 0;          A.vals[6] = -a.vals[0]; A.vals[7] = 0;
		A.vals[8] = -a.vals[1];  A.vals[9] = a.vals[0];  A.vals[10] = 0;         A.vals[11] = 0;
		A.vals[12] = 0;          A.vals[13] = 0;         A.vals[14] = 0;         A.vals[15] = 1;

		Matrix4 A2 = GMMMf(A, A);
		alpha = ToRadians(alpha);
		return GMMAf(I, GMMAf(GMSMf(A,sin(alpha)), GMSMf(A2,(1-cos(alpha)))));
	};

	struct Quat {
		float x, y, z, w;
	};

	Quat times(Quat a, Quat b) {
		Quat res;
		res.w = a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z;
		res.x = a.w*b.x + a.x*b.w + a.y*b.z - a.z*b.y;
		res.y = a.w*b.y - a.x*b.z + a.y*b.w + a.z*b.x;
		res.z = a.w*b.z + a.x*b.y - a.y*b.x + a.z*b.w;
		return res;
	}

	Quat rotation(Vector4 v, float angle) {
		Quat res;
		Normalize3(&v);
		res.w = cosf(angle/2.0);
		float tmp = sinf(angle/2.0);
		res.x = v.vals[0] * tmp;
		res.y = v.vals[1] * tmp;
		res.z = v.vals[2] * tmp;
		return res;
	}

	Matrix4 rotmatrix;
	Quat rotationtotal;
	void resetQuat(Quat &q) {
		q.x = 0;
		q.y = 0;
		q.z = 0;
		q.w = 1;
	}

	void setRotQuat(Matrix4 &m, Quat &q){
		{
			float x2 = 2.0f * q.x,  y2 = 2.0f * q.y,  z2 = 2.0f * q.z;

			float xy = x2 * q.y,  xz = x2 * q.z;
			float yy = y2 * q.y,  yw = y2 * q.w;
			float zw = z2 * q.w,  zz = z2 * q.z;

			m.vals[ 0] = 1.0f - ( yy + zz );
			m.vals[ 1] = ( xy - zw );
			m.vals[ 2] = ( xz + yw );
			m.vals[ 3] = 0.0f;

			float xx = x2 * q.x,  xw = x2 * q.w,  yz = y2 * q.z;

			m.vals[ 4] = ( xy +  zw );
			m.vals[ 5] = 1.0f - ( xx + zz );
			m.vals[ 6] = ( yz - xw );
			m.vals[ 7] = 0.0f;

			m.vals[ 8] = ( xz - yw );
			m.vals[ 9] = ( yz + xw );
			m.vals[10] = 1.0f - ( xx + yy );  
			m.vals[11] = 0.0f;  

			m.vals[12] = 0.0f;  
			m.vals[13] = 0.0f;   
			m.vals[14] = 0.0f;   
			m.vals[15] = 1.0f;
		}

	}

}
#endif