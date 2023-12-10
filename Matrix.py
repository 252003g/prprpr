def input_matrix():
    matrix = []
    for i in range(3):
        row = list(map(int,input(f"Enter elements for row{i+1} separated by commas : ").split(',')))
        matrix.append(row)
    return matrix
def matrix_addition(matrix1,matrix2):
    result = [[0 for _ in range(3)]for _ in range(3)]
    for i in range(3):
        for j in range(3):
            result[i][j] = matrix1[i][j]+matrix2[i][j]
    return result
def matrix_subtraction(matrix1,matrix2):
    result = [[0 for _ in range(3)]for _ in range(3)]
    for i in range(3):
        for j in range(3):
            result[i][j] = matrix1[i][j]-matrix2[i][j]
    return result
def matrix_multiplication(matrix1,matrix2):
    result = [[0 for _ in range(3)]for _ in range(3)]
    for i in range(3): 
        for j in range(3):
            for k in range(3):
                result[i][j] += matrix1[i][k]+matrix2[k][j]
    return result
def matrix_transpose(matrix):
    result = [[0 for _ in range(3)]for _ in range(3)]
    for i in range(3):
        for j in range(3):
            result[i][j] = matrix[j][i]
    return result
print("Enter your choice:")
print("1.Addition")
print("2.Subtraction")
print("3.Multiplication")
print("4.Transpose")

ch = int(input())
if ch == 1:
    matrixa = input_matrix()
    matrixb = input_matrix()
    result = matrix_addition(matrixa,matrixb)
    print("Addition is : ")
    for row in result:
        print(row)
elif ch == 2:
    matrixa = input_matrix()
    matrixb = input_matrix()
    result = matrix_subtraction(matrixa,matrixb)
    print("Subtraction is : ")
    for row in result:
        print(row)
elif ch == 3:
    matrixa = input_matrix()
    matrixb = input_matrix()
    result = matrix_multiplication(matrixa,matrixb)
    print("Multiplication is : ")
    for row in result:
        print(row)
elif ch == 4:
    matrixa = input_matrix()
    result = matrix_transpose(matrixa)
    print("Transpose is : ")
    for row in result:
        print(row)
else:
    print("Invalid choice")
    
