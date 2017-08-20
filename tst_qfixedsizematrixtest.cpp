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
    void copyConstructorTest();
    void assignmentOperatorTest();
    void equalsOperatorTest();
    void notEqualsOperatorTest();
    void rotateLeftTest();
    void rotateRightTest();
    void rotate180Test();
    void mirrorHorizontallyTest();
    void mirrorVerticallyTest();
    void asRotatedLeftTest();
    void asRotatedRightTest();
    void asRotated180Test();
    void asMirroredHorizontally();
    void asMirroredVertically();

private:
    static const std::array<std::array<TestEnum, 2>, 4> demoData2x4;
    static const std::array<std::array<TestEnum, 4>, 2> demoData2x4RotatedLeft;
    static const std::array<std::array<TestEnum, 4>, 2> demoData2x4RotatedRight;
    static const std::array<std::array<TestEnum, 2>, 4> demoData2x4Rotated180;

    static const std::array<std::array<TestEnum, 4>, 4> demoData4x4;
    static const std::array<std::array<TestEnum, 4>, 4> demoData4x4RotatedLeft;
    static const std::array<std::array<TestEnum, 4>, 4> demoData4x4RotatedRight;
    static const std::array<std::array<TestEnum, 4>, 4> demoData4x4Rotated180;

    template<unsigned int width, unsigned int height>
    void verifyData(const FixedSizeMatrix<TestEnum, width, height>& matrix,
                          const std::array<std::array<QFixedSizeMatrixTest::TestEnum, width>, height> &data);
};

const std::array<std::array<QFixedSizeMatrixTest::TestEnum, 2>, 4> QFixedSizeMatrixTest::demoData2x4 {
    std::array<TestEnum, 2> { TestEnum::ONE, TestEnum::ONE },
    std::array<TestEnum, 2> { TestEnum::TWO, TestEnum::TWO },
    std::array<TestEnum, 2> { TestEnum::THREE, TestEnum::THREE },
    std::array<TestEnum, 2> { TestEnum::FOUR, TestEnum::FOUR }
};

const std::array<std::array<QFixedSizeMatrixTest::TestEnum, 4>, 2> QFixedSizeMatrixTest::demoData2x4RotatedLeft {
    std::array<TestEnum, 4> { TestEnum::ONE, TestEnum::TWO, TestEnum::THREE, TestEnum::FOUR },
    std::array<TestEnum, 4> { TestEnum::ONE, TestEnum::TWO, TestEnum::THREE, TestEnum::FOUR }
};

const std::array<std::array<QFixedSizeMatrixTest::TestEnum, 4>, 2> QFixedSizeMatrixTest::demoData2x4RotatedRight {
    std::array<TestEnum, 4> { TestEnum::FOUR, TestEnum::THREE, TestEnum::TWO, TestEnum::ONE },
    std::array<TestEnum, 4> { TestEnum::FOUR, TestEnum::THREE, TestEnum::TWO, TestEnum::ONE }
};

const std::array<std::array<QFixedSizeMatrixTest::TestEnum, 2>, 4> QFixedSizeMatrixTest::demoData2x4Rotated180 {
    std::array<TestEnum, 2> { TestEnum::FOUR, TestEnum::FOUR },
    std::array<TestEnum, 2> { TestEnum::THREE, TestEnum::THREE },
    std::array<TestEnum, 2> { TestEnum::TWO, TestEnum::TWO },
    std::array<TestEnum, 2> { TestEnum::ONE, TestEnum::ONE }
};

const std::array<std::array<QFixedSizeMatrixTest::TestEnum, 4>, 4> QFixedSizeMatrixTest::demoData4x4 {
    std::array<TestEnum, 4> { TestEnum::ONE, TestEnum::ONE, TestEnum::ONE, TestEnum::ONE },
    std::array<TestEnum, 4> { TestEnum::TWO, TestEnum::TWO, TestEnum::TWO, TestEnum::TWO },
    std::array<TestEnum, 4> { TestEnum::THREE, TestEnum::THREE, TestEnum::THREE, TestEnum::THREE },
    std::array<TestEnum, 4> { TestEnum::FOUR, TestEnum::FOUR, TestEnum::FOUR, TestEnum::FOUR }
};

