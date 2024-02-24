from pyfiglet import Figlet
import sys

def main():
    if len(sys.argv) == 1:
        f = None
    elif len(sys.argv) == 3 and (sys.argv[1] == '-f' or sys.argv[1] == '--f'):
        f = sys.argv[2]
    else:
        print("Invalid usage")
        sys.exit(1)

    text = input("Input: ")
    figlet = Figlet()
    available_fonts = figlet.getFonts() if f else []

    if f and f not in available_fonts:
        print("Invalid usage")

    figlet.setFont(font = f)
    print(figlet.renderText(text))

if __name__ == "__main__":
    main()
