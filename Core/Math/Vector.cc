#include "pch.h"
#include "Vector.h"

namespace energonsoftware {
namespace math {

const Vector Vector::Zero(0.0f, 0.0f, 0.0f, 0.0f);

const Vector Vector::Right(1.0f, 0.0f, 0.0f);
const Vector Vector::Left(-1.0f, 0.0f, 0.0f);
const Vector Vector::Up(0.0f, 1.0f, 0.0f);
const Vector Vector::Down(0.0f, -1.0f, 0.0f);
const Vector Vector::Backward(0.0f, 0.0f, 1.0f);
const Vector Vector::Forward(0.0f, 0.0f, -1.0f);

const Vector Vector::XAxis(1.0f, 0.0f, 0.0f);
const Vector Vector::YAxis(0.0f, 1.0f, 0.0f);
const Vector Vector::ZAxis(0.0f, 0.0f, 1.0f);
const Vector Vector::WAxis(0.0f, 0.0f, 0.0f, 1.0f);

Vector Vector::random()
{
    return random(1.0f);
}

Vector Vector::random(float length)
{
    std::default_random_engine engine;
    std::uniform_real_distribution<float> distribution(-0.5f, 0.5f);
    auto generator = std::bind(distribution, engine);

    return Vector(generator(), generator(), generator()).set_length(length);
}

std::string Vector::str() const
{
    std::stringstream ss;
    ss << "Vector(x:" << std::fixed << x() << ", y:" << y() << ", z:" << z() << ", w:" << w() << ")";
    return ss.str();
}

} }
