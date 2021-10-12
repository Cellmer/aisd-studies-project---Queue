#include <iostream>
#include <string>
#include "List.h"


int main()
{
    List list;
    std::string option;
    while (std::cin >> option) //pêtla g³ówna
    {
        if (option == "ADD_BEG")
        {
            int n;
            std::cin >> n;
            list.add_beg(n);
        }
        else if (option == "ADD_END")
        {
            int n;
            std::cin >> n;
            list.add_end(n);
        }
        else if (option == "DEL_BEG")
        {
            list.del_beg();
        }
        else if (option == "DEL_END")
        {
            list.del_end();
        }
        else if (option == "PRINT_FORWARD")
        {
            list.print_forward();
        }
        else if (option == "PRINT_BACKWARD")
        {
            list.print_backward();
        }
        else if (option == "SIZE")
        {
            std::cout << list.get_size() << std::endl;
        }
        else if (option == "COUNT")
        {
            std::cout << list.count() << std::endl;
        }
        else if (option == "PUSH")
        {
            int n;
            std::cin >> n;
            list.push(n);
        }
        else if (option == "POP")
        {
            list.pop();
        }
        else if (option == "PRINT_QUEUE")
        {
            list.print_queue();
        }
        else if (option == "GARBAGE_SOFT")
        {
            list.garbage_soft();
        }
        else if (option == "GARBAGE_HARD")
        {
            list.garbage_hard();
        }
    }

    return 0;
}