def counting_sort(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    for i in range(n):
        index = int(arr[i] // exp) % 10
        count[index] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = n - 1
    while i >= 0:
        index = int(arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1

    for i in range(n):
        arr[i] = output[i]


def radix_sort(arr):
    max_digits = max([len(str(int(num))) + len(str(num).split(".")[1]) if "." in str(num) else len(str(int(num))) for num in arr])
    exp = 1
    for _ in range(max_digits):
        counting_sort(arr, exp)
        exp *= 10


def display_top_scores(scores, top_count):
    print(f"\nTop {top_count} Scores:")
    for i in range(min(top_count, len(scores))):
        print(f"{i + 1}. {scores[i]}%")


def main():
    # Accept user input for second-year percentages (floating-point numbers)
    student_percentages = []
    num_students = int(input("Enter the number of students: "))
    for i in range(num_students):
        percentage = float(input(f"Enter the percentage for student {i + 1}: "))
        student_percentages.append(percentage)

    print("\nOriginal Scores:")
    print(student_percentages)

    # Sort scores using radix sort
    radix_sort(student_percentages)

    print("\nSorted Scores:")
    print(student_percentages)

    # Display top 5 scores
    top_count = 5
    display_top_scores(student_percentages[::-1], top_count)


if __name__ == "__main__":
    main()
