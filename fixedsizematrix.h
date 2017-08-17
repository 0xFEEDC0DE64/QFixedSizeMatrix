#ifndef FIXEDSIZEMATRIX_H
#define FIXEDSIZEMATRIX_H

#include <array>
#include <assert.h>

template<typename T, unsigned int width, unsigned int height>
class FixedSizeMatrix
{
public:
    FixedSizeMatrix();
    FixedSizeMatrix(const std::array<std::array<T, width>, height> &data);
    FixedSizeMatrix(const FixedSizeMatrix<T, width, height> &other);

    FixedSizeMatrix<T, width, height>& operator=(const FixedSizeMatrix<T, width, height>& other);
    FixedSizeMatrix<T, width, height>& operator=(const std::array<std::array<T, width>, height> &data);

    bool operator==(const FixedSizeMatrix<T, width, height>& other) const;
    bool operator!=(const FixedSizeMatrix<T, width, height>& other) const;

    T& operator()(unsigned int x, unsigned int y);
    const T& operator()(unsigned int x, unsigned int y) const;

    const T& at(unsigned int x, unsigned int y);
    void set(unsigned int x, unsigned int y, const T &value);

    FixedSizeMatrix<T, height, width> rotatedLeft() const;
    FixedSizeMatrix<T, height, width> rotatedRight() const;
    FixedSizeMatrix<T, width, height> rotated180() const;

private:
    std::array<std::array<T, width>, height> m_data;
};

template<typename T, unsigned int width, unsigned int height>
FixedSizeMatrix<T, width, height>::FixedSizeMatrix() {}

template<typename T, unsigned int width, unsigned int height>
FixedSizeMatrix<T, width, height>::FixedSizeMatrix(const std::array<std::array<T, width>, height> &data) : m_data(data) {}

template<typename T, unsigned int width, unsigned int height>
FixedSizeMatrix<T, width, height>::FixedSizeMatrix(const FixedSizeMatrix<T, width, height> &other) : m_data(other.m_data) {}

template<typename T, unsigned int width, unsigned int height>
FixedSizeMatrix<T, width, height> &FixedSizeMatrix<T, width, height>::operator=(const FixedSizeMatrix<T, width, height> &other)
{
    if(&other != this)
        m_data = other.m_data;
    return *this;
}

template<typename T, unsigned int width, unsigned int height>
FixedSizeMatrix<T, width, height> &FixedSizeMatrix<T, width, height>::operator=(const std::array<std::array<T, width>, height> &data)
{
    m_data = data;
    return *this;
}

template<typename T, unsigned int width, unsigned int height>
bool FixedSizeMatrix<T, width, height>::operator==(const FixedSizeMatrix<T, width, height> &other) const { return m_data == other.m_data; }

template<typename T, unsigned int width, unsigned int height>
bool FixedSizeMatrix<T, width, height>::operator!=(const FixedSizeMatrix<T, width, height> &other) const { return m_data != other.m_data; }

template<typename T, unsigned int width, unsigned int height>
T &FixedSizeMatrix<T, width, height>::operator()(unsigned int x, unsigned int y)
{
    assert(x < width);
    assert(y < height);
    return m_data[y][x];
}

template<typename T, unsigned int width, unsigned int height>
const T &FixedSizeMatrix<T, width, height>::operator()(unsigned int x, unsigned int y) const
{
    assert(x < width);
    assert(y < height);
    return m_data[y][x];
}

template<typename T, unsigned int width, unsigned int height>
const T &FixedSizeMatrix<T, width, height>::at(unsigned int x, unsigned int y)
{
    assert(x < width);
    assert(y < height);
    return m_data[y][x];
}

template<typename T, unsigned int width, unsigned int height>
void FixedSizeMatrix<T, width, height>::set(unsigned int x, unsigned int y, const T &value)
{
    assert(x < width);
    assert(y < height);
    m_data[y][x] = value;
}

template<typename T, unsigned int width, unsigned int height>
FixedSizeMatrix<T, height, width> FixedSizeMatrix<T, width, height>::rotatedLeft() const
{
    std::array<std::array<T, height>, width> data;

    for(unsigned int y = 0; y < height; y++)
        for(unsigned int x = 0; x < width; x++)
            data[width-x-1][y] = m_data[y][x];

    return FixedSizeMatrix<T, height, width>(data);
}

template<typename T, unsigned int width, unsigned int height>
FixedSizeMatrix<T, height, width> FixedSizeMatrix<T, width, height>::rotatedRight() const
{
    std::array<std::array<T, height>, width> data;

    for(unsigned int y = 0; y < height; y++)
        for(unsigned int x = 0; x < width; x++)
            data[x][height-y-1] = m_data[y][x];

    return FixedSizeMatrix<T, height, width>(data);
}

template<typename T, unsigned int width, unsigned int height>
FixedSizeMatrix<T, width, height> FixedSizeMatrix<T, width, height>::rotated180() const
{
    std::array<std::array<T, width>, height> data;

    for(unsigned int y = 0; y < height; y++)
        for(unsigned int x = 0; x < width; x++)
            data[height-y-1][width-x-1] = m_data[y][x];

    return FixedSizeMatrix<T, width, height>(data);
}

#endif // FIXEDSIZEMATRIX_H