const std::array<std::array<QFixedSizeMatrixTest::TestEnum, 4>, 4> QFixedSizeMatrixTest::demoData4x4RotatedLeft {
    std::array<TestEnum, 4> { TestEnum::ONE, TestEnum::TWO, TestEnum::THREE, TestEnum::FOUR },
    std::array<TestEnum, 4> { TestEnum::ONE, TestEnum::TWO, TestEnum::THREE, TestEnum::FOUR },
    std::array<TestEnum, 4> { TestEnum::ONE, TestEnum::TWO, TestEnum::THREE, TestEnum::FOUR },
    std::array<TestEnum, 4> { TestEnum::ONE, TestEnum::TWO, TestEnum::THREE, TestEnum::FOUR }
};

const std::array<std::array<QFixedSizeMatrixTest::TestEnum, 4>, 4> QFixedSizeMatrixTest::demoData4x4RotatedRight {
    std::array<TestEnum, 4> { TestEnum::FOUR, TestEnum::THREE, TestEnum::TWO, TestEnum::ONE },
    std::array<TestEnum, 4> { TestEnum::FOUR, TestEnum::THREE, TestEnum::TWO, TestEnum::ONE },
    std::array<TestEnum, 4> { TestEnum::FOUR, TestEnum::THREE, TestEnum::TWO, TestEnum::ONE },
    std::array<TestEnum, 4> { TestEnum::FOUR, TestEnum::THREE, TestEnum::TWO, TestEnum::ONE }
};

const std::array<std::array<QFixedSizeMatrixTest::TestEnum, 4>, 4> QFixedSizeMatrixTest::demoData4x4Rotated180 {
    std::array<TestEnum, 4> { TestEnum::FOUR, TestEnum::FOUR, TestEnum::FOUR, TestEnum::FOUR },
    std::array<TestEnum, 4> { TestEnum::THREE, TestEnum::THREE, TestEnum::THREE, TestEnum::THREE },
    std::array<TestEnum, 4> { TestEnum::TWO, TestEnum::TWO, TestEnum::TWO, TestEnum::TWO },
    std::array<TestEnum, 4> { TestEnum::ONE, TestEnum::ONE, TestEnum::ONE, TestEnum::ONE }
};

template<unsigned int width, unsigned int height>
void QFixedSizeMatrixTest::verifyData(const FixedSizeMatrix<QFixedSizeMatrixTest::TestEnum, width, height> &matrix,
                                      const std::array<std::array<QFixedSizeMatrixTest::TestEnum, width>, height> &data)
{
    for(unsigned int y = 0; y < height; y++)
        for(unsigned int x = 0; x < width; x++)
            QCOMPARE(matrix(x, y), data[y][x]);
}

void QFixedSizeMatrixTest::constructorTest()
{
    FixedSizeMatrix<TestEnum, 2, 4> matrix { demoData2x4 };
    verifyData(matrix, demoData2x4);
}

void QFixedSizeMatrixTest::copyConstructorTest()
{
    FixedSizeMatrix<TestEnum, 2, 4> matrix { demoData2x4 };
    FixedSizeMatrix<TestEnum, 2, 4> otherMatrix { matrix };
    verifyData(matrix, demoData2x4);
}

void QFixedSizeMatrixTest::assignmentOperatorTest()
{
    FixedSizeMatrix<TestEnum, 2, 4> matrix { demoData2x4 };
    FixedSizeMatrix<TestEnum, 2, 4> other;
    other = matrix;
    verifyData(other, demoData2x4);
}

void QFixedSizeMatrixTest::equalsOperatorTest()
{
    FixedSizeMatrix<TestEnum, 2, 4> matrix0 { demoData2x4 };
    FixedSizeMatrix<TestEnum, 2, 4> matrix1;

    QVERIFY2(!(matrix0 == matrix1), "");

    matrix1 = FixedSizeMatrix<TestEnum, 2, 4> { demoData2x4 };

    QVERIFY2(matrix0 == matrix1, "");
}

