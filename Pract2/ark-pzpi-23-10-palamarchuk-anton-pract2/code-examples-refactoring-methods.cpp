/* ===== В.1 ===== */
#include <iostream>
#include <bitset>
#include <intrin.h>

class CPUFeatureDetector {
public:
    void printCPUFeatures() {
        int cpuInfo[4];
        __cpuid(cpuInfo, 1); // Магічне число

        std::bitset<32> ecx(cpuInfo[2]);
        std::bitset<32> edx(cpuInfo[3]);

        std::cout << "SSE: " << edx[25] << std::endl;
        std::cout << "SSE2: " << edx[26] << std::endl;
        std::cout << "SSE3: " << ecx[0] << std::endl;
        std::cout << "AVX: " << ecx[28] << std::endl;
    }
};

int main() {
    CPUFeatureDetector detector;
    detector.printCPUFeatures();
    return 0;
}
/* ===== В.2 ===== */
#include <iostream>
#include <bitset>
#include <intrin.h>

class CPUFeatureDetector {
public:
    static const int CPU_FEATURE_ID = 1;

    void printCPUFeatures() {
        int cpuInfo[4];
        __cpuid(cpuInfo, CPU_FEATURE_ID);

        std::bitset<32> ecx(cpuInfo[2]);
        std::bitset<32> edx(cpuInfo[3]);

        std::cout << "SSE: " << edx[25] << std::endl;
        std::cout << "SSE2: " << edx[26] << std::endl;
        std::cout << "SSE3: " << ecx[0] << std::endl;
        std::cout << "AVX: " << ecx[28] << std::endl;
    }
};

int main() {
    CPUFeatureDetector detector;
    detector.printCPUFeatures();
    return 0;
}
/* ===== В.3 ===== */
long long ops2;
Matrix M3 = M1.multiplyWithOperations(M2, ops2);
clock_t end2 = clock();

cout << "\n=== З об'єктами ===\n";
cout << "Sum of elements: " << M3.sumElements() << endl;
cout << "Time: " << double(end2 - start2) / CLOCKS_PER_SEC << " s\n";
cout << "Estimated O(n^3) operations: " << ops2 << endl;
/* ===== В.4 ===== */
long long operationCount;
Matrix resultMatrix = M1.multiplyAndCountOperations(M2, operationCount);
clock_t endTime = clock();

cout << "\n=== Object-Oriented Version ===\n";
cout << "Sum of elements: " << resultMatrix.getTotalSum() << endl;
cout << "Execution time: " << double(endTime - start2) / CLOCKS_PER_SEC << " seconds\n";
cout << "Estimated O(n^3) operations: " << operationCount << endl;
/* ===== В.5 ===== */
class Order {
private:
    double amount;
    Customer* customer;
public:
    Order(double a, Customer* c) : amount(a), customer(c) {}

    double getCustomerDiscount() {
        if (customer->getLoyaltyPoints() > 1000) {
            return 0.1;
        }
        else {
            return 0.05;
        }
    }

    double calculateTotalPrice() {
        return amount - amount * getCustomerDiscount();
    }
};

class Customer {
private:
    std::string name;
    int loyaltyPoints;
public:
    Customer(std::string n, int points) : name(n), loyaltyPoints(points) {}

    int getLoyaltyPoints() {
        return loyaltyPoints;
    }
};
/* ===== В.6 ===== */
class Customer {
private:
    std::string name;
    int loyaltyPoints;
public:
    Customer(std::string n, int points) : name(n), loyaltyPoints(points) {}

    int getLoyaltyPoints() {
        return loyaltyPoints;
    }

    double getDiscount() {
        if (loyaltyPoints > 1000) {
            return 0.1;
        }
        else {
            return 0.05;
        }
    }
};

class Order {
private:
    double amount;
    Customer* customer;
public:
    Order(double a, Customer* c) : amount(a), customer(c) {}

    double calculateTotalPrice() {
        return amount - amount * customer->getDiscount();
    }
};