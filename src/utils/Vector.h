#ifndef VECTOR_H
#define VECTOR_H
#include "Color.h"

#ifndef NULL
#define NULL (void *)0
#endif

#ifndef PI
#define PI 3.1415926f
#endif


inline float sqr(float n) {
	return n * n;
}

//'class'
struct Vector {
	float x, y, z;

	Color color;

	Vector();
	Vector(const Vector& v);
	Vector(float x, float y, float z);
	Vector(float f);

	virtual ~Vector();

	inline float length2();
	inline float length();

	void setColor(Color c);
	float normalize();
	Vector normalized();

	Vector& operator =(const Vector& v);
	Vector& operator +=(const Vector& v);
	Vector& operator -=(const Vector& v);
	Vector& operator *=(float f);
	Vector& operator /=(float f);
	Vector operator -() const;
};
//returns just a number
float dot(Vector v1, Vector v2);
//returns a Vector
Vector cross(Vector v1, Vector v2);

//inline everything for performance
inline Vector operator +(const Vector& v1, const Vector& v2) {
	return Vector(v1.x + v2.x,
		          v1.y + v2.y,
		          v1.z + v2.z);
}

inline Vector operator -(const Vector& v1, const Vector& v2) {
	return Vector(v1.x - v2.x,
		          v1.y - v2.y,
		          v1.z - v2.z);
}

inline Vector operator *(const Vector& v1, const Vector& v2) {
	return Vector(v1.x * v2.x,
		          v1.y * v2.y,
		          v1.z * v2.z);
}

inline Vector operator *(const Vector& v, float f) {
	return Vector(v.x * f,
	    	      v.y * f,
		          v.z * f);
}

inline Vector operator *(float f, const Vector& v) {
	return Vector(f * v.x,
		          f * v.y,
		          f * v.z);
}

inline Vector operator /(const Vector& v1, const Vector& v2) {
	return Vector(v1.x / v2.x,
		          v1.y / v2.y,
		          v1.z / v2.z);
}

inline Vector operator /(const Vector& v, float f) {
	return Vector(v.x / f,
		          v.y / f,
		          v.z / f);
}
 
inline Vector operator /(float f, const Vector& v) {
	return Vector(f / v.x,
	              f / v.y,
		          f / v.z);
}

typedef Vector Point; //using Vector = Point (C++ style)

struct Vector2 {
	float u, v;

	Vector2();
	Vector2(const Vector2& v);
	Vector2(float u, float v);
	Vector2(float f);

	virtual ~Vector2();

	Vector2& operator =(const Vector2& v);
};

#endif // VECTOR_H