void QFixedSizeMatrixTest::notEqualsOperatorTest()
{
    FixedSizeMatrix<TestEnum, 2, 4> matrix0 { demoData2x4 };
    FixedSizeMatrix<TestEnum, 2, 4> matrix1;

    QVERIFY2(matrix0 != matrix1, "");

    matrix1 = FixedSizeMatrix<TestEnum, 2, 4> { demoData2x4 };

    QVERIFY2(matrix0 == matrix1, "");
}

void QFixedSizeMatrixTest::rotateLeftTest()
{
    FixedSizeMatrix<TestEnum, 4, 4> matrix { demoData4x4 };

    matrix.rotateLeft();
    verifyData(matrix, demoData4x4RotatedLeft);

    matrix.rotateLeft();
    verifyData(matrix, demoData4x4Rotated180);

    matrix.rotateLeft();
    verifyData(matrix, demoData4x4RotatedRight);

    matrix.rotateLeft();
    verifyData(matrix, demoData4x4);
}

void QFixedSizeMatrixTest::rotateRightTest()
{
    FixedSizeMatrix<TestEnum, 4, 4> matrix { demoData4x4 };

    matrix.rotateRight();
    verifyData(matrix, demoData4x4RotatedRight);

    matrix.rotateRight();
    verifyData(matrix, demoData4x4Rotated180);

    matrix.rotateRight();
    verifyData(matrix, demoData4x4RotatedLeft);

    matrix.rotateRight();
    verifyData(matrix, demoData4x4);
}

void QFixedSizeMatrixTest::rotate180Test()
{
    FixedSizeMatrix<TestEnum, 2, 4> matrix { demoData2x4 };

    matrix.rotate180();
    verifyData(matrix, demoData2x4Rotated180);

    matrix.rotate180();
    verifyData(matrix, demoData2x4);
}

void QFixedSizeMatrixTest::mirrorHorizontallyTest()
{
    //TODO
}

void QFixedSizeMatrixTest::mirrorVerticallyTest()
{
    //TODO
}

void QFixedSizeMatrixTest::asRotatedLeftTest()
{
    FixedSizeMatrix<TestEnum, 2, 4> matrix { demoData2x4 };
    FixedSizeMatrix<TestEnum, 4, 2> rotatedContainer;

    rotatedContainer = matrix.asRotatedLeft();
    verifyData(rotatedContainer, demoData2x4RotatedLeft);

    matrix = rotatedContainer.asRotatedLeft();
    verifyData(matrix, demoData2x4Rotated180);

    rotatedContainer = matrix.asRotatedLeft();
    verifyData(rotatedContainer, demoData2x4RotatedRight);

    matrix = rotatedContainer.asRotatedLeft();
    verifyData(matrix, demoData2x4);
}

void QFixedSizeMatrixTest::asRotatedRightTest()
{
    FixedSizeMatrix<TestEnum, 2, 4> matrix { demoData2x4 };
    FixedSizeMatrix<TestEnum, 4, 2> rotatedContainer;

    rotatedContainer = matrix.asRotatedRight();
    verifyData(rotatedContainer, demoData2x4RotatedRight);

    matrix = rotatedContainer.asRotatedRight();
    verifyData(matrix, demoData2x4Rotated180);

    rotatedContainer = matrix.asRotatedRight();
    verifyData(rotatedContainer, demoData2x4RotatedLeft);

    matrix = rotatedContainer.asRotatedRight();
    verifyData(matrix, demoData2x4);
}

void QFixedSizeMatrixTest::asRotated180Test()
{
    FixedSizeMatrix<TestEnum, 2, 4> matrix { demoData2x4 };

    matrix = matrix.asRotated180();
    verifyData(matrix, demoData2x4Rotated180);

    matrix = matrix.asRotated180();
    verifyData(matrix, demoData2x4);
}

void QFixedSizeMatrixTest::asMirroredHorizontally()
{
    //TODO
}

void QFixedSizeMatrixTest::asMirroredVertically()
{
    //TODO
}

QTEST_APPLESS_MAIN(QFixedSizeMatrixTest)

#include "tst_qfixedsizematrixtest.moc"
