#include "pch.h"
#include "CppUnitTest.h"
#include "Core/Math/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace energonsoftware {
namespace math {
namespace unittests {

TEST_CLASS(VectorTests)
{
private:
    Vector create_test_vector()
    {
        return Vector(1.0f, 2.0f, 3.0f, 4.0);
    }

public:
    TEST_METHOD(random)
    {
        // Arrange
        Vector v1 = Vector::random();

        // Act

        // Assert
        Assert::AreEqual(1.0f, v1.length(), 0.0001f);
    }

    TEST_METHOD(random_length)
    {
        // Arrange
        Vector v1 = Vector::random(5.0f);

        // Act

        // Assert
        Assert::AreEqual(5.0f, v1.length(), 0.0001f);
    }

    TEST_METHOD(constructor_default)
    {
        // Arrange
        Vector v1;

        // Act

        // Assert
        Assert::AreEqual(0.0f, v1.x());
        Assert::AreEqual(0.0f, v1.y());
        Assert::AreEqual(0.0f, v1.z());
        Assert::AreEqual(0.0f, v1.w());
    }

    TEST_METHOD(constructor_1component)
    {
        // Arrange
        Vector v1(1.0f);

        // Act

        // Assert
        Assert::AreEqual(1.0f, v1.x());
        Assert::AreEqual(0.0f, v1.y());
        Assert::AreEqual(0.0f, v1.z());
        Assert::AreEqual(0.0f, v1.w());
    }

    TEST_METHOD(constructor_2component)
    {
        // Arrange
        Vector v1(1.0f, 2.0f);

        // Act

        // Assert
        Assert::AreEqual(1.0f, v1.x());
        Assert::AreEqual(2.0f, v1.y());
        Assert::AreEqual(0.0f, v1.z());
        Assert::AreEqual(0.0f, v1.w());
    }

    TEST_METHOD(constructor_3component)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f);

        // Act

        // Assert
        Assert::AreEqual(1.0f, v1.x());
        Assert::AreEqual(2.0f, v1.y());
        Assert::AreEqual(3.0f, v1.z());
        Assert::AreEqual(0.0f, v1.w());
    }

