// Задача 2. std variant.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include <ctime>

std::variant<int, std::string, std::vector<int>> get_variant() {
    std::srand(std::time(nullptr));
    int random_variable = std::rand() % 3;

    std::variant<int, std::string, std::vector<int>> result;
    switch (random_variable)
    {
    case 0:
        result = 5;
        break;
    case 1:
        result = "string";
        break;
    case 2:
        result = std::vector<int>{ 1, 2, 3, 4, 5 };
        break;
    default:
        break;
    }
    return result;
}

int main()
{
    auto tmp = get_variant();

    if (std::holds_alternative<int>(tmp)) {
        auto tru_int = std::get_if<int>(&tmp);
        std::cout << *tru_int * 2;
    }

    if (std::holds_alternative<std::string>(tmp)) {
        auto tru_string = std::get_if<std::string>(&tmp);
        std::cout << *tru_string;
    }

    if (std::holds_alternative<std::vector<int>>(tmp)) {
        auto tru_vector = std::get_if<std::vector<int>>(&tmp);
        for (int i : *tru_vector) {
            std::cout << i << " ";
        }
    }

}

