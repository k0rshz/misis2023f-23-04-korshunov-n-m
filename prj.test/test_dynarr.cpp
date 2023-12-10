#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <cstddef>

class DynArr {
public:
    DynArr() = default;
    DynArr(const DynArr&) = default;
    DynArr(const std::ptrdiff_t size);
    ~DynArr() = default;
    [[nodiscard]] DynArr& operator=(const DynArr&) = default;

    [[nodiscard]] std::ptrdiff_t Size() const noexcept;
    void Resize(const std::ptrdiff_t size);
    void Insert(const std::ptrdiff_t index, const float& val);
    [[nodiscard]] float& operator[](const std::ptrdiff_t idx);
    [[nodiscard]] const float operator[](const std::ptrdiff_t idx) const;
private:
    std::ptrdiff_t size_ = 0; //!< число элементов в массиве
    float* data_ = nullptr;          //!< элементы массива
};

std::ptrdiff_t DynArr::Size() const noexcept {
    return size_;
}

DynArr::DynArr(const std::ptrdiff_t sizeNew) {
    if (sizeNew < 0) {
        throw std::overflow_error("Error: Size cannot be less than or equal to zero");
    }
    size_ = sizeNew;
    data_ = new float[sizeNew] {};
}

float& DynArr::operator[](const std::ptrdiff_t idx) {
    if (idx >= size_ || idx < 0) {
        throw std::out_of_range("Error: Out of range");
    }
    return *(data_ + idx);
}

const float DynArr::operator[](std::ptrdiff_t idx) const {
    if (idx >= size_ || idx < 0) {
        throw std::out_of_range("Error: Out of range");
    }
    return *(data_ + idx);
}

void DynArr::Resize(const std::ptrdiff_t sizeNew) {
    if (sizeNew <= 0) {
        throw std::overflow_error("Error: Size cannot be less than or equal to zero");
    }
    if (sizeNew > size_) {
        float* pNewData = new float[sizeNew] {};
        for (std::ptrdiff_t i = 0; i < size_; ++i) {
            pNewData[i] = data_[i];
        }
        for (std::ptrdiff_t i = size_; i < sizeNew; ++i) {
            pNewData[i] = 0;
        }
        delete[] data_;
        data_ = pNewData;
    }
    size_ = sizeNew;
}

void DynArr::Insert(const std::ptrdiff_t index, const float& val) {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Error: Out of range");
    }
    for (std::ptrdiff_t i = size_; i > index; --i) {
        data_[i] = data_[i - 1];
    }
    data_[index] = val;
}

TEST_CASE("dynarr ctor") {
    DynArr arr_def;
    CHECK_EQ(arr_def.Size(), 0);

    const int size = 5;
    DynArr arr_s(size);
    CHECK_EQ(arr_s.Size(), size);
}

TEST_CASE("dynarr op[]") {
    const int size = 5;
    DynArr arr(size);
    DynArr arr2(10);
    CHECK_EQ(arr[0], 0);
    CHECK_EQ(arr[arr.Size() - 1], 0);
    CHECK_EQ(arr[0], arr[1]);
    CHECK_THROWS(arr2[-1]);
    CHECK_EQ(arr2[0], arr[arr.Size()-1]);
    CHECK_THROWS(arr[arr.Size()]);
}
