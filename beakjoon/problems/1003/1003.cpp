#include <iostream>
#include <type_traits>


constexpr long long fibonacci_1(int n)
{
    if(n == 0)
        return 0;

    if(n == 1)
        return 1;

    return fibonacci_1(n - 1) + fibonacci_1(n - 2);
}



constexpr long long fibonacci_0(int n)
{
    if(n == 0)
        return 1;

    if(n == 1)
        return 0;

    return fibonacci_0(n - 1) + fibonacci_0(n - 2);
}


long long answer[] = {
    fibonacci_0(0),
    fibonacci_0(1),
    fibonacci_0(2),
    fibonacci_0(3),
    fibonacci_0(4),
    fibonacci_0(5),
    fibonacci_0(6),
    fibonacci_0(7),
    fibonacci_0(8),
    fibonacci_0(9),
    fibonacci_0(10),
    fibonacci_0(11),
    fibonacci_0(12),
    fibonacci_0(13),
    fibonacci_0(14),
    fibonacci_0(15),
    fibonacci_0(16),
    fibonacci_0(17),
    fibonacci_0(18),
    fibonacci_0(19),
    fibonacci_0(20),
    fibonacci_0(21),
    fibonacci_0(22),
    fibonacci_0(23),
    fibonacci_0(24),
    fibonacci_0(25),
    fibonacci_0(26),
    fibonacci_0(27),
    fibonacci_0(28),
    fibonacci_0(29),
    fibonacci_0(30),
    fibonacci_0(31),
    fibonacci_0(32),
    fibonacci_0(33),
    fibonacci_0(34),
    fibonacci_0(35),
    fibonacci_0(36),
    fibonacci_0(37),
    fibonacci_0(38),
    fibonacci_0(39),
    fibonacci_0(40),

    fibonacci_1(0),
    fibonacci_1(1),
    fibonacci_1(2),
    fibonacci_1(3),
    fibonacci_1(4),
    fibonacci_1(5),
    fibonacci_1(6),
    fibonacci_1(7),
    fibonacci_1(8),
    fibonacci_1(9),
    fibonacci_1(10),
    fibonacci_1(11),
    fibonacci_1(12),
    fibonacci_1(13),
    fibonacci_1(14),
    fibonacci_1(15),
    fibonacci_1(16),
    fibonacci_1(17),
    fibonacci_1(18),
    fibonacci_1(19),
    fibonacci_1(20),
    fibonacci_1(21),
    fibonacci_1(22),
    fibonacci_1(23),
    fibonacci_1(24),
    fibonacci_1(25),
    fibonacci_1(26),
    fibonacci_1(27),
    fibonacci_1(28),
    fibonacci_1(29),
    fibonacci_1(30),
    fibonacci_1(31),
    fibonacci_1(32),
    fibonacci_1(33),
    fibonacci_1(34),
    fibonacci_1(35),
    fibonacci_1(36),
    fibonacci_1(37),
    fibonacci_1(38),
    fibonacci_1(39),
    fibonacci_1(40)
};


int main()
{
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int j;

        std::cin >> j;
        std::cout << answer[j] << " " << answer[j + 41] << std::endl;
    }
}