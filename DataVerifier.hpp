#ifndef DATAVERIFIER_HPP
#define DATAVERIFIER_HPP
#include <functional>
#include <cstddef>

template<typename T>
class DataVerifier 
{
public:
    explicit DataVerifier(const T& value);
    bool verify(const T& candidate) const;
    size_t getHash() const;
private:
    size_t referenceHash;
};

template<typename T>
DataVerifier<T>::DataVerifier(const T& value) : referenceHash{std::hash<T>{}(value)} {}

template<typename T>
bool DataVerifier<T>::verify(const T& candidate) const {return std::hash<T>{}(candidate) == referenceHash;}

template<typename T>
size_t DataVerifier<T>::getHash() const {return referenceHash;}

#endif