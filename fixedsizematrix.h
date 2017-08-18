#ifndef FIXEDSIZEMATRIX_H
#define FIXEDSIZEMATRIX_H

#include <array>
#include <assert.h>

template<typename T, unsigned int width, unsigned int height>
class FixedSizeMatrix
{
public:
    FixedSizeMatrix();
    FixedSizeMatrix(const std::array<std::array<T, width>, height>& data);
    FixedSizeMatrix(const FixedSizeMatrix<T, width, height> &other);

    auto& operator=(const FixedSizeMatrix<T, width, height>& other);
    auto& operator=(const std::array<std::array<T, width>, height>& data);

    auto operator==(const FixedSizeMatrix<T, width, height>& other) const;
    auto operator!=(const FixedSizeMatrix<T, width, height>& other) const;

    auto& operator()(unsigned int x, unsigned int y);
    const auto& operator()(unsigned int x, unsigned int y) const;

    void rotateLeft();
    void rotateRight();
    void rotate180();
    void mirrorHorizontally();
    void mirrorVertically();

    auto asRotatedLeft() const;
    auto asRotatedRight() const;
    auto asRotated180() const;
    auto asMirroredHorizontally() const;
    auto asMirroredVertically() const;

private:
    std::array<std::array<T, width>, height> m_data;
};

template<typename T, unsigned int width, unsigned int height>
FixedSizeMatrix<T, width, height>::FixedSizeMatrix() {}

template<typename T, unsigned int width, unsigned int height>
FixedSizeMatrix<T, width, height>::FixedSizeMatrix(const std::array<std::array<T, width>, height>& data) : m_data(data) {}

template<typename T, unsigned int width, unsigned int height>
FixedSizeMatrix<T, width, height>::FixedSizeMatrix(const FixedSizeMatrix<T, width, height>& other) : m_data(other.m_data) {}

template<typename T, unsigned int width, unsigned int height>
auto& FixedSizeMatrix<T, width, height>::operator=(const FixedSizeMatrix<T, width, height>& other)
{
    if(&other != this)
        m_data = other.m_data;
    return *this;
}

template<typename T, unsigned int width, unsigned int height>
auto& FixedSizeMatrix<T, width, height>::operator=(const std::array<std::array<T, width>, height>& data)
{
    m_data = data;
    return *this;
}

template<typename T, unsigned int width, unsigned int height>
auto FixedSizeMatrix<T, width, height>::operator==(const FixedSizeMatrix<T, width, height>& other) const
{
    return m_data == other.m_data;
}

template<typename T, unsigned int width, unsigned int height>
auto FixedSizeMatrix<T, width, height>::operator!=(const FixedSizeMatrix<T, width, height>& other) const
{
    return m_data != other.m_data;
}

template<typename T, unsigned int width, unsigned int height>
auto& FixedSizeMatrix<T, width, height>::operator()(unsigned int x, unsigned int y)
{
    assert(x < width);
    assert(y < height);
    return m_data[y][x];
}

template<typename T, unsigned int width, unsigned int height>
const auto& FixedSizeMatrix<T, width, height>::operator()(unsigned int x, unsigned int y) const
{
    assert(x < width);
    assert(y < height);
    return m_data[y][x];
}

template<typename T, unsigned int width, unsigned int height>
void FixedSizeMatrix<T, width, height>::rotateLeft()
{
    static_assert(width == height, "Rotating in place only works when width matches height");

    //TODO
}

template<typename T, unsigned int width, unsigned int height>
void FixedSizeMatrix<T, width, height>::rotateRight()
{
    static_assert(width == height, "Rotating in place only works when width matches height");

    //TODO
}

template<typename T, unsigned int width, unsigned int height>
void FixedSizeMatrix<T, width, height>::rotate180()
{
    //TODO
}

template<typename T, unsigned int width, unsigned int height>
void FixedSizeMatrix<T, width, height>::mirrorHorizontally()
{
    //TODO
}

template<typename T, unsigned int width, unsigned int height>
void FixedSizeMatrix<T, width, height>::mirrorVertically()
{
    //TODO
}

template<typename T, unsigned int width, unsigned int height>
auto FixedSizeMatrix<T, width, height>::asRotatedLeft() const
{
    std::array<std::array<T, height>, width> data;

    for(unsigned int y = 0; y < height; y++)
        for(unsigned int x = 0; x < width; x++)
            data[width-x-1][y] = m_data[y][x];

    return FixedSizeMatrix<T, height, width>(data);
}

template<typename T, unsigned int width, unsigned int height>
auto FixedSizeMatrix<T, width, height>::asRotatedRight() const
{
    std::array<std::array<T, height>, width> data;

    for(unsigned int y = 0; y < height; y++)
        for(unsigned int x = 0; x < width; x++)
            data[x][height-y-1] = m_data[y][x];

    return FixedSizeMatrix<T, height, width>(data);
}

template<typename T, unsigned int width, unsigned int height>
auto FixedSizeMatrix<T, width, height>::asRotated180() const
{
    std::array<std::array<T, width>, height> data;

    for(unsigned int y = 0; y < height; y++)
        for(unsigned int x = 0; x < width; x++)
            data[height-y-1][width-x-1] = m_data[y][x];

    return FixedSizeMatrix<T, width, height>(data);
}

template<typename T, unsigned int width, unsigned int height>
auto FixedSizeMatrix<T, width, height>::asMirroredHorizontally() const
{
    //TODO
}

template<typename T, unsigned int width, unsigned int height>
auto FixedSizeMatrix<T, width, height>::asMirroredVertically() const
{
    //TODO
}

#endif // FIXEDSIZEMATRIX_H
