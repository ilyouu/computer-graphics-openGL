#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int getIntFromBinaryText(const char* text)
{
    int value = 0;
    while(*text)
    {
        value <<= 1;
             if(*text == '1')    value |= 1;
        else if(*text == '0')    ;          
        else                     return -1; 
        ++text;
    }

    return value;
}

std::string getBinaryTextFromInt(int value)
{
    std::string text;
    
    
    while(value > 0)
    {
        if(value & 1)       text += '1';
        else                text += '0';
        value >>= 1;
    }
    
    if(text.empty())        return "0";
    std::reverse( text.begin(), text.end() );      
    return text;
}

int main()  
{
    int divisor = getIntFromBinaryText("1011");  
    
    std::string text;
    cout << "Nhap so nhi phan: ";
    getline (cin, text);
 
    int dividend = getIntFromBinaryText(text.c_str());
    if(dividend < 0)
    {
        cout << "Input khong hop le (yeu cau nhap so nhi phan)";
        return 1;
    }
    
    int result = dividend / divisor;
    int remainder = dividend % divisor;
    
    cout << "\n================================" << endl;
    cout << "So phai chia = " << getBinaryTextFromInt(dividend);
    cout << "\nSo chia = " <<  getBinaryTextFromInt(divisor);
    cout << "\nKet qua = " <<  getBinaryTextFromInt(result);
    cout << "\nPhan con lai = " <<  getBinaryTextFromInt(remainder);
}
