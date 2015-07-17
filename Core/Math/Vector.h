#if !defined __VECTOR_H__
#define __VECTOR_H__

namespace energonsoftware {
namespace math {

/*
Represents a size-agnostic Vector (based on a 4-dimensional vector)
with specialization where required.

For less-than-4-dimensional vectors, the unused components should be constrained to 0.
Care should be taken to avoid misusing this class and to avoid
mixing sizes where it is mathematically inappropriate to do so.
*/
class DllExport Vector
{
public:
    static const Vector Zero;

    // NOTE: right-handed orientation (OpenGL style)
    static const Vector Right;
    static const Vector Left;
    static const Vector Up;
    static const Vector Down;
    static const Vector Backward;
    static const Vector Forward;

    static const Vector XAxis;
    static const Vector YAxis;
    static const Vector ZAxis;
    static const Vector WAxis;

public:
    // length = 1.0f
    static Vector random();

    static Vector random(float length);

public:
    // TODO: with VS2015, brace-initializers can be used in this class
    // (including in member initializers)
    // instead of doing work inside the constructor bodies

    Vector()
    {
        _value[0] = _value[1] = _value[2] = _value[3] = 0.0f;
    }

    explicit Vector(float x)
        //: _value{x}
    {
        _value[0] = x;
        _value[1] = _value[2] = _value[3] = 0.0f;
    }

    Vector(float x, float y)
        //: _value{x, y}
    {
        _value[0] = x;
        _value[1] = y;
        _value[2] = _value[3] = 0.0f;
    }

    Vector(float x, float y, float z)
        //: _value{x, y, z}
    {
        _value[0] = x;
        _value[1] = y;
        _value[2] = z;
        _value[3] = 0.0f;
    }

    Vector(float x, float y, float z, float w)
        //: _value{x, y, z, w}
    {
        _value[0] = x;
        _value[1] = y;
        _value[2] = z;
        _value[3] = w;
    }

    Vector(const Vector& v, float w)
        //: _value{v.x(), v.y(), v.z(), w}
    {
        _value[0] = v.x();
        _value[1] = v.y();
        _value[2] = v.z();
        _value[3] = w;
    }

    explicit Vector(const std::initializer_list<float>& v)
    {
        // TODO: remove this
        _value[0] = _value[1] = _value[2] = _value[3] = 0.0f;

        assert(v.size() <= 4);
        std::copy(v.begin(), v.end(), _value);
    }

    // VS2015 fixes this stuff
    //explicit Vector(const Vector& v) = default;
    //Vector(Vector&& v) = default;

    virtual ~Vector() = default;

public:
    void x(float x) { _value[0] = x; }
    float x() const { return _value[0]; }

    void y(float y) { _value[1] = y; }
    float y() const { return _value[1]; }

    void z(float z) { _value[2] = z; }
    float z() const { return _value[2]; }

    void w(float w) { _value[3] = w; }
    float w() const { return _value[3]; }

public:
    float length_squared() const
    {
#if defined USE_SSE
        float d;
        __m128 A = _mm_load_ps(_value);
        __m128 R1 = _mm_mul_ps(A, A);
        __m128 R2 = _mm_hadd_ps(R1, R1);
        _mm_store_ss(&d, _mm_hadd_ps(R2, R2));
        return d;
#else
        return *this * *this;
#endif
    }

    float length() const
    {
#if defined USE_SSE
        float d;
        __m128 A = _mm_load_ps(_value);
        __m128 R1 = _mm_mul_ps(A, A);
        __m128 R2 = _mm_hadd_ps(R1, R1);
        _mm_store_ss(&d, _mm_sqrt_ss(_mm_hadd_ps(R2, R2)));
        return d;
#else
        return std::sqrt(length_squared());
#endif
    }

    Vector& set_length(float len) { return *this *= len / length(); }

public:
    Vector operator*(float rhs) const
    {
#if defined USE_SSE
        ALIGN(16) float p[4];
        __m128 A = _mm_load_ps(_value);
        __m128 S = _mm_set1_ps(rhs);
        _mm_store_ps(p, _mm_mul_ps(A, S));
        return Vector(p);
#else
        return Vector(x() * rhs, y() * rhs, z() * rhs, w() * rhs);
#endif
    }

    Vector& operator*=(float rhs)
    {
#if defined USE_SSE
        __m128 A = _mm_load_ps(_value);
        __m128 S = _mm_set1_ps(rhs);
        _mm_store_ps(_value, _mm_mul_ps(A, S));
        return *this;
#else
        return *this = *this * rhs;
#endif
    }

    // dot-product
    float operator*(const Vector& rhs) const
    {
#if defined USE_SSE
        float d;
        __m128 A = _mm_load_ps(_value);
        __m128 B = _mm_load_ps(rhs._value);

        // multiply the vector components
        __m128 R1 = _mm_mul_ps(A, B);

        // first horizontal add gives us
        // [R1.3 + R1.2, R1.1 + R1.0, R1.3 + R1.2, R1.1 + R1.0]
        __m128 R2 = _mm_hadd_ps(R1, R1);

        // second horizontal add gives us
        // [R2.3 + R2.2, R2.1 + R2.0, R2.3 + R2.2, R2.1 + R2.0]
        // which finishes the sum
        _mm_store_ss(&d, _mm_hadd_ps(R2, R2));
        return d;
#else
        return x() * rhs.x() + y() * rhs.y() + z() * rhs.z() + w() * rhs.w();
#endif
    }

private:
    // TODO: can use initializer in VS2015
    ALIGN(16) float _value[4];// = { 0, 0, 0, 0 };
};

} }

#endif
