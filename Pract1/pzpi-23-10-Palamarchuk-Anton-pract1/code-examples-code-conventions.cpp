/* ===== В.1 ===== */
// MathUtils.cpp
#ifndef MATHUTILS_H
#define MATHUTILS_H

class MathUtils {
public:
    static int add(int a, int b);
};
#endif

// MathUtils.cpp
#include "MathUtils.h"

int MathUtils::add(int a, int b) {
return a + b;
}

/* ===== В.2 ===== */
class Logger { 
    public: void log(const std::string& message); 
};

class Database {
public:
    void connect() {
        std::cout << "Connecting to database..." << std::endl;
    }
};

/* ===== В.3 ===== */
// Приклад хорошого коду 
if (x > 0) {
    std::cout << "Positive\n";
}
else {
    std::cout << "Non-positive\n";
}

// Приклад поганого коду 
if(x>0){
std::cout << "Positive\n"; 
}else{ std::cout << "Non-positive\n"; }

/* ===== В.4 ===== */
//K&R
if (x > 0) {
    std::cout << "Positive\n";
}

//Allman
if (x > 0)
{
    std::cout << "Positive\n";
}

/* ===== В.5 ===== */
 //PascalCase 
class CarEngine {
public:
    void startEngine();
private:
    //camelCase
    int horsepower;
    //UPPER_CASE
    static const int MAX_RPM = 7000;
};

/* ===== В.6 ===== */
int userAge; // добре 

int ua;      // погано

/* ===== В.7 ===== */
//Приклад хорошого коду
// Використовуємо рекурсію, бо потрібне дерево рішень
int factorial(int n) {
   if (n <= 1) return 1;
   return n * factorial(n - 1);
}

//Приклад поганого коду
// Оголошуємо функцію факторіала 
int factorial_bad(int n) {
    // Якщо п менше або дорівнює 1, повертаємо 1 
    if (n <= 1) return 1;
    // Повертаємо п помножене на факторіал (п - 1)
    return n * factorial(n - 1); // множимо п на попереднє
}

/* ===== В.8 ===== */
/**
* @brief Обчислює суму двох чисел
* @param a перше число
* @param b друге число
* @return сума чисел
*/
int add(int a, int b);

/* ===== В.9 ===== */
Приклад використання ClangFormat з стилем Google 
clang-format -style=Google -i main.cpp

/* ===== В.10 ===== */
// Використання Google Test
#include <gtest/gtest.h>
#include "MathUtils.h"

TEST(MathUtilsTest, AddPositiveNumbers) {
   EXPECT_EQ(MathUtils::add(2, 3), 5);
}

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

int add_for_test(int a, int b) { return a + b; }

TEST_CASE("Addition works correctly") {
   REQUIRE(add_for_test(2, 3) == 5);
   REQUIRE(add_for_test(-1, 1) == 0);
}

/* ===== В.11 ===== */
Підключення Cppcheck
cppcheck --enable-all src/

/* ===== В.12 ===== */
#include <iostream>
#include <vector>

class Student {
public:
    Student(const std::string& name, int age)
        : name(name), age(age) {
    }

    void printInfo() const {
        std::cout << "Name: " << name
            << ", Age: " << age << std::endl;
    }

private:
    std::string name;
    int age;
};

int main() {
    std::vector<Student> group = {
        {"Anna", 20}, {"Petro", 22}, {"Olena", 21}
    };

    for (const auto& student : group) {
        student.printInfo();
    }

    return 0;
}

#include<iostream>
class s { public:int a; std::string n; s(std::string N, int A)
{ n = N; a = A; }void p() { std::cout << n << ":" << a; } }; int main_bad() { s 
4 x("A", 20); x.p(); }