    TEST_METHOD(constructor_4component)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);

        // Act

        // Assert
        Assert::AreEqual(1.0f, v1.x());
        Assert::AreEqual(2.0f, v1.y());
        Assert::AreEqual(3.0f, v1.z());
        Assert::AreEqual(4.0f, v1.w());
    }

    TEST_METHOD(constructor_vector_with_w)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f);
        Vector v2(v1, 4.0f);

        // Act

        // Assert
        Assert::AreEqual(v1.x(), v2.x());
        Assert::AreEqual(v1.y(), v2.y());
        Assert::AreEqual(v1.z(), v2.z());
        Assert::AreEqual(4.0f, v2.w());
    }

    TEST_METHOD(constructor_initializer_list_empty)
    {
        // Arrange
        Vector v1({ });

        // Act

        // Assert
        Assert::AreEqual(0.0f, v1.x());
        Assert::AreEqual(0.0f, v1.y());
        Assert::AreEqual(0.0f, v1.z());
        Assert::AreEqual(0.0f, v1.w());
    }

    TEST_METHOD(constructor_initializer_list_1component)
    {
        // Arrange
        Vector v1({ 1.0f });

        // Act

        // Assert
        Assert::AreEqual(1.0f, v1.x());
        Assert::AreEqual(0.0f, v1.y());
        Assert::AreEqual(0.0f, v1.z());
        Assert::AreEqual(0.0f, v1.w());
    }

    TEST_METHOD(constuctor_initializer_list_2component)
    {
        // Arrange
        Vector v1({ 1.0f, 2.0f });

        // Act

        // Assert
        Assert::AreEqual(1.0f, v1.x());
        Assert::AreEqual(2.0f, v1.y());
        Assert::AreEqual(0.0f, v1.z());
        Assert::AreEqual(0.0f, v1.w());
    }

    TEST_METHOD(constuctor_initializer_list_3component)
    {
        // Arrange
        Vector v1({ 1.0f, 2.0f, 3.0f });

        // Act

        // Assert
        Assert::AreEqual(1.0f, v1.x());
        Assert::AreEqual(2.0f, v1.y());
        Assert::AreEqual(3.0f, v1.z());
        Assert::AreEqual(0.0f, v1.w());
    }

    TEST_METHOD(constuctor_initializer_list_4component)
    {
        // Arrange
        Vector v1({ 1.0f, 2.0f, 3.0, 4.0f });

        // Act

        // Assert
        Assert::AreEqual(1.0f, v1.x());
        Assert::AreEqual(2.0f, v1.y());
        Assert::AreEqual(3.0f, v1.z());
        Assert::AreEqual(4.0f, v1.w());
    }

    TEST_METHOD(constuctor_array)
    {
        // Arrange
        float v1[] = { 1.0f, 2.0f, 3.0f, 4.0f };
        Vector v2(v1);

        // Act

        // Assert
        Assert::AreEqual(1.0f, v2.x());
        Assert::AreEqual(2.0f, v2.y());
        Assert::AreEqual(3.0f, v2.z());
        Assert::AreEqual(4.0f, v2.w());
    }

    TEST_METHOD(copy_constructor)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);
        Vector v2(v1);

        // Act

        // Assert
        Assert::AreEqual(v1.x(), v2.x());
        Assert::AreEqual(v1.y(), v2.y());
        Assert::AreEqual(v1.z(), v2.z());
        Assert::AreEqual(v1.w(), v2.w());
    }

    TEST_METHOD(move_constructor)
    {
        // Arrange
        Vector v1(create_test_vector());

        // Act

        // Assert
        Assert::AreEqual(1.0f, v1.x());
        Assert::AreEqual(2.0f, v1.y());
        Assert::AreEqual(3.0f, v1.z());
        Assert::AreEqual(4.0f, v1.w());
    }

    TEST_METHOD(property_x)
    {
        // Arrange
        Vector v1;

        // Act
        v1.x(5.0f);

        // Assert
        Assert::AreEqual(5.0f, v1.x());
        Assert::AreEqual(0.0f, v1.y());
        Assert::AreEqual(0.0f, v1.z());
        Assert::AreEqual(0.0f, v1.w());
    }

    TEST_METHOD(property_y)
    {
        // Arrange
        Vector v1;

        // Act
        v1.y(5.0f);

        // Assert
        Assert::AreEqual(0.0f, v1.x());
        Assert::AreEqual(5.0f, v1.y());
        Assert::AreEqual(0.0f, v1.z());
        Assert::AreEqual(0.0f, v1.w());
    }

    TEST_METHOD(property_z)
    {
        // Arrange
        Vector v1;

        // Act
        v1.z(5.0f);

        // Assert
        Assert::AreEqual(0.0f, v1.x());
        Assert::AreEqual(0.0f, v1.y());
        Assert::AreEqual(5.0f, v1.z());
        Assert::AreEqual(0.0f, v1.w());
    }

    TEST_METHOD(property_w)
    {
        // Arrange
        Vector v1;

        // Act
        v1.w(5.0f);

        // Assert
        Assert::AreEqual(0.0f, v1.x());
        Assert::AreEqual(0.0f, v1.y());
        Assert::AreEqual(0.0f, v1.z());
        Assert::AreEqual(5.0f, v1.w());
    }

    TEST_METHOD(property_array)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);

        // Act
        const float* const v2 = v1.array();

        // Assert
        Assert::AreEqual(1.0f, v2[0]);
        Assert::AreEqual(2.0f, v2[1]);
        Assert::AreEqual(3.0f, v2[2]);
        Assert::AreEqual(4.0f, v2[3]);
    }

    TEST_METHOD(zero)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);

        // Act
        v1.zero();

        // Assert
        Assert::AreEqual(0.0f, v1.x());
        Assert::AreEqual(0.0f, v1.y());
        Assert::AreEqual(0.0f, v1.z());
        Assert::AreEqual(0.0f, v1.w());
    }

    TEST_METHOD(is_zero)
    {
        // Arrange
        Vector v1;
        Vector v2(1.0f, 2.0f, 3.0f, 4.0f);

        // Act

        // Assert
        Assert::IsTrue(v1.is_zero());
        Assert::IsFalse(v2.is_zero());
    }

    TEST_METHOD(length_squared)
    {
        // Arrange
        Vector v1(3.0f, 4.0f, 12.0f);

        // Act
        float v1_length_squared = v1.length_squared();

        // Assert
        Assert::AreEqual(169.0f, v1_length_squared, 0.0001f);
    }

    TEST_METHOD(length)
    {
        // Arrange
        Vector v1(3.0f, 4.0f, 12.0f);

        // Act
        float v1_length = v1.length();

        // Assert
        Assert::AreEqual(13.0f, v1_length, 0.0001f);
    }

    TEST_METHOD(set_length)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f);

        // Act
        v1.set_length(123.5f);

        // Assert
        Assert::AreEqual(123.5f, v1.length(), 0.0001f);
    }

    TEST_METHOD(normalize)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f);

        // Act
        v1.normalize();

        // Assert
        Assert::AreEqual(1.0f, v1.length(), 0.001f);
    }

    TEST_METHOD(normalized)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f);
        Vector v1_copy(v1);

        // Act
        Vector v2 = v1.normalized();

        // Assert
        Assert::AreEqual(1.0f, v2.length(), 0.001f);
        Assert::AreEqual(v1_copy.length(), v1.length(), 0.001f);
    }

    TEST_METHOD(perpendicular)
    {
        // Arrange

        // Act

        // Assert
        Assert::IsTrue(Vector::XAxis.perpendicular(Vector::YAxis));
        Assert::IsTrue(Vector::XAxis.perpendicular(Vector::ZAxis));
        Assert::IsTrue(Vector::YAxis.perpendicular(Vector::ZAxis));

        Assert::IsFalse(Vector::XAxis.perpendicular(Vector::XAxis));
        Assert::IsFalse(Vector::YAxis.perpendicular(Vector::YAxis));
        Assert::IsFalse(Vector::ZAxis.perpendicular(Vector::ZAxis));
    }

    TEST_METHOD(same_direction)
    {
        // Arrange
        Vector v1(1.0f, 0.0f, 0.0f);
        Vector v2(2.0f, 0.0f, 0.0f);
        Vector v3(0.0f, 1.0f, 0.0f);

        // Act

        // Assert
        Assert::IsTrue(v1.same_direction(v1));
        Assert::IsTrue(v1.same_direction(v2));

        Assert::IsFalse(v1.same_direction(v3));
        Assert::IsFalse(v2.same_direction(v3));
    }

    TEST_METHOD(opposite_direction)
    {
        // Arrange
        Vector v1(1.0f, 0.0f, 0.0f);
        Vector v2(-1.0f, 0.0f, 0.0f);
        Vector v3(0.0f, 1.0f, 0.0f);

        // Act

        // Assert
        Assert::IsTrue(v1.opposite_direction(v2));

        Assert::IsFalse(v1.opposite_direction(v1));
        Assert::IsFalse(v2.opposite_direction(v3));
    }

    TEST_METHOD(manhattan_normal)
    {
        // Arrange
        Vector v1(1.0f, -2.0f, 3.0f);

        // Act

        // Assert
        Assert::AreEqual(6.0f, v1.manhattan_normal());
    }

    TEST_METHOD(infinite_normal)
    {
        // Arrange
        Vector v1(1.0f, -2.0f, 3.0f);
        Vector v2(1.0f, 2.0f, -3.0f);

        // Act

        // Assert
        Assert::AreEqual(3.0f, v1.infinite_normal());
        Assert::AreEqual(3.0f, v2.infinite_normal());
    }

    TEST_METHOD(distance_squared)
    {
        // Arrange
        Vector v1(1.0f, 3.0f, 0.0f);
        Vector v2(1.0f, 9.0f, 0.0f);

        // Act

        // Assert
        Assert::AreEqual(0.0f, v1.distance_squared(v1));
        Assert::AreEqual(36.0f, v1.distance_squared(v2));
        Assert::AreEqual(36.0f, v2.distance_squared(v1));
    }

    TEST_METHOD(distance)
    {
        // Arrange
        Vector v1(1.0f, 3.0f, 0.0f);
        Vector v2(1.0f, 9.0f, 0.0f);

        // Act

        // Assert
        Assert::AreEqual(0.0f, v1.distance(v1));
        Assert::AreEqual(6.0f, v1.distance(v2));
        Assert::AreEqual(6.0f, v2.distance(v1));
    }

    TEST_METHOD(multiply)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);
        Vector v2(4.0f, 12.0f, 15.0f, -8.0f);

        // Act
        Vector v3 = v1.multiply(v2);

        // Assert
        Assert::AreEqual(4.0f, v3.x());
        Assert::AreEqual(24.0f, v3.y());
        Assert::AreEqual(45.0f, v3.z());
        Assert::AreEqual(-32.0f, v3.w());
    }

    TEST_METHOD(homogeneous_position)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);

        // Act
        Vector v2 = v1.homogeneous_position();

        // Assert
        Assert::AreEqual(1.0f, v2.x());
        Assert::AreEqual(2.0f, v2.y());
        Assert::AreEqual(3.0f, v2.z());
        Assert::AreEqual(1.0f, v2.w());
    }

    TEST_METHOD(homogeneous_direction)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);

        // Act
        Vector v2 = v1.homogeneous_direction();

        // Assert
        Assert::AreEqual(1.0f, v2.x());
        Assert::AreEqual(2.0f, v2.y());
        Assert::AreEqual(3.0f, v2.z());
        Assert::AreEqual(0.0f, v2.w());
    }

    TEST_METHOD(xy)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);

        // Act
        Vector v2 = v1.xy();

        // Assert
        Assert::AreEqual(1.0f, v2.x());
        Assert::AreEqual(2.0f, v2.y());
        Assert::AreEqual(0.0f, v2.z());
        Assert::AreEqual(0.0f, v2.w());
    }

    TEST_METHOD(xz)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);

        // Act
        Vector v2 = v1.xz();

        // Assert
        Assert::AreEqual(1.0f, v2.x());
        Assert::AreEqual(3.0f, v2.y());
        Assert::AreEqual(0.0f, v2.z());
        Assert::AreEqual(0.0f, v2.w());
    }

    TEST_METHOD(yz)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);

        // Act
        Vector v2 = v1.yz();

        // Assert
        Assert::AreEqual(2.0f, v2.x());
        Assert::AreEqual(3.0f, v2.y());
        Assert::AreEqual(0.0f, v2.z());
        Assert::AreEqual(0.0f, v2.w());
    }

    TEST_METHOD(xyz)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);

        // Act
        Vector v2 = v1.xyz();

        // Assert
        Assert::AreEqual(1.0f, v2.x());
        Assert::AreEqual(2.0f, v2.y());
        Assert::AreEqual(3.0f, v2.z());
        Assert::AreEqual(0.0f, v2.w());
    }

    TEST_METHOD(operator_index)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);

        // Act

        // Assert
        Assert::AreEqual(1.0f, v1[0]);
        Assert::AreEqual(2.0f, v1[1]);
        Assert::AreEqual(3.0f, v1[2]);
        Assert::AreEqual(4.0f, v1[3]);
    }

    TEST_METHOD(operator_equals)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);
        Vector v2(5.0f, 6.0f, 7.0f, 8.0f);

        // Act

        // Assert
        Assert::IsTrue(v1 == v1);
        Assert::IsFalse(v1 == v2);
        Assert::IsFalse(v2 == v1);
    }

    TEST_METHOD(operator_not_equals)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);
        Vector v2(5.0f, 6.0f, 7.0f, 8.0f);

        // Act

        // Assert
        Assert::IsFalse(v1 != v1);
        Assert::IsTrue(v1 != v2);
        Assert::IsTrue(v2 != v1);
    }

    TEST_METHOD(operator_less)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);
        Vector v2(5.0f, 6.0f, 7.0f, 8.0f);

        // Act

        // Assert
        Assert::IsTrue(v1 < v2);
        Assert::IsFalse(v2 < v1);
    }

    TEST_METHOD(operator_add)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);
        Vector v2(4.0f, 12.0f, 17.0f, -8.0f);

        // Act
        Vector v3 = v1 + v2;

        // Assert
        Assert::AreEqual(5.0f, v3.x());
        Assert::AreEqual(14.0f, v3.y());
        Assert::AreEqual(20.0f, v3.z());
        Assert::AreEqual(-4.0f, v3.w());
    }

    TEST_METHOD(operator_add_assign)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);
        Vector v2(4.0f, 12.0f, 17.0f, -8.0f);

        // Act
        v1 += v2;

        // Assert
        Assert::AreEqual(5.0f, v1.x());
        Assert::AreEqual(14.0f, v1.y());
        Assert::AreEqual(20.0f, v1.z());
        Assert::AreEqual(-4.0f, v1.w());
    }

    TEST_METHOD(operator_minus)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);
        Vector v2(4.0f, 12.0f, 17.0f, -8.0f);

        // Act
        Vector v3 = v1 - v2;

        // Assert
        Assert::AreEqual(-3.0f, v3.x());
        Assert::AreEqual(-10.0f, v3.y());
        Assert::AreEqual(-14.0f, v3.z());
        Assert::AreEqual(12.0f, v3.w());
    }

    TEST_METHOD(operator_minus_assign)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);
        Vector v2(4.0f, 12.0f, 17.0f, -8.0f);

        // Act
        v1 -= v2;

        // Assert
        Assert::AreEqual(-3.0f, v1.x());
        Assert::AreEqual(-10.0f, v1.y());
        Assert::AreEqual(-14.0f, v1.z());
        Assert::AreEqual(12.0f, v1.w());
    }

    TEST_METHOD(operator_scale)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);

        // Act
        Vector v2 = v1 * 3.0f;
        Vector v3 = 3.0f * v2;

        // Assert
        Assert::AreEqual(3.0f, v2.x());
        Assert::AreEqual(6.0f, v2.y());
        Assert::AreEqual(9.0f, v2.z());
        Assert::AreEqual(12.0f, v2.w());

        Assert::AreEqual(9.0f, v3.x());
        Assert::AreEqual(18.0f, v3.y());
        Assert::AreEqual(27.0f, v3.z());
        Assert::AreEqual(36.0f, v3.w());
    }

    TEST_METHOD(operator_scale_assign)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);

        // Act
        v1 *= 3.0f;

        // Assert
        Assert::AreEqual(3.0f, v1.x());
        Assert::AreEqual(6.0f, v1.y());
        Assert::AreEqual(9.0f, v1.z());
        Assert::AreEqual(12.0f, v1.w());
    }

    TEST_METHOD(operator_descale)
    {
        // Arrange
        Vector v1(3.0f, 6.0f, 9.0f, 12.0f);

        // Act
        Vector v2 = v1 / 3.0f;

        // Assert
        Assert::AreEqual(1.0f, v2.x());
        Assert::AreEqual(2.0f, v2.y());
        Assert::AreEqual(3.0f, v2.z());
        Assert::AreEqual(4.0f, v2.w());
    }

    TEST_METHOD(operator_descale_assign)
    {
        // Arrange
        Vector v1(3.0f, 6.0f, 9.0f, 12.0f);

        // Act
        v1 /= 3.0f;

        // Assert
        Assert::AreEqual(1.0f, v1.x());
        Assert::AreEqual(2.0f, v1.y());
        Assert::AreEqual(3.0f, v1.z());
        Assert::AreEqual(4.0f, v1.w());
    }

    TEST_METHOD(operator_negate)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);
        Vector v2(-1.0f, -2.0f, -3.0f, -4.0f);

        // Act
        Vector v3 = -v1;
        Vector v4 = -v2;

        // Assert
        Assert::AreEqual(-1.0f, v3.x());
        Assert::AreEqual(-2.0f, v3.y());
        Assert::AreEqual(-3.0f, v3.z());
        Assert::AreEqual(-4.0f, v3.w());

        Assert::AreEqual(1.0f, v4.x());
        Assert::AreEqual(2.0f, v4.y());
        Assert::AreEqual(3.0f, v4.z());
        Assert::AreEqual(4.0f, v4.w());
    }

    TEST_METHOD(operator_dot_product)
    {
        // Arrange
        Vector v1(1.0f, 3.0f, 6.0f);
        Vector v2(4.0f, -2.0f, 1.0f);

        // Act
        float dot = v1 * v2;

        // Assert
        Assert::AreEqual(4.0f, dot, 0.0001f);
    }

    TEST_METHOD(operator_dot_product_array)
    {
        // Arrange
        Vector v1(1.0f, 3.0f, 6.0f);
        ALIGN(16) float v2[] = { 4.0f, -2.0f, 1.0f, 0.0f };

        // Act
        float dot = v1 * v2;

        // Assert
        Assert::AreEqual(4.0f, dot, 0.0001f);
    }

    TEST_METHOD(operator_cross_product)
    {
        // Arrange

        // Act
        Vector v1 = Vector::XAxis ^ Vector::YAxis;

        // Assert
        Assert::IsTrue(Vector::ZAxis == v1);
    }

    TEST_METHOD(operator_cross_product_assign)
    {
        // Arrange
        Vector v1 = Vector::XAxis;

        // Act
        v1 ^= Vector::YAxis;

        // Assert
        Assert::IsTrue(Vector::ZAxis == v1);
    }
};

} } }
