def main():
    text = input("Greeting:").strip().lower()
    if text.startswith("hello"):
        print("$0")
    elif text.startswith("h"):
        print("$20")
    else:
        print("$100")

if __name__ == "__main__":
    main()
