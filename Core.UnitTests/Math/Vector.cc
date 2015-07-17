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
    /*TEST_METHOD(random)
    {
        // Arrange
        Vector v1 = Vector::random();

        // Act

        // Assert
        Assert::AreEqual(1.0f, v1.length(), 0.0001f);
    }*/

    /*TEST_METHOD(random_length)
    {
        // Arrange
        Vector v1 = Vector::random(5.0f);

        // Act

        // Assert
        Assert::AreEqual(5.0f, v1.length(), 0.0001f);
    }*/

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

    /*TEST_METHOD(constructor_initializer_list_1component)
    {
        // Arrange
        Vector v1({ 1.0f });

        // Act

        // Assert
        Assert::AreEqual(1.0f, v1.x());
        Assert::AreEqual(0.0f, v1.y());
        Assert::AreEqual(0.0f, v1.z());
        Assert::AreEqual(0.0f, v1.w());
    }*/

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

    TEST_METHOD(length_squared)
    {
        // Arrange
        Vector v1(3.0f, 4.0f, 12.0f);
        Vector v2(17.0f, 3.13f, 22.75f);

        // Act
        float v1_length_squared = v1.length_squared();
        float v2_length_squared = v2.length_squared();

        // Assert
        Assert::AreEqual(169.0f, v1_length_squared, 0.0001f);
        Assert::AreEqual(816.359f, v2_length_squared, 0.001f);
    }

    TEST_METHOD(length)
    {
        // Arrange
        Vector v1(3.0f, 4.0f, 12.0f);
        Vector v2(17.0f, 3.13f, 22.75f);

        // Act
        float v1_length = v1.length();
        float v2_length = v2.length();

        // Assert
        Assert::AreEqual(13.0f, v1_length, 0.0001f);
        Assert::AreEqual(28.572f, v2_length, 0.0001f);
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

    TEST_METHOD(operator_scale)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);

        // Act
        Vector v2 = v1 * 3.0f;

        // Assert
        Assert::AreEqual(3.0f, v2.x(), 0.0001f);
        Assert::AreEqual(6.0f, v2.y(), 0.0001f);
        Assert::AreEqual(9.0f, v2.z(), 0.0001f);
        Assert::AreEqual(12.0f, v2.w(), 0.0001f);
    }

    TEST_METHOD(operator_scale_assign)
    {
        // Arrange
        Vector v1(1.0f, 2.0f, 3.0f, 4.0f);

        // Act
        v1 *= 3.0f;

        // Assert
        Assert::AreEqual(3.0f, v1.x(), 0.0001f);
        Assert::AreEqual(6.0f, v1.y(), 0.0001f);
        Assert::AreEqual(9.0f, v1.z(), 0.0001f);
        Assert::AreEqual(12.0f, v1.w(), 0.0001f);
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

    /*TEST_METHOD(operator_dot_product_array)
    {
        // Arrange
        Vector v1(1.0f, 3.0f, 6.0f);
        ALIGN(16) float v2[] = { 4.0f, -2.0f, 1.0f, 0.0f };

        // Act
        float dot = v1 * v2;

        // Assert
        Assert::AreEqual(4.0f, dot, 0.0001f);
    }*/
};

} } }
