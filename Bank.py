def calculate_net_amount(transactions):
    balance = 0

    for transaction in transactions:
        transaction_type,amount = transaction.split()
        amount = int(amount)

        if transaction_type == 'D':
            balance += amount
        elif transaction_type == 'W':
            if balance>=amount:
                balance -= amount
            else:
                print("Withdrawal not allowed.Insufficuent balance.")
    return balance

if __name__ == "__main__":
    transactions =[]

    while True:
        transaction = input("Enter transaction(D/W amount):")
        if transaction.lower() == 'q':
            break
        transactions.append(transaction)

        net_amount = calculate_net_amount(transactions)
        print(f"Net amount in the account : {net_amount}")
            