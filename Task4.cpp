#include <iostream>
#include <bitset>


//алгоритм упаковки цифр от 0 до 5 с помощью битовых сдвигов. set3 - упаковать число, get3 - распаковать число.

//числа упаковываются в unsigned int по 11 штук, при этом последнее 11-ое число должно быть от 0 до 3, иначе оно упакуется неверно

//второй метод упаковки через битовые поля структуры

unsigned int get3(unsigned int val, unsigned int no)
{
    const unsigned int mask = 0x7; //7 - это 3 в 16сс (на одно число нужно минимум три бита)
    return (val >> no * 3) & mask;
}

unsigned int set3(unsigned int val, unsigned int no, unsigned int to_val)
{
    const unsigned int mask = 0x7;
    to_val = (to_val & mask) << (no * 3);
    return (val & ~(mask << no * 3)) | to_val;
}


int main()
{
    unsigned int val = 0;
    struct number
    {
        unsigned char field_1 : 3;
        unsigned char field_2 : 3;
        unsigned char field_3 : 3;
        unsigned char field_4 : 3;
        unsigned char field_5 : 3;
        unsigned char field_6 : 3;
        unsigned char field_7 : 3;
        unsigned char field_8 : 3;
    };
    number g;
    g.field_1 = 2;
    g.field_2 = 3;
    g.field_3 = 4;
    g.field_4 = 1;
    g.field_5 = 5;
    g.field_6 = 3;
    g.field_7 = 2;
    g.field_8 = 5;

  
    val = set3(val, 0, 2);
    val = set3(val, 1, 3);
    val = set3(val, 2, 4);
    val = set3(val, 3, 1);
    val = set3(val, 4, 5);
    val = set3(val, 5, 3);
    val = set3(val, 6, 2);
    val = set3(val, 7, 5);
    val = set3(val, 8, 5);
    val = set3(val, 9, 4);
    val = set3(val, 10, 3);

    printf("%u - %u - %u - %u - %u - %u - %u - %u - %u - %u - %u\n", get3(val, 0), get3(val, 1), get3(val, 2),
        get3(val, 3), get3(val, 4), get3(val, 5), get3(val, 6), get3(val, 7), get3(val, 8), get3(val, 9), get3(val, 10));

    printf("%u - %u - %u - %u - %u - %u - %u - %u\n", g.field_1, g.field_2, g.field_3, g.field_4, g.field_5, g.field_6, g.field_7, g.field_8);
}