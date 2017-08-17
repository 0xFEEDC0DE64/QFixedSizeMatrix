#include <QtTest>

#include <array>

#include "fixedsizematrix.h"

class QFixedSizeMatrixTest : public QObject
{
    Q_OBJECT

public:
    enum class TestEnum { ONE, TWO, THREE, FOUR };
    Q_ENUM(TestEnum)

private Q_SLOTS:
    void constructorTest();
    void assignmentTest();
    void comparisonTest();
    void rotateLeftTest();
    void rotateRightTest();
    void rotate180Test();

private:
    static const std::array<std::array<TestEnum, 2>, 4> demoData;
    static const std::array<std::array<TestEnum, 4>, 2> demoDataRotatedLeft;
    static const std::array<std::array<TestEnum, 4>, 2> demoDataRotatedRight;
    static const std::array<std::array<TestEnum, 2>, 4> demoDataRotated180;

    template<unsigned int width, unsigned int height>
    void verifyToDemoData(const FixedSizeMatrix<TestEnum, width, height>& matrix,
                          const std::array<std::array<QFixedSizeMatrixTest::TestEnum, width>, height> &data);
};

const std::array<std::array<QFixedSizeMatrixTest::TestEnum, 2>, 4> QFixedSizeMatrixTest::demoData {
    std::array<TestEnum, 2> { TestEnum::ONE, TestEnum::ONE },
    std::array<TestEnum, 2> { TestEnum::TWO, TestEnum::TWO },
    std::array<TestEnum, 2> { TestEnum::THREE, TestEnum::THREE },
    std::array<TestEnum, 2> { TestEnum::FOUR, TestEnum::FOUR }
};

const std::array<std::array<QFixedSizeMatrixTest::TestEnum, 4>, 2> QFixedSizeMatrixTest::demoDataRotatedLeft {
    std::array<TestEnum, 4> { TestEnum::ONE, TestEnum::TWO, TestEnum::THREE, TestEnum::FOUR },
    std::array<TestEnum, 4> { TestEnum::ONE, TestEnum::TWO, TestEnum::THREE, TestEnum::FOUR }
};

const std::array<std::array<QFixedSizeMatrixTest::TestEnum, 4>, 2> QFixedSizeMatrixTest::demoDataRotatedRight {
    std::array<TestEnum, 4> { TestEnum::FOUR, TestEnum::THREE, TestEnum::TWO, TestEnum::ONE },
    std::array<TestEnum, 4> { TestEnum::FOUR, TestEnum::THREE, TestEnum::TWO, TestEnum::ONE }
};

const std::array<std::array<QFixedSizeMatrixTest::TestEnum, 2>, 4> QFixedSizeMatrixTest::demoDataRotated180 {
    std::array<TestEnum, 2> { TestEnum::FOUR, TestEnum::FOUR },
    std::array<TestEnum, 2> { TestEnum::THREE, TestEnum::THREE },
    std::array<TestEnum, 2> { TestEnum::TWO, TestEnum::TWO },
    std::array<TestEnum, 2> { TestEnum::ONE, TestEnum::ONE }
};

template<unsigned int width, unsigned int height>
void QFixedSizeMatrixTest::verifyToDemoData(const FixedSizeMatrix<QFixedSizeMatrixTest::TestEnum, width, height> &matrix,
                                   const std::array<std::array<QFixedSizeMatrixTest::TestEnum, width>, height> &data)
{
    for(unsigned int y = 0; y < height; y++)
        for(unsigned int x = 0; x < width; x++)
            QCOMPARE(matrix(x, y), data[y][x]);
}

void QFixedSizeMatrixTest::constructorTest()
{
    FixedSizeMatrix<TestEnum, 2, 4> matrix(demoData);
    verifyToDemoData(matrix, demoData);
}

void QFixedSizeMatrixTest::assignmentTest()
{
    FixedSizeMatrix<TestEnum, 2, 4> matrix(demoData);
    FixedSizeMatrix<TestEnum, 2, 4> other;
    other = matrix;
    verifyToDemoData(other, demoData);
}

void QFixedSizeMatrixTest::comparisonTest()
{
    FixedSizeMatrix<TestEnum, 2, 4> matrix0(demoData);
    FixedSizeMatrix<TestEnum, 2, 4> matrix1;

    QVERIFY2(matrix0 != matrix1, "");

    matrix1 = FixedSizeMatrix<TestEnum, 2, 4> { demoData };

    QVERIFY2(matrix0 == matrix1, "");
}

void QFixedSizeMatrixTest::rotateLeftTest()
{
    FixedSizeMatrix<TestEnum, 2, 4> matrix(demoData);
    FixedSizeMatrix<TestEnum, 4, 2> rotatedContainer;

    rotatedContainer = matrix.rotatedLeft();
    verifyToDemoData(rotatedContainer, demoDataRotatedLeft);

    matrix = rotatedContainer.rotatedLeft();
    verifyToDemoData(matrix, demoDataRotated180);

    rotatedContainer = matrix.rotatedLeft();
    verifyToDemoData(rotatedContainer, demoDataRotatedRight);

    matrix = rotatedContainer.rotatedLeft();
    verifyToDemoData(matrix, demoData);
}

void QFixedSizeMatrixTest::rotateRightTest()
{
    FixedSizeMatrix<TestEnum, 2, 4> matrix(demoData);
    FixedSizeMatrix<TestEnum, 4, 2> rotatedContainer;

    rotatedContainer = matrix.rotatedRight();
    verifyToDemoData(rotatedContainer, demoDataRotatedRight);

    matrix = rotatedContainer.rotatedRight();
    verifyToDemoData(matrix, demoDataRotated180);

    rotatedContainer = matrix.rotatedRight();
    verifyToDemoData(rotatedContainer, demoDataRotatedLeft);

    matrix = rotatedContainer.rotatedRight();
    verifyToDemoData(matrix, demoData);
}

void QFixedSizeMatrixTest::rotate180Test()
{
    FixedSizeMatrix<TestEnum, 2, 4> matrix(demoData);

    matrix = matrix.rotated180();
    verifyToDemoData(matrix, demoDataRotated180);

    matrix = matrix.rotated180();
    verifyToDemoData(matrix, demoData);
}

QTEST_APPLESS_MAIN(QFixedSizeMatrixTest)

#include "tst_qfixedsizematrixtest.moc"
