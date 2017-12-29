#ifndef _JSON_VALUE_H_
#define _JSON_VALUE_H_

#include <string>

class JsonArray;
class JsonObject;

class JsonValue 
{
public:
    enum Type 
    {
        Null = 0x0,
        Bool = 0x1,
        Double = 0x2,
        String = 0x3,
        Array = 0x4,
        Object = 0x5,
        Undefined = 0x8
    };
    JsonValue(Type type = Null);
    JsonValue(bool b);
    JsonValue(double n);
    JsonValue(int n);
    JsonValue(const std::string &s);
    JsonValue(const JsonArray &s);
    JsonValue(const JsonObject &s);

    ~JsonValue();

    JsonValue(const JsonValue &other);
    JsonValue &operator =(const JsonValue &other);

    Type type() const;
    inline bool isNull() const { return type() == Null; };
    inline bool isBool() const { return type() == Bool; };
    inline bool isDouble() const { return type() == Double; };
    inline bool isString() const { return type() == String; };
    inline bool isArray() const { return type() == Array; };
    inline bool isObject() const { return type() == Object; };
    inline bool isUndefined() const { return type() == Undefined; };

    bool toBool(bool defaultValue=false) const;
    int toInit(int defalutValue=0) const;
    double toDouble(int defalutValue=0) const;
    std::string toString() const;
    std::string toString(const std::string &defaultValue) const;
    JsonArray toArray() const;
    JsonArray toArray(const JsonArray &defaultValue) const;
    JsonObject toObject() const;
    JsonObject toObject(const JsonObject &defaultValue) const;

    bool operator==(const JsonValue &other) const;
    bool operator!=(const JsonValue &other) const;
private:
    union {
        bool b;
        double dbl;
    };
    Type t;
};

#endif // _JSON_VALUE_H_