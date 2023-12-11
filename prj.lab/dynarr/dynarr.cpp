#include "dynarr.hpp"

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
        //delete[] data_;
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
    size_ += 1;
    data_[index] = val;
}