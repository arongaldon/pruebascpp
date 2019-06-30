#include <array>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>

const size_t MAX = 20;

int main(int argc, char *argv[])
{
    const std::array<uint64_t, 10> values = {{
        0x1ULL,
        0x2ULL,
        0x4ULL,
        0x8ULL,
        0x10ULL,
        0x20ULL,
        0x1ULL,
        0x1ULL,
        0x1ULL,
        0x1ULL
    }};

    std::cout<<"                 bin     oct    dec   hex  i"<<std::endl;
    std::cout<<"==================== ======= ====== ===== =="<<std::endl;
    std::cout<<"09876543210987654321 7654321 654321 54321   "<<std::endl;
    uint64_t num = 0x1ULL;
    for (size_t i = 1; i <= MAX; ++i, num <<= 1)
    {
        std::cout<<std::bitset<MAX>(num);
        std::cout<<" "<<std::setfill(' ')<<std::setw(7)<<std::oct<<num;
        std::cout<<" "<<std::setfill(' ')<<std::setw(6)<<std::dec<<num;
        std::cout<<" "<<std::setfill(' ')<<std::setw(5)<<std::hex<<num;
        std::cout<<" "<<std::setfill(' ')<<std::setw(MAX > 0 ? (int) std::log10 ((double) MAX) + 1 : 1)<<std::dec<<i<<std::endl;
    }

    return EXIT_SUCCESS;
}
