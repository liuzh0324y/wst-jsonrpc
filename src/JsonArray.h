#ifndef _JSON_ARRAY_H_
#define _JSON_ARRAY_H_

class JsonArray 
{
public:
    JsonArray();
    ~JsonArray();

    JsonArray(const JsonArray &other);
    JsonArray &operator =(const JsonArray &other);
};

#endif // _JSON_ARRAY_H_