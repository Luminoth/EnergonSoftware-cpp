#include "pch.h"
#include "CppUnitTest.h"
#include "Core/Math/Util.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace energonsoftware {
namespace math {
namespace unittests {

TEST_CLASS(UtilTests)
{
public:
    TEST_METHOD(is_odd)
    {
        // Arrange

        // Act

        // Assert
        Assert::IsTrue(IS_ODD(3));
        Assert::IsFalse(IS_ODD(4));
        Assert::IsFalse(IS_ODD(0));
    }

    TEST_METHOD(is_even)
    {
        // Arrange

        // Act

        // Assert
        Assert::IsTrue(IS_EVEN(4));
        Assert::IsFalse(IS_EVEN(3));
        Assert::IsTrue(IS_EVEN(0));
    }

    TEST_METHOD(rad_deg)
    {
        // Arrange

        // Act
        double deg = RAD_DEG(M_PI);

        // Assert
        Assert::AreEqual(180.0, deg, 0.0001);
    }

    TEST_METHOD(deg_rad)
    {
        // Arrange

        // Act
        double rad = DEG_RAD(90);

        // Assert
        Assert::AreEqual(M_PI_2, rad, 0.0001);
    }

    TEST_METHOD(util_min)
    {
        // Arrange

        // Act
        float min = MIN(1.0f, 2.0f);

        // Assert
        Assert::AreEqual(1.0f, min);
    }

    TEST_METHOD(util_max)
    {
        // Arrange

        // Act
        float max = MAX(1.0f, 2.0f);

        // Assert
        Assert::AreEqual(2.0f, max);
    }

    TEST_METHOD(util_manhattan_distance)
    {
        // Arrange
        long x1 = 123L;
        long y1 = 3456L;
        long x2 = 245L;
        long y2 = 23L;

        // Act
        long distance = manhattan_distance(x1, y1, x2, y2);

        // Assert
        Assert::AreEqual(3555L, distance);
    }

    TEST_METHOD(util_ilog2)
    {
        // Arrange

        // Act

        // Assert
        Assert::AreEqual(0U, ilog2(1));
        Assert::AreEqual(1U, ilog2(2));
        Assert::AreEqual(2U, ilog2(4));
        Assert::AreEqual(3U, ilog2(10));
    }

    TEST_METHOD(util_power_of_2)
    {
        // Arrange

        // Act

        // Assert
        Assert::AreEqual(0U, power_of_2(0));
        Assert::AreEqual(1U, power_of_2(1));
        Assert::AreEqual(2U, power_of_2(2));
        Assert::AreEqual(4U, power_of_2(3));
        Assert::AreEqual(256U, power_of_2(200));
        Assert::AreEqual(2048U, power_of_2(2000));
    }

    TEST_METHOD(util_invsqrt)
    {
        // Arrange
        static const float v1 = 10.0f;
        static const float v2 = 1234.0f;
        static const float v3 = 5000.0f;

        float e1 = 1.0f / std::sqrt(v1);
        float e2 = 1.0f / std::sqrt(v2);
        float e3 = 1.0f / std::sqrt(v3);

        // Act
        float a1 = invsqrt(v1);
        float a2 = invsqrt(v2);
        float a3 = invsqrt(v3);

        // Assert
        Assert::AreEqual(e1, a1, 0.001f);
        Assert::AreEqual(e2, a2, 0.001f);
        Assert::AreEqual(e3, a3, 0.001f);
    }
};

} } }
