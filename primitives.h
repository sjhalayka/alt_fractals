// Source code by Shawn Halayka
// Source code is in the public domain

#ifndef PRIMITIVES_H
#define PRIMITIVES_H


#include <cmath>
#include <cstddef> // g++ chokes on size_t without this

class vector_4
{
public:
	double x, y, z, w;


	inline bool operator<(const vector_4 &right) const
	{
		if (right.x > x)
			return true;
		else if (right.x < x)
			return false;

		if (right.y > y)
			return true;
		else if (right.y < y)
			return false;

		if (right.z > z)
			return true;
		else if (right.z < z)
			return false;

		if (right.w > w)
			return true;
		else if (right.w < w)
			return false;

		return false;
	}

	vector_4(void)
	{
		x = y = z = w = 0.0f;
	}

	vector_4(const double &src_x, const double &src_y, const double &src_z, const double &src_w)
	{
		x = src_x;
		y = src_y;
		z = src_z;
		w = src_w;
	}

	void zero(void)
	{
		x = y = z = w = 0;
	}

	vector_4 operator+(const vector_4 &rhs)
	{
		return vector_4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
	}

	vector_4 operator-(const vector_4 &rhs)
	{
		return vector_4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
	}

	vector_4 operator*(const vector_4 &rhs)
	{
		return vector_4(x*rhs.x, y*rhs.y, z*rhs.z, w*rhs.w);
	}

	vector_4 operator*(const double &rhs)
	{
		return vector_4(x*rhs, y*rhs, z*rhs, w*rhs);
	}

	vector_4 operator/(const double &rhs)
	{
		return vector_4(x / rhs, y / rhs, z / rhs, w / rhs);
	}

	vector_4 &operator=(const vector_4 &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		w = rhs.w;
		return *this;
	}

	vector_4 &operator+=(const vector_4 &rhs)
	{
		x += rhs.x; y += rhs.y; z += rhs.z; w += rhs.w;
		return *this;
	}

	vector_4 &operator*=(const vector_4 &rhs)
	{
		x *= rhs.x; y *= rhs.y; z *= rhs.z; w *= rhs.w;
		return *this;
	}

	vector_4 &operator*=(const double &rhs)
	{
		x *= rhs; y *= rhs; z *= rhs; w *= rhs;
		return *this;
	}

	vector_4 operator-(void)
	{
		vector_4 temp;
		temp.x = -x;
		temp.y = -y;
		temp.z = -z;
		temp.w = -w;

		return temp;
	}

	double length(void) const
	{
		return sqrt(self_dot());
	}

	vector_4 &normalize(void)
	{
		double len = length();

		if (len != 1)
		{
			x /= len;
			y /= len;
			z /= len;
			w /= len;
		}

		return *this;
	}

	double dot(const vector_4 &rhs) const
	{
		return x*rhs.x + y*rhs.y + z*rhs.z + w*rhs.w;
	}

	double self_dot(void) const
	{
		return x*x + y*y + z*z + w*w;
	}
};






class vector_3
{
public:
	inline vector_3(void) : x(0.0f), y(0.0f), z(0.0f), index(0) { /*default constructor*/ }
	inline vector_3(const float src_x, const float src_y, const float src_z, const size_t src_index) : x(src_x), y(src_y), z(src_z), index(src_index) { /* custom constructor */ }

	inline bool operator==(const vector_3 &right) const
	{
		if(right.x == x && right.y == y && right.z == z)
			return true;
		else
			return false;
	}

	inline bool operator<(const vector_3 &right) const
	{
		if(right.x > x)
			return true;
		else if(right.x < x)
			return false;

		if(right.y > y)
			return true;
		else if(right.y < y)
			return false;

		if(right.z > z)
			return true;
		else if(right.z < z)
			return false;

		return false;
	}

	inline const vector_3& operator-(const vector_3 &right) const
	{
		static vector_3 temp;

		temp.x = this->x - right.x;
		temp.y = this->y - right.y;
		temp.z = this->z - right.z;

		return temp;
	}

	inline const vector_3& operator+(const vector_3 &right) const
	{
		static vector_3 temp;

		temp.x = this->x + right.x;
		temp.y = this->y + right.y;
		temp.z = this->z + right.z;

		return temp;
	}

	inline const vector_3& operator*(const float &right) const
	{
		static vector_3 temp;

		temp.x = this->x * right;
		temp.y = this->y * right;
		temp.z = this->z * right;

		return temp;
	}
	
	inline const vector_3& cross(const vector_3 &right) const
	{
		static vector_3 temp;

		temp.x = y*right.z - z*right.y;
		temp.y = z*right.x - x*right.z;
		temp.z = x*right.y - y*right.x;

		return temp;
	}

	inline float dot(const vector_3 &right) const
	{
		return x*right.x + y*right.y + z*right.z;
	}

	inline const float self_dot(void)
	{
		return x*x + y*y + z*z;
	}

	inline const float length(void)
	{
		return std::sqrt(self_dot());
	}

	inline const void normalize(void)
	{
		float len = length();

		if(0.0f != len)
		{
			x /= len;
			y /= len;
			z /= len;
		}
	}

	float x, y, z;
	size_t index;
};

class triangle
{
public:
	vector_3 vertex[3];
};

class quaternion
{
public:
	inline quaternion(void) : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { /*default constructor*/ }
	inline quaternion(const float src_x, const float src_y, const float src_z, const float src_w) : x(src_x), y(src_y), z(src_z), w(src_w) { /* custom constructor */ }

	inline float self_dot(void)
	{
		return x*x + y*y + z*z + w*w;
	}

	float x, y, z, w;
};



#endif
