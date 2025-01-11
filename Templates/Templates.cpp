#include <iostream>


template<int N>
class Array
{
    private: 
    int array[N];

    public:
    int GetSize() const {return N;}

};

template<typename T, int N>
class Array2
{
    private: 
    T array[N];
    char character = 'a';

    public:
    int GetSize() const {return N;}

    void fill()
    {
        if constexpr (std::is_same<T, std::string>::value)
        {
            char character = 'A'; // Start from 'A'
            for (int i = 0; i < N; i++)
            {
                array[i] = std::string(1, character); // Convert character to string
                character++;
            }
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
                array[i] = i + 1;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < N; i++)
        {
            std::cout << array[i];
        }
        std::cout << std::endl;
    }
};



void printInt(int value)
{
    std::cout << value << std::endl;
}

void printString(std::string value)
{
    std::cout << value << std::endl;
}

void printFloat(float value)
{
    std::cout<<value << std::endl;
}


template<typename T>
void printAny(T value)
{
    std::cout << value << std::endl;
}


//template<typename F>
// void print(F value)
// {
//     std::cout << valu << std::endl;
// }


int main()
{
    int integer = 69;
    float floaty = 4.20;
    std::string stringy = "Insert joke once finsished\n";
    
    std::cout <<"Using individual functions\n";
    printInt(integer);
    printFloat(floaty);
    printString(stringy);

    std::cout<<"\nUsing printAny Function\n";
    printAny(integer);
    printAny(floaty);
    printAny(stringy);

    Array<7> array;
    std::cout << array.GetSize() <<std::endl;

    Array2<std::string, 7> array2;
    Array2<int, 5> array3;

    array2.fill();
    array3.fill();

    array2.print();
    array3.print();
}