import numpy as np
import random

def generate_random_matrix(n, m):
    arr = [[random.uniform(-1.0, 1.0) for j in range(m)]
            for i in range(n)]
    return np.array(arr)

def square_matrix(mat):
    n = min(mat.shape)
    square = [[mat[i][j] for j in range(n)] for i in range(n)]
    square = np.array(square)
    return square

def main():
    eps = 1e-9
    tests_num = 20
    for i in range(tests_num):
        f = open("test{}.txt".format(i), "w")
        g = open("test{}.ans".format(i), "w")
        n = random.randint(2, 20)
        m = n + random.randint(1, 5)
        mat = generate_random_matrix(n, m)
        det = np.linalg.det(square_matrix(mat))
        if abs(det) > 1000000:
            print('too big determinant on test {}'.format(i))
        g.write('{}'.format(det))
        f.write('{} {}\n'.format(n, m))
        for j in range(n):
            for k in range(m):
                f.write('{} '.format(mat[j][k]))
            f.write('\n')
        f.close()
        g.close()


if __name__ == '__main__':
    main()
