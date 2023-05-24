#include "validator.h"

bool Validator::validateSize(string size)
{
    if (size != "XXS" && size != "XS" && size != "S" && size != "M" && size != "L" && size != "XL" && size != "XXL")
        return false;
    else
        return true;
}

float Validator::validatePrice(string price)
{
    for (char i : price)
        if (isalpha(i) || i=='.')
            return -1;
    int new_price;
    new_price = stof(price);
    return new_price;
}

int Validator::validateQuantity(string quantity)
{
    for (char i : quantity)
        if (isalpha(i))
            return -1;
    int new_quantity;
    new_quantity = stoi(quantity);
    return new_quantity;
}

bool Validator::validatePhoto(string photo)
{
    if (photo.length() < 13)
        return false;
    if (photo[0] != 'h' || photo[1] != 't' || photo[2] != 't' || photo[3] != 'p' ||
        photo[4] != 's' || photo[5] != ':' || photo[6] != '/' || photo[7] != '/')
        return false;
  /*  if (photo.find(".com") == std::string::npos && photo.find(".jpg") == std::string::npos)
        return false;*/
    return true;
}
