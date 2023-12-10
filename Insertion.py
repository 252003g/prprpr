def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2


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

    # Sort scores using Insertion Sort
    insertion_sorted_scores = student_percentages.copy()
    insertion_sort(insertion_sorted_scores)
    print("\nScores after Insertion Sort:")
    print(insertion_sorted_scores)

    # Sort scores using Shell Sort
    shell_sorted_scores = student_percentages.copy()
    shell_sort(shell_sorted_scores)
    print("\nScores after Shell Sort:")
    print(shell_sorted_scores)

    # Display top 5 scores for Insertion Sort
    display_top_scores(insertion_sorted_scores[::-1], 5)

    # Display top 5 scores for Shell Sort
    display_top_scores(shell_sorted_scores[::-1], 5)


if __name__ == "__main__":
    main()
