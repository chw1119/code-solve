#include <algorithm>
#include <iostream>
#include <vector>
#include <memory.h>

int main()
{
    int len, max = 0, min = 1001;
    int temp[1001];
    memset(temp, 0, 1001 * sizeof(int));    

    std::cin >> len;

    std::vector<int> input(len);
    std::vector<int> copy(len);

    for(int i = 0; i < len; i++)
    {
        std::cin >> input[i];
        copy[i] = input[i];

        temp[input[i]]++;

        if(max < input[i])
            max = input[i];

        if(min > input[i])
            min = input[i];
    }

    std::sort(input.begin(), input.end());

    int now = 0;
    for(int i = 0; i <= max; i++)
    {
        int max_i = 0;
        
        for(int j = 0; j < temp[i]; j++)
        {
            for(int k = max_i; k < max; k++)
            {
                if(input[k] == copy[now])
                {
                    max_i = k;

                    std::cout << k << " ";

                    now++;
                }
            }
        }
    }

}