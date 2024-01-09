#ifndef WMATH_MATRIX_H
#define WMATH_MATRIX_H

// #include <vector.h>

namespace WMath {
    template<typename T, size_t ROWS, size_t COLS>
    class Matrix {
        static_assert(ROWS > 0, "ROWS must be greater than 0");
        static_assert(COLS > 0, "COLS must be greater than 0");
    private:
        T data[ROWS][COLS];

    public:
        // 构造函数
        Matrix() {
            for (size_t i = 0; i < ROWS; i++) {
                for (size_t j = 0; j < COLS; j++) {
                    data[i][j] = 0;
                }
            }
        }

        Matrix(const T (&arr)[ROWS][COLS]) {
            for (size_t i = 0; i < ROWS; i++) {
                for (size_t j = 0; j < COLS; j++) {
                    data[i][j] = arr[i][j];
                }
            }
        }

        Matrix(const Matrix<T, ROWS, COLS>& other) {
            for (size_t i = 0; i < ROWS; i++) {
                for (size_t j = 0; j < COLS; j++) {
                    data[i][j] = other.get(i, j);
                }
            }
        }

        T get(size_t row, size_t col) const {
            return data[row][col];
        }

        void set(size_t row, size_t col, T value) {
            data[row][col] = value;
        }

        Matrix<T, ROWS, COLS> operator+(const Matrix<T, ROWS, COLS>& other) const {
            Matrix<T, ROWS, COLS> result;
            for (size_t i = 0; i < ROWS; i++) {
                for (size_t j = 0; j < COLS; j++) {
                    result.set(i, j, this->get(i, j) + other.get(i, j));
                }
            }
            return result;
        }

        template<size_t K>
        Matrix<T, ROWS, K> operator*(const Matrix<T, COLS, K>& other) const {
            Matrix<T, ROWS, K> result;
            for (size_t i = 0; i < ROWS; i++) {
                for (size_t k = 0; k < K; k++) {
                    T sum = 0;
                    for (size_t j = 0; j < COLS; j++) {
                        sum += this->get(i, j) * other.get(j, k);
                    }
                    result.set(i, k, sum);
                }
            }
            return result;
        }

        template<typename S, typename V, typename current>
        Matrix<T, ROWS, 1> operator*(const Vec<S, COLS, V, current>& vec) const {
            Matrix<T, ROWS, 1> result;
            for (size_t i = 0; i < ROWS; i++) {
                T sum = 0;
                for (size_t j = 0; j < COLS; j++) {
                    sum += this->get(i, j) * vec[j];
                }
                result.set(i, 0, sum);
            }
            return result;
        }
    };

    using Matrix2f = Matrix<float, 2, 2>;
    using Matrix3f = Matrix<float, 3, 3>;
    using Matrix4f = Matrix<float, 4, 4>;
}

#endif
