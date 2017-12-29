#include "JsonValue.h"
#include "JsonObject.h"
#include "JsonArray.h"

JsonValue::JsonValue(Type type)
    : t(type)
{

}

JsonValue::JsonValue(bool b)
    : t(Bool)
{
    this->b = b;
}

JsonValue::JsonValue(double n)
    : t(Double)
{
    this->dbl = n;
}

JsonValue::JsonValue(int n)
    : t(Double)
{
    this->dbl = n;
}

JsonValue::JsonValue(const std::string &s)
    : t(String)
{

}

JsonValue::JsonValue(const JsonArray &s)
    : t(Array)
{

}

JsonValue::JsonValue(const JsonObject &s)
    : t(Object)
{

}

JsonValue::~JsonValue()
{

}

JsonValue::JsonValue(const JsonValue &other)
{
    this->t = other.t;
}

JsonValue &JsonValue::operator =(const JsonValue &other)
{
    JsonValue copy(other);

    return *this;
}

JsonValue::Type JsonValue::type() const
{
    return t;
}

bool JsonValue::toBool(bool defaultValue) const
{
    if (t != Bool)
    {
        return defaultValue;
    }

    return b;
}

int JsonValue::toInit(int defalutValue) const
{
    if (t == Double && int(dbl) == dbl)
    {
        return int(dbl);
    }

    return defalutValue;
}

double JsonValue::toDouble(int defalutValue) const
{
    if (t != Double)
    {
        return defalutValue;
    }

    return dbl;
}

std::string JsonValue::toString() const
{
    return toString(std::string());
}

std::string JsonValue::toString(const std::string &defaultValue) const
{
    if (t != String)
    {
        return defaultValue;
    }
}

JsonArray JsonValue::toArray() const
{
    return toArray(JsonArray());
}

JsonArray JsonValue::toArray(const JsonArray &defaultValue) const
{
    if (t != Array)
    {
        return defaultValue;
    }
}

JsonObject JsonValue::toObject() const
{
    return toObject(JsonObject());
}

JsonObject JsonValue::toObject(const JsonObject &defaultValue) const
{
    if (t != Object)
    {
        return defaultValue;
    }
}

bool JsonValue::operator==(const JsonValue &other) const
{
    if (t != other.t)
    {
        return false;
    }

    switch (t)
    {
    case Undefined:
    case Null:
        break;
    case Bool:
        return b == other.b;
    case Double:
        return dbl == other.dbl;
    case String:
        return toString() == other.toString();
    case Array:
    case Object:
        break;
    }

    return true;
}

bool JsonValue::operator!=(const JsonValue &other) const
{
    return !(*this == other);
}