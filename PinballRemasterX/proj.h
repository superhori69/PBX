#pragma once
#include "maths.h"

struct vector_type4
{
	float X;
	float Y;
	float Z;
	float W;
};

struct mat4_row_major
{
	vector_type4 Row0;
	vector_type4 Row1;
	vector_type4 Row2;
	vector_type4 Row3;
};


class proj
{
public:
	static void init(float* mat4x3, float d, float centerX, float centerY, float zMin, float zScaler);
	static vector3 matrix_vector_multiply(const mat4_row_major& mat, const vector3& vec);
	static float z_distance(const vector3& vec);
	static vector2i xform_to_2d(const vector3& vec);
	static vector2i xform_to_2d(const vector2& vec);
	static vector3 ReverseXForm(const vector2i& vec);
	static void recenter(float centerX, float centerY);
	static uint16_t NormalizeDepth(float depth);
private:
	static mat4_row_major matrix;
	static float d_, centerx, centery;
	static float zscaler, zmin, zmax;
};
