#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <cstddef>
#include <iostream>

class DynArr {
public:
    DynArr() = default;
    DynArr(const DynArr&) = default; // нельзя дефолтным
    DynArr(const std::ptrdiff_t size);
    ~DynArr() = default;
    [[nodiscard]] DynArr& operator=(const DynArr&) = default; // нельзя дефолтным

    [[nodiscard]] std::ptrdiff_t Size() const noexcept;
    void Resize(const std::ptrdiff_t size);
    void Insert(const std::ptrdiff_t index, const float& val);
    [[nodiscard]] float& operator[](const std::ptrdiff_t idx);
    [[nodiscard]] const float operator[](const std::ptrdiff_t idx) const;
private:
    std::ptrdiff_t size_ = 0;
    float* data_ = nullptr;
};

#endif